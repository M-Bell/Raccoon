#include "ChessBoard.h"
#include "ChessBoardTile.h"
#include "ChessGame.h"
#include "Pawn.h"

ChessBoard::ChessBoard(ChessGame &game) : _currentGame(game) { initPieces(); }

void ChessBoard::drawBoard(const int x, const int y) {
  int shift = 100;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      ChessBoardTile *tile = new ChessBoardTile(_currentGame);
      _currentGame._allTiles[i][j] = tile;
      tile->row() = i;
      tile->col() = j;
      tile->setPos(x + shift * j, y + shift * i);
      if ((i + j) % 2 == 0) {

        tile->setColor(Qt::lightGray);
        tile->getColor() = Qt::lightGray;
      } else {

        tile->setColor(Qt::darkGray);
        tile->getColor() = Qt::darkGray;
      }
      _currentGame.addToScene(tile);
    }
  }
}

void ChessBoard::initPieces() {
  ChessPiece *piece;
  for (int i = 0; i < 8; i++) {
    piece = new Pawn(WHITE, _currentGame);
    _allPieces.append(piece);
    piece = new Pawn(BLACK, _currentGame);
    _allPieces.append(piece);
  }
  //    piece = new Rook(WHITE);
  //    _allPieces.append(piece);
  //    piece = new ROOK(BLACK);
  //    _allPieces.append(piece);

  //    piece = new Knight(WHITE);
  //    _allPieces.append(piece);
  //      piece = new Knight(BLACK);
  //      _allPieces.append(piece);

  //    piece = new Bishop(WHITE);
  //    _allPieces.append(piece);
  //    piece = new Bishop(BLACK);
  //    _allPieces.append(piece);

  //    piece = new Queen(WHITE);
  //    _allPieces.append(piece);
  //    piece = new Queen(BLACK);
  //    _allPieces.append(piece);

  //    piece = new King(WHITE);
  //    _allPieces.append(piece);
  //    piece = new King(BLACK);
  //    _allPieces.append(piece);

  //    piece = new Bishop(WHITE);
  //    _allPieces.append(piece);
  //    piece = new Bishop(BLACK);
  //    _allPieces.append(piece);

  //    piece = new Knight(WHITE);
  //    _allPieces.append(piece);
  //    piece = new Knight(BLACK);
  //    _allPieces.append(piece);

  //    piece = new Rook(WHITE);
  //    _allPieces.append(piece);
  //    piece = new Rook(BLACK);
  //    _allPieces.append(piece);
}

void ChessBoard::placePieces() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {

      ChessBoardTile *tile = _currentGame._allTiles[i][j];
      if (i == 1) {
        static int k = 1;
        tile->placePiece(_allPieces[k]);
        _currentGame._playablePieces.append(_allPieces[k]);
        _currentGame.addToScene(_allPieces[k]);
        k += 2;
      }
      if (i == 6) {
        static int h = 0;
        tile->placePiece(_allPieces[h]);
        _currentGame._playablePieces.append(_allPieces[h]);
        _currentGame.addToScene(_allPieces[h]);
        h += 2;
      }
    }
  }
}

void ChessBoard::reset() {}
