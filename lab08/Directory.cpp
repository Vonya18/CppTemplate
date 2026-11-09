#include "Directory.h"
#include "File.h"
#include <algorithm>

Directory::Directory(const string& name) : FileSystemItem(name) {}

Directory::~Directory() {
    for (auto child : children) {
        delete child;
    }
}

Directory::Directory(const Directory& other) : FileSystemItem(other.name) {
    for (auto child : other.children) {
        children.push_back(child->clone());
    }
}

Directory& Directory::operator=(Directory other) {
    std::swap(name, other.name);
    std::swap(children, other.children);
    return *this;
}

void Directory::add(FileSystemItem* item) {
    children.push_back(item);
}

void Directory::remove(const string& name) {
    auto it = std::remove_if(children.begin(), children.end(),
                             [&name](FileSystemItem* item) { return item->getName() == name; });
    if (it != children.end()) {
        delete *it; // Free memory
        children.erase(it, children.end());
    }
}

FileSystemItem* Directory::find(const string& name) {
    for (auto child : children) {
        if (child->getName() == name) {
            return child;
        }
    }
    return nullptr;
}

long Directory::getSize() const {
    long totalSize = 0;
    for (auto child : children) {
        totalSize += child->getSize();
    }
    return totalSize;
}

void Directory::display(ostream& os, int depth) const {
    for (int i = 0; i < depth; ++i) {
        os << "  "; // Indentation for depth
    }
    os << name << " (Directory)" << endl;
    for (auto child : children) {
        child->display(os, depth + 1);
    }
}

FileSystemItem* Directory::clone() const {
    return new Directory(*this);
}

Directory& Directory::operator+=(FileSystemItem* item) {
    add(item);
    return *this;
}

Directory& Directory::operator-=(const string& name) {
    remove(name);
    return *this;
}

