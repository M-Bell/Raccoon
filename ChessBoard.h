#pragma once
#include "ChessPiece.h"
class ChessGame;
class ChessBoard {
public:
  ChessBoard(ChessGame& game);

  void drawBoard(const int x, const int y);

  void placePieces();
  void reset();

  void setLayout(const QString &pgnFilename);

private:
  QList<ChessPiece *> _allPieces;

  void initPieces();


  ChessGame &_currentGame;
};
