#include "lemsview.h"
#include <QFileDialog>

CLemsView::CLemsView(QWidget *parent) :
    QListWidget(parent)
{
    setMinimumSize(100, 100);
}

void CLemsView::LoadFromFile(const QString& fileName, const CParadigmsData& paradigmsData)
{
    CLemLoaderHandler handler(&lemsData);
    QXmlSimpleReader reader;
    reader.setContentHandler(&handler);

    reader.parse(QXmlInputSource(new QFile(fileName)));
    for (CLemsData::iterator it = lemsData.begin(); it != lemsData.end(); ++it)
    {
        const CFormInfo& normFormInfo = paradigmsData[it->Paradigm].FormInfo(0);
        addItem(normFormInfo.Prefix() + it->Lem + normFormInfo.Suffix());
    }
}
