#include "Bishop.h"
#include "ChessGame.h"
#include <QDebug>

Bishop::Bishop(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent)
    : ChessPiece(side, game, parent) {
  setImage();
}

void Bishop::setImage() {
  if (_side == WHITE)
    setPixmap(QPixmap(":/res/images/alpha_chess_piece_bishop_white.png"));
  else
    setPixmap(QPixmap(":/res/images/alpha_chess_piece_bishop.png"));
}

void Bishop::moves() {
  _location.clear();
  int row = this->getCurrentTile()->row();
  int col = this->getCurrentTile()->col();
  ChessPieceSide currentSide = this->side();
  // For upper Left

  for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    if (_currentGame._allTiles[i][j]->chessPieceColor() == currentSide) {
      break;

    } else {
      kingIsSafe(_currentGame._allTiles[i][j]);
      if (_location.size()<=0)
        continue;
      if (tileSetting(_location.last())) {
        break;
      }
    }
  }

  // For upper right

  for (int i = row - 1, j = col + 1; i >= 0 && j <= 7; i--, j++) {
    if (_currentGame._allTiles[i][j]->chessPieceColor() == currentSide) {
      break;

    } else {
      kingIsSafe(_currentGame._allTiles[i][j]);
      if (_location.size()<=0)
        continue;
      if (tileSetting(_location.last())) {
        break;
      }
    }
  }

  // For downward right

  for (int i = row + 1, j = col + 1; i <= 7 && j <= 7; i++, j++) {
    if (_currentGame._allTiles[i][j]->chessPieceColor() == currentSide) {
      break;

    } else {
      kingIsSafe(_currentGame._allTiles[i][j]);
      if (_location.size()<=0)
        continue;
      if (tileSetting(_location.last())) {
        break;
      }
    }
  }

  // For downward left

  for (int i = row + 1, j = col - 1; i <= 7 && j >= 0; i++, j--) {
    if (_currentGame._allTiles[i][j]->chessPieceColor() == currentSide) {
      break;

    } else {
      kingIsSafe(_currentGame._allTiles[i][j]);
      if (_location.size()<=0)
        continue;
      if (tileSetting(_location.last())) {
        break;
      }
    }
  }

    for (qsizetype i = 0; i < _location.size(); i++) {
      tileSetting(_location[i]);
    }

}
