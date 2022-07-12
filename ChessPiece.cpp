#include "ChessPiece.h"
#include "ChessGame.h"
#include "King.h"
#include "Pawn.h"

ChessPiece::ChessPiece(ChessPieceSide side, ChessGame &game,
                       QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), _currentGame(game), _side(side) {
  _isPlaced = true;
}

ChessBoardTile *ChessPiece::getCurrentTile() { return _currentTile; }
void ChessPiece::setCurrentTile(ChessBoardTile *value) { _currentTile = value; }

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  if (!_currentGame.gameRunning())
    return;
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
    _currentGame.pieceToMove->moves();
    _currentGame.pieceToMove->_currentTile->setColor(Qt::red);

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
  _kingFound = false;
}

bool ChessPiece::kingIsSafe(ChessBoardTile *tile) {
  if (_currentGame.pieceToMove != this) {
    _location.append(tile);
    return false;
  }

  ChessPiece *beatenPiece = tile->currentPiece();
  QList<ChessPiece *> pList = _currentGame._playablePieces;
  for (qsizetype i = 0; i < pList.size(); i++) {
    if (pList[i] != beatenPiece && pList[i] != this &&
        pList[i]->side() != this->side()) {
      this->getCurrentTile()->connectToPiece(nullptr);
      tile->connectToPiece(this);
      pList[i]->moves();
      if (pList[i]->_kingFound) {
        pList[i]->decolor();
        this->getCurrentTile()->connectToPiece(this);
        tile->connectToPiece(beatenPiece);
        pList[i]->moves();
        pList[i]->decolor();
        return false;
      }
      pList[i]->decolor();
      this->getCurrentTile()->connectToPiece(this);
      tile->connectToPiece(beatenPiece);
      pList[i]->moves();
      pList[i]->decolor();
    }
  }
  _location.append(tile);
  return true;
}

bool ChessPiece::tileSetting(ChessBoardTile *tile) {
  if (tile->hasChessPiece()) {
    King *q = dynamic_cast<King *>(tile->currentPiece());
    if (q) {
      tile->setColor(Qt::blue);
      _kingFound = true;
      return false;
    } else if (_currentGame._enPassantTile == tile &&
               typeid(*this) != typeid(Pawn(NONE, _currentGame))) {
      tile->setColor(Qt::darkRed);
      return false;
    } else if (!_kingFound) {
      tile->setColor(Qt::red);
    }
    return true;
  } else if (!_kingFound)
    tile->setColor(Qt::darkRed);
  return false;
}
