/**
 * @file main.cpp
 * @author Mitch Campbell
 * @date 2024-07-11
 * @copyright Copyright (c) Mitch Campbell 2024
 * @brief The entry point of the application.
 */


#include "mainwindow.h"

#include <QApplication>


 /** @brief This function is the entry point of the application. It initializes the QApplication object, creates an instance of the MainWindow class, and displays the main window of the application. Finally, it enters the event loop by calling the exec() function of the QApplication object.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return int The exit code of the application.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
