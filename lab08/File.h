#pragma once

#include "FileSystemItem.h"

class File : public FileSystemItem {
private:
    long size;

public:
    File(const string& name, long size);

    long getSize() const override;
    void display(ostream& os = cout, int depth = 0) const override;
    FileSystemItem* clone() const override;
};