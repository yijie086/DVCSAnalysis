cmake_minimum_required(VERSION 3.10)
project(AnalysisFramework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Check if CLAS12ROOT environment is set
if(NOT DEFINED ENV{CLAS12ROOT})
    message(FATAL_ERROR "CLAS12ROOT environment variable not set!")
endif()

# Use root-config to get compile and link flags
execute_process(
    COMMAND root-config --cflags
    OUTPUT_VARIABLE ROOT_CFLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
    COMMAND root-config --libs
    OUTPUT_VARIABLE ROOT_LIBS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Include ROOT headers using the flags from root-config
include_directories(${ROOT_CFLAGS})

# Also, include the ROOT include path directly (if necessary)
include_directories("/cvmfs/oasis.opensciencegrid.org/jlab/hallb/clas12/sw/almalinux9-gcc11/local/root/6.30.04/include")

# Include your own project's headers (such as DataReader.h)
include_directories(${CMAKE_SOURCE_DIR}/DreamAN)

# Add source files
add_executable(
    AnalysisFramework 
    macros/main.C
    DreamAN/DataReader.cxx
    DreamAN/FirstAnalysis.cxx
)

# Link against ROOT libraries and CLAS12ROOT libraries
target_link_libraries(AnalysisFramework ${ROOT_LIBS} pthread)

# Debugging info (optional)
message(STATUS "ROOT Libraries: ${ROOT_LIBS}")
