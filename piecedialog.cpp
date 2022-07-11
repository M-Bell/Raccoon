#include "piecedialog.h"
#include "Bishop.h"
#include "ChessGame.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"
#include "ui_piecedialog.h"

ChessPiece *PieceDialog::_selectedPiece = nullptr;

PieceDialog::PieceDialog(ChessPiece *init, QWidget *parent)
    : QDialog(parent), ui(new Ui::PieceDialog), _current(init) {
  ui->setupUi(this);
  setModal(false);
  switch (_current->side()) {
  case WHITE:
    ui->queen_button->setIcon(
        QIcon(":/res/images/chess_piece_queen_white.png"));
    ui->rook_button->setIcon(QIcon(":/res/images/chess_piece_rook_white.png"));
    ui->bishop_button->setIcon(
        QIcon(":/res/images/chess_piece_bishop_white.png"));
    ui->knight_button->setIcon(
        QIcon(":/res/images/chess_piece_knight_white.png"));
    break;
  case BLACK:
    ui->queen_button->setIcon(QIcon(":/res/images/chess_piece_queen.png"));
    ui->rook_button->setIcon(QIcon(":/res/images/chess_piece_rook.png"));
    ui->bishop_button->setIcon(QIcon(":/res/images/chess_piece_bishop.png"));
    ui->knight_button->setIcon(QIcon(":/res/images/chess_piece_knight.png"));
    break;
  }
}

ChessPiece *PieceDialog::getPiece(ChessPiece *initial, QWidget *parent,
                                  const QString &title) {
  PieceDialog dlg(initial, parent);
  if (!title.isEmpty())
    dlg.setWindowTitle(title);
  dlg.exec();
  return _selectedPiece;
}

PieceDialog::~PieceDialog() { delete ui; }

void PieceDialog::on_queen_button_clicked() {
  _selectedPiece = new Queen(_current->side(), _current->game());
  this->hide();
}

void PieceDialog::on_rook_button_clicked() {
  _selectedPiece = new Rook(_current->side(), _current->game());
  this->hide();
}

void PieceDialog::on_bishop_button_clicked() {
  _selectedPiece = new Bishop(_current->side(), _current->game());
  this->hide();

}

void PieceDialog::on_knight_button_clicked() {
  _selectedPiece = new Knight(_current->side(), _current->game());
  this->hide();
}
