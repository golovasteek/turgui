#include "gramtab.h"

CGramtab::CGramtab()
{
}

CGrammarInfo* CGramtab::AddPart(int id, const QString &shortName, const QString &fullName)
{
    CGrammarInfo& current = parts[id];
    current.Id = id;
    current.ShortName = shortName;
    current.FullName = fullName;
    return &current;
}

CGrammarInfo* CGramtab::AddGrammem(int id, const QString &shortName, const QString &fullName)
{
    CGrammarInfo& current = grammems[id];
    current.Id = id;
    current.ShortName = shortName;
    current.FullName = fullName;
    return &current;
}

bool CGrammtabHandler::startElement(const QString& /*namespaceURI*/,
    const QString& /*localName*/,
    const QString& qName,
    const QXmlAttributes& atts)
{
    if (qName == "PoS")
    {
         currentItem = gramTab->AddPart(atts.value("id").toInt(), atts.value("short"));
    }
    else if (qName == "grammem")
    {
        currentItem = gramTab->AddGrammem(atts.value("id").toInt(), atts.value("short"));
    }
    return true;
}
