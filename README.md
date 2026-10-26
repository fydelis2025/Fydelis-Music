# 🎵 Fydelis-Music

> Reprodutor de música multiplataforma desenvolvido com **C++**, **Qt 5/6** e **QML**. Projeto do ecossistema Fydelis.

---

## 📋 Sobre o Projeto

O **Fydelis-Music** é um reprodutor de áudio com interface moderna, construído para ser leve, expansível e compatível com Linux, Windows e macOS. Integra lógica em C++ com camada visual declarativa em QML, seguindo as boas práticas de desenvolvimento com Qt.

---

## 📂 Estrutura do Projeto
Fydelis-Music/
├── qml/ # Arquivos de interface QML
├── FydelisMusic.pro # Configuração do projeto (qmake)
├── main.cpp # Ponto de entrada da aplicação
├── fydmusic.h/cpp # Classe principal — lógica de negócio
├── qml.qrc # Recursos compilados no binário
├── fydelis-music.jpg # Arte/capa do projeto
├── Makefile # Script de build gerado
└── README.md # Este arquivo


---

## 🛠️ Tecnologias

| Camada | Tecnologia |
|---|---|
| **Lógica** | C++ 17+ |
| **Framework** | Qt 5 / Qt 6 (Qt Quick) |
| **Interface** | QML |
| **Build** | qmake / make |
| **Compatibilidade** | Linux, Windows, macOS |

---

## 🚀 Como Compilar e Executar

### Pré-requisitos
- Qt 5.15+ ou Qt 6
- Compilador C++ compatível (GCC, Clang ou MSVC)
- `qmake` e `make` disponíveis no PATH

### Passo a passo

```bash
# 1. Clonar o repositório
git clone https://github.com/fydelis2025/Fydelis-Music.git
cd Fydelis-Music

# 2. Gerar o Makefile
qmake FydelisMusic.pro

# 3. Compilar
make -j$(nproc)

# 4. Executar
./FydelisMusic   # Linux/macOS
# ou FydelisMusic.exe no Windows
