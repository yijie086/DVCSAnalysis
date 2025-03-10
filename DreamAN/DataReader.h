#ifndef DATA_READER_H
#define DATA_READER_H

#include <iostream>
#include <string>
#include "TObjArray.h"  // Include ROOT header for TObjArray
#include "TObjString.h"
class DataReader {
public:
    // Constructor
    explicit DataReader(const std::string& dataPath);

    // Function to check and set directory path
    void setDirToHIPO();

    // Getter for data path
    const std::string& GetDataPath() const;

    // Function to retrieve list of files
    TObjArray* GetListLFiles();

private:
    std::string mDataPath;
    TObjArray* mListFiles;
};

#endif // DATA_READER_H