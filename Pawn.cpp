#include "Pawn.h"
#include "ChessGame.h"
#include "ChessPieceSide.h"

Pawn::Pawn(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent)
    : ChessPiece(side, game, parent) {
  setImage();
}

void Pawn::setImage() {
  if (_side == WHITE)
    setPixmap(QPixmap(":/res/images/alpha_chess_piece_pawn_white.png"));
  else
    setPixmap(QPixmap(":/res/images/alpha_chess_piece_pawn_black.png"));
}

void Pawn::moveForward(int row, int col, ChessPieceSide side) {
  int direction;
  if (side == WHITE) {
    direction = -1;
  } else if (side == BLACK) {
    direction = 1;
  } else {
    return;
  }
  if (!_currentGame._allTiles[row + direction][col]->hasChessPiece() &&
      kingIsSafe(_currentGame._allTiles[row + direction][col])) {

    if (!hasMoved() &&
        !_currentGame._allTiles[row + direction * 2][col]->hasChessPiece()) {

      kingIsSafe(_currentGame._allTiles[row + direction * 2][col]);
    }
  }
}

void Pawn::capture(int row, int col, ChessPieceSide oppositeSide) {
  if (_currentGame._allTiles[row][col]->chessPieceColor() == oppositeSide &&
      kingIsSafe(_currentGame._allTiles[row][col])) {
  }
}

void Pawn::captureEnPassant(int row, int col, ChessPieceSide oppositeSide) {
  int direction;
  if (oppositeSide == WHITE) {
    direction = 1;
  } else if (oppositeSide == BLACK) {
    direction = -1;
  } else {
    return;
  }
  Pawn *c =
      dynamic_cast<Pawn *>(_currentGame._allTiles[row][col]->currentPiece());
  if (!c)
    return;
  if (_currentGame._allTiles[row][col]->chessPieceColor() == oppositeSide &&
      _currentGame._allTiles[row][col]->currentPiece()->moveLen() > 1 &&
      _currentGame._allTiles[row][col]->currentPiece()->firstMove() &&
      kingIsSafe(_currentGame._allTiles[row + direction][col])) {
    _currentGame._allTiles[row + direction][col]->connectToPiece(
        _currentGame._allTiles[row][col]->currentPiece());
    _currentGame._enPassantTile = _currentGame._allTiles[row + direction][col];
  }
}

void Pawn::moves() {
  _location.clear();

  int row = this->_currentTile->row();

  int col = this->_currentTile->col();
  if (this->side() == WHITE) {
    if (row > 0) {
      moveForward(row, col, WHITE);
      if (col > 0) {
        capture(row - 1, col - 1, BLACK);
        captureEnPassant(row, col - 1, BLACK);
      }
      if (col < 7) {
        capture(row - 1, col + 1, BLACK);
        captureEnPassant(row, col + 1, BLACK);
      }
    }
  } else {
    if (row < 7) {
      moveForward(row, col, BLACK);
      if (col > 0) {
        capture(row + 1, col - 1, WHITE);
        captureEnPassant(row, col - 1, WHITE);
      }
      if (col < 7) {
        capture(row + 1, col + 1, WHITE);
        captureEnPassant(row, col + 1, WHITE);
      }
    }
  }

  for (qsizetype i = 0; i < _location.size(); i++) {
    tileSetting(_location[i]);
  }
}
