#include "UserInterface.h"
#include "Logger.h"
#include <iostream>

UserInterface::UserInterface(TaskManager& taskManager) : taskManager(taskManager) {
    taskManager.addObserver(this);
}

void UserInterface::run() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            handleAddTask();
            break;
        case 2:
            handleCompleteTask();
            break;
        case 3:
            handleDisplayTasks();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);
}

void UserInterface::update(const Task& task) {
    Logger::getInstance()->log("Task updated: " + task.getTitle());
}

void UserInterface::displayMenu() {
    cout << "\nTask Management System\n";
    cout << "1. Add Task\n";
    cout << "2. Complete Task\n";
    cout << "3. Display Tasks\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

void UserInterface::handleAddTask() {
    string title, description;
    int priority;

    cout << "Enter Task Title: ";
    getline(cin, title);
    cout << "Enter Task Description: ";
    getline(cin, description);
    cout << "Enter Task Priority (1-High, 2-Medium, 3-Low): ";
    cin >> priority;
    cin.ignore();

    Task task(title, description, priority);
    taskManager.addTask(task);
}

void UserInterface::handleCompleteTask() {
    string title;
    cout << "Enter Task Title to complete: ";
    getline(cin, title);

    taskManager.completeTask(title);
}

void UserInterface::handleDisplayTasks() {
    taskManager.displayTasks();
}
