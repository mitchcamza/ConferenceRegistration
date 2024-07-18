/**
 * @file mainwindow.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell 2024
 */


#include "mainwindow.h"
#include "newregistrationdialog.h"
#include "registrationfilterproxymodel.h"
#include "registrationlist.h"
#include "registrationmodel.h"
#include "totalfeesdialog.h"
#include "totalregistereddialog.h"
#include "registrationlistwriter.h"
#include "registration.h"

#include <QGridLayout>
#include <QHeaderView>
#include <QIcon>
#include <QLineEdit>
#include <QMenuBar>
#include <QPushButton>
#include <QStandardItem>
#include <QStatusBar>
#include <QTableView>
#include <QToolBar>
#include <QFileDialog>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    registrationModel(new RegistrationModel(this)),
    registrationList(new RegistrationList(*registrationModel)),
    tableViewRegistrations(new QTableView(this)),
    actionAddAttendee(new QAction(QIcon(":/icons/add"), tr("New Registration"), this)),
    actionExportRegistrationList(new QAction(QIcon(":/icons/export"), tr("Export Registration List"), this)),
    actionSearchAttendee(new QAction(QIcon(":/icons/search"), tr("Search"), this)),
    actionGetTotalFees(new QAction(QIcon(":/icons/fees"), tr("Total Fees"), this)),
    actionGetNumberOfAttendeesForAffiliation(new QAction(QIcon(":/icons/affiliation"), tr("Registration per Affiliation"), this)),
    actionClose(new QAction(QIcon(":/icons/close"), tr("&Close"), this)),
    lineEditSearch(new QLineEdit(this)),
    pushButtonClear(new QPushButton("Clear Filter", this)),
    proxyModel(new RegistrationFilterProxyModel(this))
{
    // Connect signals and slots
    connect(actionAddAttendee, &QAction::triggered, this, &MainWindow::on_actionAddAttendee_triggered);
    connect(actionExportRegistrationList, &QAction::triggered, this, &MainWindow::on_actionExportRegistrationList_triggered);
    connect(actionGetTotalFees, &QAction::triggered, this, &MainWindow::on_actionGetTotalFees_triggered);
    connect(actionGetNumberOfAttendeesForAffiliation, &QAction::triggered, this, &MainWindow::on_actionGetNumberOfAttendeesFromAffiliation_triggered);
    connect(actionClose, &QAction::triggered, this, &MainWindow::close);
    connect(pushButtonClear, &QPushButton::clicked, this, &MainWindow::on_actionClearFilter_triggered);
    connect(lineEditSearch, &QLineEdit::textEdited, proxyModel, &RegistrationFilterProxyModel::setFilterText);

    // Set up the user interface
    setupUI(this);
}


MainWindow::~MainWindow()
{

}


void MainWindow::setupUI(QMainWindow *mainApplicationWindow)
{
    // Main Application window
    setWindowTitle("Conference Registration");
    mainApplicationWindow->resize(1000, 600);

    // Menubar
    menuBar = new QMenuBar(mainApplicationWindow);
    menuBar->setGeometry(QRect(0, 0, 800, 24));
    mainApplicationWindow->setMenuBar(menuBar);

    // File Menu
    QMenu *fileMenu = menuBar->addMenu(tr("&File"));
    fileMenu->addAction(actionExportRegistrationList);
    actionExportRegistrationList->setToolTip("Exports current registration list to file.");
    fileMenu->addSeparator();
    fileMenu->addAction(actionClose);

    // Edit Menu
    QMenu *editMenu = menuBar->addMenu(tr("&Edit"));
    editMenu->addAction(actionAddAttendee);

    // Reports Menu
    QMenu *reportsMenu = menuBar->addMenu(tr("&Reports"));
    reportsMenu->addAction(actionGetTotalFees);
    reportsMenu->addAction(actionGetNumberOfAttendeesForAffiliation);

    // Help Menu
    QMenu *helpMenu = menuBar->addMenu(tr("&Help"));

    // Statusbar
    statusBar = new QStatusBar(mainApplicationWindow);
    setStatusBar(statusBar);

    // Toolbar
    toolBar = new QToolBar(mainApplicationWindow);
    mainApplicationWindow->addToolBar(Qt::TopToolBarArea, toolBar);
    toolBar->addAction(actionAddAttendee);
    toolBar->addSeparator();
    toolBar->addAction(actionExportRegistrationList);
    toolBar->addSeparator();
    toolBar->addAction(actionGetTotalFees);
    toolBar->addAction(actionGetNumberOfAttendeesForAffiliation);

    // Central widget and layout
    QWidget *centralWidget = new QWidget(this);
    QGridLayout *gridLayout = new QGridLayout(centralWidget);
    mainApplicationWindow->setCentralWidget(centralWidget);

    // Searchbar
    lineEditSearch->setPlaceholderText("Search name");
    gridLayout->addWidget(lineEditSearch, 0, 0, 1, 3);
    gridLayout->addWidget(pushButtonClear, 0, 3, 1, 1);

    // Proxy model
    proxyModel->setSourceModel(registrationModel);
    proxyModel->setFilterKeyColumn(0);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    // Registration table
    tableViewRegistrations->setModel(proxyModel);
    tableViewRegistrations->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableViewRegistrations->setSortingEnabled(true);
    gridLayout->addWidget(tableViewRegistrations, 1, 0, 1, 4);
}


void MainWindow::on_actionAddAttendee_triggered()
{
    NewRegistrationDialog *newRegistrationDialog = new NewRegistrationDialog(registrationList);
    newRegistrationDialog->show();
}


void MainWindow::on_actionGetTotalFees_triggered()
{
    TotalFeesDialog *totalFeesDialog = new TotalFeesDialog(registrationList);
    totalFeesDialog->show();
}


void MainWindow::on_actionGetNumberOfAttendeesFromAffiliation_triggered()
{
    TotalRegisteredDialog *totalRegisteredDialog = new TotalRegisteredDialog(registrationList);
    totalRegisteredDialog->show();
}


void MainWindow::on_actionClearFilter_triggered()
{
    lineEditSearch->clear();
    lineEditSearch->setFocus();
    proxyModel->setFilterText(lineEditSearch->text());
}

/**
 * @brief Slot for the "Export Registration List" action.
 * Opens a file dialog to export the registration list to an XML file.
 */
void MainWindow::on_actionExportRegistrationList_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Registration List"), "", tr("XML Files (*.xml);;All Files (*)"));
    if (fileName.isEmpty()) { return; }

    RegistrationListWriter writer(fileName);
    if (writer.write(registrationList->getAttendeeList()))
    {
        QMessageBox::information(this, tr("Export Successful"), tr("The registration list was successfully exported."));
    }
    else
    {
        QMessageBox::warning(this, tr("Export Failed"), tr("Failed to export the registration list."));
    }
}
