#pragma once
#include "ChessPiece.h"
class ChessGame;
class Bishop : public ChessPiece {
public:
  Bishop(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent = 0);
  void setImage();

  void moves();
};
