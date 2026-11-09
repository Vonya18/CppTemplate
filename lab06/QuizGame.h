#ifndef QUIZGAME_H
#define QUIZGAME_H

#include "Quiz.h"
#include "User.h"

class QuizGame {
    User &user;
    Quiz &quiz;

public:
    QuizGame(User &user, Quiz &quiz) : user(user), quiz(quiz) {}

    void run();

};

#endif