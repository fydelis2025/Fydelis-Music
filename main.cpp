#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFile>
#include "fydmusic.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    qmlRegisterType<FydMusic>("FydelisMusic", 1, 0, "FydMusic");

    QQmlApplicationEngine engine;

    QString caminho = QCoreApplication::applicationDirPath() + "/../qml/Main.qml";
    if (!QFile::exists(caminho))
        caminho = QCoreApplication::applicationDirPath() + "/qml/Main.qml";
    if (!QFile::exists(caminho))
        caminho = QCoreApplication::applicationDirPath() + "/Main.qml";

    engine.load(QUrl::fromLocalFile(caminho));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
