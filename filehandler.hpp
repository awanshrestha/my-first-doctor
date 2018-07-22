#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP
#include <iostream>
#include <fstream>

class FileHandler {
public:

   static  QString fileReader(QString curPath,QString path){
         //QString curPath = qApp->applicationDirPath();
        std::string line;
        QString file;
        file = "";
        std::ifstream reader(curPath.toStdString() + path.toStdString());

        while(!reader.eof()){
            std::getline(reader,line);
            file = file + QString::fromStdString(line) + "\n";
        }
        reader.close();
        return file;
    }
};
#endif // FILEHANDLER_HPP
