#ifndef FORMVIEW_H
#define FORMVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>

#include "forminfo.h"

class CFormView : public QWidget
{
Q_OBJECT
public:
    explicit CFormView(QWidget *parent = 0);
    void SetFormInfo(const CFormInfo& info);
    CFormInfo FormInfo();

signals:

public slots:

private:
    QLineEdit fullForm;
    QLabel prefix;
    QLabel suffix;
    QComboBox caseBox;
    QHBoxLayout layout;
};

#endif // FORMVIEW_H
