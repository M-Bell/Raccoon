#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include "piece.h"
#include "mainwindow.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    Piece whitePieces[16];
    Piece blackPieces[16];
    QLabel *cells[8][8];
    int BOARD_SIZE;
    int BOARD_X;
    int BOARD_Y;
    int CELL_SIZE;
    int FONT_SIZE;
    explicit GameWindow(MainWindow *parent = nullptr);
    ~GameWindow();

    void draw();

private slots:
    void on_backToMenuBtn_clicked();

private:
    Ui::GameWindow *ui;
    QWidget *parent;
};

#endif // GAMEWINDOW_H
