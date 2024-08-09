#include "Task.h"

Task::Task(const string& title, const string& description, int priority)
    : title(title), description(description), priority(priority), completed(false) {}

string Task::getTitle() const { return title; }
string Task::getDescription() const { return description; }
int Task::getPriority() const { return priority; }
bool Task::isCompleted() const { return completed; }

void Task::setTitle(const string& title) { this->title = title; }
void Task::setDescription(const string& description) { this->description = description; }
void Task::setPriority(int priority) { this->priority = priority; }
void Task::markCompleted() { completed = true; }
