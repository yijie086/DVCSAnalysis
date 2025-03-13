cmake_minimum_required(VERSION 3.10)
project(AnalysisFramework)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Check if CLAS12ROOT environment is set
if(NOT DEFINED ENV{CLAS12ROOT})
    message(FATAL_ERROR "CLAS12ROOT environment variable not set!")
endif()

# Set the HIPO4 path
set(HIPO4 "/u/scigroup/cvmfs/hallb/clas12/sw/almalinux9-gcc11/local/hipo/4.2.0")

# Include ROOT headers using the flags from root-config (if necessary)
execute_process(
    COMMAND root-config --cflags
    OUTPUT_VARIABLE ROOT_CFLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# You can also use the ROOT library via 'root-config'
execute_process(
    COMMAND root-config --libs
    OUTPUT_VARIABLE ROOT_LIBS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Include ROOT headers
include_directories(${ROOT_CFLAGS})

# Include CLAS12ROOT headers
include_directories(${CLAS12ROOT}/Clas12Root)
include_directories(${CLAS12ROOT}/Clas12Banks)
include_directories("/u/scigroup/cvmfs/hallb/clas12/sw/almalinux9-gcc11/local/clas12root/1.8.5/4.2.0/Clas12Banks")
include_directories("/u/scigroup/cvmfs/hallb/clas12/sw/almalinux9-gcc11/local/clas12root/1.8.5/4.2.0/Clas12Root")
include_directories("/cvmfs/oasis.opensciencegrid.org/jlab/hallb/clas12/sw/almalinux9-gcc11/local/root/6.30.04/include")

# Include HIPO4 headers
include_directories(${HIPO4}/include)

# Link the libraries
link_directories(${CLAS12ROOT}/lib)  # Make sure this is correct
link_directories(${HIPO4}/lib)


# Add the path to Clas12Root and Clas12Banks libraries
link_directories("/u/scigroup/cvmfs/hallb/clas12/sw/almalinux9-gcc11/local/clas12root/1.8.5/4.2.0/lib")

# Add your source files
add_executable(AnalysisFramework
    macros/main.C
    macros/RunDVCSAnalysis.C
    DreamAN/EventProcessor.cxx
    DreamAN/Event.cxx
    DreamAN/EventCuts.cxx
    DreamAN/TrackCuts.cxx
  
    DreamAN/DVCSAnalysis.cxx
)

# Link against ROOT libraries, CLAS12ROOT libraries, and HIPO4
target_link_libraries(AnalysisFramework
    ${ROOT_LIBS}
    pthread
    Clas12Root  # Link against the precompiled Clas12Root library
    Clas12Banks
    hipo4
)

# Debugging info (optional)
message(STATUS "ROOT Libraries: ${ROOT_LIBS}")
