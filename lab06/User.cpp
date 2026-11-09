#include "User.h"
#include <iostream>

User::User(const std::string& name) : id(nextId++), name(name) {}

int User::getId() const {
    return id;
}

const std::string& User::getName() const {
    return name;
}

void User::addResult(int quizId, double percent) {
    results[quizId] = percent;
}

void User::printResults() const {
    std::cout << "Results for user: " << name << std::endl;
    for (const auto& [quizId, percent]: results) {
        std::cout << "Quiz ID: " << quizId << ", Score: " << percent << "%" << std::endl;
    }
}
