#include "ToDoList.h"
#include <fstream>

void ToDoList::addTask(const std::string& desc) {
    tasks.emplace_back(desc);
}

void ToDoList::removeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

void ToDoList::displayTasks() const {
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        tasks[i].display();
    }
}

void ToDoList::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& task : tasks) {
        file << task.description << "," << task.isComplete << "\n";
    }
}

void ToDoList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    tasks.clear();
    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        std::string desc = line.substr(0, commaPos);
        bool isComplete = (line.substr(commaPos + 1) == "1");
        Task task(desc);
        if (isComplete) {
            task.markComplete();
        }
        tasks.push_back(task);
    }
}
