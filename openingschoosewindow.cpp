#include "openingschoosewindow.h"
#include "gameinfodialog.h"
#include "gamewindow.h"
#include "ui_openingschoosewindow.h"
OpeningsChooseWindow::OpeningsChooseWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::OpeningsChooseWindow) {
  ui->setupUi(this);
}

OpeningsChooseWindow::~OpeningsChooseWindow() { delete ui; }

void OpeningsChooseWindow::on_pirc_def_button_clicked() {
  GameInfoDialog info(":/res/text/pirc_def.txt", this);
  info.exec();
  GameWindow win(true, new QString(":/res/text/pirc_def_fen.txt"),
                 (QWidget *)QDialog::parent());
  win.exec();
}

void OpeningsChooseWindow::on_caro_kann_button_clicked() {
  GameInfoDialog info(":/res/text/caro_kann_def.txt", this);
  info.exec();
  GameWindow win(true, new QString(":/res/text/caro_kann_def_fen.txt"),
                 (QWidget *)QDialog::parent());
  win.exec();
}

void OpeningsChooseWindow::on_italian_game_button_clicked() {
  GameInfoDialog info(":/res/text/italian_game.txt", this);
  info.exec();
  GameWindow win(true, new QString(":/res/text/italian_game_fen.txt"),
                 (QWidget *)QDialog::parent());
  win.exec();
}
