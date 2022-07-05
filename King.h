#pragma once
#include "ChessPiece.h"
class King : public ChessPiece {
private:
  bool _canCastle = false;

public:
  King(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent = 0);
  void setImage();
  void findUnSafeLocation();
  void moves();
};
