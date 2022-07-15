#include "gamewindow.h"
#include "ChessGame.h"
#include "ui_gamewindow.h"
#include <QFile>
#include <QFont>
#include <QPixmap>
#include <QPushButton>
#include <iostream>

GameWindow::GameWindow(const bool hasBot, QString *fen, QWidget *parent, int btnType)
    : QDialog(parent), ui(new Ui::GameWindow), _fen(new QList<QString>()),
      _hasBot(hasBot) {
  ui->setupUi(this);

  // style prev and next btns
  int BUTTON_W = 180 * 1.1;
  int BUTTON_H = 60 * 1.1;

  QPixmap prevBtnPixmap(":/res/images/prevBtn.png");
  QIcon prevBtnIcon(prevBtnPixmap);

  QPushButton *prevBtn = ui -> prev_pos;
  prevBtn->setIcon(prevBtnIcon);
  prevBtn->setObjectName("prevBtn");
  prevBtn->resize(BUTTON_W, BUTTON_H);
  prevBtn->setIconSize(QSize(BUTTON_W, BUTTON_H));
  prevBtn->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
  connect(prevBtn, SIGNAL(clicked()), this,
          SLOT(on_prevBtn_clicked()));
  prevBtn->show();



  QPixmap nextBtnPixmap(":/res/images/nextBtn.png");
  QIcon nextBtnIcon(nextBtnPixmap);

  QPushButton *nextBtn = ui -> next_pos;
  nextBtn->setIcon(nextBtnIcon);
  nextBtn->setObjectName("nextBtn");
  nextBtn->resize(BUTTON_W, BUTTON_H);
  nextBtn->setIconSize(QSize(BUTTON_W, BUTTON_H));
  nextBtn->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
  connect(nextBtn, SIGNAL(clicked()), this,
          SLOT(on_nextBtn_clicked()));
  nextBtn->show();


  if (fen) {
    QFile file(*fen);
    if (!file.open(QIODevice::ReadOnly)) {
      qDebug() << "error: " << file.errorString();
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
      _fen->append(in.readLine());
    }
    file.close();
    if (_fen->length() < 2) {
      ui->next_pos->setVisible(false);
      ui->prev_pos->setVisible(false);
    }
  } else {
    ui->next_pos->setVisible(false);
    ui->prev_pos->setVisible(false);
  }

  this->parent = parent;

  this->resize(parent->width(), parent->height());

  BOARD_SIZE = 520;
  BOARD_X = (parent->width() - BOARD_SIZE) / 2;
  BOARD_Y = (parent->height() - BOARD_SIZE) / 8;
  CELL_SIZE = BOARD_SIZE / 8;
  FONT_SIZE = BOARD_SIZE / 8;

  QPixmap backToMenuBtnPixmap;
  if (btnType==0)
    backToMenuBtnPixmap = QPixmap(":/res/images/backToMenuBtn.png");
  else
    backToMenuBtnPixmap = QPixmap(":/res/images/backBtn.png");

  QIcon backToMenuBtnIcon(backToMenuBtnPixmap);

  QPushButton *backToMenuBtn = new QPushButton(backToMenuBtnIcon, "", this);
  backToMenuBtn->setObjectName("backToMenuBtn");
  backToMenuBtn->resize(BUTTON_W, BUTTON_H);
  backToMenuBtn->move((parent->width() - BUTTON_W) / 2+10,
                      parent->height() - BUTTON_H * 1.8);
  backToMenuBtn->setIconSize(QSize(BUTTON_W, BUTTON_H));
  backToMenuBtn->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
  connect(backToMenuBtn, SIGNAL(clicked()), this,
          SLOT(on_backToMenuBtn_clicked()));
  backToMenuBtn->show();
  _game = new ChessGame(_hasBot, _fen);
  _game->displayMainMenu();
  ui->chessboard->setFixedSize(_game->width(), _game->height());
  ui->chessboard->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->chessboard->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->chessboard->setScene(_game);
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

void GameWindow::on_nextBtn_clicked() { _game->nextPos(); }

void GameWindow::on_prevBtn_clicked() { _game->prevPos(); }
