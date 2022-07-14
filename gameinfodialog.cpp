#include "gameinfodialog.h"
#include "ui_gameinfodialog.h"
#include <QFile>
#include <QTextStream>

GameInfoDialog::GameInfoDialog(QString source, QWidget *parent)
    : QDialog(parent), ui(new Ui::GameInfoDialog) {
  ui->setupUi(this);
  QFile file(source);
  if (!file.open(QIODevice::ReadOnly)) {
    qDebug() << "error: " << file.errorString();
  }
  QTextStream in(&file);
  QString line;
  while (!in.atEnd()) {
    line.append(in.readLine());
  }
  ui->textEdit->setPlainText(line);
  file.close();
}

GameInfoDialog::~GameInfoDialog() { delete ui; }
