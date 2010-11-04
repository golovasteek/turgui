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
    int words_ind = 0;
    for (int i = 0; i < rowCount(); ++i)
    {
        curItem = item(i, 0);
        if (curItem != 0 && !curItem->text().isEmpty())
        {
            setItem(i, 1, new QTableWidgetItem(words[words_ind].left(offsets[words_ind])));
            setItem(i, 2, new QTableWidgetItem(words[words_ind].mid(offsets[words_ind], length)));
            setItem(i, 3, new QTableWidgetItem(
                words[words_ind].right(words[words_ind].size() - offsets[words_ind] - length)));
            words_ind++;
        }
    }
}

void WordsList::onCellChanged(int row, int collumn)
{
    if(row == rowCount() - 1)
    {
        setRowCount(rowCount() + 1);
    }
    if(collumn == 0)
    {
        findGeneral();
    }
}
