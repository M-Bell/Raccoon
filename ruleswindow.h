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

private:
    Ui::RulesWindow *ui;
};

#endif // RULESWINDOW_H
