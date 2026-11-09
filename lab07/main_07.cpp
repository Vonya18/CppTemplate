#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cctype>
#include <random>

using namespace std;

struct FurcsaAbc {
    unsigned char abc[256];

    FurcsaAbc() {
        unsigned char tmp[256];
        for (int i = 0; i < 256; ++i) {
            tmp[i] = i;
        }

        random_device rd;
        mt19937 rg(rd());
        shuffle(tmp, tmp + 256, rg);

        for (int i = 0; i < 256; ++i) {
            abc[tmp[i]] = i;
        }
    }

    // Ez a függvény hasonlítja össze a sztringeket (pl. hónapokat) a furcsa ábécé szerint
    bool operator() (const string& a, const string& b) const {
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [this](char c1, char c2) {
            return abc[static_cast<size_t>(c1)] < abc[static_cast<size_t>(c2)];
        });
    }
};

int main() {
    // ==========================================
    // 1. FELADAT
    // ==========================================
    cout << "--- 1. Feladat ---" << endl;
    vector<string> fruits {
        "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
    };
    string keresett = "berry";
    auto it1 = find_if(fruits.begin(), fruits.end(), [&keresett](const string& s) {
        return s.find(keresett) != string::npos;
    });
    if (it1 != fruits.end()) {
        cout << "Talalat: " << *it1 << endl;
    } else {
        cout << "Nincs talalat." << endl;
    }
    cout << endl;

    // ==========================================
    // 2. FELADAT
    // ==========================================
    cout << "--- 2. Feladat ---" << endl;
    vector<int> szamok2 = {2, 4, 6, 8, 10};
    bool minden_paros = all_of(szamok2.begin(), szamok2.end(), [](int n) {
        return n % 2 == 0;
    });
    cout << "Minden elem paros? " << (minden_paros ? "Igen" : "Nem") << endl << endl;

    // ==========================================
    // 3. FELADAT
    // ==========================================
    cout << "--- 3. Feladat ---" << endl;
    vector<int> szamok3 = {1, 2, 3, 4, 5};
    for_each(szamok3.begin(), szamok3.end(), [](int& n) {
        n *= 2;
    });
    cout << "Duplazott szamok: ";
    for_each(szamok3.begin(), szamok3.end(), [](int n) { cout << n << " "; });
    cout << endl << endl;

    // ==========================================
    // 4. FELADAT
    // ==========================================
    cout << "--- 4. Feladat ---" << endl;
    vector<string> months {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    long darab = count_if(months.begin(), months.end(), [](const string& m) {
        return m.length() == 5;
    });
    cout << "Az 5 betubol allo honapok szama: " << darab << endl << endl;

    // ==========================================
    // 5. FELADAT
    // ==========================================
    cout << "--- 5. Feladat ---" << endl;
    vector<double> valosak5_1 = {3.5, 1.2, 5.8, 2.1};
    vector<double> valosak5_2 = {3.5, 1.2, 5.8, 2.1};

    sort(valosak5_1.begin(), valosak5_1.end(), [](double a, double b) {
        return a > b;
    });
    cout << "Csokkeno sorrend (lambda): ";
    for_each(valosak5_1.begin(), valosak5_1.end(), [](double n) { cout << n << " "; });
    cout << endl;

    sort(valosak5_2.begin(), valosak5_2.end(), greater<double>());
    cout << "Csokkeno sorrend (greater): ";
    for_each(valosak5_2.begin(), valosak5_2.end(), [](double n) { cout << n << " "; });
    cout << endl << endl;

    // ==========================================
    // 6. FELADAT
    // ==========================================
    cout << "--- 6. Feladat ---" << endl;
    vector<pair<string, double>> evszak_homerseklet = {
        {"January", -2.5}, {"February", -1.0}, {"March", 4.0},
        {"April", 10.5}, {"May", 16.0}, {"June", 20.0},
        {"July", 22.0}, {"August", 21.5}, {"September", 16.5},
        {"October", 10.0}, {"November", 4.5}, {"December", -1.0}
    };
    sort(evszak_homerseklet.begin(), evszak_homerseklet.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    cout << "Leghidegebb honap: " << evszak_homerseklet.front().first << " (" << evszak_homerseklet.front().second << " C)" << endl;
    cout << "Legmelegebb honap: " << evszak_homerseklet.back().first << " (" << evszak_homerseklet.back().second << " C)" << endl << endl;

    // ==========================================
    // 7. FELADAT
    // ==========================================
    cout << "--- 7. Feladat ---" << endl;
    vector<double> szamok7 = {-5.5, 2.1, -1.2, 3.4};
    sort(szamok7.begin(), szamok7.end(), [](double a, double b) {
        return abs(a) < abs(b);
    });
    cout << "Abszolutertenek szerint rendezve: ";
    for_each(szamok7.begin(), szamok7.end(), [](double n) { cout << n << " "; });
    cout << endl << endl;

    // ==========================================
    // 8. FELADAT
    // ==========================================
    cout << "--- 8. Feladat ---" << endl;
    vector<string> months_kisbetus = months;
    transform(months_kisbetus.begin(), months_kisbetus.end(), months_kisbetus.begin(), [](string s) {
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return tolower(c);
        });
        return s;
    });
    
    cout << "Kisbetusitett honapok: ";
    for_each(months_kisbetus.begin(), months_kisbetus.end(), [](const string& s) {
        cout << s << " ";
    });
    cout << endl << endl;

    // ==========================================
    // 9. FELADAT
    // ==========================================
    cout << "--- 9. Feladat ---" << endl;
    vector<string> months_furcsa = months_kisbetus;

    // Létrehozzuk a tanár struktúráját (ez véletlenszerűen összekeveri a karaktereket a konstruktorban)
    FurcsaAbc furcsa_rendezo;

    // Rendezzük a kisbetűs hónapneveket a furcsa ábécé szerint
    sort(months_furcsa.begin(), months_furcsa.end(), furcsa_rendezo);

    cout << "Rendezett honapok a furcsa abece szerint:\n";
    for_each(months_furcsa.begin(), months_furcsa.end(), [](const string& s) {
        cout << " - " << s << endl;
    });

    return 0;
}