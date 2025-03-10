#include "DataReader.h"
#include "TObjArray.h"  // Include ROOT header for TObjArray
#include <TSystem.h>    // Include ROOT header for TSystem
#include "TH1.h"

// Constructor
DataReader::DataReader(const std::string& dataPath) : mDataPath(dataPath), mListFiles(nullptr) {}

// Function to check and set directory path
void DataReader::setDirToHIPO() {
    if (mDataPath.empty()) {
        std::cout << "\nNeed data file" << std::endl;
        std::cout << "Analysis script terminated due to no valid path to Hipo files\n" << std::endl;
        exit(0);
    }
}

// Function to retrieve list of files in directory
TObjArray* DataReader::GetListLFiles() {
    if (!mListFiles) {
        mListFiles = new TObjArray();
        void* dir = gSystem->OpenDirectory(mDataPath.c_str());

        if (!dir) {
            std::cerr << "Error: Could not open directory " << mDataPath << std::endl;
            return nullptr;
        }

        const char* file;
        while ((file = gSystem->GetDirEntry(dir))) {
            std::string filename(file);
            if (filename.find(".hipo") != std::string::npos) {
                mListFiles->Add(new TObjString(filename.c_str()));  // Ensure TObjString is recognized
            }
        }
        gSystem->FreeDirectory(dir);
    }

    return mListFiles;
}

// Getter for data path
const std::string& DataReader::GetDataPath() const {
    return mDataPath;
}