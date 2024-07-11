#include "mainwindow.h"
#include "newregistrationdialog.h"
#include "totalfeesdialog.h"
#include "totalregistereddialog.h"
#include "registrationmodel.h"
#include "registrationlist.h"
#include "registrationfilterproxymodel.h"

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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    registrationModel(new RegistrationModel(this)),
    registrationList(new RegistrationList(*registrationModel)),
    tableViewRegistrations(new QTableView(this)),
    actionAddAttendee(new QAction(QIcon(":/icons/add"), tr("New Registration"), this)),
    actionSearchAttendee(new QAction(QIcon(":/icons/search"), tr("Search"), this)),
    actionGetTotalFees(new QAction(QIcon(":/icons/fees"), tr("Total Fees"), this)),
    actionGetNumberOfAttendeesForAffiliation(new QAction(QIcon(":/icons/affiliation"), tr("Registration per Affiliation"), this)),
    actionClose(new QAction(QIcon(":/icons/close"), tr("&Close"), this)),
    lineEditSearch(new QLineEdit(this)),
    pushButtonClear(new QPushButton("Clear Filter", this)),
    gridLayout(new QGridLayout(this)),
    proxyModel(new RegistrationFilterProxyModel(this))

{
    // Connect signals and slots
    connect(actionAddAttendee, &QAction::triggered, this, &MainWindow::on_actionAddAttendee_triggered);
    connect(actionGetTotalFees, &QAction::triggered, this, &MainWindow::on_actionGetTotalFees_triggered);
    connect(actionGetNumberOfAttendeesForAffiliation, &QAction::triggered, this, &MainWindow::on_actionGetNumberOfAttendeesForAffiliation_triggered);
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
    mainApplicationWindow->resize(1200, 600);

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
    setStatusBar(statusBar);

    // Toolbar
    toolBar = new QToolBar(mainApplicationWindow);
    mainApplicationWindow->addToolBar(Qt::TopToolBarArea, toolBar);
    toolBar->addAction(actionAddAttendee);
    toolBar->addSeparator();
    toolBar->addAction(actionGetTotalFees);
    toolBar->addAction(actionGetNumberOfAttendeesForAffiliation);

    // Central widget and layout
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(gridLayout);
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

void MainWindow::on_actionGetNumberOfAttendeesForAffiliation_triggered()
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
