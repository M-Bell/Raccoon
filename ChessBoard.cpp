#include "ChessBoard.h"
#include "Bishop.h"
#include "ChessBoardTile.h"
#include "ChessGame.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

ChessBoard::ChessBoard(ChessGame &game) : _currentGame(game) { initPieces(); }

void ChessBoard::drawBoard(const int x, const int y) {
  int shift = _currentGame.width() * 0.075;
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
  piece = new Rook(BLACK, _currentGame);
  _allPieces.append(piece);
  piece = new Knight(BLACK, _currentGame);
  _allPieces.append(piece);
  piece = new Bishop(BLACK, _currentGame);
  _allPieces.append(piece);
  piece = new Queen(BLACK, _currentGame);
  _allPieces.append(piece);
  piece = new King(BLACK, _currentGame);
  _allPieces.append(piece);
  piece = new Bishop(BLACK, _currentGame);
  _allPieces.append(piece);
  piece = new Knight(BLACK, _currentGame);
  _allPieces.append(piece);
  piece = new Rook(BLACK, _currentGame);
  _allPieces.append(piece);
  for (int i = 0; i < 8; i++) {
    piece = new Pawn(BLACK, _currentGame);
    _allPieces.append(piece);
  }

  for (int i = 0; i < 8; i++) {
    piece = new Pawn(WHITE, _currentGame);
    _allPieces.append(piece);
  }

  piece = new Rook(WHITE, _currentGame);
  _allPieces.append(piece);
  piece = new Knight(WHITE, _currentGame);
  _allPieces.append(piece);
  piece = new Bishop(WHITE, _currentGame);
  _allPieces.append(piece);
  piece = new Queen(WHITE, _currentGame);
  _allPieces.append(piece);
  piece = new King(WHITE, _currentGame);
  _allPieces.append(piece);
  piece = new Bishop(WHITE, _currentGame);
  _allPieces.append(piece);
  piece = new Knight(WHITE, _currentGame);
  _allPieces.append(piece);
  piece = new Rook(WHITE, _currentGame);
  _allPieces.append(piece);
}

void ChessBoard::placePieces() {
  int pieceCode = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {

      ChessBoardTile *tile = _currentGame._allTiles[i][j];
      if (i < 2) {
        tile->placePiece(_allPieces[pieceCode]);
        _currentGame._playablePieces.append(_allPieces[pieceCode]);
        _currentGame.addToScene(_allPieces[pieceCode++]);
      }
      if (i > 5) {
        tile->placePiece(_allPieces[pieceCode]);
        _currentGame._playablePieces.append(_allPieces[pieceCode]);
        _currentGame.addToScene(_allPieces[pieceCode++]);
      }
    }
  }
}
void ChessBoard::reset() {}
