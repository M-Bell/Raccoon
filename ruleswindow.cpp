#include "ruleswindow.h"
#include "ui_ruleswindow.h"

#include <QFile>

RulesWindow::RulesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RulesWindow) {
    ui->setupUi(this);
    init();
}

RulesWindow::~RulesWindow() {
    delete ui;
}


QString read(const QString& path) {
    QFile file(path);
    file.open(QIODevice::ReadOnly | QFile::Text);
    QTextStream in(&file);
    QString text(in.readAll());
    return text;
}

void RulesWindow::init() {
    this->descriptions.append(":/rules/text/rules/intro.txt");
    this->descriptions.append(":/rules/text/rules/pawn.txt");
    this->descriptions.append(":/rules/text/rules/pawn.txt");
    this->descriptions.append(":/rules/text/rules/knight.txt");
    this->descriptions.append(":/rules/text/rules/bishop.txt");
    this->descriptions.append(":/rules/text/rules/rook.txt");
    this->descriptions.append(":/rules/text/rules/queen.txt");
    this->descriptions.append(":/rules/text/rules/king.txt");
    this->ui->description->setText(read(this->descriptions.at(currentPage)));
    this->ui->image->setPixmap(QPixmap(":/rules/images/rules/0.bmp"));
}




void RulesWindow::on_forward_clicked() {
    if (currentPage < this->descriptions.size() - 1) {
        ++currentPage;
        this->ui->description->setText(read(this->descriptions.at(currentPage)));
        this->ui->image->setPixmap(QPixmap(":/rules/images/rules/" + QString::number(currentPage) + ".bmp"));

    }
}


void RulesWindow::on_back_clicked()
{
    if (currentPage > 0) {
        --currentPage;
        this->ui->description->setText(read(this->descriptions.at(currentPage)));
        this->ui->image->setPixmap(QPixmap(":/rules/images/rules/" + QString::number(currentPage) + ".bmp"));

    }
}

