#include "ChessBoardTile.h"
#include "ChessGame.h"
#include "King.h"
#include "Pawn.h"
#include "piecedialog.h"
#include <QRandomGenerator>

ChessBoardTile::ChessBoardTile(ChessGame &game, QGraphicsItem *parent)
    : QGraphicsRectItem(parent), _currentGame(game) {
  // making the Square CHess Box
  setRect(0, 0, _currentGame.width() * 0.078, _currentGame.width() * 0.078);
  _brush.setStyle(Qt::SolidPattern);
  setZValue(-1);
  _currentPiece = nullptr;
  setPen(Qt::NoPen);
}

ChessBoardTile::~ChessBoardTile() {}

void ChessBoardTile::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  //  qDebug() << getChessPieceColor();
  // Deselecting counter part of ChessPiece
  if (!_currentGame.gameRunning())
    return;

  if (_currentPiece == _currentGame.pieceToMove && _currentPiece) {
    _currentPiece->mousePressEvent(event);
    return;
  }

  // if selected
  if (_currentGame.pieceToMove) {
    // if same team
    if (this->chessPieceColor() == _currentGame.pieceToMove->side())
      return;
    if (typeid(*_currentGame.pieceToMove) != typeid(Pawn(NONE, _currentGame))) {
      if (_currentGame._enPassantTile != nullptr) {
        _currentGame._enPassantTile->_currentPiece = nullptr;
        _currentGame._enPassantTile = nullptr;
      }
    }

    // removing the eaten piece
    QList<ChessBoardTile *> movLoc = _currentGame.pieceToMove->moveLocation();
    // TO make sure the selected box is in move zone
    int check = 0;
    for (qsizetype i = 0; i < movLoc.size(); i++) {
      if (movLoc[i] == this) {
        check++;
        _currentGame.pieceToMove->moveLen() =
            sqrt(pow(_currentGame.pieceToMove->getCurrentTile()->row() -
                         movLoc[i]->row(),
                     2) +
                 pow(_currentGame.pieceToMove->getCurrentTile()->col() -
                         movLoc[i]->col(),
                     2));
      }
    }
    // if not prsent return
    if (check == 0)
      return;
    // change the color back to normal
    ++_currentGame._halfMovesCounter;
    _currentGame.pieceToMove->decolor();
    // make the first move false applicable for pawn only
    for (int i = 0; i < _currentGame._playablePieces.length(); i++) {
      _currentGame._playablePieces[i]->firstMove() = false;
    }
    if (!_currentGame.pieceToMove->hasMoved()) {
      _currentGame.pieceToMove->firstMove() = true;
    } else {
      _currentGame.pieceToMove->firstMove() = false;
    }
    _currentGame.pieceToMove->hasMoved() = true;

    // this is to eat or consume the enemy present inn the movable region
    if (this->hasChessPiece()) {
      _currentGame._halfMovesCounter = 0;

      this->_currentPiece->setIsPlaced(false);
      if (this->_currentPiece->getCurrentTile() != this) {
        this->_currentPiece->getCurrentTile()->_currentPiece = nullptr;
      }
      this->_currentPiece->setCurrentTile(nullptr);
      _currentGame.placeInDeadPlace(this->_currentPiece);
    }

    if (_currentGame._enPassantTile != nullptr) {
      _currentGame._enPassantTile->_currentPiece = nullptr;
      _currentGame._enPassantTile = nullptr;
    }

    // changing the new stat and resetting the previous left region

    _currentGame.pieceToMove->getCurrentTile()->_currentPiece = nullptr;
    _currentGame.pieceToMove->getCurrentTile()->setColor(
        _currentGame.pieceToMove->getCurrentTile()->getColor());
    placePiece(_currentGame.pieceToMove);

    if (typeid(*_currentGame.pieceToMove) == typeid(King(NONE, _currentGame)) &&
        _currentGame.pieceToMove->moveLen() > 1) {
      int row = _currentGame.pieceToMove->getCurrentTile()->row();
      if (this->col() == 2) {
        _currentGame._allTiles[row][3]->placePiece(
            _currentGame._allTiles[row][0]->currentPiece());
        _currentGame._allTiles[row][0]->_currentPiece = nullptr;
      } else if (this->col() == 6) {
        _currentGame._allTiles[row][5]->placePiece(
            _currentGame._allTiles[row][7]->currentPiece());
        _currentGame._allTiles[row][7]->_currentPiece = nullptr;
      }
    }

    Pawn *p = dynamic_cast<Pawn *>(_currentGame.pieceToMove);
    if (p) {
      _currentGame._halfMovesCounter = 0;
      if (p->side() == WHITE && p->getCurrentTile()->row() == 0) {
        _currentGame._playablePieces.removeAll(_currentGame.pieceToMove);
        ChessPiece *piece = PieceDialog::getPiece(_currentGame.pieceToMove);

        _currentGame.removeFromScene(_currentGame.pieceToMove);
        _currentGame.pieceToMove = nullptr;
        _currentGame.addToScene(piece);
        placePiece(piece);
        _currentGame.pieceToMove = piece;
        _currentGame._playablePieces.append(piece);
      }
      if (p->side() == BLACK && p->getCurrentTile()->row() == 7) {
        _currentGame._playablePieces.removeAll(_currentGame.pieceToMove);
        ChessPiece *piece = PieceDialog::getPiece(_currentGame.pieceToMove);
        _currentGame.removeFromScene(_currentGame.pieceToMove);
        _currentGame.pieceToMove = nullptr;
        _currentGame.addToScene(piece);
        placePiece(piece);
        _currentGame.pieceToMove = piece;
        _currentGame._playablePieces.append(piece);
      }
    }

    _currentGame.changeTurn();
    validateCheck();
    _currentGame.pieceToMove = nullptr;
    if (_currentGame.turn() == WHITE)
      ++_currentGame._fullMovesCounter;
    if (_currentGame._hasBot) {
      moveBlack();
    }
    // qDebug() << _currentGame.generateFEN();
  }
  // Selecting couterpart of the chessPiece
  else if (this->hasChessPiece()) {
    this->_currentPiece->mousePressEvent(event);
  }
}

void ChessBoardTile::moveBlack() {
  ChessPiece *piece = nullptr;
  for (qsizetype i = 0; i < _currentGame._playablePieces.length(); ++i) {
    if (_currentGame._playablePieces.at(i)->side() == BLACK) {
      piece = _currentGame._playablePieces.at(i);
      piece->mousePressEvent(nullptr);
      break;
    }
  }
  if (!piece)
    return;
  int len = piece->moveLocation().length();
  if (len > 0) {
    QRandomGenerator rnd;
    piece->moveLocation().at(rnd.bounded(len))->mousePressEvent(nullptr);
  }
}

void ChessBoardTile::setColor(QColor color) {
  _brush.setColor(color);
  setBrush(color);
}

QColor &ChessBoardTile::getColor() { return _color; }

void ChessBoardTile::placePiece(ChessPiece *piece) {
  int shift = _currentGame.width() * 0.075;
  piece->setPos(x() + shift / 2 - piece->pixmap().width() / 2,
                y() + shift / 2 - piece->pixmap().width() / 2);
  piece->setCurrentTile(this);
  _currentPiece = piece;
}

void ChessBoardTile::connectToPiece(ChessPiece *piece) {
  _currentPiece = piece;
}
bool ChessBoardTile::hasCheckmate() {
  int availableMoves = 0;
  QList<ChessPiece *> pList = _currentGame._playablePieces;
  ChessPiece *piece = _currentPiece;
  for (size_t i = 0, n = pList.size(); i < n; i++) {
    if (pList[i]->side() == _currentGame.turn()) {
      _currentGame.pieceToMove = pList[i];
      pList[i]->moves();
      pList[i]->decolor();
      availableMoves += pList[i]->moveLocation().size();
    }
  }
  _currentGame.pieceToMove = piece;
  return availableMoves == 0;
}
void ChessBoardTile::validateCheck() {
  int c = 0;
  ChessPiece *kingPiece = nullptr;
  QList<ChessPiece *> pList = _currentGame._playablePieces;
  for (size_t i = 0, n = pList.size(); i < n; i++) {

    King *p = dynamic_cast<King *>(pList[i]);
    if (p) {
      continue;
    }
    pList[i]->moves();
    pList[i]->decolor();
    QList<ChessBoardTile *> bList = pList[i]->moveLocation();
    for (size_t j = 0, n = bList.size(); j < n; j++) {
      King *p = dynamic_cast<King *>(bList[j]->_currentPiece);
      if (p) {
        if (p->side() == _currentGame.turn()) {
          kingPiece = p;
        }
        if (p->side() == pList[i]->side())
          continue;
        bList[j]->setColor(Qt::blue);
        pList[i]->getCurrentTile()->setColor(Qt::darkRed);
        if (!_currentGame._check->isVisible())
          _currentGame._check->setVisible(true);
        else {
          bList[j]->setColor(bList[j]->getColor());
          pList[i]->getCurrentTile()->setColor(
              pList[i]->getCurrentTile()->getColor());
          // _currentGame.gameOver();
        }
        c++;
      }
    }
  }
  bool cantMove = hasCheckmate();
  if (!c && cantMove) {
    if (kingPiece)
      kingPiece->getCurrentTile()->setColor(Qt::blue);
    _currentGame._check->setVisible(false);
    for (size_t i = 0, n = pList.size(); i < n; i++) {
      pList[i]->getCurrentTile()->setColor(
          pList[i]->getCurrentTile()->getColor());
    }
    _currentGame.gameRunning() = false;
    _currentGame.showMessage((char *)"Stalemate: DRAW");

  } else if (c && cantMove) {
    _currentGame.gameRunning() = false;
    if (_currentGame.turn() == BLACK) {
      _currentGame.showMessage((char *)"Checkmate: WHITE won");
    } else {
      _currentGame.showMessage((char *)"Checkmate: BLACK won");
    }
  } else if (c) {
    if (kingPiece)
      kingPiece->getCurrentTile()->setColor(Qt::blue);
  }
  if (_currentGame._halfMovesCounter == 100) {
    _currentGame.gameRunning() = false;
    _currentGame.showMessage(
        (char *)"Stalemate: DRAW (Exceeded allowed moves)");
  }
}
