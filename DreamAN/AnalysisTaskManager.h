#ifndef ANALYSISTASKMANAGER_H
#define ANALYSISTASKMANAGER_H

#include "AnalysisTask.h"
#include <vector>

class AnalysisTaskManager {
    public:
        void AddTask(std::unique_ptr<AnalysisTask> task) {
            tasks.push_back(std::move(task)); // Move ownership
        }
        void ExecuteTasks(Event& event) {
            for (auto& task : tasks) {
                task->UserExec(event);
            }
        }
    
    private:
        std::vector<std::unique_ptr<AnalysisTask>> tasks; // Store smart pointers
};

#endif // ANALYSISTASKMANAGER_H
