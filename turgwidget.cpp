#include "turgwidget.h"

#include <QFileDialog>
#include <QMessageBox>

CTurgWidget::CTurgWidget(QWidget *parent) :
    QWidget(parent),
    lems(this),
    paradigm(this)
{
    layout.addWidget(&lems, 1);
    layout.addWidget(&paradigm, 3);
    setLayout(&layout);

    connect(&lems, SIGNAL(activated(QModelIndex)), this, SLOT(onLemSelected(QModelIndex)));
}

void CTurgWidget::LoadFromFile()
{
    QFileDialog openDialog(this, "Open lems file...","", "Turglem lemmas file (lemmas.xml)");
    openDialog.setFileMode(QFileDialog::ExistingFile);
    openDialog.setViewMode(QFileDialog::Detail);
    if (!openDialog.exec())
    {
        return;
    }
    QString lemsFileName = openDialog.selectedFiles().front();
    openDialog.setWindowTitle("Open paradigms file...");
    openDialog.setFilter("Turglem paradigms file (paradigms.xml)");
    if (!openDialog.exec())
    {
        return;
    }
    QString paradigmsFileName = openDialog.selectedFiles().front();

    openDialog.setWindowTitle("Open grammtab file...");
    openDialog.setFilter("Turglem grammtab file (gramtab.xml)");
    if (!openDialog.exec())
    {
        return;
    }
    QString grammtabFileName = openDialog.selectedFiles().front();

    {
        CParadigmsHandler handler(&paradigms);
        QXmlSimpleReader reader;
        reader.setContentHandler(&handler);
        reader.parse(new QFile(paradigmsFileName));
    }
    {
        CGrammtabHandler handler(&gramtab);
        QXmlSimpleReader reader;
        reader.setContentHandler(&handler);
        reader.parse(new QFile(grammtabFileName));
    }

    paradigm.SetGramtab(&gramtab);

    lems.LoadFromFile(lemsFileName, paradigms);
}

void CTurgWidget::onLemSelected(const QModelIndex& index)
{
    paradigm.SetLem(lems.GetLem(index));
    paradigm.SetParadigm(paradigms[lems.GetParadigm(index)]);
}

