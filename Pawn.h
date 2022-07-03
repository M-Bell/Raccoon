#pragma once
#include "ChessPiece.h"

class Pawn : public ChessPiece {
public:
  Pawn(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent = 0);
  void setImage();
  void moves();

private:
  void moveForward(int x, int y, ChessPieceSide side);
  void capture(int x, int y, ChessPieceSide side);
  void captureEnPassant(int x, int y, ChessPieceSide side);
};
