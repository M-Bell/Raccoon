#ifndef GAMEINFODIALOG_H
#define GAMEINFODIALOG_H

#include <QDialog>

namespace Ui {
class GameInfoDialog;
}

class GameInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameInfoDialog(QString sourceFile, QWidget *parent = nullptr);
    ~GameInfoDialog();


private slots:
    void on_backToMenuBtn_clicked();

private:
    Ui::GameInfoDialog *ui;
    QWidget *parent;
};

#endif // GAMEINFODIALOG_H
