#include "FileSystemItem.h"

FileSystemItem::FileSystemItem(const string& name) : name(name) {}

string FileSystemItem::getName() const {
    return name;
}

ostream& operator<<(ostream& os, const FileSystemItem& item) {
    item.display(os, 0);
    return os;
}

bool FileSystemItem::operator<(const FileSystemItem& other) const {
    return this-> name < other.name;
}