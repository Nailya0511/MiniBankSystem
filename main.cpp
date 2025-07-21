#include <iostream>
#include <string>
#include <unordered_map>
#include <locale>     // äëÿ setlocale

using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");

// Ñòðóêòóðà äëÿ õðàíåíèÿ äàííûõ î êëèåíòå
struct User {
    string password;
    double balance;
};

// Ãëîáàëüíîå õðàíèëèùå ïîëüçîâàòåëåé
unordered_map<string, User> users;

// Ôóíêöèÿ ðåãèñòðàöèè
void registerUser() {
    string username, password;
    cout << "Ïðèäóìàéòå ëîãèí: ";
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "Ïîëüçîâàòåëü ñ òàêèì ëîãèíîì óæå ñóùåñòâóåò.\n";
        return;
    }

    cout << "Ïðèäóìàéòå ïàðîëü: ";
    cin >> password;

    users[username] = { password, 0.0 };
    cout << "Ðåãèñòðàöèÿ ïðîøëà óñïåøíî!\n";
}

// Ôóíêöèÿ âõîäà
void loginUser() {
    string username, password;
    cout << "Ëîãèí: ";
    cin >> username;
    cout << "Ïàðîëü: ";
    cin >> password;

    if (users.find(username) != users.end() && users[username].password == password) {
        cout << "Âû âîøëè â àêêàóíò " << username << "!\n";
        cout << "Âàø áàëàíñ: $" << users[username].balance << "\n";
    }
    else {
        cout << "Íåâåðíûé ëîãèí èëè ïàðîëü.\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); // Óñòàíàâëèâàåì ðóññêóþ ëîêàëü

    int choice;

    while (true) {
        cout << "\n--- Ìèíè-Áàíê ---\n";
        cout << "1. Çàðåãèñòðèðîâàòüñÿ\n";
        cout << "2. Âîéòè\n";
        cout << "3. Âûõîä\n";
        cout << "Âàø âûáîð: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        }
        else if (choice == 2) {
            loginUser();
        }
        else if (choice == 3) {
            cout << "Âûõîä èç ïðîãðàììû.\n";
            break;
        }
        else {
            cout << "Íåâåðíûé âûáîð. Ïîâòîðèòå.\n";
        }
    }

    return 0;
}


