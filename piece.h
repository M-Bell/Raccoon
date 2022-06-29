#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <QLabel>

enum pieceName {pawn, knight, bishop, rook, queen, king};

class Piece
{
private:
    const char *pieceChars[12] = {"♟","♞","♝","♜","♛","♚","♙","♘","♗","♖","♕","♔"};
public:
    Piece();
    Piece(int color, pieceName name, int x, int y);
    int color; // 0 - black, 1 - white
    pieceName name;
    std::string pieceImg;
    int x, y; // 0-7 board position
    QLabel *label;

    void draw();
    void setLabel(QLabel *label);
};

#endif // PIECE_H
