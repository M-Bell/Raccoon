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
    setPixmap(QPixmap(":/images/images/chess_piece_pawn.png"));
  else
    setPixmap(QPixmap(":/images/images/chess_piece_pawn.png"));
}

void Pawn::moves() {
  //  location.clear();

  //  int row = this->currentTile->rowLoc;

  //  int col = this->currentTile->col();
  //  if (this->side() == WHITE) {
  //    if (col > 0 && row > 0 &&
  //        _currentGame.collection[row - 1][col - 1]->getChessPieceColor() ==
  //        "BLACK") {
  //      location.append(_currentGame.collection[row - 1][col - 1]);
  //      boxSetting(location.last());
  //    }
  //    if (col < 7 && row > 0 &&
  //        game->collection[row - 1][col + 1]->getChessPieceColor() == "BLACK")
  //        {
  //      location.append(game->collection[row - 1][col + 1]);
  //      boxSetting(location.last());
  //    }
  //    if (row > 0 && (!game->collection[row - 1][col]->getHasChessPiece())) {
  //      location.append(game->collection[row - 1][col]);
  //      boxSetting(location.last());
  //      if (firstMove && !game->collection[row - 2][col]->getHasChessPiece())
  //      {
  //        location.append(game->collection[row - 2][col]);
  //        boxSetting(location.last());
  //      }
  //    }

  //  } else {
  //    if (col > 0 && row < 7 &&
  //        game->collection[row + 1][col - 1]->getChessPieceColor() ==
  //            "WHITE") { // left
  //      location.append(game->collection[row + 1][col - 1]);
  //      boxSetting(location.last());
  //    }
  //    if (col < 7 && row < 7 &&
  //        game->collection[row + 1][col + 1]->getChessPieceColor() ==
  //            "WHITE") { // right
  //      location.append(game->collection[row + 1][col + 1]);
  //      boxSetting(location.last());
  //    }
  //    if (row < 7 && (!game->collection[row + 1][col]->getHasChessPiece())) {
  //      location.append(game->collection[row + 1][col]);
  //      boxSetting(location.last());
  //      if (firstMove && !game->collection[row + 2][col]->getHasChessPiece())
  //      {
  //        location.append(game->collection[row + 2][col]);
  //        boxSetting(location.last());
  //      }
  //    }
  //  }
}
