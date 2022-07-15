#include "openingschoosewindow.h"
#include "gameinfodialog.h"
#include "gamewindow.h"
#include "ui_openingschoosewindow.h"

OpeningsChooseWindow::OpeningsChooseWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::OpeningsChooseWindow) {
  this->parent = parent;
  ui->setupUi(this);

  int WINDOW_W = 854;
  int WINDOW_H = 480;
  int BUTTON_W = 180 * 1.1;
  int BUTTON_H = 60 * 1.1;

  this->resize(WINDOW_W, WINDOW_H);

  QPushButton *backToMenuBtn = ui -> backBtn;

  QPixmap backToMenuBtnPixmap(":/res/images/backBtn.png");
  QIcon backToMenuBtnIcon(backToMenuBtnPixmap);
  backToMenuBtn->setIcon(backToMenuBtnIcon);
  backToMenuBtn->resize(BUTTON_W, BUTTON_H);
  backToMenuBtn->setIconSize(QSize(BUTTON_W, BUTTON_H));
  backToMenuBtn->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
  connect(backToMenuBtn, SIGNAL(clicked()), this,
          SLOT(on_backToMenuBtn_clicked()));
  backToMenuBtn->show();
}

OpeningsChooseWindow::~OpeningsChooseWindow() { delete ui; }

void OpeningsChooseWindow::on_pirc_def_button_clicked() {
  GameInfoDialog info(":/res/text/pirc_def.txt", this);
  info.exec();
  GameWindow win(true, new QString(":/res/text/pirc_def_fen.txt"),
                 (QWidget *)QDialog::parent(), 1);
  win.exec();
}

void OpeningsChooseWindow::on_caro_kann_button_clicked() {
  GameInfoDialog info(":/res/text/caro_kann_def.txt", this);
  info.exec();
  GameWindow win(true, new QString(":/res/text/caro_kann_def_fen.txt"),
                 (QWidget *)QDialog::parent(), 1);
  win.exec();
}

void OpeningsChooseWindow::on_italian_game_button_clicked() {
  GameInfoDialog info(":/res/text/italian_game.txt", this);
  info.exec();
  GameWindow win(true, new QString(":/res/text/italian_game_fen.txt"),
                 (QWidget *)QDialog::parent(), 1);
  win.exec();
}

void OpeningsChooseWindow::on_backToMenuBtn_clicked() {
  parent->show();
  hide();
}

