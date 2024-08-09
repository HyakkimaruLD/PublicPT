#include "TaskManager.h"

void TaskManager::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void TaskManager::removeObserver(Observer* observer) {
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void TaskManager::notifyObservers(const Task& task) {
    for (auto observer : observers) {
        observer->update(task);
    }
}

void TaskManager::addTask(const Task& task) {
    taskQueue.addTask(task);
    notifyObservers(task);
}

void TaskManager::completeTask(const string& title) {
    Task* task = taskQueue.findTask(title);
    if (task) {
        task->markCompleted();
        notifyObservers(*task);
    }
}

void TaskManager::displayTasks() const {
    taskQueue.listTasks();
}
