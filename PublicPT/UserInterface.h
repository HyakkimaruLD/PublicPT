#pragma once
#include "TaskManager.h"

class UserInterface : public Observer {
private:
    TaskManager& taskManager;

public:
    UserInterface(TaskManager& taskManager);

    void run();
    void update(const Task& task) override;

    void displayMenu();
    void handleAddTask();
    void handleCompleteTask();
    void handleDisplayTasks();
};
