#include "endgameschoosewindow.h"
#include "gameinfodialog.h"
#include "gamewindow.h"
#include "ui_endgameschoosewindow.h"

EndgamesChooseWindow::EndgamesChooseWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::EndgamesChooseWindow) {
  ui->setupUi(this);
}

EndgamesChooseWindow::~EndgamesChooseWindow() { delete ui; }

void EndgamesChooseWindow::on_queen_king_endgame_clicked() {
  GameInfoDialog info(":/res/text/queen_king.txt", this);
  info.exec();
  GameWindow win(true, new QString(":/res/text/queen_king_fen.txt"),
                 (QWidget *)QDialog::parent(), 1);
  win.exec();
}

void EndgamesChooseWindow::on_pushButton_clicked() {
  GameInfoDialog info(":/res/text/two_rooks_king.txt", this);
  info.exec();
  GameWindow win(true, new QString(":/res/text/two_rooks_king_fen.txt"),
                 (QWidget *)QDialog::parent(), 1);
  win.exec();
}

void EndgamesChooseWindow::on_rook_king_endgame_clicked() {
  GameInfoDialog info(":/res/text/rook_king.txt", this);
  info.exec();
  GameWindow win(true, new QString(":/res/text/rook_king_fen.txt"),
                 (QWidget *)QDialog::parent(), 1);
  win.exec();
}
