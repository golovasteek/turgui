#include <QtGui/QApplication>
#include <QMainWindow>
#include <QMenuBar>

#include "turgwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    CTurgWidget turgWidget;
    w.setCentralWidget(&turgWidget);
    QMenuBar* menu = w.menuBar();
    QMenu* fileMenu = menu->addMenu("&File");
    //QAction* findAction = fileMenu->addAction("F&ind");
    QAction* openAction = fileMenu->addAction("&Open");
    QAction* quitAction = fileMenu->addAction("&Quit");
    QObject::connect(openAction, SIGNAL(triggered()), &turgWidget, SLOT(LoadFromFile()));
    QObject::connect(quitAction, SIGNAL(triggered()), &w, SLOT(close()));
    //QObject::connect(findAction, SIGNAL(triggered()), &turgWidget, SLOT(findGeneral()));
    w.show();
    return a.exec();
}
