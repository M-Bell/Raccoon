#include "Pawn.h"
#include "ChessGame.h"
#include "ChessPieceSide.h"

Pawn::Pawn(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent)
    : ChessPiece(side, game, parent), _currentGame(game) {
  setImage();
  firstMove = true;
}

void Pawn::setImage() {
  if (_side == WHITE)
    setPixmap(QPixmap(":/res/images/chess_piece_pawn_white.png"));
  else
    setPixmap(QPixmap(":/res/images/chess_piece_pawn_black.png"));
}

void Pawn::moves() {
  _location.clear();

  int row = this->_currentTile->row();

  int col = this->_currentTile->col();
  if (this->side() == WHITE) {
    if (col > 0 && row > 0 &&
        _currentGame._allTiles[row - 1][col - 1]->сhessPieceColor() == BLACK) {
      _location.append(_currentGame._allTiles[row - 1][col - 1]);
      tileSetting(_location.last());
    }
    if (col < 7 && row > 0 &&
        _currentGame._allTiles[row - 1][col + 1]->сhessPieceColor() == BLACK) {
      _location.append(_currentGame._allTiles[row - 1][col + 1]);
      tileSetting(_location.last());
    }
    if (row > 0 && (!_currentGame._allTiles[row - 1][col]->hasChessPiece())) {
      _location.append(_currentGame._allTiles[row - 1][col]);
      tileSetting(_location.last());
      if (firstMove && !_currentGame._allTiles[row - 2][col]->hasChessPiece()) {
        _location.append(_currentGame._allTiles[row - 2][col]);
        tileSetting(_location.last());
      }
    }

  } else {
    if (col > 0 && row < 7 &&
        _currentGame._allTiles[row + 1][col - 1]->сhessPieceColor() ==
            WHITE) { // left
      _location.append(_currentGame._allTiles[row + 1][col - 1]);
      tileSetting(_location.last());
    }
    if (col < 7 && row < 7 &&
        _currentGame._allTiles[row + 1][col + 1]->сhessPieceColor() ==
            WHITE) { // right
      _location.append(_currentGame._allTiles[row + 1][col + 1]);
      tileSetting(_location.last());
    }
    if (row < 7 && (!_currentGame._allTiles[row + 1][col]->hasChessPiece())) {
      _location.append(_currentGame._allTiles[row + 1][col]);
      tileSetting(_location.last());
      if (firstMove && !_currentGame._allTiles[row + 2][col]->hasChessPiece()) {
        _location.append(_currentGame._allTiles[row + 2][col]);
        tileSetting(_location.last());
      }
    }
  }
}
