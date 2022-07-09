#include "ChessGame.h"
#include "ChessBoard.h"
#include "King.h"
#include <QDebug>
#include <QPixmap>

int ChessGame::SCENE_WIDTH = 900;
int ChessGame::SCENE_HEIGHT = SCENE_WIDTH * 0.6 + 25;

ChessGame::ChessGame() : QGraphicsScene(), _gameRunning(true) {
  // Making the Scene
  setSceneRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT);
  setParent(this);

  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(Qt::black);
  setBackgroundBrush(brush);
  pieceToMove = nullptr;

  // display turn
  _turnDisplay = new QGraphicsTextItem();
  _turnDisplay->setPos(width() / 2 - SCENE_HEIGHT * 0.1, 3);
  _turnDisplay->setZValue(1);
  _turnDisplay->setDefaultTextColor(Qt::white);
  _turnDisplay->setFont(QFont("", SCENE_HEIGHT * 0.02));
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
  drawDeadHolder(0, 0, {190,190,190});
  drawDeadHolder(SCENE_WIDTH - SCENE_WIDTH * 0.2, 0, {190,190,190});
  _chessBoard->drawBoard(SCENE_WIDTH * 0.2, SCENE_HEIGHT * 0.05);
}

void ChessGame::displayDeadWhite() {
  int SHIFT = SCENE_WIDTH * 0.065;
  int j = 0;
  int k = 0;
  for (size_t i = 0, n = _whiteDead.size(); i < n; i++) {
    if (j == 3) {
      k++;
      j = 0;
    }
    _whiteDead[i]->setPos(10 + SHIFT * j++, 45 + SHIFT * k);
  }
}

void ChessGame::displayDeadBlack() {
  int SHIFT = SCENE_WIDTH * 0.065;
  int j = 0;
  int k = 0;
  for (size_t i = 0, n = _blackDead.size(); i < n; i++) {
    if (j == 3) {
      k++;
      j = 0;
    }
    _blackDead[i]->setPos(SCENE_WIDTH * 0.8 + 10 + SHIFT * j++, 45 + SHIFT * k);
  }
}

void ChessGame::placeInDeadPlace(ChessPiece *piece) {
  if (piece->side() == WHITE) {
    _whiteDead.append(piece);
    King *g = dynamic_cast<King *>(piece);
    if (g) {
      _check->setPlainText("Black Won");
      gameOver();
    }
    displayDeadWhite();
  } else {
    _blackDead.append(piece);
    King *g = dynamic_cast<King *>(piece);
    if (g) {

      _check->setPlainText("White Won");
      gameOver();
    }
    displayDeadBlack();
  }
  _playablePieces.removeAll(piece);
}

void ChessGame::addToScene(QGraphicsItem *item) { addItem(item); }

void ChessGame::removeFromScene(QGraphicsItem *item) { removeItem(item); }

void ChessGame::changeTurn() {
  if (turn() == WHITE) {
    turn() = BLACK;
    _turnDisplay->setPlainText("Turn : BLACK");
  } else {
    turn() = WHITE;
    _turnDisplay->setPlainText("Turn : WHITE");
  }
}

void ChessGame::showMessage(char *msg) { _turnDisplay->setPlainText(msg); }

void ChessGame::start() {
  for (size_t i = 0, n = _listG.size(); i < n; i++)
    removeFromScene(_listG[i]);

  addToScene(_turnDisplay);
  QGraphicsTextItem *whitePiece = new QGraphicsTextItem();
  whitePiece->setPos(SCENE_WIDTH * 0.1 - SCENE_WIDTH * 0.085,
                     SCENE_HEIGHT * 0.02);
  whitePiece->setZValue(1);
  whitePiece->setDefaultTextColor(Qt::white);
  whitePiece->setFont(QFont("", 14));
  whitePiece->setPlainText("WHITE PIECE");
  addToScene(whitePiece);
  QGraphicsTextItem *blackPiece = new QGraphicsTextItem();

  blackPiece->setPos(SCENE_WIDTH * 0.9 - SCENE_WIDTH * 0.085, 10);
  blackPiece->setZValue(1);
  blackPiece->setDefaultTextColor(Qt::black);
  blackPiece->setFont(QFont("", 14));
  blackPiece->setPlainText("BLACK PIECE");
  addToScene(blackPiece);
  addToScene(_check);
  _chessBoard->placePieces();
}

void ChessGame::drawDeadHolder(int x, int y, QColor color) {
  _deadHolder = new QGraphicsRectItem(x, y, SCENE_WIDTH * 0.2, SCENE_HEIGHT);
  QBrush brush;
  brush.setStyle(Qt::SolidPattern);
  brush.setColor(color);
  _deadHolder->setBrush(brush);
  addToScene(_deadHolder);
}

void ChessGame::displayMainMenu() {
  drawChessBoard();
  start();
}

void ChessGame::gameOver() {
  removeAll();
  turn() = WHITE;
  _playablePieces.clear();
  _chessBoard->reset();
}

void ChessGame::removeAll() {
  QList<QGraphicsItem *> itemsList = items();
  for (size_t i = 0, n = itemsList.size(); i < n; i++) {
    if (itemsList[i] != _check)
      removeFromScene(itemsList[i]);
  }
}
