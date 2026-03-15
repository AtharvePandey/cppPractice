//an implementation of the fileIO class

#include "../include/fileIO.h"


fileIO& fileIO::getObj(){
    static fileIO instance;
    return instance;
}

std::string fileIO::getFilePath(const int& fileID){
    std::unordered_map<int, std::string>::iterator iter = this->filePathMap.find(fileID);
    if(iter != this->filePathMap.end()){
        return iter->second;
    }
    std::string retStr = "";
    return retStr;
}

int fileIO::writeToFile(const std::string& message, const int& fileID){
    const std::string path = this->getFilePath(fileID);
    if(path == ""){
        std::cout << "error, can't find file, with associated id: " <<fileID << std::endl;
        return -1;
    }else{
        std::ofstream file(path, std::ios::app);
        if(!file.is_open()){
            std::cout << "error can't open the file on path: " << path << std :: endl;
        }
        file << message;
        file.close();
        return 1;
    }
}

void fileIO::readFile(int& fileID){
    const std::string path = this->getFilePath(fileID);
    if(path == ""){
        std :: cout << "error, can't find file with associated id: " << fileID << std ::endl;
    }else{
        std::ofstream file(path);
        file.flush();
        file.close();
    }
}

int fileIO :: addPath(const std::string& path){
    this->id++;
    this->filePathMap.insert({this->id, path});
    return this->id;
}

