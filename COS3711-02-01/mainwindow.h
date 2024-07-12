#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTableView;
class RegistrationModel;
class RegistrationList;
class QGridLayout;
class QLineEdit;
class QPushButton;
class RegistrationFilterProxyModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupUI(QMainWindow *mainApplicationWindow);

private slots:
    void on_actionAddAttendee_triggered();
    void on_actionGetTotalFees_triggered();
    void on_actionGetNumberOfAttendeesForAffiliation_triggered();
    void on_actionClearFilter_triggered();

private:
<<<<<<< Updated upstream
    QTableView *tableViewRegistrations;
    RegistrationModel *registrationModel;
    RegistrationList *registrationList;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QAction *actionAddAttendee;
    QAction *actionSearchAttendee;
    QAction *actionGetTotalFees;
    QAction *actionGetNumberOfAttendeesForAffiliation;
    QAction *actionClose;
    QGridLayout *gridLayout;
    QLineEdit *lineEditSearch;
    QPushButton *pushButtonClear;
    RegistrationFilterProxyModel *proxyModel;
=======
    QTableView *tableViewRegistrations; /**< The table view widget for displaying registrations. */
    RegistrationModel *registrationModel; /**< The model for managing registrations. */
    RegistrationList *registrationList; /**< The list of registrations. */
    QMenuBar *menuBar; /**< The menu bar widget. */
    QStatusBar *statusBar; /**< The status bar widget. */
    QToolBar *toolBar; /**< The tool bar widget. */
    QAction *actionAddAttendee; /**< The action for adding an attendee. */
    QAction *actionSearchAttendee; /**< The action for searching an attendee. */
    QAction *actionGetTotalFees; /**< The action for getting the total fees. */
    QAction *actionGetNumberOfAttendeesForAffiliation; /**< The action for getting the number of attendees for an affiliation. */
    QAction *actionClose; /**< The action for closing the application. */
    QLineEdit *lineEditSearch; /**< The line edit widget for searching. */
    QPushButton *pushButtonClear; /**< The push button widget for clearing the filter. */
    RegistrationFilterProxyModel *proxyModel; /**< The proxy model for filtering registrations. */
>>>>>>> Stashed changes
};

#endif // MAINWINDOW_H
