#include "King.h"
#include "ChessGame.h"
#include "Pawn.h"
#include <QDebug>

King::King(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent)
    : ChessPiece(side, game, parent) {
  setImage();
}

void King::setImage() {
  if (_side == WHITE)
    setPixmap(QPixmap(":/res/images/chess_piece_king_white.png"));
  else
    setPixmap(QPixmap(":/res/images/chess_piece_king.png"));
}
void King::findUnSafeLocation() {
  QList<ChessPiece *> pList = _currentGame._playablePieces;
  for (qsizetype i = 0; i < pList.size(); i++) {

    if (pList[i]->side() != this->side()) {
      QList<ChessBoardTile *> bList = pList[i]->moveLocation();

      for (qsizetype j = 0; j < bList.size(); j++) {
        Pawn *c = dynamic_cast<Pawn *>(pList[i]);
        if (c)
          continue;
        for (size_t k = 0, n = _location.size(); k < n; k++) {
          if (bList[j] == _location[k]) {
            _location[k]->setColor(Qt::blue);
          }
        }
      }
    }
  }
}
void King::moves() {
  _location.clear();
  int row = this->getCurrentTile()->row();
  int col = this->getCurrentTile()->col();
  ChessPieceSide team = this->side();

  if (col > 0 && row > 0 &&
      !(_currentGame._allTiles[row - 1][col - 1]->chessPieceColor() ==
        team)) { // up left
    _location.append(_currentGame._allTiles[row - 1][col - 1]);
    _currentGame._allTiles[row - 1][col - 1]->setColor(Qt::darkRed);
    if (_location.last()->hasChessPiece()) {
      _location.last()->setColor(Qt::red);
    }
  }
  if (col < 7 && row > 0 &&
      !(_currentGame._allTiles[row - 1][col + 1]->chessPieceColor() ==
        team)) { // up right
    _location.append(_currentGame._allTiles[row - 1][col + 1]);
    _currentGame._allTiles[row - 1][col + 1]->setColor(Qt::darkRed);
    if (_location.last()->hasChessPiece()) {
      _location.last()->setColor(Qt::red);
    }
  }
  if (row > 0 && !(_currentGame._allTiles[row - 1][col]->chessPieceColor() ==
                   team)) { // up
    _location.append(_currentGame._allTiles[row - 1][col]);
    _currentGame._allTiles[row - 1][col]->setColor(Qt::darkRed);
    if (_location.last()->hasChessPiece()) {
      _location.last()->setColor(Qt::red);
    }
  }
  if (row < 7 && !(_currentGame._allTiles[row + 1][col]->chessPieceColor() ==
                   team)) { // down
    _location.append(_currentGame._allTiles[row + 1][col]);
    _currentGame._allTiles[row + 1][col]->setColor(Qt::darkRed);
    if (_location.last()->hasChessPiece()) {
      _location.last()->setColor(Qt::red);
    }
  }
  if (col > 0 && !(_currentGame._allTiles[row][col - 1]->chessPieceColor() ==
                   team)) { // left
    _location.append(_currentGame._allTiles[row][col - 1]);
    _currentGame._allTiles[row][col - 1]->setColor(Qt::darkRed);
    if (_location.last()->hasChessPiece()) {
      _location.last()->setColor(Qt::red);
    }
  }
  if (col < 7 && !(_currentGame._allTiles[row][col + 1]->chessPieceColor() ==
                   team)) { // right
    _location.append(_currentGame._allTiles[row][col + 1]);
    _currentGame._allTiles[row][col + 1]->setColor(Qt::darkRed);
    if (_location.last()->hasChessPiece()) {
      _location.last()->setColor(Qt::red);
    }
  }
  if (col > 0 && row < 7 &&
      !(_currentGame._allTiles[row + 1][col - 1]->chessPieceColor() ==
        team)) { // down left
    _location.append(_currentGame._allTiles[row + 1][col - 1]);
    _currentGame._allTiles[row + 1][col - 1]->setColor(Qt::darkRed);
    if (_location.last()->hasChessPiece()) {
      _location.last()->setColor(Qt::red);
    }
  }
  if (col < 7 && row < 7 &&
      !(_currentGame._allTiles[row + 1][col + 1]->chessPieceColor() ==
        team)) { // down right
    _location.append(_currentGame._allTiles[row + 1][col + 1]);
    _currentGame._allTiles[row + 1][col + 1]->setColor(Qt::darkRed);
    if (_location.last()->hasChessPiece()) {
      _location.last()->setColor(Qt::red);
    }
  }

  findUnSafeLocation();
}
