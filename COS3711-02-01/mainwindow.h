#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTableView;
class RegistrationModel;
class RegistrationList;
class QGridLayout;
class QLineEdit;
class QPushButton;

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
    void on_actionSearchAttendee_triggered();
    void on_actionGetTotalFees_triggered();
    void on_actionGetNumberOfAttendeesForAffiliation_triggered();
    void on_actionClearFilter_triggered();

private:
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
};

#endif // MAINWINDOW_H
