#include "File.h"

File::File(const string& name, long size) : FileSystemItem(name), size(size) {}

long File::getSize() const {
    return size;
}

void File::display(ostream& os, int depth) const {
    for (int i = 0; i < depth; ++i) {
        os << "  "; // Indentation for depth
    }
    os << name << " (" << size << " bytes)" << endl;
}

FileSystemItem* File::clone() const {
    return new File(*this);
}

