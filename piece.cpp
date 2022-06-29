#include "piece.h"
#include <QLabel>

Piece::Piece()
{
    color = 0;
    name = pawn;
    x = 0;
    y = 0;
    QLabel label;
}


Piece::Piece(int color, pieceName name, int x, int y)
{
    this -> color = color;
    this -> name = name;
    this -> x = x;
    this -> y = y;
    this -> pieceImg = this -> pieceChars[name+6*color];
}


void Piece::setLabel(QLabel *label)
{
    this -> label = label;
};
