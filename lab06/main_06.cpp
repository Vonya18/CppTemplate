#include <iostream>
#include "QuizItem.h"
#include "Quiz.h"
#include "User.h"
#include "QuizGame.h"
int main() {

    quiz.addItem(QuizItem("Melyik kulcsszo oroklest jelol?", {"class", "public", "static"}, 1));
    quiz.addItem(QuizItem("Mi a kompozicio?", {"Szoros tartalmazas", "Laza tartalmazas", "Template"}, 0));
    quiz.addItem(QuizItem("Melyik tarolo asszociativ?", {"vector", "list", "map"}, 2));
    quiz.finalize();
 
    User user("Bela");
    QuizGame game(user, quiz);
    game.run();
 
    user.printResults();
    return 0;
}