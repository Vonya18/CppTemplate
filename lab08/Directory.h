#pragma once

#include "FileSystemItem.h"
#include <vector>

class Directory : public FileSystemItem {
private:
    vector<FileSystemItem*> children;

public:
    Directory(const string& name);
    virtual ~Directory();

    Directory(const Directory& other);
    Directory& operator=(Directory other);

    void add(FileSystemItem* item);
    void remove(const string& name);
    FileSystemItem* find(const string& name);

    long getSize() const override;
    void display(ostream& os = cout, int depth = 0) const override;
    FileSystemItem* clone() const override;

    Directory& operator+=(FileSystemItem* item);
    Directory& operator-=(const string& name);
};  