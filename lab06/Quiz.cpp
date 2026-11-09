#include "Quiz.h"
#include <iostream>

Quiz::Quiz(const std::string& name, const std::vector<QuizItem>& items, bool isReady)
    : id(nextId++), name(name), items(items), isReady(false) {}

void Quiz::addItem(const QuizItem& item) {
    if (isReady) throw std::logic_error("a kviz le van zarva");
    items.push_back(item);
}

void Quiz::finalize() {
    isReady = true;
}

int Quiz::getId() const {
    return id;}

const std::string& Quiz::getName() const {
    return name;
}

const std::vector<QuizItem>& Quiz::getItems() const {
    return items;
}

bool Quiz::getIsReady() const {
    return isReady;
}