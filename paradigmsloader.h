#ifndef PARADIGMSLOADER_H
#define PARADIGMSLOADER_H

#include <QXmlDefaultHandler>
#include <QXmlSimpleReader>
#include <QMap>

#include "paradigminfo.h"

typedef QMap<int, CParadigmInfo> CParadigmsData;

class CParadigmsHandler : public QXmlDefaultHandler
{
public:
    CParadigmsHandler(CParadigmsData* _paradigms);
    bool startElement(const QString& namespaceURI,
        const QString &localName,
        const QString &qName,
        const QXmlAttributes &atts);

 /*   bool endElement(const QString& namespaceURI,
        const QString& localName,
        const QString& qName);
*/
private:
    CParadigmsData* paradigms;
    CParadigmInfo* currentParadigm;
};

#endif // PARADIGMSLOADER_H
