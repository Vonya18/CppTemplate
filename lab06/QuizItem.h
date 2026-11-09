#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <vector>
#include <iostream>
#include <string>

class QuizItem {
    inline static int nextId = 1; // Static member to keep track of the next ID
    int id;
    std::string question;
    std::vector<std::string> answers;
    int correctAnswer;

public:
    explicit QuizItem(const std::string& question,
                     const std::vector<std::string>& answers = {},
                     int correctAnswer = -1)
        : id(nextId++), question(question), answers(answers), correctAnswer(correctAnswer) {};

        int getId() const;
        const std::string& getQuestion() const;
        const std::vector<std::string>& getAnswers() const;
        bool isCorrectAnswer(int index) const;

};

#endif