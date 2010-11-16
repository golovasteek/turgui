#ifndef LEMLOADER_H
#define LEMLOADER_H

#include <QXmlDefaultHandler>
#include <QVector>

struct CLemInfo
{
    QString Lem;
    int Paradigm;

    CLemInfo(const QString& lem = "", int paradigm = 0) : Lem(lem), Paradigm(paradigm) {}
};

typedef QVector<CLemInfo> CLemsData;

class CLemLoaderHandler : public QXmlDefaultHandler
{
public:
    CLemLoaderHandler(CLemsData* lemsData);
    bool startElement(const QString& namespaceURI,
        const QString& locaName,
        const QString& name,
        const QXmlAttributes& attrs);
private:
    CLemsData* lemsData;
};

class CLemLoader
{
public:
    CLemLoader();
};

#endif // LEMLOADER_H
