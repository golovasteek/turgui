#ifndef LEMSVIEW_H
#define LEMSVIEW_H

#include <QListWidget>
#include <QString>
#include "lemloader.h"
#include "paradigmsloader.h"

class CLemsView : public QListWidget
{
    Q_OBJECT
public:
    CLemsView(QWidget* parent = 0);
    int GetParadigm(QListWidgetItem* item) const {return lemsData[indexFromItem(item).row()].Paradigm; }

public slots:
    void LoadFromFile(const QString& fileName, const CParadigmsData& paradigmInfo);

private:
    CLemsData lemsData;
};

#endif // LEMSVIEW_H
