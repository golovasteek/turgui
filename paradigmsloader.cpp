#include "paradigmsloader.h"

CParadigmsHandler::CParadigmsHandler(CParadigmsData* _paradigms) :
    paradigms(_paradigms),
    currentParadigm(0)
{
}

bool CParadigmsHandler::startElement(const QString& /*namespaceURI*/,
    const QString& /*localName*/,
    const QString &qName,
    const QXmlAttributes &atts)
{
    if (qName == "paradigm")
    {
        currentParadigm = &(*paradigms)[atts.value("id").toInt()];
        return true;
    }
    else if (qName == "f")
    {
        Q_ASSERT(currentParadigm != 0);
        CFormInfo form;
        form.SetPrefix(atts.value("p"));
        form.SetSuffix(atts.value("s"));
        form.SetGrammem(atts.value("g").toLongLong());
        form.setPartOfSpeech(atts.value("ps").toInt());
        currentParadigm->PushFormBack(form);
        return true;
    }
    return true;
}
