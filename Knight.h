#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece {
public:
  Knight(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent = 0);
  void setImage();
  void moves();
};
