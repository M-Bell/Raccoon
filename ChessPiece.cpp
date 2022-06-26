#include "ChessPiece.h"
#include "ChessGame.h"

ChessPiece::ChessPiece(ChessPieceSide side, ChessGame &game,
                       QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), _currentGame(game), _side(side) {
  _isPlaced = true;
  firstMove = true;
}

ChessBoardTile *ChessPiece::getCurrentTile() { return _currentTile; }
void ChessPiece::setCurrentTile(ChessBoardTile *value) { _currentTile = value; }

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  // Deselect
  //  if (this == _currentGame.pieceToMove) {
  //    _currentGame.pieceToMove->currentTile->resetOriginalColor();
  //    _currentGame.pieceToMove->decolor();
  //    _currentGame.pieceToMove = NULL;
  //    return;
  //  }
  //  // if it is already consumed or not the respective color's turn
  //  if ((!getIsPlaced()) ||
  //      ((game->getTurn() != this->getSide()) && (!game->pieceToMove)))
  //    return;
  //  // selecting
  //  if (!game->pieceToMove) {

  //    game->pieceToMove = this;
  //    game->pieceToMove->getCurrentBox()->setColor(Qt::red);
  //    game->pieceToMove->moves();
  //  }
  //  // Consuming counterPart of the CHessBox
  //  else if (this->getSide() != game->pieceToMove->getSide()) {
  //    this->getCurrentBox()->mousePressEvent(event);
  //  }
}

bool ChessPiece::getIsPlaced() { return _isPlaced; }

void ChessPiece::setIsPlaced(bool value) { _isPlaced = value; }
QList<ChessBoardTile *> ChessPiece::moveLocation() { return {}; }
void ChessPiece::decolor() {
  //    for (size_t i = 0, n = location.size(); i < n; i++) {
  //      location[i]->resetOriginalColor();
  //    }
}

bool ChessPiece::tileSetting(ChessBoardTile *box) {
  //  if (box->getHasChessPiece()) {
  //    King *q = dynamic_cast<King *>(location.last()->currentPiece);
  //    if (q) {
  //      box->setColor(Qt::blue);
  //    } else
  //      box->setColor(Qt::red);
  //    return true;
  //  } else
  //    location.last()->setColor(Qt::darkRed);
  //  return false;
}
