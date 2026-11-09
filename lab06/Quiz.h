#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <vector>
#include <iostream>

class Quiz {
    inline static int nextId = 1; // Static member to keep track of the next ID
    int id;
    std::string name;
    std::vector<QuizItem> items;
    bool isReady;

public:
    explicit Quiz(const std::string& name,
                  const std::vector<QuizItem>& items = {},
                  bool isReady = false)
        : id(nextId++), name(name), items(items), isReady(isReady) {};

        void addItem(const QuizItem& item);
        void finalize();

        int getId() const;
        const std::string& getName() const;
        const std::vector<QuizItem>& getItems() const;
        bool getIsReady() const;

};

#endif