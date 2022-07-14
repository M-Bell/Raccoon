#include "tutorialpage.h"
#include "ui_tutorialpage.h"

TutorialPage::TutorialPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TutorialPage)
{
    ui->setupUi(this);
}

TutorialPage::~TutorialPage()
{
    delete ui;
}
