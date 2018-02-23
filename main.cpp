#include <QCoreApplication>
#include "fileone.h"
#include "filetwo.h"
#include <QFile>
#include <QVector>
#include <QTextStream>
#include <QVectorIterator>
#include <QStringList>

void FillFileOne(QStringList &strList, FileOne * ff1);
void FillFileTwo(QStringList &strList, FileTwo * ff2);
void WriteOutputFile(QVector<FileOne> & f1v, QVector<FileTwo> & f2v);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString fStr1 = "C:/Users/mcorovic/Desktop/qt_projects/FilesTask01/file01.csv";
    QString fStr2 = "C:/Users/mcorovic/Desktop/qt_projects/FilesTask01/file02.csv";

	// komentar neki
	
    QFile firstFile(fStr1);
    QFile secondFile(fStr2);

    QVector<FileOne> f1vect;
    QVector<FileTwo> f2vect;

    //file01
    if(!firstFile.open(QFile::ReadOnly))
    {
        qDebug() << "Cannot open file01!";
    }
    else
    {
        qDebug() << "file01 successfully opened!";
        QString line;
        QTextStream rf(&firstFile);
        line = rf.readLine();

        QStringList strList;

        while(!rf.atEnd())
        {
            line = rf.readLine();
            strList = line.split(',');
            //qDebug() << strList[1];
            FileOne * f1 = new FileOne();
            FillFileOne(strList, f1);
            f1vect.append(*f1);
            //qDebug() << f1->getY();
        }

        //qDebug() << line;
        firstFile.close();
    }

//    FileOne file1 = f1vect.first();

//    qDebug() << file1.getCSG();

//    file1 = f1vect.last();

//    qDebug() << file1.getCSG();


    // file02
    if(!secondFile.open(QFile::ReadOnly))
    {
        qDebug() << "Cannot open file02!";
    }
    else
    {
        qDebug() << "file02 successfully opened!";
        QString line;
        QTextStream rf(&secondFile);
        line = rf.readLine();

        QStringList strList;

        while(!rf.atEnd())
        {
            line = rf.readLine();
            strList = line.split(',');
            //qDebug() << strList[1];
            FileTwo * f2 = new FileTwo();
            FillFileTwo(strList, f2);
            f2vect.append(*f2);
            //qDebug() << f2->getFROM();
        }

        //qDebug() << line;
        secondFile.close();
    }

    QString ss = "C:/Users/mcorovic/Desktop/qt_projects/FilesTask01/outputFile.csv";
    QFile fout(ss);

    WriteOutputFile(f1vect, f2vect);

    return a.exec();
}

void FillFileOne(QStringList &strList, FileOne * ff1)
{
    ff1->setCSG(strList[0]);
    ff1->setX(strList[1].toDouble());
    ff1->setY(strList[2].toDouble());
    ff1->setZ(strList[3].toDouble());
    ff1->setHDG(strList[4].toDouble());
    ff1->setSPD(strList[5].toInt());
}

void FillFileTwo(QStringList &strList, FileTwo * ff2)
{
    ff2->setCSG(strList[0]);
    ff2->setFROM(strList[1]);
    ff2->setTO(strList[2]);
    ff2->setSRV(strList[3]);
    ff2->setTYP(strList[4]);
}

void WriteOutputFile(QVector<FileOne> & f1v, QVector<FileTwo> & f2v)
{
    QString ss = "C:/Users/mcorovic/Desktop/qt_projects/FilesTask01/outputFile.csv";
    QFile fout(ss);

    QVector<QString> outvect;

    QVectorIterator<FileOne> vIter1(f1v);
    QVectorIterator<FileTwo> vIter2(f2v);

    while(vIter1.hasNext())
    {
        FileOne fone = vIter1.next();
        //qDebug() << fone.getCSG();

        QStringList sl;
        int flag = 0;
        QString ffrom, tto;
        for(int j = 0; j < f2v.length(); j++)
        {
            FileTwo ftwo = f2v.at(j);
            if(fone.getCSG() == ftwo.getCSG())
            {
                if(flag == 0)
                {
                    ffrom = ftwo.getFROM();
                    tto = ftwo.getTO();
                    sl << fone.getCSG() << "," << QString::number(fone.getX()) << ","
                       << QString::number(fone.getY()) << "," << QString::number(fone.getZ()) << "," << ffrom << "," << tto;
                    flag++;
                }
                else
                {
                    if((ffrom != ftwo.getFROM()) || (tto != ftwo.getTO()))
                    {
                        sl << "\n______," << "_____," << "_____," << "______," << ftwo.getFROM() << "," << ftwo.getTO();
                        //qDebug() << "Flag = 1!";
                    }
                }
                //qDebug() << ftwo.getFROM();
            }
        }
        QString sls = sl.join("");
        //qDebug().noquote() << sls;

        if(sls != "")
            outvect.append(sls);

    }
        if(!fout.open(QFile::WriteOnly))
        {
            qDebug() << "Cannot open output1 for writing!";
        }
        else
        {
            qDebug() << "outputFile successfully opened!";
            QTextStream out(&fout);
            QString fHeader = "#CSG,#X,#Y,#Z,#FROM,#TO\n";
            out << fHeader;

            QVectorIterator<QString> sIter(outvect);
            while(sIter.hasNext())
            {
                out << sIter.next() << "\n";
            }

            qDebug() << "Output file successfully written!";

            fout.flush();
            fout.close();

        }
//    for(int i = 0; i < f1v.length(); i++)
//    {
//        QStringList sl;
//        FileOne fone = f1v.at(i);


//        int flag = 0;
//        QString ffrom, tto;
//        for(int j = 0; j < f2v.length(); j++)
//        {
//            FileTwo ftwo = f2v.at(j);

//            if(fone.getCSG() == ftwo.getCSG())
//            {
//                if(flag == 0)
//                {
//                    ffrom = ftwo.getFROM();
//                    tto = ftwo.getTO();
//                    sl << fone.getCSG() << "," << QString::number(fone.getX()) << ","
//                       << QString::number(fone.getY()) << "," << QString::number(fone.getZ()) << "," << ffrom << "," << tto;
//                    flag++;
//                }
//                else
//                {
//                    if((ffrom != ftwo.getFROM()) || (tto != ftwo.getTO()))
//                    {
//                        sl << "\n" << ftwo.getFROM() << ftwo.getTO();
//                    }
//                }

//                //qDebug() << ftwo.getFROM();
//            }
//        }
//        //qDebug() << f2v.length();



//        QString sls = sl.join("");
//        //qDebug().noquote() << sls;

//        if(sls != "")
//            outvect.append(sls);
//    }

//    if(!fout.open(QFile::WriteOnly))
//    {
//        qDebug() << "Cannot open output1 for writing!";
//    }
//    else
//    {
//        QTextStream out(&fout);
//        QString fr = "#CSG,#X,#Y,#Z,#FROM,#TO\n";
//        out << fr;
//        for(int i = 0; i < outvect.size(); i++)
//        {
//            fr = outvect.at(i);
//            out << fr << "\n";
//        }

//        qDebug() << "Zavrseno ispisivanje izlaznog fajla!";

//        fout.close();

//    }
}
