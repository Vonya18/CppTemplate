#ifndef USER_H
#define USER_H

class User{
    inline static int nextId = 1; // Static member to keep track of the next ID
    int id;
    std::string name;
    std::map<int, double> results; // Map of quiz ID to score

public:
    explicit User(const std::string& name) : id(0), name(name) {};

    int getId() const; 
    const std::string& getName() const;
    void addResult(int quizId, double percent);
    void printResults() const;


};

#endif