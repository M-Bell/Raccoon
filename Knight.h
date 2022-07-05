#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece {
private:
  void move(int x, int y);

public:
  Knight(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent = 0);
  void setImage();
  void moves();
};
