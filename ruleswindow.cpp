#include "ruleswindow.h"
#include "ui_ruleswindow.h"

RulesWindow::RulesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RulesWindow)
{
    ui->setupUi(this);
}

RulesWindow::~RulesWindow()
{
    delete ui;
}
