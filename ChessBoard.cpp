#include "ChessBoard.h"
#include "Bishop.h"
#include "ChessBoardTile.h"
#include "ChessGame.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

ChessBoard::ChessBoard(ChessGame &game) : _currentGame(game) {
  if (!_currentGame._fen || _currentGame._fen->length() == 0) {
    initPieces();
  }
}

void ChessBoard::drawBoard(const int x, const int y) {
  int shift = _currentGame.width() * 0.071;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      ChessBoardTile *tile = new ChessBoardTile(_currentGame);
      _currentGame._allTiles[i][j] = tile;
      tile->row() = i;
      tile->col() = j;
      tile->setPos(x + shift * j + _currentGame.width() * 0.032, y + shift * i);
      if ((i + j) % 2 == 0) {

        tile->setColor({255, 206, 158});
        tile->getColor() = {255, 206, 158};
      } else {

        tile->setColor({209, 139, 71});
        tile->getColor() = {209, 139, 71};
      }
      _currentGame.addToScene(tile);
    }
    QGraphicsTextItem *number = new QGraphicsTextItem();
    number->setPos(_currentGame.width() * 0.2 + _currentGame.width() * 0.012,
                   50 + i * shift);
    number->setZValue(1);
    number->setDefaultTextColor(Qt::white);
    number->setFont(QFont("", 8));
    number->setPlainText(QString::number(8 - i));
    _currentGame.addToScene(number);

    number = new QGraphicsTextItem();
    number->setPos(_currentGame.width() * 0.185 + i * shift + shift,
                   50 + 7.8 * shift);
    number->setZValue(1);
    number->setDefaultTextColor(Qt::white);
    number->setFont(QFont("", 8));
    number->setPlainText(QChar('A' + i));
    _currentGame.addToScene(number);
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
  if (!_currentGame._fen || _currentGame._fen->length() == 0) {
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
  } else {
    if (_currentGame._fen->length() > 1)
      _currentGame.gameRunning() = false;
    int shift = 0;
    QStringList data =
        _currentGame._fen->at(_currentGame._currentLayer).split(" ");
    QString position = data.at(0);
    if (data.at(1) == "b") {
      _currentGame.turn() = BLACK;
      _currentGame._turnDisplay->setPlainText("Turn : BLACK");
    } else {
      _currentGame.turn() = WHITE;
      _currentGame._turnDisplay->setPlainText("Turn : WHITE");
    }
    _currentGame.changeTurn();
    _currentGame._halfMovesCounter = data.at(4).toInt();
    _currentGame._fullMovesCounter = data.at(5).toInt();
    QStringList positions = position.split("/");
    for (qsizetype i = 0; i < positions.length(); ++i) {
      for (qsizetype j = 0; j < positions.at(i).length(); ++j) {
        if (positions.at(i).at(j).isNumber()) {
          shift += positions.at(i).at(j).digitValue() - 1;
        } else {
          addPieceFromChar(i, shift + j, positions.at(i).at(j));
        }
      }
      shift = 0;
    }
  }
}

void ChessBoard::addPieceFromChar(int x, int y, const QChar name) {
  ChessPiece *piece = nullptr;
  ChessPieceSide side = name.isUpper() ? WHITE : BLACK;
  QChar _lowercaseName = name.toLower();
  if (_lowercaseName == 'p') {
    piece = new Pawn(side, _currentGame);
  }
  if (_lowercaseName == 'k') {
    piece = new King(side, _currentGame);
  }
  if (_lowercaseName == 'n') {
    piece = new Knight(side, _currentGame);
  }
  if (_lowercaseName == 'b') {
    piece = new Bishop(side, _currentGame);
  }
  if (_lowercaseName == 'q') {
    piece = new Queen(side, _currentGame);
  }
  if (_lowercaseName == 'r') {
    piece = new Rook(side, _currentGame);
  }
  if (piece) {
    _allPieces.append(piece);
    ChessBoardTile *tile = _currentGame._allTiles[x][y];
    tile->placePiece(piece);
    _currentGame._playablePieces.append(piece);
    _currentGame.addToScene(piece);
  }
}

void ChessBoard::reset() {
  for (qsizetype i = 0; i < _allPieces.length(); ++i) {
    _currentGame.removeFromScene(_allPieces.at(i));
    delete _allPieces.at(i);
  }
  _allPieces.clear();
}
