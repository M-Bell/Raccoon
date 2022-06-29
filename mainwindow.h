#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int WINDOW_W;
    int WINDOW_H;
private slots:
    void on_exitBtn_clicked();

    void on_playBtn_clicked();

    void on_tutorialBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
