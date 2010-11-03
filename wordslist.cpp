#include "wordslist.h"
#include <QVector>
#include <QString>
#include <QMessageBox>

#include <algo.h>

WordsList::WordsList(QWidget* w) :
    QTableWidget(1, 4, w)
{
    QObject::connect(this, SIGNAL(cellChanged(int,int)), this, SLOT(onCellChanged(int,int)));
}

void WordsList::findGeneral()
{
    QVector<QString> words;
    QTableWidgetItem* curItem;
    for (int i = 0; i < rowCount(); ++i)
    {
        curItem = item(i, 0);
        if (curItem != 0 && !curItem->text().isEmpty())
        {

            words.push_back(curItem->text());
        }
    }
    QVector<int> offsets;
    int length = maxCommonSubstring(words, offsets);
    QMessageBox::information(0, "length", QString::number(length));
    for (int i = 0; i < rowCount(); ++i)
    {
        curItem = item(i, 0);
        if (curItem != 0 && !curItem->text().isEmpty())
        {
            ;
        }
    }
}

void WordsList::onCellChanged(int row, int collumn)
{
    if(row == rowCount() - 1)
    {
        setRowCount(rowCount() + 1);
    }
}
