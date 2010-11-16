#include "lemloader.h"

#include <QMessageBox>

CLemLoaderHandler::CLemLoaderHandler(CLemsData* _lemsData) :
    lemsData(_lemsData)
{
}

bool CLemLoaderHandler::startElement(const QString& /*namespaceURI*/,
    const QString& /*locaName*/,
    const QString& name,
    const QXmlAttributes& attrs)
{
    if (name == "l")
    {
        lemsData->push_back(CLemInfo(attrs.value("id"), attrs.value("p").toInt()));
    }
    return true;
}


CLemLoader::CLemLoader()
{
}
