#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPixmap>
#include <QFont>
#include <QPushButton>
#include <iostream>

GameWindow::GameWindow(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    this->parent = parent;
    ui->setupUi(this);

    this->resize(parent->WINDOW_W,parent->WINDOW_H);

    BOARD_SIZE = 520;
    BOARD_X = (parent->WINDOW_W-BOARD_SIZE)/2;
    BOARD_Y = (parent->WINDOW_H-BOARD_SIZE)/8;
    CELL_SIZE = BOARD_SIZE/8;
    FONT_SIZE = BOARD_SIZE/8;
    int BUTTON_W = 180*1.1;
    int BUTTON_H = 60*1.1;

//    this->setStyleSheet("background-color:rgba(76, 175, 80, 0.0);");

    QPixmap backToMenuBtnPixmap(":/res/images/backToMenuBtn.png");
    QIcon backToMenuBtnIcon(backToMenuBtnPixmap);

    QPushButton *backToMenuBtn = new QPushButton(backToMenuBtnIcon,"",this);
    backToMenuBtn->setObjectName("backToMenuBtn");
    backToMenuBtn->resize(BUTTON_W, BUTTON_H);
    backToMenuBtn->move((parent->WINDOW_W-BUTTON_W)/2, parent->WINDOW_H-BUTTON_H*1.8);
    backToMenuBtn->setIconSize(QSize(BUTTON_W, BUTTON_H));
    backToMenuBtn->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    connect(backToMenuBtn, SIGNAL(clicked()), this, SLOT(on_backToMenuBtn_clicked()));
    backToMenuBtn->show();

    QLabel *boardLbl = new QLabel(this);
    boardLbl -> setObjectName("boardLbl");
    boardLbl -> resize(BOARD_SIZE, BOARD_SIZE);
    boardLbl -> move(BOARD_X, BOARD_Y);

    QPixmap boardPixmap(":/res/images/board.png");
    boardLbl->setPixmap(boardPixmap.scaled(BOARD_SIZE,BOARD_SIZE,Qt::KeepAspectRatio));
    boardLbl->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    boardLbl->show();

//    QPixmap boardPixmap(":/res/images/board.png");
//    QIcon boardIcon(boardPixmap);

//    QPushButton *board = new QPushButton(boardIcon,"",this);
//    board->setObjectName("board");
//    std::cout << BOARD_Y << std::endl;
//    board->resize(BOARD_SIZE, BOARD_SIZE);
//    board->move(100, 50);
//    board->setIconSize(QSize(BOARD_SIZE, BOARD_SIZE));
//    board->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
//    board->show();

    // Initialize starting board
    QFont pieceFont = QFont();
    pieceFont.setPixelSize(FONT_SIZE);

    for (int i{0}; i<8;i++){
        for (int j{0}; j<8;j++){
            QLabel *label = new QLabel(this);

            label->setFont(pieceFont);
            label->setGeometry(QRect(BOARD_X+CELL_SIZE*i,BOARD_Y+CELL_SIZE*j,CELL_SIZE,CELL_SIZE));
            label->setStyleSheet("background-color:rgba(255, 255, 255, 0.0);");
            label->show();

            cells[i][j] = label;
        }
    }
    // White
    for (int i{0}; i<8;i++){
        whitePieces[i]=Piece(1,pawn,i,1);
    }

    whitePieces[8] = Piece(1, knight, 1,0);
    whitePieces[9] = Piece(1, knight, 6,0);

    whitePieces[10] = Piece(1, bishop, 2,0);
    whitePieces[11] = Piece(1, bishop, 5,0);


    whitePieces[12] = Piece(1, rook, 0,0);
    whitePieces[13] = Piece(1, rook, 7,0);


    whitePieces[14] = Piece(1, queen, 3,0);
    whitePieces[15] = Piece(1, king, 4,0);

    // Black
    for (int i{0}; i < 8;i++){
        blackPieces[i]=Piece(0, pawn, i, 6);
    }

    blackPieces[8] = Piece(0, knight, 1, 7);
    blackPieces[9] = Piece(0, knight, 6, 7);

    blackPieces[10] = Piece(0, bishop, 2, 7);
    blackPieces[11] = Piece(0, bishop, 5, 7);

    blackPieces[12] = Piece(0, rook, 0, 7);
    blackPieces[13] = Piece(0, rook, 7, 7);

    blackPieces[14] = Piece(0, queen, 4, 7);
    blackPieces[15] = Piece(0, king, 3, 7);

    draw();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_backToMenuBtn_clicked()
{
    parent->show();
    hide();
}


void GameWindow::draw()
{

    for (int i=0; i<16;i++){
        Piece piece = whitePieces[i];
        QLabel *label = cells[piece.x][7-piece.y];
        label -> setText(piece.pieceImg.c_str());

        piece.setLabel(label);
    }

    for (int i=0; i<16;i++){
        Piece piece = blackPieces[i];

        QLabel *label = cells[piece.x][7-piece.y];
        label -> setText(piece.pieceImg.c_str());

        piece.setLabel(label);
    }
}

