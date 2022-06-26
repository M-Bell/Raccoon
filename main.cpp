#include "mainwindow.h"
#include <ChessGame.h>
#include <ChessPieceType.h>
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  ChessGame *game = new ChessGame();
  game->show();
  game->displayMainMenu();
  return a.exec();
}
