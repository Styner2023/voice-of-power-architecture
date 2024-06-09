#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

class Task {
public:
    std::string description;
    bool isComplete;

    Task(std::string desc);
    void markComplete();
    void display() const;
};

#endif
