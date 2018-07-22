#ifndef SEARCHFUNCTION_HPP
#define SEARCHFUNCTION_HPP
#include<QString>
#include <iostream>
#include <fstream>
#include "filehandler.hpp"
#include <QDebug>

using namespace std;

class DiseaseFinder {
public:
    static QString find(QString query){
        QString curPath = qApp->applicationDirPath();
        ifstream reader(curPath.toStdString() + "/data/diseases.txt");

        std::string line;
        QString qLine;
        QString file = "";

        while(!reader.eof()){
            std::getline(reader,line);
            qLine = QString::fromStdString(line);

            qDebug() << qLine;

            if (qLine.indexOf(":") != -1){
                   QStringList fields = qLine.split(":");
                   if (fields[0].trimmed().toLower().indexOf(query.trimmed().toLower()) != -1){
                        file = FileHandler::fileReader(curPath,"/data/" + fields[1]);
                        break;
                   }
            }
        }
        reader.close();

        return file;
    }
};

#endif // SEARCHFUNCTION_HPP
