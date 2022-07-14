#ifndef OPENINGSCHOOSEWINDOW_H
#define OPENINGSCHOOSEWINDOW_H

#include <QDialog>

namespace Ui {
class OpeningsChooseWindow;
}

class OpeningsChooseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OpeningsChooseWindow(QWidget *parent = nullptr);
    ~OpeningsChooseWindow();

private slots:
    void on_pirc_def_button_clicked();

    void on_caro_kann_button_clicked();

    void on_italian_game_button_clicked();

private:
    Ui::OpeningsChooseWindow *ui;
};

#endif // OPENINGSCHOOSEWINDOW_H
