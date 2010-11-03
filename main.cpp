#include <QtGui/QApplication>
#include <QMainWindow>
#include <QMenuBar>

#include "wordslist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    WordsList* table = new WordsList(&w);
    w.setCentralWidget(table);
    QMenuBar* menu = w.menuBar();
    QMenu* fileMenu = menu->addMenu("&File");
    QAction* findAction = fileMenu->addAction("F&ind");
    QAction* quitAction = fileMenu->addAction("&Quit");
    QObject::connect(quitAction, SIGNAL(triggered()), &w, SLOT(close()));
    QObject::connect(findAction, SIGNAL(triggered()), table, SLOT(findGeneral()));
    w.show();
    return a.exec();
}
