#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

class QLineEdit;
class QPushButton;

class SearchDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SearchDialog(QDialog *parent = nullptr);
    ~SearchDialog();

private:
    void setupUI();

private:
    QLineEdit *lineEditName;
    QPushButton *pushButtonSearch;
    QPushButton *pushButtonCancel;
};

#endif // SEARCHDIALOG_H
