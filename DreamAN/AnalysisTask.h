#ifndef ANALYSIS_TASK_H
#define ANALYSIS_TASK_H

#include "Event.h"

class AnalysisTask {
public:
    virtual ~AnalysisTask() {}
    virtual void UserExec(Event& event) = 0; // Pure virtual function used to be executed for each event
};

#endif // ANALYSIS_TASK_H
