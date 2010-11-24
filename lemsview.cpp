#include "lemsview.h"
#include <QFileDialog>
#include <QMessageBox>

CLemsView::CLemsView(QWidget* /*parent*/)
{
    list.setLayoutMode(QListView::Batched);
    list.setEditTriggers(QListView::NoEditTriggers);
    layout.addWidget(&searchEdit);
    layout.addWidget(&list);
    setLayout(&layout);

    connect(&searchEdit, SIGNAL(returnPressed()), this, SLOT(search()));
    connect(&list, SIGNAL(activated(const QModelIndex&)), this, SIGNAL(activated(const QModelIndex&)));
    //setMinimumSize(100, 100);
}

void CLemsView::LoadFromFile(const QString& fileName, const CParadigmsData& paradigmsData)
{
    CLemLoaderHandler handler(&lemsData);
    QXmlSimpleReader reader;
    reader.setContentHandler(&handler);

    reader.parse(QXmlInputSource(new QFile(fileName)));

    QStringList tmpStringList;
    for (CLemsData::iterator it = lemsData.begin(); it != lemsData.end(); ++it)
    {
        const CFormInfo& normFormInfo = paradigmsData[it->Paradigm].FormInfo(0);
        //addItem(normFormInfo.Prefix() + it->Lem + normFormInfo.Suffix());
        tmpStringList << normFormInfo.Prefix() + it->Lem + normFormInfo.Suffix();
    }
    stringModel.setStringList(tmpStringList);

    filterModel.setSourceModel(&stringModel);
    filterModel.setFilterCaseSensitivity(Qt::CaseInsensitive);
    filterModel.setFilterFixedString("");
    list.setModel(&filterModel);
}

void CLemsView::search()
{
    QString filterStr = searchEdit.text();
    filterModel.setFilterFixedString(filterStr);
}
