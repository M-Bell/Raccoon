#include "Knight.h"
#include "ChessGame.h"
#include <QDebug>

Knight::Knight(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent)
    : ChessPiece(side, game, parent) {
  setImage();
}

void Knight::setImage() {
  if (_side == WHITE)
    setPixmap(QPixmap(":/res/images/chess_piece_knight_white.png"));
  else
    setPixmap(QPixmap(":/res/images/chess_piece_knight.png"));
}

void Knight::moves() {
  int row = this->getCurrentTile()->row();
  int col = this->getCurrentTile()->col();
  int i, j;
  ChessPieceSide currentSide = this->side();

  // There are total 8 places where a night can move

  // 1st up up left
  i = row - 2;
  j = col - 1;
  if (i >= 0 && j >= 0 &&
      (_currentGame._allTiles[i][j]->chessPieceColor() != currentSide)) {
    _location.append(_currentGame._allTiles[i][j]);
    if (_location.last()->hasChessPiece())
      _location.last()->setColor(Qt::red);
    else
      _location.last()->setColor(Qt::darkRed);
  }

  // 2nd up up right
  i = row - 2;
  j = col + 1;
  if (i >= 0 && j <= 7 &&
      (_currentGame._allTiles[i][j]->chessPieceColor() != currentSide)) {
    _location.append(_currentGame._allTiles[i][j]);
    if (_location.last()->hasChessPiece())
      _location.last()->setColor(Qt::red);
    else
      _location.last()->setColor(Qt::darkRed);
  }

  // 3rd down down left
  i = row + 2;
  j = col - 1;
  if (i <= 7 && j >= 0 &&
      (_currentGame._allTiles[i][j]->chessPieceColor() != currentSide)) {
    _location.append(_currentGame._allTiles[i][j]);
    if (_location.last()->hasChessPiece())
      _location.last()->setColor(Qt::red);
    else
      _location.last()->setColor(Qt::darkRed);
  }

  // 4th  down down right
  i = row + 2;
  j = col + 1;
  if (i <= 7 && j <= 7 &&
      (_currentGame._allTiles[i][j]->chessPieceColor() != currentSide)) {
    _location.append(_currentGame._allTiles[i][j]);
    if (_location.last()->hasChessPiece())
      _location.last()->setColor(Qt::red);
    else
      _location.last()->setColor(Qt::darkRed);
  }

  // 5th left left up
  i = row - 1;
  j = col - 2;
  if (i >= 0 && j >= 0 &&
      (_currentGame._allTiles[i][j]->chessPieceColor() != currentSide)) {
    _location.append(_currentGame._allTiles[i][j]);
    if (_location.last()->hasChessPiece())
      _location.last()->setColor(Qt::red);
    else
      _location.last()->setColor(Qt::darkRed);
  }

  // 6th left left down
  i = row + 1;
  j = col - 2;
  if (i <= 7 && j >= 0 &&
      (_currentGame._allTiles[i][j]->chessPieceColor() != currentSide)) {
    _location.append(_currentGame._allTiles[i][j]);
    if (_location.last()->hasChessPiece())
      _location.last()->setColor(Qt::red);
    else
      _location.last()->setColor(Qt::darkRed);
  }

  // 7th right right up
  i = row - 1;
  j = col + 2;
  if (i >= 0 && j <= 7 &&
      (_currentGame._allTiles[i][j]->chessPieceColor() != currentSide)) {
    _location.append(_currentGame._allTiles[i][j]);
    if (_location.last()->hasChessPiece())
      _location.last()->setColor(Qt::red);
    else
      _location.last()->setColor(Qt::darkRed);
  }

  // 8th right right down
  i = row + 1;
  j = col + 2;
  if (i <= 7 && j <= 7 &&
      (_currentGame._allTiles[i][j]->chessPieceColor() != currentSide)) {
    _location.append(_currentGame._allTiles[i][j]);
    if (_location.last()->hasChessPiece())
      _location.last()->setColor(Qt::red);
    else
      _location.last()->setColor(Qt::darkRed);
  }
}
