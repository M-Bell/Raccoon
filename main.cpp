#include "mainwindow.h"
#include <ChessGame.h>
#include <ChessPieceType.h>
#include <QApplication>
#include <iostream>
ChessGame *game;
int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  game = new ChessGame();
  game->show();
  game->displayMainMenu();
  return a.exec();
}
