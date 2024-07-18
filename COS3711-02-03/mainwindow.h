/**
 * @file mainwindow.h
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) 2024 Mitch Campbell
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGridLayout;
class QLineEdit;
class QPushButton;
class QTableView;
class RegistrationFilterProxyModel;
class RegistrationList;
class RegistrationModel;


/**
 * @class MainWindow
 * @brief The MainWindow class represents the main application window.
 * @details This class inherits from QMainWindow and provides the user interface for the application. It contains various widgets such as a table view, line edit, push button, and actions. The MainWindow class also manages the registration model, registration list, and proxy model.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * @brief Constructs a MainWindow object.
     * 
     * @param parent The parent widget (default is nullptr).
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the MainWindow object.
     */
    ~MainWindow();

private:
    /**
     * @brief Sets up the user interface for the main application window.
     * 
     * @param mainApplicationWindow The main application window.
     */
    void setupUI(QMainWindow *mainApplicationWindow);

private slots:
    /**
     * @brief Slot function called when the "Add Attendee" action is triggered.
     */
    void on_actionAddAttendee_triggered();

    /**
     * @brief Slot function called when the "Get Total Fees" action is triggered.
     */
    void on_actionGetTotalFees_triggered();

    /**
     * @brief Slot function called when the "Get Number of Attendees for Affiliation" action is triggered.
     */
    void on_actionGetNumberOfAttendeesFromAffiliation_triggered();

    /**
     * @brief Slot function called when the "Clear Filter" action is triggered.
     */
    void on_actionClearFilter_triggered();

    /**
     * @brief Slot function called when the "Export" action is triggered.
     */
    void on_actionExportRegistrationList_triggered();

    /**
     * @brief Slot function called when the "Import" action is triggered.
     */
    void on_actionImportRegistrationList_triggered();

private:
    QTableView *tableViewRegistrations; /**< The table view widget for displaying registrations. */
    RegistrationModel *registrationModel; /**< The model for managing registrations. */
    RegistrationList *registrationList; /**< The list of registrations. */
    QMenuBar *menuBar; /**< The menu bar widget. */
    QStatusBar *statusBar; /**< The status bar widget. */
    QToolBar *toolBar; /**< The tool bar widget. */
    QAction *actionAddAttendee; /**< The action for adding an attendee. */
    QAction *actionExportRegistrationList; /**< The action for exporting the registrationList. */
    QAction *actionImportRegistrationList; /**< The action for importing the registrationList. */
    QAction *actionSearchAttendee; /**< The action for searching an attendee. */
    QAction *actionGetTotalFees; /**< The action for getting the total fees. */
    QAction *actionGetNumberOfAttendeesForAffiliation; /**< The action for getting the number of attendees for an affiliation. */
    QAction *actionClose; /**< The action for closing the application. */
    QLineEdit *lineEditSearch; /**< The line edit widget for searching. */
    QPushButton *pushButtonClear; /**< The push button widget for clearing the filter. */
    RegistrationFilterProxyModel *proxyModel; /**< The proxy model for filtering registrations. */
};

#endif // MAINWINDOW_H
