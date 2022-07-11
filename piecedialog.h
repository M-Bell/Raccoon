#ifndef PIECEDIALOG_H
#define PIECEDIALOG_H

#include "ChessPiece.h"
#include "ChessPieceSide.h"
#include <QDialog>

namespace Ui {
class PieceDialog;
}

class PieceDialog : public QDialog {
  Q_OBJECT

public:
  explicit PieceDialog(ChessPiece *, QWidget *parent = nullptr);
  ~PieceDialog();

  static ChessPiece *getPiece(ChessPiece *, QWidget *parent = nullptr,
                              const QString &title = QString());

private slots:
  void on_queen_button_clicked();

  void on_rook_button_clicked();

  void on_bishop_button_clicked();

  void on_knight_button_clicked();

private:
  Ui::PieceDialog *ui;
  static ChessPiece *_selectedPiece;
  ChessPiece *_current;
};

#endif // PIECEDIALOG_H
