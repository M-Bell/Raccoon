#include "ChessBoardTile.h"
#include "ChessGame.h"

extern ChessGame *_game;
ChessBoardTile::ChessBoardTile(QGraphicsItem *parent)
    : QGraphicsRectItem(parent) {
  // making the Square CHess Box
  setRect(0, 0, 100, 100);
  _brush.setStyle(Qt::SolidPattern);
  setZValue(-1);
  _currentPiece = nullptr;
}

ChessBoardTile::~ChessBoardTile() { }

void ChessBoardTile::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  //  //  qDebug() << getChessPieceColor();
  //  // Deselecting counter part of ChessPiece
  //  if (_currentPiece == _game->pieceToMove && _currentPiece) {

  //    _currentPiece->mousePressEvent(event);
  //    return;
  //  }

  //  // if selected
  //  if (_game->pieceToMove) {
  //    // if same team
  //    if (this->_currentPiece-> == _game->pieceToMove->getSide())
  //      return;
  //    // removing the eaten piece
  //    QList<ChessBoardTile *> movLoc = game->pieceToMove->moveLocation();
  //    // TO make sure the selected box is in move zone
  //    int check = 0;
  //    for (size_t i = 0, n = movLoc.size(); i < n; i++) {
  //      if (movLoc[i] == this) {
  //        check++;
  //      }
  //    }
  //    // if not prsent return
  //    if (check == 0)
  //      return;
  //    // change the color back to normal
  //    game->pieceToMove->decolor();
  //    // make the first move false applicable for pawn only
  //    game->pieceToMove->firstMove = false;
  //    // this is to eat or consume the enemy present inn the movable region
  //    if (this->getHasChessPiece()) {
  //      this->currentPiece->setIsPlaced(false);
  //      this->currentPiece->setCurrentBox(NULL);
  //      game->placeInDeadPlace(this->currentPiece);
  //    }
  //    // changing the new stat and resetting the previous left region
  //    game->pieceToMove->getCurrentBox()->setHasChessPiece(false);
  //    game->pieceToMove->getCurrentBox()->currentPiece = NULL;
  //    game->pieceToMove->getCurrentBox()->resetOriginalColor();
  //    placePiece(game->pieceToMove);

  //    game->pieceToMove = NULL;
  //    // changing turn
  //    game->changeTurn();
  //    checkForCheck();
  //  }
  //  // Selecting couterpart of the chessPiece
  //  else if (this->getHasChessPiece()) {
  //    this->currentPiece->mousePressEvent(event);
  //  }
}

void ChessBoardTile::setColor(QColor color) {
  _brush.setColor(color);
  setBrush(color);
}

void ChessBoardTile::placePiece(ChessPiece *piece) {

  piece->setPos(x() + 50 - piece->pixmap().width() / 2,
                y() + 50 - piece->pixmap().width() / 2);
  piece->setCurrentTile(this);
  сhessPieceColor() = piece->side();
  _currentPiece = piece;
}

// void ChessBoardTile::resetOriginalColor() { setColor(originalColor); }

// void ChessBoardTile::setOriginalColor(QColor value) {
//   originalColor = value;
//   setColor(originalColor);
// }

// bool ChessBoardTile::getHasChessPiece() { return hasChessPiece; }

// void ChessBoardTile::setHasChessPiece(bool value, ChessPiece *piece) {
//   hasChessPiece = value;
//   if (value)
//     setChessPieceColor(piece->getSide());
//   else
//     setChessPieceColor("NONE");
// }

void ChessBoardTile::checkForCheck() {
  //  int c = 0;
  //  QList<ChessPiece *> pList = game->alivePiece;
  //  for (size_t i = 0, n = pList.size(); i < n; i++) {

  //    King *p = dynamic_cast<King *>(pList[i]);
  //    if (p) {
  //      continue;
  //    }
  //    pList[i]->moves();
  //    pList[i]->decolor();
  //    QList<ChessBoardTile *> bList = pList[i]->moveLocation();
  //    for (size_t j = 0, n = bList.size(); j < n; j++) {
  //      King *p = dynamic_cast<King *>(bList[j]->currentPiece);
  //      if (p) {
  //        if (p->getSide() == pList[i]->getSide())
  //          continue;
  //        bList[j]->setColor(Qt::blue);
  //        pList[i]->getCurrentBox()->setColor(Qt::darkRed);
  //        if (!game->check->isVisible())
  //          game->check->setVisible(true);
  //        else {
  //          bList[j]->resetOriginalColor();
  //          pList[i]->getCurrentBox()->resetOriginalColor();
  //          game->gameOver();
  //        }
  //        c++;
  //      }
  //    }
  //  }
  //  if (!c) {
  //    game->check->setVisible(false);
  //    for (size_t i = 0, n = pList.size(); i < n; i++)
  //      pList[i]->getCurrentBox()->resetOriginalColor();
  //  }
}

// QString ChessBoardTile::getChessPieceColor() { return chessPieceColor; }

// void ChessBoardTile::setChessPieceColor(QString value) {
//   chessPieceColor = value;
// }
