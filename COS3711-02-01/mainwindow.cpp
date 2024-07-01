#include "mainwindow.h"
#include "newregistrationdialog.h"
#include "searchdialog.h"
#include "totalfeesdialog.h"
#include "totalregistereddialog.h"

#include <QTableWidget>
#include <QStandardItem>
#include <QHeaderView>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QIcon>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    tableWidgetRegistrations(new QTableWidget(0, 8, this)),
    actionAddAttendee(new QAction(QIcon(":/icons/add"), tr("New Registration"), this)),
    actionSearchAttendee(new QAction(QIcon(":/icons/search"), tr("Search"), this)),
    actionGetTotalFees(new QAction(QIcon(":/icons/fees"), tr("Total Fees"), this)),
    actionGetNumberOfAttendeesForAffiliation(new QAction(QIcon(":/icons/affiliation"), tr("Registration per Affiliation"), this)),
    actionClose(new QAction(QIcon(":/icons/close"), tr("&Close"), this))

{
    // Connect signals and slots
    connect(actionAddAttendee, &QAction::triggered, this, &MainWindow::on_actionAddAttendee_triggered);
    connect(actionSearchAttendee, &QAction::triggered, this, &MainWindow::on_actionSearchAttendee_triggered);
    connect(actionGetTotalFees, &QAction::triggered, this, &MainWindow::on_actionGetTotalFees_triggered);
    connect(actionGetNumberOfAttendeesForAffiliation, &QAction::triggered, this, &MainWindow::on_actionGetNumberOfAttendeesForAffiliation_triggered);
    connect(actionClose, &QAction::triggered, this, &MainWindow::close);

    // Set up the user interface
    setupUI(this);
}

MainWindow::~MainWindow()
{

}

void MainWindow::setupUI(QMainWindow *mainApplicationWindow)
{
    // Main Application window
    if (mainApplicationWindow->objectName().isEmpty())
    {
        mainApplicationWindow->setObjectName("Conference Registration");
    }
    mainApplicationWindow->resize(800, 600);

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

    // Toolbar
    toolBar = new QToolBar(mainApplicationWindow);
    mainApplicationWindow->addToolBar(Qt::TopToolBarArea, toolBar);
    toolBar->addAction(actionAddAttendee);
    toolBar->addAction(actionSearchAttendee);
    toolBar->addAction(actionGetTotalFees);
    toolBar->addAction(actionGetNumberOfAttendeesForAffiliation);

    // Registration table
    mainApplicationWindow->setCentralWidget(tableWidgetRegistrations);
    tableWidgetRegistrations->setSortingEnabled(true);
    QStringList tableHeaders;
    tableHeaders << "Name"
                 << "Affiliation"
                 << "Email"
                 << "Booking Date"
                 << "Type"
                 << "Fee"
                 << "Qualification"
                 << "Category";
    tableWidgetRegistrations->setHorizontalHeaderLabels(tableHeaders);
    tableWidgetRegistrations->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_actionAddAttendee_triggered()
{
    NewRegistrationDialog *newRegistrationDialog = new NewRegistrationDialog();
    newRegistrationDialog->show();
}

void MainWindow::on_actionSearchAttendee_triggered()
{
    SearchDialog *checkRegistrationDialog = new SearchDialog();
    checkRegistrationDialog->show();
}

void MainWindow::on_actionGetTotalFees_triggered()
{
    TotalFeesDialog *totalFeesDialog = new TotalFeesDialog();
    totalFeesDialog->show();
}

void MainWindow::on_actionGetNumberOfAttendeesForAffiliation_triggered()
{
    TotalRegisteredDialog *totalRegisteredDialog = new TotalRegisteredDialog();
    totalRegisteredDialog->show();
}