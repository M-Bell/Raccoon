#include "gamewindow.h"
#include "ChessGame.h"
#include "ui_gamewindow.h"
#include <QFont>
#include <QPixmap>

#include <QPushButton>
#include <iostream>

GameWindow::GameWindow(const bool hasBot, QString *fen, QWidget *parent)
    : QDialog(parent), ui(new Ui::GameWindow), _fen(fen), _hasBot(hasBot) {
  this->parent = parent;
  ui->setupUi(this);

  this->resize(parent->width(), parent->height());

  BOARD_SIZE = 520;
  BOARD_X = (parent->width() - BOARD_SIZE) / 2;
  BOARD_Y = (parent->height() - BOARD_SIZE) / 8;
  CELL_SIZE = BOARD_SIZE / 8;
  FONT_SIZE = BOARD_SIZE / 8;
  int BUTTON_W = 180 * 1.1;
  int BUTTON_H = 60 * 1.1;

  //    this->setStyleSheet("background-color:rgba(76, 175, 80, 0.0);");

  QPixmap backToMenuBtnPixmap(":/res/images/backToMenuBtn.png");
  QIcon backToMenuBtnIcon(backToMenuBtnPixmap);

  QPushButton *backToMenuBtn = new QPushButton(backToMenuBtnIcon, "", this);
  backToMenuBtn->setObjectName("backToMenuBtn");
  backToMenuBtn->resize(BUTTON_W, BUTTON_H);
  backToMenuBtn->move((parent->width() - BUTTON_W) / 2,
                      parent->height() - BUTTON_H * 1.8);
  backToMenuBtn->setIconSize(QSize(BUTTON_W, BUTTON_H));
  backToMenuBtn->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
  connect(backToMenuBtn, SIGNAL(clicked()), this,
          SLOT(on_backToMenuBtn_clicked()));
  backToMenuBtn->show();

  ChessGame *game = new ChessGame(_hasBot, _fen);
  game->displayMainMenu();
  ui->chessboard->setFixedSize(game->width(), game->height());
  ui->chessboard->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->chessboard->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->chessboard->setScene(game);
}

GameWindow::~GameWindow() { delete ui; }

void GameWindow::on_backToMenuBtn_clicked() {
  parent->show();
  hide();
}

void GameWindow::draw() {

  for (int i = 0; i < 16; i++) {
    Piece piece = whitePieces[i];
    QLabel *label = cells[piece.x][7 - piece.y];
    label->setText(piece.pieceImg.c_str());

    piece.setLabel(label);
  }

  for (int i = 0; i < 16; i++) {
    Piece piece = blackPieces[i];

    QLabel *label = cells[piece.x][7 - piece.y];
    label->setText(piece.pieceImg.c_str());

    piece.setLabel(label);
  }
}
