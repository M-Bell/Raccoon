#include "endgameschoosewindow.h"
#include "gameinfodialog.h"
#include "gamewindow.h"
#include "ui_endgameschoosewindow.h"

EndgamesChooseWindow::EndgamesChooseWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::EndgamesChooseWindow) {
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

void EndgamesChooseWindow::on_backToMenuBtn_clicked() {
  parent->show();
  hide();
}

