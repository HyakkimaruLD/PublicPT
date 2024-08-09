#include "TaskQueue.h"
#include <iostream>

void TaskQueue::addTask(const Task& task) {
    tasks.push_back(task);
}

void TaskQueue::removeTask(const string& title) {
    tasks.erase(remove_if(tasks.begin(), tasks.end(),
        [&title](const Task& task) { return task.getTitle() == title; }), tasks.end());
}

Task* TaskQueue::findTask(const string& title) {
    for (auto& task : tasks) {
        if (task.getTitle() == title) {
            return &task;
        }
    }
    return nullptr;
}

void TaskQueue::listTasks() const {
    for (const auto& task : tasks) {
        cout << "Title: " << task.getTitle() << ", Description: " << task.getDescription()
            << ", Priority: " << task.getPriority() << ", Completed: "
            << (task.isCompleted() ? "Yes" : "No") << endl;
    }
}

bool TaskQueue::isEmpty() const {
    return tasks.empty();
}
