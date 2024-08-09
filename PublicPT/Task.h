#pragma once
#include <string>

using namespace std;

class Task {
private:
    string title;
    string description;
    int priority; // 1 - High, 2 - Medium, 3 - Low
    bool completed;

public:
    Task(const string& title, const string& description, int priority);

    string getTitle() const;
    string getDescription() const;
    int getPriority() const;
    bool isCompleted() const;

    void setTitle(const string& title);
    void setDescription(const string& description);
    void setPriority(int priority);
    void markCompleted();
};
