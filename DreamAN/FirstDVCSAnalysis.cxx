#include "FirstDVCSAnalysis.h"

FirstDVCSAnalysis::FirstDVCSAnalysis(double threshold) : threshold(threshold) {}
bool FirstDVCSAnalysis::passesCut(double value) const {
    return value > threshold;
}