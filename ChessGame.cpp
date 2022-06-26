#include "ChessGame.h"
#include "ChessBoard.h"
#include <QDebug>
#include <QPixmap>
ChessGame::ChessGame(QWidget *parent) : QGraphicsView(parent) {

  // Making the Scene
  _gameScene = new QGraphicsScene();
  _gameScene->setSceneRect(0, 0, 1400, 900);

  // Making the view
  setFixedSize(1400, 900);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setScene(_gameScene);
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt::black);
  setBackgroundBrush(brush);
  pieceToMove = nullptr;

  // display turn
  _turnDisplay = new QGraphicsTextItem();
  _turnDisplay->setPos(width() / 2 - 100, 10);
  _turnDisplay->setZValue(1);
  _turnDisplay->setDefaultTextColor(Qt::white);
  _turnDisplay->setFont(QFont("", 18));
  _turnDisplay->setPlainText("Turn : WHITE");

  // display Check
  _check = new QGraphicsTextItem();
  _check->setPos(width() / 2 - 100, 860);
  _check->setZValue(4);
  _check->setDefaultTextColor(Qt::red);
  _check->setFont(QFont("", 18));
  _check->setPlainText("CHECK!");
  _check->setVisible(false);
  turn() = WHITE;
}

void ChessGame::drawChessBoard() {
  _chessBoard = new ChessBoard(*this);
  drawDeadHolder(0, 0, Qt::lightGray);
  drawDeadHolder(1100, 0, Qt::lightGray);
  _chessBoard->drawBoard(width() / 2 - 400, 50);
}

void ChessGame::displayDeadWhite() {
  int SHIFT = 50;
  int j = 0;
  int k = 0;
  for (size_t i = 0, n = _whiteDead.size(); i < n; i++) {
    if (j == 4) {
      k++;
      j = 0;
    }
    _whiteDead[i]->setPos(40 + SHIFT * j++, 100 + SHIFT * 2 * k);
  }
}

void ChessGame::displayDeadBlack() {
  int SHIFT = 50;
  int j = 0;
  int k = 0;
  for (size_t i = 0, n = _blackDead.size(); i < n; i++) {
    if (j == 4) {
      k++;
      j = 0;
    }
    _blackDead[i]->setPos(1140 + SHIFT * j++, 100 + SHIFT * 2 * k);
  }
}

void ChessGame::placeInDeadPlace(ChessPiece *piece) {
  if (piece->side() == WHITE) {
    _whiteDead.append(piece);
    //    King *g = dynamic_cast<King *>(piece);
    //    if (g) {

    //      _check->setPlainText("Black Won");
    //      gameOver();
    //    }
    displayDeadWhite();
  } else {
    _blackDead.append(piece);
    //    King *g = dynamic_cast<King *>(piece);
    //    if (g) {

    //      _check->setPlainText("White Won");
    //      gameOver();
    //    }
    displayDeadBlack();
  }
  _playablePieces.removeAll(piece);
}

void ChessGame::addToScene(QGraphicsItem *item) { _gameScene->addItem(item); }

void ChessGame::removeFromScene(QGraphicsItem *item) {
  _gameScene->removeItem(item);
}

void ChessGame::changeTurn() {
  if (turn() == WHITE) {
    turn() = BLACK;
    _turnDisplay->setPlainText("Turn : BLACK");
  } else {
    turn() = WHITE;
    _turnDisplay->setPlainText("Turn : BLACK");
  }
}

void ChessGame::start() {
  for (size_t i = 0, n = _listG.size(); i < n; i++)
    removeFromScene(_listG[i]);

  addToScene(_turnDisplay);
  QGraphicsTextItem *whitePiece = new QGraphicsTextItem();
  whitePiece->setPos(70, 10);
  whitePiece->setZValue(1);
  whitePiece->setDefaultTextColor(Qt::white);
  whitePiece->setFont(QFont("", 14));
  whitePiece->setPlainText("WHITE PIECE");
  addToScene(whitePiece);
  QGraphicsTextItem *blackPiece = new QGraphicsTextItem();

  blackPiece->setPos(1170, 10);
  blackPiece->setZValue(1);
  blackPiece->setDefaultTextColor(Qt::black);
  blackPiece->setFont(QFont("", 14));
  blackPiece->setPlainText("BLACK PIECE");
  addToScene(blackPiece);
  addToScene(_check);
  _chessBoard->placePieces();
}

void ChessGame::drawDeadHolder(int x, int y, QColor color) {
  _deadHolder = new QGraphicsRectItem(x, y, 300, 900);
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(color);
  _deadHolder->setBrush(brush);
  addToScene(_deadHolder);
}

void ChessGame::displayMainMenu() {
  //  QGraphicsPixmapItem *p = new QGraphicsPixmapItem();
  //  p->setPixmap(QPixmap(":/images/king1.png"));
  //  p->setPos(420, 170);
  //  addToScene(p);
  //  _listG.append(p);

  //  QGraphicsPixmapItem *p1 = new QGraphicsPixmapItem();
  //  p1->setPixmap(QPixmap(":/images/king.png"));
  //  p1->setPos(920, 170);
  //  addToScene(p1);
  //  _listG.append(p1);
  // Create the title
  //  QGraphicsTextItem *titleText = new QGraphicsTextItem("Chess Pro");
  //  QFont titleFont("arial", 50);
  //  titleText->setFont(titleFont);
  //  int xPos = width() / 2 - titleText->boundingRect().width() / 2;
  //  int yPos = 150;
  //  titleText->setPos(xPos, yPos);
  //  addToScene(titleText);
  //  _listG.append(titleText);
  // create Button
  //  Button *playButton = new Button("Play 2 v 2");
  //  int pxPos = width() / 2 - playButton->boundingRect().width() / 2;
  //  int pyPos = 300;
  //  playButton->setPos(pxPos, pyPos);
  //  connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
  //  addToScene(playButton);
  //  listG.append(playButton);

  // Create Quit Button
  //  Button *quitButton = new Button("Quit");
  //  int qxPos = width() / 2 - quitButton->boundingRect().width() / 2;
  //  int qyPos = 375;
  //  quitButton->setPos(qxPos, qyPos);
  //  connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
  //  addToScene(quitButton);
  drawChessBoard();
  //  listG.append(quitButton);
}

void ChessGame::gameOver() {
  // removeAll();
  turn() = WHITE;
  _playablePieces.clear();
  _chessBoard->reset();
}

void ChessGame::removeAll() {
  QList<QGraphicsItem *> itemsList = _gameScene->items();
  for (size_t i = 0, n = itemsList.size(); i < n; i++) {
    if (itemsList[i] != _check)
      removeFromScene(itemsList[i]);
  }
}
