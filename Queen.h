#pragma once
#include "ChessPiece.h"

class Queen : public ChessPiece {
public:
  Queen(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent = 0);
  void setImage();
  void moves();
};
