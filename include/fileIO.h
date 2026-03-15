//this class is the blueprint for fileIO object which we will implement
//includes will have all the 'dependencies'
//this is also for a cpp program, so we will have cpp style functions

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>


class fileIO {
    private:
    /*
        instantiates a fileIO object
    */
    fileIO();

    //id associated with paths
    int id = 0;

    //below 2 are for deleting the copy constructors
    fileIO(const fileIO&) = delete;
    fileIO& operator=(const fileIO&) = delete;

    //this represents the reference to currently opened file...
    int file;

    //the map inits id, path combos so we can open and manipulate multiple files
    std::unordered_map <int, std::string>filePathMap;

    public:
    /*
    destructor deallocates any memory, and free's variables part of this class...
    */
   ~fileIO();

   //a function to init and get an object (singleton)
   static fileIO& getObj();

    //we will need a function to get the file path
    std::string getFilePath(const int& fileID);

    //a function to write to the file returns 1 for success
    int writeToFile(const std::string& message, const int& fileID);

    //a function to read the file
    void readFile(int& fileID);

    //a function to add a new path to the map (this is to avoid a new obj with new path all the time)
    int addPath(const std::string& path);
};