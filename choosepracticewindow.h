#ifndef CHOOSEPRACTICEWINDOW_H
#define CHOOSEPRACTICEWINDOW_H

#include <QDialog>

namespace Ui {
class ChoosePracticeWindow;
}

class ChoosePracticeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChoosePracticeWindow(QWidget *parent = nullptr);
    ~ChoosePracticeWindow();

private slots:
    void on_first_task_clicked();

    void on_second_task_clicked();

    void on_third_task_clicked();

    void on_fourth_task_clicked();

    void on_fifth_task_clicked();

    void on_sixth_task_clicked();

private:
    Ui::ChoosePracticeWindow *ui;
};

#endif // CHOOSEPRACTICEWINDOW_H
