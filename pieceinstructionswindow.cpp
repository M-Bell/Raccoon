#include "pieceinstructionswindow.h"
#include "ui_pieceinstructionswindow.h"

PieceInstructionsWindow::PieceInstructionsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PieceInstructionsWindow)
{
    ui->setupUi(this);
}

PieceInstructionsWindow::~PieceInstructionsWindow()
{
    delete ui;
}
