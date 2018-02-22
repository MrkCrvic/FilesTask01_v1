#ifndef FILEONE_H
#define FILEONE_H

#include <QDebug>
#include <QString>


class FileOne
{
private:
    QString csg;
    double x, y, z, hdg;
    int spd;

public:
    FileOne();

    void setCSG(QString ccsg);
    QString getCSG();

    void setX(double xx);
    double getX();

    void setY(double yy);
    double getY();

    void setZ(double zz);
    double getZ();

    void setHDG(double hhdg);
    double getHDG();

    void setSPD(int sspd);
    int getSPD();
};

#endif // FILEONE_H
