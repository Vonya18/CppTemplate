#include <iostream>
#include "File.h"
#include "Directory.h"

using namespace std;

int main() {
    cout << "=== Fajlrendszer Szimulacio ===" << endl << endl;

    // 1. Gyökér könyvtár létrehozása
Directory* root = new Directory("root");

// 2. Struktúra felépítése
cout << "Fajlrendszer felepitese..." << endl;

// Documents könyvtár
Directory* documents = new Directory("documents");
documents->add(new File("report.txt", 1500));
documents->add(new File("notes.txt", 800));

// Pictures könyvtár
Directory* pictures = new Directory("pictures");
pictures->add(new File("photo1.jpg", 2048000));
pictures->add(new File("photo2.jpg", 1856000));

// Root-hoz hozzáadás operátor használatával
*root += documents;
*root += pictures;
*root += new File("readme.txt", 500);

// 3. Teljes struktúra megjelenítése
cout << endl << "Teljes fajlrendszer:" << endl;
cout << "=====================" << endl;
root->display();

// 4. Teljes méret kiírása
cout << endl << "Teljes meret: " << root->getSize() << " bytes" << endl;
    return 0;
}