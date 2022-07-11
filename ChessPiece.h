#pragma once
#include "ChessPieceSide.h"
#include <QGraphicsPathItem>

class ChessBoardTile;
class ChessGame;

class ChessPiece : public QGraphicsPixmapItem {
protected:
  bool kingIsSafe(ChessBoardTile *);
  bool _kingFound = false;
  ChessBoardTile *_currentTile;
  ChessGame &_currentGame;
  ChessPieceSide _side;
  bool _isPlaced;
  QList<ChessBoardTile *> _location;
  bool _hasMoved = false;
  bool _firstMove = false;
  int _moveLen = 0;

public:
  ChessPiece(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent = 0);

  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void setCurrentTile(ChessBoardTile *tile);

  ChessBoardTile *getCurrentTile();

  inline const ChessPieceSide &side() const { return _side; }
  inline ChessPieceSide &side() { return _side; }

  inline bool &hasMoved() { return _hasMoved; }
  inline bool &firstMove() { return _firstMove; }
  inline bool &kingFound() { return _kingFound; }
  inline int &moveLen() { return _moveLen; }
  virtual void setImage() = 0;

  virtual ChessGame &game() const { return _currentGame; }

  bool getIsPlaced();
  void setIsPlaced(bool value);

  QList<ChessBoardTile *> moveLocation();
  virtual void moves() = 0;
  void decolor();

  bool tileSetting(ChessBoardTile *tile);
};
