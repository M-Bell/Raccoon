#ifndef TUTORIALWINDOW_H
#define TUTORIALWINDOW_H
#include "mainwindow.h"

#include <QDialog>

namespace Ui {
class TutorialWindow;
}

class TutorialWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TutorialWindow(MainWindow *parent = nullptr);
    ~TutorialWindow();

private slots:
    void on_backToMenuBtn_clicked();

private:
    Ui::TutorialWindow *ui;
    QWidget *parent;
};

#endif // TUTORIALWINDOW_H
