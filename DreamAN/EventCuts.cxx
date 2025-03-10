#include "EventCuts.h"

EventCuts::EventCuts(double threshold) : threshold(threshold) {}

bool EventCuts::passesCut(double value) const {
    return value > threshold;
}

