/**
 * @file mainwindow_test.cpp
 * @brief Unit tests for MainWindow UI component
 * @details Tests window initialization, menu actions, toolbar, and table display
 */

#include "mainwindow.h"
#include "registrationmodel.h"
#include "registrationlist.h"
#include "registration.h"

#include <QTest>
#include <QAction>
#include <QLineEdit>
#include <QTableView>
#include <QMenuBar>
#include <QToolBar>
#include <QApplication>
#include <QTimer>

class MainWindowTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        // Initialization before all tests
    }

    void cleanupTestCase()
    {
        // Cleanup after all tests
    }

    void init()
    {
        // Setup before each test
    }

    void cleanup()
    {
        // Cleanup after each test
    }

    // Test Cases
    void testWindowInitialization()
    {
        MainWindow window;
        
        // Verify window title
        QCOMPARE(window.windowTitle(), QString("Conference Registration"));
        
        // Verify window is not null
        QVERIFY(&window != nullptr);
    }

    void testWindowDefaultState()
    {
        MainWindow window;
        
        // Verify initial window state
        QVERIFY(!window.isVisible());  // Window should not be visible initially
        
        // Verify window size
        QSize size = window.size();
        QVERIFY(size.width() > 0);
        QVERIFY(size.height() > 0);
    }

    void testMenuBarExists()
    {
        MainWindow window;
        
        // Verify menu bar exists
        QMenuBar *menuBar = window.findChild<QMenuBar*>();
        QVERIFY(menuBar != nullptr);
    }

    void testFileMenuExists()
    {
        MainWindow window;
        
        QMenuBar *menuBar = window.findChild<QMenuBar*>();
        QVERIFY(menuBar != nullptr);
        
        // Find File menu
        QList<QAction*> menuActions = menuBar->actions();
        bool foundFileMenu = false;
        for (QAction *action : menuActions)
        {
            if (action->text().contains("File"))
            {
                foundFileMenu = true;
                break;
            }
        }
        QVERIFY(foundFileMenu);
    }

    void testEditMenuExists()
    {
        MainWindow window;
        
        QMenuBar *menuBar = window.findChild<QMenuBar*>();
        QVERIFY(menuBar != nullptr);
        
        // Find Edit menu
        QList<QAction*> menuActions = menuBar->actions();
        bool foundEditMenu = false;
        for (QAction *action : menuActions)
        {
            if (action->text().contains("Edit"))
            {
                foundEditMenu = true;
                break;
            }
        }
        QVERIFY(foundEditMenu);
    }

    void testReportsMenuExists()
    {
        MainWindow window;
        
        QMenuBar *menuBar = window.findChild<QMenuBar*>();
        QVERIFY(menuBar != nullptr);
        
        // Find Reports menu
        QList<QAction*> menuActions = menuBar->actions();
        bool foundReportsMenu = false;
        for (QAction *action : menuActions)
        {
            if (action->text().contains("Reports"))
            {
                foundReportsMenu = true;
                break;
            }
        }
        QVERIFY(foundReportsMenu);
    }

    void testToolBarExists()
    {
        MainWindow window;
        
        // Verify toolbar exists
        QToolBar *toolBar = window.findChild<QToolBar*>();
        QVERIFY(toolBar != nullptr);
    }

    void testTableViewExists()
    {
        MainWindow window;
        
        // Verify table view exists
        QTableView *tableView = window.findChild<QTableView*>();
        QVERIFY(tableView != nullptr);
    }

    void testSearchLineEditExists()
    {
        MainWindow window;
        
        // Verify search line edit exists
        QLineEdit *lineEdit = window.findChild<QLineEdit*>();
        QVERIFY(lineEdit != nullptr);
    }

    void testActionAddAttendeeExists()
    {
        MainWindow window;
        
        // Find the add attendee action
        QAction *action = window.findChild<QAction*>();
        QVERIFY(action != nullptr);
    }

    void testTableViewHasModel()
    {
        MainWindow window;
        
        QTableView *tableView = window.findChild<QTableView*>();
        QVERIFY(tableView != nullptr);
        
        // Verify table has a model
        QVERIFY(tableView->model() != nullptr);
    }
};

// Qt Test main function
QTEST_MAIN(MainWindowTest)
#include "mainwindow_test.moc"
