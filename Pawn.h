#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece {
public:
  Pawn(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent = 0);
  void setImage();
  void moves();

};
