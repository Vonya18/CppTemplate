#pragma once

#include <string>
#include <iostream>
using namespace std;

class FileSystemItem{
protected:
    string name;

public:
    FileSystemItem(const string& name);
    virtual ~FileSystemItem() = default;

    string getName() const;

    virtual void display(ostream& os = cout, int depth = 0) const = 0;
    virtual FileSystemItem* clone() const = 0;
    virtual long getSize() const = 0;

    friend ostream& operator<<(ostream& os, const FileSystemItem& item);
    bool operator<(const FileSystemItem& other) const;
};