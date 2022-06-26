#pragma once
#include "ChessPiece.h"
class Rook : public ChessPiece {
public:
  Rook(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent = 0);
  void setImage();
  void moves();
};
