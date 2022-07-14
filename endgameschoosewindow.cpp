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
  GameWindow win(true, new QString("8/8/4k3/2Q5/8/4K3/8/8 w - - 74 1"),
                 (QWidget *)QDialog::parent());
  win.exec();
}

void EndgamesChooseWindow::on_pushButton_clicked() {
  GameInfoDialog info(":/res/text/two_rooks_king.txt", this);
  info.exec();
  GameWindow win(true, new QString("6k1/8/8/8/8/8/7R/5K1R w - - 0 1"),
                 (QWidget *)QDialog::parent());
  win.exec();
}

void EndgamesChooseWindow::on_rook_king_endgame_clicked() {
  GameInfoDialog info(":/res/text/rook_king.txt", this);
  info.exec();
  GameWindow win(true, new QString("8/8/7k/8/8/4R3/5K2/8 w - - 60 1"),
                 (QWidget *)QDialog::parent());
  win.exec();
}
