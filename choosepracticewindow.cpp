#include "choosepracticewindow.h"
#include "gamewindow.h"
#include "ui_choosepracticewindow.h"

ChoosePracticeWindow::ChoosePracticeWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::ChoosePracticeWindow) {
  ui->setupUi(this);
}

ChoosePracticeWindow::~ChoosePracticeWindow() { delete ui; }

void ChoosePracticeWindow::on_first_task_clicked() {
  GameWindow win(true, new QString(":/res/text/one_move_checkmate_1.txt"),
                 (QWidget *)QDialog::parent());
  win.exec();
}

void ChoosePracticeWindow::on_second_task_clicked()
{
    GameWindow win(true, new QString(":/res/text/one_move_checkmate_2.txt"),
                   (QWidget *)QDialog::parent());
    win.exec();
}


void ChoosePracticeWindow::on_third_task_clicked()
{
    GameWindow win(true, new QString(":/res/text/one_move_checkmate_3.txt"),
                   (QWidget *)QDialog::parent());
    win.exec();
}


void ChoosePracticeWindow::on_fourth_task_clicked()
{
    GameWindow win(true, new QString(":/res/text/one_move_checkmate_4.txt"),
                   (QWidget *)QDialog::parent());
    win.exec();
}


void ChoosePracticeWindow::on_fifth_task_clicked()
{
    GameWindow win(true, new QString(":/res/text/one_move_checkmate_5.txt"),
                   (QWidget *)QDialog::parent());
    win.exec();
}


void ChoosePracticeWindow::on_sixth_task_clicked()
{
    GameWindow win(true, new QString(":/res/text/one_move_checkmate_6.txt"),
                   (QWidget *)QDialog::parent());
    win.exec();
}

