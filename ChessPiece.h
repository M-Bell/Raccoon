#pragma once
#include "ChessPieceSide.h"
#include <QGraphicsPathItem>

class ChessBoardTile;
class ChessGame;

class ChessPiece : public QGraphicsPixmapItem {
protected:
  ChessBoardTile *_currentTile;
  ChessGame &_currentGame;
  ChessPieceSide _side;
  bool _isPlaced;

public:
  ChessPiece(ChessPieceSide side, ChessGame &game, QGraphicsItem *parent = 0);

  void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setCurrentTile(ChessBoardTile *tile);

    ChessBoardTile *getCurrentTile() ;

  inline const ChessPieceSide &side() const { return _side; }
  inline ChessPieceSide &side() { return _side; }
  virtual void setImage() = 0;

  bool getIsPlaced();
  void setIsPlaced(bool value);

  QList<ChessBoardTile *> moveLocation();
  virtual void moves() = 0;
  void decolor();

  bool firstMove;

  bool tileSetting(ChessBoardTile *tile);
};
