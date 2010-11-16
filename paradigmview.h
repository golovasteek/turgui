#ifndef WORDSLIST_H
#define WORDSLIST_H

#include <QTableWidget>
#include <QString>

#include "paradigminfo.h"
#include "gramtab.h"

class CParadigmView : public QTableWidget
{
    Q_OBJECT
public:
    CParadigmView(QWidget* w = 0);
    void SetParadigm(const CParadigmInfo& paradigm);
    //CParadigmInfo GetParadirm() const {}

    QString GetLem() const { return lem; }
    void SetLem(const QString& _lem) {lem = _lem;}
    void SetGramtab(const CGramtab* _gramtab) {gramtab = _gramtab;}

public slots:
    void findGeneral();
    void onCellChanged(int row, int collumn);

private:
    QString lem;
    const CGramtab* gramtab;
};

#endif // WORDSLIST_H
