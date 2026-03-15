#include "../include/fileIO.h"

int main() {
    // Example usage
    fileIO& fio = fileIO::getObj();
    int id = fio.addPath("example.txt");
    fio.writeToFile("Hello, World!", id);
    fio.readFile(id);
    return 0;
}