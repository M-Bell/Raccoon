#pragma once
#include "ChessPiece.h"
class King : public ChessPiece {
private:
  bool _canCastle = false;
  bool _canCastleKingside = true;
  bool _canCastleQueenside = true;

public:
  King(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent = 0);
  void setImage();
  void findUnSafeLocation();
  void moves();

  inline bool canCastleKingside() const { return _canCastleKingside; }
  inline bool canCastleQueenside() const { return _canCastleQueenside; }
};
