QT += quick multimedia
CONFIG += c++11

SOURCES += \
    main.cpp \
    fydmusic.cpp

HEADERS += \
    fydmusic.h

RESOURCES += qml.qrc

# Pasta de saída
DESTDIR = $$OUT_PWD/bin
