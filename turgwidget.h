#ifndef TURGWIDGET_H
#define TURGWIDGET_H

#include <QWidget>
#include <QHBoxLayout>

#include "paradigmview.h"
#include "lemsview.h"
#include "paradigmsloader.h"
#include "gramtab.h"

class CTurgWidget : public QWidget
{
Q_OBJECT
public:
    explicit CTurgWidget(QWidget *parent = 0);

signals:
    void openFile();

public slots:
    void LoadFromFile();
    void onLemSelected(const QModelIndex& index);

private:
    CLemsView lems;
    CParadigmView paradigm;
    CParadigmsData paradigms;
    CGramtab gramtab;
    QHBoxLayout layout;
};

#endif // TURGWIDGET_H
