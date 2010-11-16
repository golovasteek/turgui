#ifndef FORMINFO_H
#define FORMINFO_H

#include <QString>

class CFormInfo
{
public:
    CFormInfo();
    enum TCase
    {
        Nominative,
        Genitive,
        Dative,
        Acusative,
        Instrumentalis,
        Locative,
        Vocative
    };
    TCase Case() const { return caseVal; }
    void SetCase(TCase _caseVal) { caseVal = _caseVal; };
    QString Prefix() const { return prefix; }
    void SetPrefix(const QString& _prefix) { prefix = _prefix; }
    QString Suffix() const { return suffix; }
    void SetSuffix(const QString& _suffix) { suffix = _suffix; }
    qint64 Grammem() const { return grammem; }
    void SetGrammem(qint64 _grammem) { grammem = _grammem; }
    int PartOfSpeech() const { return partOfSpeech;}
    void setPartOfSpeech(int _partOfSpeech) { partOfSpeech = _partOfSpeech; }

private:
    TCase caseVal;
    QString prefix;
    QString suffix;
    qint64 grammem;
    int partOfSpeech;
};

#endif // FORMINFO_H
