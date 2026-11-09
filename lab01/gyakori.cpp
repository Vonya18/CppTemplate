// string 5. feladat: n leggyakoribb szo
// Hasznalat: ./gyakori bible.txt 10
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second != b.second)
        return a.second > b.second;   // gyakorisag szerint csokkeno
    return a.first < b.first;         // egyenlonel abc
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Hasznalat: " << argv[0] << " fajlnev n" << endl;
        return 1;
    }

    ifstream f(argv[1]);
    if (!f) {
        cout << "Nem sikerult megnyitni a fajlt!" << endl;
        return 1;
    }
    int n = atoi(argv[2]);

    map<string, int> counts;
    string word;
    while (f >> word) {
        // csak a betuk maradnak, kisbetuvel
        string clean = "";
        for (int i = 0; i < word.size(); i++) {
            if (isalpha((unsigned char)word[i]))
                clean += tolower(word[i]);
        }
        if (clean != "")
            counts[clean]++;
    }
    f.close();

    vector<pair<string, int> > v(counts.begin(), counts.end());
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n && i < v.size(); i++)
        cout << v[i].first << ": " << v[i].second << endl;

    return 0;
}