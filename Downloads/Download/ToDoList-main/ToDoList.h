#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include "Task.h"

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& desc);
    void removeTask(int index);
    void displayTasks() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
