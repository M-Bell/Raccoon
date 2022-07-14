#pragma once
#include "ChessBoard.h"
#include "ChessBoardTile.h"
#include "ChessPiece.h"
#include <QGraphicsScene>
#include <QGraphicsView>
class ChessGame : public QGraphicsScene {
  Q_OBJECT
public:
  // Constructors
  ChessGame(const bool hasBot, QString *fen = nullptr);

  // public Methods
  void drawDeadHolder(int x, int y, QColor color);
  void drawChessBoard();
  void displayDeadWhite();
  void displayDeadBlack();
  void placeInDeadPlace(ChessPiece *piece);

  // Scene Related
  void addToScene(QGraphicsItem *item);
  void removeFromScene(QGraphicsItem *item);

  // getters/setters
  ChessPiece *pieceToMove;

  inline const ChessPieceSide &turn() const { return _turn; }
  inline ChessPieceSide &turn() { return _turn; }

  inline bool &gameRunning() { return _gameRunning; }

  void changeTurn();
  void showMessage(char *);

  ChessBoardTile *_allTiles[8][8];
  QGraphicsTextItem *_check;
  QList<ChessPiece *> _playablePieces;
  ChessBoardTile *_enPassantTile = nullptr;

  QString generateFEN();

  int _halfMovesCounter = 0;
  int _fullMovesCounter = 0;
  bool _hasBot;

  void displayMainMenu();

  void gameOver();
  void removeAll();

  inline int width() const { return SCENE_WIDTH; }
  inline int height() const { return SCENE_HEIGHT; }

  QString *_fen;
public slots:
  void start();

private:
  QList<ChessPiece *> _whiteDead;
  QList<ChessPiece *> _blackDead;
  QGraphicsRectItem *_deadHolder;
  ChessPieceSide _turn;
  ChessBoard *_chessBoard;
  QList<QGraphicsItem *> _listG;
  QGraphicsTextItem *_turnDisplay;
  bool _gameRunning;

  char getPieceChar(ChessPiece *);
  QString getTileName(const int row, const int col);

  static int SCENE_WIDTH;
  static int SCENE_HEIGHT;
};
