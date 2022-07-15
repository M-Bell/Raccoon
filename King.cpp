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
    setPixmap(QPixmap(":/res/images/alpha_chess_piece_king_white.png"));
  else
    setPixmap(QPixmap(":/res/images/alpha_chess_piece_king.png"));
}
void King::findUnSafeLocation() {

  QList<ChessBoardTile *> blockedTiles;
  QList<ChessPiece *> pList = _currentGame._playablePieces;
  for (qsizetype i = 0; i < pList.size(); i++) {
    if (pList[i]->side() != this->side()) {
      QList<ChessBoardTile *> bList = pList[i]->moveLocation();
      for (qsizetype j = 0; j < bList.size(); j++) {
        for (size_t k = 0, n = _location.size(); k < n; k++) {
          if (bList[j] == _location[k]) {
            kingIsSafe(_location[k]);
          }
        }
      }
      for (qsizetype i = 0; i < blockedTiles.size(); ++i) {
        _location.removeOne(blockedTiles[i]);
      }
      if (_canCastle) {
        if (_location.contains(_currentGame._allTiles[0][2]) &&
            (!_location.contains(_currentGame._allTiles[0][3]) ||
             bList.contains(_currentGame._allTiles[0][1]))) {
          _currentGame._allTiles[0][2]->setColor(
              _currentGame._allTiles[0][2]->getColor());
          blockedTiles.append(_currentGame._allTiles[0][2]);
        }
        if (_location.contains(_currentGame._allTiles[0][6]) &&
            !_location.contains(_currentGame._allTiles[0][5])) {
          _currentGame._allTiles[0][6]->setColor(
              _currentGame._allTiles[0][6]->getColor());
          blockedTiles.append(_currentGame._allTiles[0][6]);
        }
        if (_location.contains(_currentGame._allTiles[7][2]) &&
            (!_location.contains(_currentGame._allTiles[7][3]) ||
             bList.contains(_currentGame._allTiles[7][1]))) {
          _currentGame._allTiles[7][2]->setColor(
              _currentGame._allTiles[7][2]->getColor());
          blockedTiles.append(_currentGame._allTiles[7][2]);
        }
        if (_location.contains(_currentGame._allTiles[7][6]) &&
            !_location.contains(_currentGame._allTiles[7][5])) {
          _currentGame._allTiles[7][6]->setColor(
              _currentGame._allTiles[7][6]->getColor());
          blockedTiles.append(_currentGame._allTiles[7][6]);
        }
      }
    }
  }
  for (qsizetype i = 0; i < blockedTiles.size(); ++i) {
    _location.removeOne(blockedTiles[i]);
  }
}
void King::moves() {
  _location.clear();
  int row = this->getCurrentTile()->row();
  int col = this->getCurrentTile()->col();
  ChessPieceSide currentSide = this->side();

  if (col > 0 && row > 0 &&
      _currentGame._allTiles[row - 1][col - 1]->chessPieceColor() !=
          currentSide &&
      kingIsSafe(_currentGame._allTiles[row - 1][col - 1])) { // up left
    //    _location.append(_currentGame._allTiles[row - 1][col - 1]);
    //    _currentGame._allTiles[row - 1][col - 1]->setColor(Qt::darkRed);
    //    if (_location.last()->hasChessPiece()) {
    //      _location.last()->setColor(Qt::red);
    //    }
  }
  if (col < 7 && row > 0 &&
      !(_currentGame._allTiles[row - 1][col + 1]->chessPieceColor() ==
        currentSide) &&
      kingIsSafe(_currentGame._allTiles[row - 1][col + 1])) { // up right
    //    _location.append(_currentGame._allTiles[row - 1][col + 1]);
    //    _currentGame._allTiles[row - 1][col + 1]->setColor(Qt::darkRed);
    //    if (_location.last()->hasChessPiece()) {
    //      _location.last()->setColor(Qt::red);
    //    }
  }
  if (row > 0 &&
      !(_currentGame._allTiles[row - 1][col]->chessPieceColor() ==
        currentSide) &&
      kingIsSafe(_currentGame._allTiles[row - 1][col])) { // up
    //    _location.append(_currentGame._allTiles[row - 1][col]);
    //    _currentGame._allTiles[row - 1][col]->setColor(Qt::darkRed);
    //    if (_location.last()->hasChessPiece()) {
    //      _location.last()->setColor(Qt::red);
    //    }
  }
  if (row < 7 &&
      !(_currentGame._allTiles[row + 1][col]->chessPieceColor() ==
        currentSide) &&
      kingIsSafe(_currentGame._allTiles[row + 1][col])) { // down
    //    _location.append(_currentGame._allTiles[row + 1][col]);
    //    _currentGame._allTiles[row + 1][col]->setColor(Qt::darkRed);
    //    if (_location.last()->hasChessPiece()) {
    //      _location.last()->setColor(Qt::red);
    //    }
  }
  if (col > 0 &&
      !(_currentGame._allTiles[row][col - 1]->chessPieceColor() ==
        currentSide) &&
      kingIsSafe(_currentGame._allTiles[row][col - 1])) { // left
    //    _location.append(_currentGame._allTiles[row][col - 1]);
    //    _currentGame._allTiles[row][col - 1]->setColor(Qt::darkRed);
    //    if (_location.last()->hasChessPiece()) {
    //      _location.last()->setColor(Qt::red);
    //    }
  }
  if (col < 7 &&
      !(_currentGame._allTiles[row][col + 1]->chessPieceColor() ==
        currentSide) &&
      kingIsSafe(_currentGame._allTiles[row][col + 1])) { // right
    //    _location.append(_currentGame._allTiles[row][col + 1]);
    //    _currentGame._allTiles[row][col + 1]->setColor(Qt::darkRed);
    //    if (_location.last()->hasChessPiece()) {
    //      _location.last()->setColor(Qt::red);
    //    }
  }
  if (col > 0 && row < 7 &&
      !(_currentGame._allTiles[row + 1][col - 1]->chessPieceColor() ==
        currentSide) &&
      kingIsSafe(_currentGame._allTiles[row + 1][col - 1])) { // down left
    //    _location.append(_currentGame._allTiles[row + 1][col - 1]);
    //    _currentGame._allTiles[row + 1][col - 1]->setColor(Qt::darkRed);
    //    if (_location.last()->hasChessPiece()) {
    //      _location.last()->setColor(Qt::red);
    //    }
  }
  if (col < 7 && row < 7 &&
      !(_currentGame._allTiles[row + 1][col + 1]->chessPieceColor() ==
        currentSide) &&
      kingIsSafe(_currentGame._allTiles[row + 1][col + 1])) { // down right
    //    _location.append(_currentGame._allTiles[row + 1][col + 1]);
    //    _currentGame._allTiles[row + 1][col + 1]->setColor(Qt::darkRed);
    //    if (_location.last()->hasChessPiece()) {
    //      _location.last()->setColor(Qt::red);
    //    }
  }
  if (!this->_hasMoved) {
    if (_side == WHITE) {
      if (_currentGame._allTiles[7][7]->currentPiece() != nullptr &&
          !_currentGame._allTiles[7][7]->currentPiece()->hasMoved()) {
        if (_currentGame._allTiles[7][6]->currentPiece() == nullptr &&
            _currentGame._allTiles[7][5]->currentPiece() == nullptr) {
          _location.append(_currentGame._allTiles[7][6]);
          _currentGame._allTiles[7][6]->setColor(Qt::darkRed);
          _canCastle = true;
        }
      } else {
        _canCastleKingside = false;
      }
      if (_currentGame._allTiles[7][0]->currentPiece() != nullptr &&
          !_currentGame._allTiles[7][0]->currentPiece()->hasMoved()) {
        if (_currentGame._allTiles[7][1]->currentPiece() == nullptr &&
            _currentGame._allTiles[7][2]->currentPiece() == nullptr &&
            _currentGame._allTiles[7][3]->currentPiece() == nullptr) {
          _location.append(_currentGame._allTiles[7][2]);
          _currentGame._allTiles[7][2]->setColor(Qt::darkRed);
          _canCastle = true;
        }
      } else {
        _canCastleQueenside = false;
      }
    } else {
      if (_currentGame._allTiles[0][7]->currentPiece() != nullptr &&
          !_currentGame._allTiles[0][7]->currentPiece()->hasMoved()) {
        if (_currentGame._allTiles[0][6]->currentPiece() == nullptr &&
            _currentGame._allTiles[0][5]->currentPiece() == nullptr) {
          _location.append(_currentGame._allTiles[0][6]);
          _currentGame._allTiles[0][6]->setColor(Qt::darkRed);
          _canCastle = true;
        }
      } else {
        _canCastleKingside = false;
      }
      if (_currentGame._allTiles[0][0]->currentPiece() != nullptr &&
          !_currentGame._allTiles[0][0]->currentPiece()->hasMoved()) {

        if (_currentGame._allTiles[0][1]->currentPiece() == nullptr &&
            _currentGame._allTiles[0][2]->currentPiece() == nullptr &&
            _currentGame._allTiles[0][3]->currentPiece() == nullptr) {
          _location.append(_currentGame._allTiles[0][2]);
          _currentGame._allTiles[0][2]->setColor(Qt::darkRed);
          _canCastle = true;
        }
      } else {
        _canCastleQueenside = false;
      }
    }
  } else {
    _canCastleQueenside = false;
    _canCastleKingside = false;
  }

  findUnSafeLocation();
  _canCastle = false;

  for (qsizetype i = 0; i < _location.size(); i++) {
    tileSetting(_location[i]);
  }
}
