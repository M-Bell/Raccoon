#include "ChessPiece.h"
#include "ChessGame.h"
#include "King.h"

ChessPiece::ChessPiece(ChessPieceSide side, ChessGame &game,
                       QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), _currentGame(game), _side(side) {
  _isPlaced = true;
  firstMove = true;
}

ChessBoardTile *ChessPiece::getCurrentTile() { return _currentTile; }
void ChessPiece::setCurrentTile(ChessBoardTile *value) { _currentTile = value; }

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  if (this == _currentGame.pieceToMove) {
    _currentGame.pieceToMove->_currentTile->setColor(_currentTile->getColor());
    _currentGame.pieceToMove->decolor();
    _currentGame.pieceToMove = nullptr;
    return;
  }
  // if it is already consumed or not the respective color's turn
  if ((!getIsPlaced()) ||
      ((_currentGame.turn() != this->side()) && (!_currentGame.pieceToMove)))
    return;
  // selecting
  if (!_currentGame.pieceToMove) {
    _currentGame.pieceToMove = this;
    _currentGame.pieceToMove->_currentTile->setColor(Qt::red);
    _currentGame.pieceToMove->moves();
  }
  // Consuming counterPart of the CHessBox
  else if (this->side() != _currentGame.pieceToMove->side()) {
    this->_currentTile->mousePressEvent(event);
  }
}

bool ChessPiece::getIsPlaced() { return _isPlaced; }

void ChessPiece::setIsPlaced(bool value) { _isPlaced = value; }
QList<ChessBoardTile *> ChessPiece::moveLocation() { return _location; }
void ChessPiece::decolor() {
  for (qsizetype i = 0; i < _location.size(); i++) {
    _location[i]->setColor(_location[i]->getColor());
  }
}

bool ChessPiece::tileSetting(ChessBoardTile *tile) {
  if (tile->hasChessPiece()) {
    King *q = dynamic_cast<King *>(_location.last()->currentPiece());
    if (q) {
      tile->setColor(Qt::blue);
    } else
      tile->setColor(Qt::red);
    return true;
  } else
    _location.last()->setColor(Qt::darkRed);
  return false;
}
