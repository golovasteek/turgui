#ifndef PARADIGMINFO_H
#define PARADIGMINFO_H

#include <QVector>

#include "forminfo.h"

class CParadigmInfo
{
public:
    CParadigmInfo();
    CFormInfo& FormInfo(int formInd) { return forms[formInd]; }
    const CFormInfo& FormInfo(int formInd) const { return forms[formInd]; }
    void PushFormBack(const CFormInfo& formInfo) {forms.push_back(formInfo);}
    int FormCount() const { return forms.size(); }

private:
    QVector<CFormInfo> forms;
};

#endif // PARADIGMINFO_H
