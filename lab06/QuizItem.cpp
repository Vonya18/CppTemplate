#include "QuizItem.h"
#include <iostream>

QuizItem::QuizItem(const std::string& question, const std::vector<std::string>& answers, int correctAnswer)
    : id(nextId++), question(question), answers(answers), correctAnswer(correctAnswer) {}

    int QuizItem::getId() const {
        return id;
    }

    const std::string& QuizItem::getQuestion() const {
        return question;
    }

    const std::vector<std::string>& QuizItem::getAnswers() const {
        return answers;
    }

    bool QuizItem::isCorrectAnswer(int index) const {
        return index == correctAnswer;
    }