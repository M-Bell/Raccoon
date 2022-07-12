#ifndef PIECEINSTRUCTIONSWINDOW_H
#define PIECEINSTRUCTIONSWINDOW_H

#include <QDialog>

namespace Ui {
class PieceInstructionsWindow;
}

class PieceInstructionsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PieceInstructionsWindow(QWidget *parent = nullptr);
    ~PieceInstructionsWindow();

private:
    Ui::PieceInstructionsWindow *ui;
};

#endif // PIECEINSTRUCTIONSWINDOW_H
