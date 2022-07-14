#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"
#include "tutorialwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap menuIcon(":/res/images/logo.png");

    WINDOW_W = 1280;
    WINDOW_H = 720;
    int BUTTON_W = 180*1.1;
    int BUTTON_H = 60*1.1;
    int LOGO_W = 470/1.2;
    int LOGO_H = 460/1.2;

//    this->setStyleSheet("background-color:#DDDDDD;");

    this->resize(WINDOW_W,WINDOW_H);

    // Raccoon logo
    QLabel *menuLogo = new QLabel(this);
    menuLogo->resize(LOGO_W, LOGO_H);
    menuLogo->move((WINDOW_W-LOGO_W)/1.92, WINDOW_H/50);
    menuLogo->setPixmap(menuIcon.scaled(LOGO_W,LOGO_H,Qt::KeepAspectRatio));

    // Menu buttons
    QPixmap playBtnPixmap(":/res/images/playBtn.png");
    QIcon playBtnIcon(playBtnPixmap);

    QPushButton *playBtn = new QPushButton(playBtnIcon,"",this);
    playBtn->setObjectName("playBtn");
    playBtn->resize(BUTTON_W, BUTTON_H);
    playBtn->move((WINDOW_W-BUTTON_W)/2, WINDOW_H-BUTTON_H*3.9);
    playBtn->setIconSize(QSize(BUTTON_W, BUTTON_H));
    playBtn->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    connect(playBtn, SIGNAL(clicked()), this, SLOT(on_playBtn_clicked()));


    QPixmap tutorialBtnPixmap(":/res/images/tutorialBtn.png");
    QIcon tutorialBtnIcon(tutorialBtnPixmap);

    QPushButton *tutorialBtn = new QPushButton(tutorialBtnIcon,"",this);
    tutorialBtn->setObjectName("tutorialBtn");
    tutorialBtn->resize(BUTTON_W, BUTTON_H);
    tutorialBtn->move((WINDOW_W-BUTTON_W)/2, WINDOW_H-BUTTON_H*2.6);
    tutorialBtn->setIconSize(QSize(BUTTON_W, BUTTON_H));
    tutorialBtn->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    connect(tutorialBtn, SIGNAL(clicked()), this, SLOT(on_tutorialBtn_clicked()));


    QPixmap exitBtnPixmap(":/res/images/exitBtn.png");
    QIcon exitBtnIcon(exitBtnPixmap);

    QPushButton *exitBtn = new QPushButton(exitBtnIcon,"",this);
    exitBtn->setObjectName("exitBtn");
    exitBtn->resize(BUTTON_W, BUTTON_H);
    exitBtn->move((WINDOW_W-BUTTON_W)/2, WINDOW_H-BUTTON_H*1.3);
    exitBtn->setIconSize(QSize(BUTTON_W, BUTTON_H));
    exitBtn->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    connect(exitBtn, SIGNAL(clicked()), this, SLOT(on_exitBtn_clicked()));


//    int BOARD_SIZE = 520;
//    int BOARD_X = (WINDOW_W-BOARD_SIZE)/2;
//    int BOARD_Y = (WINDOW_H-BOARD_SIZE)/8;

//    QLabel *boardLbl = new QLabel(this);
//    boardLbl -> setObjectName("boardLbl");
//    boardLbl -> resize(BOARD_SIZE, BOARD_SIZE);
//    boardLbl -> move(0, 0);

//    QPixmap boardPixmap(":/res/images/board.png");
//    boardLbl->setPixmap(boardPixmap.scaled(BOARD_SIZE,BOARD_SIZE,Qt::KeepAspectRatio));
//    boardLbl->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exitBtn_clicked()
{
    exit(0);
}


void MainWindow::on_playBtn_clicked()
{
    hide();
    GameWindow *game = new GameWindow(this);
    game -> show();
}

void MainWindow::on_tutorialBtn_clicked()
{
    hide();
    TutorialWindow *tutorialWindow = new TutorialWindow(this);
    tutorialWindow->show();
}

