#ifndef WORDSLIST_H
#define WORDSLIST_H

#include <QTableWidget>

class WordsList : public QTableWidget
{
    Q_OBJECT
public:
    WordsList(QWidget* w);

public slots:
    void findGeneral();
    void onCellChanged(int row, int collumn);
};

#endif // WORDSLIST_H
