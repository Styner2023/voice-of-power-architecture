#include "Task.h"

Task::Task(std::string desc) : description(desc), isComplete(false) {}

void Task::markComplete() {
    isComplete = true;
}

void Task::display() const {
    std::cout << (isComplete ? "[X] " : "[ ] ") << description << std::endl;
}
