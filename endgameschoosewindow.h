#ifndef ENDGAMESCHOOSEWINDOW_H
#define ENDGAMESCHOOSEWINDOW_H

#include <QDialog>

namespace Ui {
class EndgamesChooseWindow;
}

class EndgamesChooseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EndgamesChooseWindow(QWidget *parent = nullptr);
    ~EndgamesChooseWindow();

private slots:
    void on_queen_king_endgame_clicked();

    void on_pushButton_clicked();

    void on_rook_king_endgame_clicked();

private:
    Ui::EndgamesChooseWindow *ui;
};

#endif // ENDGAMESCHOOSEWINDOW_H
