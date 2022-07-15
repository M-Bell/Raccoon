#include "gameinfodialog.h"
#include "ui_gameinfodialog.h"
#include <QFile>
#include <QTextStream>

GameInfoDialog::GameInfoDialog(QString source, QWidget *parent)
    : QDialog(parent), ui(new Ui::GameInfoDialog) {
  this->parent = parent;
  ui->setupUi(this);

  int WINDOW_W = 640;
  int WINDOW_H = 420;
  int BUTTON_W = 180 * 1.1;
  int BUTTON_H = 60 * 1.1;

  this->resize(WINDOW_W, WINDOW_H);

  QPushButton *backToMenuBtn = ui -> backBtn;

  QPixmap backToMenuBtnPixmap(":/res/images/okBtn.png");
  QIcon backToMenuBtnIcon(backToMenuBtnPixmap);
  backToMenuBtn->setIcon(backToMenuBtnIcon);
  backToMenuBtn->resize(BUTTON_W, BUTTON_H);
  backToMenuBtn->setIconSize(QSize(BUTTON_W, BUTTON_H));
  backToMenuBtn->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
  connect(backToMenuBtn, SIGNAL(clicked()), this,
          SLOT(on_backToMenuBtn_clicked()));
  backToMenuBtn->show();

  QFile file(source);
  if (!file.open(QIODevice::ReadOnly)) {
    qDebug() << "error: " << file.errorString();
  }
  QTextStream in(&file);
  QString line;
  while (!in.atEnd()) {
    line.append(in.readLine());
  }
  ui->textEdit->setText(line);
  file.close();
}

GameInfoDialog::~GameInfoDialog() { delete ui; }

void GameInfoDialog::on_backToMenuBtn_clicked() {
  parent->show();
  hide();
}
