#include "ChessBoardTile.h"
#include "ChessGame.h"

ChessBoardTile::ChessBoardTile(ChessGame &game, QGraphicsItem *parent)
    : QGraphicsRectItem(parent), _currentGame(game) {
  // making the Square CHess Box
  setRect(0, 0, 100, 100);
  _brush.setStyle(Qt::SolidPattern);
  setZValue(-1);
  _currentPiece = nullptr;
}

ChessBoardTile::~ChessBoardTile() {}

void ChessBoardTile::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  //  qDebug() << getChessPieceColor();
  // Deselecting counter part of ChessPiece
  if (_currentPiece == _currentGame.pieceToMove && _currentPiece) {

    _currentPiece->mousePressEvent(event);
    return;
  }

  // if selected
  if (_currentGame.pieceToMove) {
    // if same team
    if (this->сhessPieceColor() == _currentGame.pieceToMove->side())
      return;
    // removing the eaten piece
    QList<ChessBoardTile *> movLoc = _currentGame.pieceToMove->moveLocation();
    // TO make sure the selected box is in move zone
    int check = 0;
    for (size_t i = 0, n = movLoc.size(); i < n; i++) {
      if (movLoc[i] == this) {
        check++;
      }
    }
    // if not prsent return
    if (check == 0)
      return;
    // change the color back to normal
    _currentGame.pieceToMove->decolor();
    // make the first move false applicable for pawn only
    _currentGame.pieceToMove->firstMove = false;
    // this is to eat or consume the enemy present inn the movable region
    if (this->hasChessPiece()) {
      this->_currentPiece->setIsPlaced(false);
      this->_currentPiece->setCurrentTile(nullptr);
      _currentGame.placeInDeadPlace(this->_currentPiece);
    }
    // changing the new stat and resetting the previous left region

    _currentGame.pieceToMove->getCurrentTile()->_currentPiece = nullptr;
    _currentGame.pieceToMove->getCurrentTile()->setColor(
        _currentGame.pieceToMove->getCurrentTile()->getColor());
    placePiece(_currentGame.pieceToMove);

    _currentGame.pieceToMove = nullptr;
    // changing turn
    _currentGame.changeTurn();
    checkForCheck();
  }
  // Selecting couterpart of the chessPiece
  else if (this->hasChessPiece()) {
    this->_currentPiece->mousePressEvent(event);
  }
}

void ChessBoardTile::setColor(QColor color) {
  _brush.setColor(color);
  setBrush(color);
}

QColor &ChessBoardTile::getColor() { return _color; }

void ChessBoardTile::placePiece(ChessPiece *piece) {

  piece->setPos(x() + 50 - piece->pixmap().width() / 2,
                y() + 50 - piece->pixmap().width() / 2);
  piece->setCurrentTile(this);
  _currentPiece = piece;
}

void ChessBoardTile::checkForCheck() {
  int c = 0;
  QList<ChessPiece *> pList = _currentGame._playablePieces;
  for (size_t i = 0, n = pList.size(); i < n; i++) {

    //    King *p = dynamic_cast<King *>(pList[i]);
    //    if (p) {
    //      continue;
    //    }
    pList[i]->moves();
    pList[i]->decolor();
    QList<ChessBoardTile *> bList = pList[i]->moveLocation();
    //    for (size_t j = 0, n = bList.size(); j < n; j++) {
    //            King *p = dynamic_cast<King *>(bList[j]->_currentPiece);
    //            if (p) {
    //              if (p->getSide() == pList[i]->side())
    //                continue;
    //            bList[j]->setColor(Qt::blue);
    //            pList[i]->getCurrentTile()->setColor(Qt::darkRed);
    //            if (!_currentGame._check->isVisible())
    //              _currentGame._check->setVisible(true);
    //            else {
    //              bList[j]->setColor(bList[j]->getColor());
    //              pList[i]->getCurrentTile()->setColor(
    //                  pList[i]->getCurrentTile()->getColor());
    //              _currentGame.gameOver();
    //            }
    //            c++;
    //          }
    //    }
  }
  if (!c) {
    _currentGame._check->setVisible(false);
    for (size_t i = 0, n = pList.size(); i < n; i++)
      pList[i]->getCurrentTile()->setColor(pList[i]->getCurrentTile()->getColor());
  }
}
