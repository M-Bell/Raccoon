
QT       += core gui

win32:RC_ICONS += images/logo.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bishop.cpp \
    ChessBoard.cpp \
    ChessBoardTile.cpp \
    ChessGame.cpp \
    ChessPiece.cpp \
    King.cpp \
    Knight.cpp \
    Pawn.cpp \
    Queen.cpp \
    Rook.cpp \
    gamewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    piece.cpp \
    tutorialwindow.cpp

HEADERS += \
    Bishop.h \
    ChessBoard.h \
    ChessBoardTile.h \
    ChessGame.h \
    ChessPiece.h \
    ChessPieceSide.h \
    ChessPieceType.h \
    King.h \
    Knight.h \
    Pawn.h \
    Queen.h \
    Rook.h \
    СhessBoard.h \
    gamewindow.h \
    mainwindow.h \
    piece.h \
    tutorialwindow.h

FORMS += \
    mainwindow.ui \
    gamewindow.ui \
    tutorialwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourses.qrc
