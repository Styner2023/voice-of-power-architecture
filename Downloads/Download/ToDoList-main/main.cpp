#include <iostream>
#include "ToDoList.h"

void handleInput(const std::string& input, ToDoList& todoList) {
    if (input == "view") {
        todoList.displayTasks();
    } else if (input.substr(0, 3) == "add") {
        todoList.addTask(input.substr(4));
    } else if (input.substr(0, 6) == "remove") {
        int index = std::stoi(input.substr(7));
        std::cout << "About to remove task.\n";
        todoList.removeTask(index - 1);
        std::cout << "Task removed.\n";
    } else if (input == "save") {
        todoList.saveToFile("tasks.txt");
    } else if (input == "load") {
        todoList.loadFromFile("tasks.txt");
    } else {
        std::cout << "Invalid command. Try again.\n";
    }
}

int main() {
    ToDoList todoList;
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        }
        handleInput(input, todoList);
    }
    return 0;
}
