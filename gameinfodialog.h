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

private:
    Ui::GameInfoDialog *ui;
};

#endif // GAMEINFODIALOG_H
