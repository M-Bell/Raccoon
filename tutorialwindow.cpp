#include "tutorialwindow.h"
#include "endgameschoosewindow.h"
#include "mainwindow.h"
#include "openingschoosewindow.h"
#include "ui_tutorialwindow.h"
#include "ruleswindow.h"
#include <QFont>
#include <QPixmap>
#include <QPushButton>

TutorialWindow::TutorialWindow(MainWindow *parent)
    : QDialog(parent), ui(new Ui::TutorialWindow) {
  this->parent = parent;
  ui->setupUi(this);

  int WINDOW_W = 1280;
  int WINDOW_H = 720;
  int BUTTON_W = 180 * 1.1;
  int BUTTON_H = 60 * 1.1;
  int BAR_W = 1100;
  int BAR_H = 90;

  //    this->setStyleSheet("background-color:#DDDDDD;");

  this->resize(WINDOW_W, WINDOW_H);

  QPixmap backToMenuBtnPixmap(":/res/images/backToMenuBtn.png");
  QIcon backToMenuBtnIcon(backToMenuBtnPixmap);

  QPushButton *backToMenuBtn = new QPushButton(backToMenuBtnIcon, "", this);
  backToMenuBtn->setObjectName("backToMenuBtn");
  backToMenuBtn->resize(BUTTON_W, BUTTON_H);
  backToMenuBtn->move((parent->WINDOW_W - BUTTON_W) / 2,
                      parent->WINDOW_H - BUTTON_H * 1.8);
  backToMenuBtn->setIconSize(QSize(BUTTON_W, BUTTON_H));
  backToMenuBtn->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
  connect(backToMenuBtn, SIGNAL(clicked()), this,
          SLOT(on_backToMenuBtn_clicked()));
  backToMenuBtn->show();

  // Option bars
  QPixmap tutorialBarRulesPixmap(":/res/images/tutorialBarRules.png");
  QIcon tutorialBarRulesIcon(tutorialBarRulesPixmap);

  QPushButton *tutorialBarRulesBtn =
      new QPushButton(tutorialBarRulesIcon, "", this);
  tutorialBarRulesBtn->setObjectName("tutorialBarRulesBtn");
  tutorialBarRulesBtn->resize(BAR_W, BAR_H);
  tutorialBarRulesBtn->move((parent->WINDOW_W - BAR_W) / 2, 20 * 1 + BAR_H * 0);
  tutorialBarRulesBtn->setIconSize(QSize(BAR_W, BAR_H));
  tutorialBarRulesBtn->setStyleSheet(
      "background-color: rgba(255, 255, 255, 0);");
  connect(tutorialBarRulesBtn, SIGNAL(clicked()), this,
          SLOT(on_tutorialBarRulesBtn_clicked()));
  tutorialBarRulesBtn->show();

  QPixmap tutorialBarOpeningsPixmap(":/res/images/tutorialBarOpenings.png");
  QIcon tutorialBarOpeningsIcon(tutorialBarOpeningsPixmap);

  QPushButton *tutorialBarOpeningsBtn =
      new QPushButton(tutorialBarOpeningsIcon, "", this);
  tutorialBarOpeningsBtn->setObjectName("tutorialBarOpeningsBtn");
  tutorialBarOpeningsBtn->resize(BAR_W, BAR_H);
  tutorialBarOpeningsBtn->move((parent->WINDOW_W - BAR_W) / 2,
                               20 * 2 + BAR_H * 1);
  tutorialBarOpeningsBtn->setIconSize(QSize(BAR_W, BAR_H));
  tutorialBarOpeningsBtn->setStyleSheet(
      "background-color: rgba(255, 255, 255, 0);");
  connect(tutorialBarOpeningsBtn, SIGNAL(clicked()), this,
          SLOT(on_tutorialBarOpeningsBtn_clicked()));
  tutorialBarOpeningsBtn->show();

  QPixmap tutorialBarEndgamesPixmap(":/res/images/tutorialBarEndgames.png");
  QIcon tutorialBarEndgamesIcon(tutorialBarEndgamesPixmap);

  QPushButton *tutorialBarEndgamesBtn =
      new QPushButton(tutorialBarEndgamesIcon, "", this);
  tutorialBarEndgamesBtn->setObjectName("tutorialBarEndgamesBtn");
  tutorialBarEndgamesBtn->resize(BAR_W, BAR_H);
  tutorialBarEndgamesBtn->move((parent->WINDOW_W - BAR_W) / 2,
                               20 * 3 + BAR_H * 2);
  tutorialBarEndgamesBtn->setIconSize(QSize(BAR_W, BAR_H));
  tutorialBarEndgamesBtn->setStyleSheet(
      "background-color: rgba(255, 255, 255, 0);");
  connect(tutorialBarEndgamesBtn, SIGNAL(clicked()), this,
          SLOT(on_tutorialBarEndgamesBtn_clicked()));
  tutorialBarEndgamesBtn->show();

  QPixmap tutorialBarPracticePixmap(":/res/images/tutorialBarPractice.png");
  QIcon tutorialBarPracticeIcon(tutorialBarPracticePixmap);

  QPushButton *tutorialBarPracticeBtn =
      new QPushButton(tutorialBarPracticeIcon, "", this);
  tutorialBarPracticeBtn->setObjectName("tutorialBarPracticeBtn");
  tutorialBarPracticeBtn->resize(BAR_W, BAR_H);
  tutorialBarPracticeBtn->move((parent->WINDOW_W - BAR_W) / 2,
                               20 * 4 + BAR_H * 3);
  tutorialBarPracticeBtn->setIconSize(QSize(BAR_W, BAR_H));
  tutorialBarPracticeBtn->setStyleSheet(
      "background-color: rgba(255, 255, 255, 0);");
  //    connect(tutorialBarPracticeBtn, SIGNAL(clicked()), this,
  //    SLOT(on_tutorialBarPracticeBtn_clicked()));
  tutorialBarPracticeBtn->show();

  QPixmap tutorialBarAnalysisPixmap(":/res/images/tutorialBarAnalysis.png");
  QIcon tutorialBarAnalysisIcon(tutorialBarAnalysisPixmap);

  QPushButton *tutorialBarAnalysisBtn =
      new QPushButton(tutorialBarAnalysisIcon, "", this);
  tutorialBarAnalysisBtn->setObjectName("tutorialBarAnalysisBtn");
  tutorialBarAnalysisBtn->resize(BAR_W, BAR_H);
  tutorialBarAnalysisBtn->move((parent->WINDOW_W - BAR_W) / 2,
                               20 * 5 + BAR_H * 4);
  tutorialBarAnalysisBtn->setIconSize(QSize(BAR_W, BAR_H));
  tutorialBarAnalysisBtn->setStyleSheet(
      "background-color: rgba(255, 255, 255, 0);");
  //    connect(tutorialBarAnalysisBtn, SIGNAL(clicked()), this,
  //    SLOT(on_tutorialBarAnalysisBtn_clicked()));
  tutorialBarAnalysisBtn->show();
}

TutorialWindow::~TutorialWindow() { delete ui; }

void TutorialWindow::on_backToMenuBtn_clicked() {
  parent->show();
  hide();
}

void TutorialWindow::on_tutorialBarRulesBtn_clicked() {
    RulesWindow rulesWindow;
    rulesWindow.exec();
    rulesWindow.show();
}

void TutorialWindow::on_tutorialBarOpeningsBtn_clicked() {
  OpeningsChooseWindow win(this);
  win.exec();
  win.show();
}

void TutorialWindow::on_tutorialBarEndgamesBtn_clicked() {
  EndgamesChooseWindow win(this);
  win.exec();
  win.show();
}
