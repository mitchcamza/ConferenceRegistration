/**
 * @file mainwindow.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell 2024
 * @brief Implementation file for the MainWindow class.
 * @details This file contains the implementation of the MainWindow class, which represents the main application window for a conference registration system. It includes the setup of the user interface, menu actions, toolbar, and signal-slot connections for various actions.
 */


#include "mainwindow.h"
#include "newregistrationdialog.h"
#include "totalfeesdialog.h"
#include "totalregistereddialog.h"
#include "registrationmodel.h"
#include "registrationlist.h"
#include "registrationfilterproxymodel.h"
#include "registrationlistwriter.h"
#include "registrationlistreader.h"
#include "registration.h"

#include <QTableView>
#include <QStandardItem>
#include <QHeaderView>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QIcon>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>


/**
 * @brief Constructs a MainWindow object.
 * @param parent The parent widget.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    registrationModel(new RegistrationModel(this)),
    registrationList(new RegistrationList(*registrationModel)),
    tableViewRegistrations(new QTableView(this)),
    actionAddAttendee(new QAction(QIcon(":/icons/add"), tr("New Registration"), this)),
    actionExportRegistrationList(new QAction(QIcon(":/icons/export"), tr("Export Registration List"), this)),
    actionImportRegistrationList(new QAction(QIcon(":/icons/import"), tr("Import Registration List. Appends to existing list."), this)),
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
    connect(actionImportRegistrationList, &QAction::triggered, this, &MainWindow::on_actionImportRegistrationList_triggered);
    connect(actionGetTotalFees, &QAction::triggered, this, &MainWindow::on_actionGetTotalFees_triggered);
    connect(actionGetNumberOfAttendeesForAffiliation, &QAction::triggered, this, &MainWindow::on_actionGetNumberOfAttendeesFromAffiliation_triggered);
    connect(actionClose, &QAction::triggered, this, &MainWindow::close);
    connect(pushButtonClear, &QPushButton::clicked, this, &MainWindow::on_actionClearFilter_triggered);
    connect(lineEditSearch, &QLineEdit::textEdited, proxyModel, &RegistrationFilterProxyModel::setFilterText);

    // Set up the user interface
    setupUI(this);
}

/**
 * @brief Destroys the MainWindow object.
 */
MainWindow::~MainWindow()
{

}

/**
 * @brief Sets up the user interface for the main application window.
 * @param mainApplicationWindow The main application window.
 */
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
    fileMenu->addAction(actionClose);
    // TODO: add file menu actions

    // Edit Menu
    QMenu *editMenu = menuBar->addMenu(tr("&Edit"));
    editMenu->addAction(actionAddAttendee);
    editMenu->addSeparator();
    editMenu->addAction(actionImportRegistrationList);
    editMenu->addAction(actionExportRegistrationList);

    // View Menu
    QMenu *viewMenu = menuBar->addMenu(tr("&View"));
    viewMenu->addAction(actionSearchAttendee);
    viewMenu->addAction(actionGetTotalFees);
    viewMenu->addAction(actionGetNumberOfAttendeesForAffiliation);

    // Help Menu
    QMenu *helpMenu = menuBar->addMenu(tr("&Help"));
    // TODO: Add help actions

    // Statusbar
    statusBar = new QStatusBar(mainApplicationWindow);
    setStatusBar(statusBar);

    // Toolbar
    toolBar = new QToolBar(mainApplicationWindow);
    mainApplicationWindow->addToolBar(Qt::TopToolBarArea, toolBar);
    toolBar->addAction(actionAddAttendee);
    toolBar->addSeparator();
    toolBar->addAction(actionImportRegistrationList);
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

/**
 * @brief Slot for the "New Registration" action.
 * Opens the dialog for adding a new registration.
 */
void MainWindow::on_actionAddAttendee_triggered()
{
    NewRegistrationDialog *newRegistrationDialog = new NewRegistrationDialog(registrationList);
    newRegistrationDialog->show();
}

/**
 * @brief Slot for the "Total Fees" action.
 * Opens the dialog for displaying the total fees.
 */
void MainWindow::on_actionGetTotalFees_triggered()
{
    TotalFeesDialog *totalFeesDialog = new TotalFeesDialog(registrationList);
    totalFeesDialog->show();
}

/**
 * @brief Slot for the "Registration per Affiliation" action.
 * Opens the dialog for displaying the total number of attendees per affiliation.
 */
void MainWindow::on_actionGetNumberOfAttendeesFromAffiliation_triggered()
{
    TotalRegisteredDialog *totalRegisteredDialog = new TotalRegisteredDialog(registrationList);
    totalRegisteredDialog->show();
}

/**
 * @brief Slot for the "Clear Filter" action.
 * Clears the search filter and sets focus to the search bar.
 */
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
    // Open a file dialog to save the XML file
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Registration List"), "", tr("XML Files (*.xml);;All Files (*)"));
    if (fileName.isEmpty()) { return; }

    // Serialize to XML and write to file
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

/**
 * @brief Slot for the "Import Registration List" action.
 * Opens a file dialog to import an existing registration list from an XML file and appends it to the current registration list.
 */
void MainWindow::on_actionImportRegistrationList_triggered()
{
    // Open a file dialog to select the XML file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Import Registration List"), "", tr("XML Files (*.xml);;All Files (*)"));
    if (fileName.isEmpty()) { return; }

    // Read the file, deserialize XML, and store registrations in a new QList
    RegistrationListReader reader(fileName);
    QList<Registration*> importedRegistrations = reader.read();

    // If there is nothing to import, return
    if (importedRegistrations.isEmpty())
    {
        QMessageBox::warning(this, tr("Import Failed"), tr("Failed to import the registration list. Check that the file exists, and that the XML structure is well-formed."));
        return;
    }

    // Append imported registrations to current registration list
    for (Registration *registration : importedRegistrations)
    {
        registrationList->addRegistration(registration);
    }
    QMessageBox::information(this, tr("Import Successful"), tr("The registration list was imported successfully."));

    // TODO: check that registrationList::addRegistration() updates the model and view
}
