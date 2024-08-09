#pragma once
#include <vector>
#include "TaskQueue.h"

using namespace std;

class Observer {
public:
    virtual void update(const Task& task) = 0;
};

class TaskManager {
private:
    TaskQueue taskQueue;
    vector<Observer*> observers;

public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers(const Task& task);
    void addTask(const Task& task);
    void completeTask(const string& title);
    void displayTasks() const;
};
