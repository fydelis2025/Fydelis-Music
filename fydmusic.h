#ifndef FYDMUSIC_H
#define FYDMUSIC_H

#include <QObject>
#include <QVector>
#include <QAudioOutput>
#include <QIODevice>
#include <QTimer>
#include <QVariantList>
#include <QVariantMap>

struct NotaMusical {
    QString nome;
    int frequencia = 0;
    int duracaoMs = 500;
    int figura = 4;       // 1=semibreve 2=mínima 4=semínima 8=colcheia 16=semicolcheia
    bool temPonto = false;
    bool ePausa = false;
    bool temLigadura = false;
};

class FydMusic : public QObject {
    Q_OBJECT
    Q_PROPERTY(int andamento READ andamento WRITE setAndamento NOTIFY andamentoChanged)
    Q_PROPERTY(bool estaTocando READ estaTocando NOTIFY estaTocandoChanged)
    Q_PROPERTY(QString listaNotas READ listaNotas NOTIFY partituraChanged)
    Q_PROPERTY(QVariantList partitura READ partitura NOTIFY partituraChanged)

public:
    explicit FydMusic(QObject *parent = nullptr);

    Q_INVOKABLE void adicionarNota(const QString& nome, int figura, bool temPonto);
    Q_INVOKABLE void adicionarPausa(int figura);
    Q_INVOKABLE void aplicarLigadura();
    Q_INVOKABLE void removerUltima();
    Q_INVOKABLE void limparPartitura();
    Q_INVOKABLE void tocarSequencia();
    Q_INVOKABLE void parar();
    Q_INVOKABLE void tocarNotaAvulsa(const QString& nome);

    QString listaNotas() const;
    QVariantList partitura() const;

    int andamento() const;
    void setAndamento(int bpm);
    bool estaTocando() const;

signals:
    void andamentoChanged();
    void estaTocandoChanged();
    void partituraChanged();
    void notaTocada(int indice);
    void sequenciaTerminada();

private slots:
    void tocarProxima();

private:
    void gerarEReproduzirSom(int freq, int durMs);
    int frequenciaNota(const QString& nome) const;
    int calcularDuracao(int figura, bool temPonto) const;

    QVector<NotaMusical> m_partitura;
    int m_andamento;
    bool m_estaTocando;
    int m_indiceAtual;

    QAudioOutput *m_audioSaida = nullptr;
    QIODevice *m_audioDispositivo = nullptr;
};

#endif
