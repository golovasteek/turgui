#ifndef GRAMTAB_H
#define GRAMTAB_H

#include <QXmlDeclHandler>
#include <QString>
#include <QMap>

struct CGrammarInfo
{
    int Id;
    QString ShortName;
    QString FullName;
};

class CGramtab
{
public:
    CGramtab();
    CGrammarInfo* AddPart(int Id, const QString& shortName, const QString& fullName = "");
    CGrammarInfo* AddGrammem(int Id, const QString& shortName, const QString& fullName = "");
    QString GetPartName(int id) const { return parts[id].ShortName; }
    QString GetGrammemName(int id) const { return grammems[id].ShortName; }

private:
    QMap<int, CGrammarInfo> parts;
    QMap<int, CGrammarInfo> grammems;
};

class CGrammtabHandler : public QXmlDefaultHandler
{
public:
    CGrammtabHandler(CGramtab* _gramtab) : gramTab(_gramtab), currentItem(0) {}
    bool startElement(const QString& namespaceURI,
        const QString &localName,
        const QString &qName,
        const QXmlAttributes &atts);
    /* bool characters(const QString &ch) {}
    bool endElement(const QString& namespaceURI,
        const QString& localName,
        const QString &qName) {}
*/
public:
    CGramtab* gramTab;
    CGrammarInfo* currentItem;
};

#endif // GRAMTAB_H
