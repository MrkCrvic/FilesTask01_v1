#ifndef FILETWO_H
#define FILETWO_H

#include <QDebug>
#include <QString>
#include <QStringList>

class FileTwo
{
private:
    QString csg, from, to, srv, typ;
public:
    FileTwo();

    FileTwo(QStringList &strList);

    void setCSG(QString ccsg);
    QString getCSG();

    void setFROM(QString ffrom);
    QString getFROM();

    void setTO(QString tto);
    QString getTO();

    void setSRV(QString ssrv);
    QString getSRV();

    void setTYP(QString ttyp);
    QString getTYP();
};

#endif // FILETWO_H
