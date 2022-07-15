#ifndef RULESWINDOW_H
#define RULESWINDOW_H

#include <QDialog>

namespace Ui {
class RulesWindow;
}

class RulesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RulesWindow(QWidget *parent = nullptr);
    ~RulesWindow();

private slots:
    void on_forward_clicked();

    void on_back_clicked();

private:
    Ui::RulesWindow *ui;
    QList<QString> descriptions; // for each n-th image there is it's own path to it's file with description
    int currentPage = 0;

    void init();
};

#endif // RULESWINDOW_H
