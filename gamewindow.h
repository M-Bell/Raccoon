#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "ChessGame.h"
#include "mainwindow.h"
#include "piece.h"
#include <QDialog>

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog {
  Q_OBJECT

public:
  Piece whitePieces[16];
  Piece blackPieces[16];
  QLabel *cells[8][8];
  int BOARD_SIZE;
  int BOARD_X;
  int BOARD_Y;
  int CELL_SIZE;
  int FONT_SIZE;
  explicit GameWindow(const bool hasBot, QString *fen = nullptr,
                      QWidget *parent = nullptr, int btnType=0);
  ~GameWindow();

  void draw();

private slots:
  void on_backToMenuBtn_clicked();

  void on_next_pos_clicked();

  void on_prev_pos_clicked();

private:
  Ui::GameWindow *ui;
  QWidget *parent;
  QList<QString> *_fen;
  ChessGame *_game;
  bool _hasBot;
};

#endif // GAMEWINDOW_H
