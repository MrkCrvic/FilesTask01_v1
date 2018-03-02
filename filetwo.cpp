#include "filetwo.h"

FileTwo::FileTwo()
{

}

FileTwo::FileTwo(QStringList &strList)
{
    this->csg = strList[0];
    this->from = strList[1];
    this->to = strList[2];
    this->srv = strList[3];
    this->typ = strList[4];
}

void FileTwo::setCSG(QString ccsg)
{
    this->csg = ccsg;
}

QString FileTwo::getCSG()
{
    return this->csg;
}

void FileTwo::setFROM(QString ffrom)
{
    this->from = ffrom;
}

QString FileTwo::getFROM()
{
    return this->from;
}

void FileTwo::setTO(QString tto)
{
    this->to = tto;
}

QString FileTwo::getTO()
{
    return this->to;
}

void FileTwo::setSRV(QString ssrv)
{
    this->srv = ssrv;
}

QString FileTwo::getSRV()
{
    return this->srv;
}

void FileTwo::setTYP(QString ttyp)
{
    this->typ = ttyp;
}

QString FileTwo::getTYP()
{
    return this->typ;
}


