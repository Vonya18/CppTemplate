#include "QuizGame.h"
#include <iostream>

void QuizGame::run() {
    if (!quiz.getIsReady()) {
        std::cout << "The quiz is not ready yet." << std::endl;
        return;
    }

    int score = 0;
    const auto& items = quiz.getItems();
    for (const auto& item : items) {
        std::cout << item.getQuestion() << std::endl;
        const auto& answers = item.getAnswers();
        for (size_t i = 0; i < answers.size(); ++i) {
            std::cout << i + 1 << ". " << answers[i] << std::endl;
        }

        int userAnswer;
        std::cout << "Your answer (1-" << answers.size() << "): ";
        std::cin >> userAnswer;

        if (item.isCorrectAnswer(userAnswer - 1)) {
            std::cout << "Correct!" << std::endl;
            ++score;
        } else {
            std::cout << "Incorrect. The correct answer was: " 
                      << answers[item.getCorrectAnswer()] << std::endl;
        }
    }

    double percent = static_cast<double>(score) / items.size() * 100.0;
    user.addResult(quiz.getId(), percent);
    std::cout << "You scored: " << percent << "%" << std::endl;
}