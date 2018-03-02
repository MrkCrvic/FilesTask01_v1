#include "fileone.h"

FileOne::FileOne()
{

}

FileOne::FileOne(QStringList &strList)
{
    this->csg = strList[0];
    this->x = strList[1].toDouble();
    this->y = strList[2].toDouble();
    this->z = strList[3].toDouble();
    this->hdg = strList[4].toDouble();
    this->spd = strList[5].toInt();
}

void FileOne::setCSG(QString ccsg)
{
    this->csg = ccsg;
}

QString FileOne::getCSG()
{
    return this->csg;
}

void FileOne::setX(double xx)
{
    this->x = xx;
}

double FileOne::getX()
{
    return this->x;
}

void FileOne::setY(double yy)
{
    this->y = yy;
}

double FileOne::getY()
{
    return this->y;
}

void FileOne::setZ(double zz)
{
    this->z = zz;
}

double FileOne::getZ()
{
    return this->z;
}

void FileOne::setHDG(double hhdg)
{
    this->hdg = hhdg;
}

double FileOne::getHDG()
{
    return this->hdg;
}

void FileOne::setSPD(int sspd)
{
    this->spd = sspd;
}

int FileOne::getSPD()
{
    return this->spd;
}
