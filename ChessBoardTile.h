#pragma once

#include "ChessGame.h"
#include "ChessPieceSide.h"
#include <QBrush>
#include <QGraphicsRectItem>
class ChessPiece;

class ChessBoardTile : public QGraphicsRectItem {
private:
  ChessGame &_currentGame;
  QBrush _brush;
  QColor _color;
  ChessPiece *_currentPiece;
  int _row;
  int _col;

public:
  // Constructor
  ChessBoardTile(ChessGame &game, QGraphicsItem *parent = 0);
  ~ChessBoardTile();

  // public member function
  void mousePressEvent(QGraphicsSceneMouseEvent *event);

  inline const int &row() const { return _row; }
  inline int &row() { return _row; }

  inline const int &col() const { return _col; }
  inline int &col() { return _col; }

  inline ChessPiece *currentPiece() const { return _currentPiece; }

  void setColor(QColor color);
  QColor &getColor();
  void placePiece(ChessPiece *piece);
  void connectToPiece(ChessPiece *piece);
  inline ChessPieceSide chessPieceColor() const {
    return (_currentPiece == nullptr) ? NONE : _currentPiece->side();
  }

  inline bool hasChessPiece() { return _currentPiece != nullptr; }

  void checkForCheck();
};
