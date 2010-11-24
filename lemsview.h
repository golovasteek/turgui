#ifndef LEMSVIEW_H
#define LEMSVIEW_H

#include <QLineEdit>
#include <QListView>
#include <QString>
#include <QStringListModel>
#include <QSortFilterProxyModel>
#include <QVBoxLayout>
#include <QMessageBox>

#include "lemloader.h"
#include "paradigmsloader.h"

class CLemsView : public QWidget
{
    Q_OBJECT
public:
    CLemsView(QWidget* parent = 0);
    int GetParadigm(const QModelIndex& item) const {
        return lemsData[filterModel.mapToSource(item).row()].Paradigm;
    }
    QString GetLem(const QModelIndex& item) const { return lemsData[filterModel.mapToSource(item).row()].Lem; }

public slots:
    void LoadFromFile(const QString& fileName, const CParadigmsData& paradigmInfo);
    void search();

signals:
    void activated(const QModelIndex& index);

private:
    QVBoxLayout layout;
    CLemsData lemsData;
    QListView list;
    QLineEdit searchEdit;
    QStringListModel stringModel;
    QSortFilterProxyModel filterModel;
};

#endif // LEMSVIEW_H
