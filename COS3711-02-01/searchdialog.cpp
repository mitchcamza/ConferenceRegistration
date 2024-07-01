#include "searchdialog.h"

#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

SearchDialog::SearchDialog(QDialog *parent)
    : QDialog{parent},
    lineEditName(new QLineEdit()),
    pushButtonSearch(new QPushButton("Search")),
    pushButtonCancel(new QPushButton("Cancel"))

{
    setWindowTitle("Search for Applicant");
    setupUI();
}

SearchDialog::~SearchDialog()
{

}

void SearchDialog::setupUI()
{
    // Add a grid layout
    QGridLayout *gridLayout = new QGridLayout();
    setLayout(gridLayout);

    // Add additional widgets
    QLabel *labelName = new QLabel("Name: ");

    // Add widgets to the grid layout
    gridLayout->addWidget(labelName, 0, 0);
    gridLayout->addWidget(lineEditName, 0, 1);
    gridLayout->addWidget(pushButtonSearch, 1, 0, 1, 2);
    gridLayout->addWidget(pushButtonCancel, 2, 0, 1, 2);
}


