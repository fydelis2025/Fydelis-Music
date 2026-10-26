#include "fydmusic.h"
#include <QDebug>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QtMath>
#include <cmath>

FydMusic::FydMusic(QObject *parent)
    : QObject(parent), m_andamento(120), m_estaTocando(false), m_indiceAtual(0)
{
    QAudioFormat formato;
    formato.setSampleRate(44100);
    formato.setChannelCount(1);
    formato.setSampleSize(16);
    formato.setCodec("audio/pcm");
    formato.setByteOrder(QAudioFormat::LittleEndian);
    formato.setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultOutputDevice();
    if (!info.isFormatSupported(formato))
        formato = info.nearestFormat(formato);

    m_audioSaida = new QAudioOutput(formato, this);
    m_audioSaida->setVolume(0.8);
}

int FydMusic::andamento() const { return m_andamento; }

void FydMusic::setAndamento(int bpm) {
    bpm = qBound(20, bpm, 300);
    if (m_andamento != bpm) {
        m_andamento = bpm;
        emit andamentoChanged();
    }
}

bool FydMusic::estaTocando() const { return m_estaTocando; }

QString FydMusic::listaNotas() const {
    QString saida;
    for (const auto &n : m_partitura)
        saida += n.ePausa ? "♪ " : n.nome + " ";
    return saida.trimmed();
}

QVariantList FydMusic::partitura() const {
    QVariantList lista;
    for (const auto &n : m_partitura) {
        QVariantMap m;
        m["nome"]     = n.nome;
        m["figura"]   = n.figura;
        m["temPonto"] = n.temPonto;
        m["ePausa"]   = n.ePausa;
        m["ligadura"] = n.temLigadura;
        lista.append(m);
    }
    return lista;
}

// Frequência exata, A4 = 440 Hz
int FydMusic::frequenciaNota(const QString& nome) const {
    static const QMap<QString, double> tabela = {
        {"C4", 261.63}, {"D4", 293.66}, {"E4", 329.63}, {"F4", 349.23},
        {"G4", 392.00}, {"A4", 440.00}, {"B4", 493.88},
        {"C5", 523.25}, {"D5", 587.33}, {"E5", 659.25}, {"F5", 698.46},
        {"G5", 783.99}, {"A5", 880.00}, {"B5", 987.77}, {"C6", 1046.50}
    };
    return qRound(tabela.value(nome, 440.0));
}

// figura: 1=semibreve(4 tempos) 2=mínima(2) 4=semínima(1) 8=colcheia(1/2) 16=semicolcheia(1/4)
int FydMusic::calcularDuracao(int figura, bool temPonto) const {
    double tempoBase = (60.0 / m_andamento) * 1000.0 * 4.0 / figura;
    if (temPonto) tempoBase *= 1.5;
    return qMax(30, qRound(tempoBase));
}

void FydMusic::adicionarNota(const QString& nome, int figura, bool temPonto) {
    NotaMusical n;
    n.nome = nome;
    n.frequencia = frequenciaNota(nome);
    n.figura = figura;
    n.temPonto = temPonto;
    n.duracaoMs = calcularDuracao(figura, temPonto);
    m_partitura.append(n);
    emit partituraChanged();
}

void FydMusic::adicionarPausa(int figura) {
    NotaMusical n;
    n.nome = "Pausa";
    n.figura = figura;
    n.duracaoMs = calcularDuracao(figura, false);
    n.ePausa = true;
    m_partitura.append(n);
    emit partituraChanged();
}

void FydMusic::aplicarLigadura() {
    if (m_partitura.size() < 2) return;
    NotaMusical &ultima = m_partitura.last();
    NotaMusical &penultima = m_partitura[m_partitura.size() - 2];
    if (!penultima.ePausa && !ultima.ePausa && penultima.nome == ultima.nome) {
        penultima.duracaoMs += ultima.duracaoMs;
        penultima.temLigadura = true;
        m_partitura.removeLast();
        emit partituraChanged();
    }
}

void FydMusic::removerUltima() {
    if (!m_partitura.isEmpty()) {
        m_partitura.removeLast();
        emit partituraChanged();
    }
}

void FydMusic::limparPartitura() {
    m_partitura.clear();
    emit partituraChanged();
    emit sequenciaTerminada();
}

void FydMusic::tocarNotaAvulsa(const QString& nome) {
    gerarEReproduzirSom(frequenciaNota(nome), 250);
}

// Onda senoidal com envelope (fade) para não estalar
void FydMusic::gerarEReproduzirSom(int freq, int durMs) {
    if (!m_audioSaida || freq <= 0) return;

    if (m_audioSaida->state() != QAudio::ActiveState)
        m_audioDispositivo = m_audioSaida->start();
    if (!m_audioDispositivo) return;

    const int taxa = 44100;
    const int amostras = (taxa * durMs) / 1000;
    const int fade = qMin(amostras / 4, taxa / 100);

    QByteArray buffer;
    buffer.resize(amostras * 2);
    qint16 *dados = reinterpret_cast<qint16*>(buffer.data());

    const double vol = 0.25;
    const double pi = 2.0 * M_PI;
    for (int i = 0; i < amostras; i++) {
        double t = double(i) / taxa;
        double env = 1.0;
        if (i < fade)          env = double(i) / fade;
        else if (i > amostras - fade) env = double(amostras - i) / fade;
        dados[i] = qint16(qSin(2.0 * pi * freq * t) * env * vol * 32767.0);
    }

    m_audioDispositivo->write(buffer);
}

void FydMusic::tocarSequencia() {
    if (m_partitura.isEmpty()) return;
    if (m_estaTocando) parar();

    m_estaTocando = true;
    m_indiceAtual = 0;
    emit estaTocandoChanged();
    tocarProxima();
}

// Slot membro: seguro, sem lambda recursiva (corrige o segfault original)
void FydMusic::tocarProxima() {
    if (!m_estaTocando || m_indiceAtual >= m_partitura.size()) {
        m_estaTocando = false;
        m_indiceAtual = 0;
        emit estaTocandoChanged();
        emit sequenciaTerminada();
        return;
    }

    const NotaMusical &n = m_partitura.at(m_indiceAtual);
    emit notaTocada(m_indiceAtual);

    if (!n.ePausa)
        gerarEReproduzirSom(n.frequencia, n.duracaoMs);

    m_indiceAtual++;
    QTimer::singleShot(n.duracaoMs, this, &FydMusic::tocarProxima);
}

void FydMusic::parar() {
    m_estaTocando = false;
    if (m_audioSaida) m_audioSaida->stop();
    emit estaTocandoChanged();
}
