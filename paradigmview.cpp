#include "paradigmview.h"
#include <QVector>
#include <QString>
#include <QMessageBox>

#include <algo.h>

CParadigmView::CParadigmView(QWidget* w) :
    QTableWidget(1, 6, w)
{
    QObject::connect(this, SIGNAL(cellChanged(int,int)), this, SLOT(onCellChanged(int,int)));
    setMinimumSize(100, 100);
}

void CParadigmView::findGeneral()
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

void CParadigmView::onCellChanged(int row, int collumn)
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

void CParadigmView::SetParadigm(const CParadigmInfo& paradigm)
{
    clear();
    int formCount = paradigm.FormCount();
    setRowCount( formCount + 1);
    for (int i = 0; i < formCount; ++i)
    {
            const CFormInfo& formInfo = paradigm.FormInfo(i);
            setItem(i, 0, new QTableWidgetItem(formInfo.Prefix() + lem + formInfo.Suffix()));
            setItem(i, 1, new QTableWidgetItem(formInfo.Prefix()));
            setItem(i, 2, new QTableWidgetItem(lem));
            setItem(i, 3, new QTableWidgetItem(formInfo.Suffix()));
            setItem(i, 4, new QTableWidgetItem(gramtab->GetPartName(formInfo.PartOfSpeech())));
            QString grammemStr;
            quint64 grammem = formInfo.Grammem();
            for (int j = 0; j < 64; ++j)
            {
                if ((grammem & (quint64(1) << j)) != 0)
                {
                    if (!grammemStr.isEmpty())
                    {
                        grammemStr += ",";
                    }
                    grammemStr += gramtab->GetGrammemName(j);
                }
            }
            setItem(i, 5, new QTableWidgetItem(grammemStr));
    }
}
