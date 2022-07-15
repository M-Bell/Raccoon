#include "Knight.h"
#include "ChessGame.h"
#include <QDebug>

Knight::Knight(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent)
    : ChessPiece(side, game, parent) {
  setImage();
}

void Knight::setImage() {
  if (_side == WHITE)
    setPixmap(QPixmap(":/res/images/alpha_chess_piece_knight_white.png"));
  else
    setPixmap(QPixmap(":/res/images/alpha_chess_piece_knight.png"));
}

void Knight::move(int x, int y) {
  if (_currentGame._allTiles[x][y]->chessPieceColor() != _side &&
      kingIsSafe(_currentGame._allTiles[x][y])) {
    //_location.append(_currentGame._allTiles[x][y]);
  }

  //    if (_location.last()->hasChessPiece())
  //      _location.last()->setColor(Qt::red);
  //    else
  //      _location.last()->setColor(Qt::darkRed);
}

void Knight::moves() {
    _location.clear();
  int row = this->getCurrentTile()->row();
  int col = this->getCurrentTile()->col();
  int i, j;
  // There are total 8 places where a night can move

  // 1st up up left
  i = row - 2;
  j = col - 1;
  if (i >= 0 && j >= 0) {
    move(i, j);
  }

  // 2nd up up right
  i = row - 2;
  j = col + 1;
  if (i >= 0 && j <= 7) {
    move(i, j);
  }

  // 3rd down down left
  i = row + 2;
  j = col - 1;
  if (i <= 7 && j >= 0) {
    move(i, j);
  }

  // 4th  down down right
  i = row + 2;
  j = col + 1;
  if (i <= 7 && j <= 7) {
    move(i, j);
  }

  // 5th left left up
  i = row - 1;
  j = col - 2;
  if (i >= 0 && j >= 0) {
    move(i, j);
  }

  // 6th left left down
  i = row + 1;
  j = col - 2;
  if (i <= 7 && j >= 0) {
    move(i, j);
  }

  // 7th right right up
  i = row - 1;
  j = col + 2;
  if (i >= 0 && j <= 7) {
    move(i, j);
  }

  // 8th right right down
  i = row + 1;
  j = col + 2;
  if (i <= 7 && j <= 7) {
    move(i, j);
  }

    for (qsizetype i = 0; i < _location.size(); i++) {
      tileSetting(_location[i]);
    }

}
