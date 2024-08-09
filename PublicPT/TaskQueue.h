#pragma once
#include <vector>
#include "Task.h"

using namespace std;

class TaskQueue {
private:
    vector<Task> tasks;

public:
    void addTask(const Task& task);
    void removeTask(const string& title);
    Task* findTask(const string& title);
    void listTasks() const;
    bool isEmpty() const;
};
