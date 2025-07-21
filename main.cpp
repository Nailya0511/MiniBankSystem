#include <iostream>
#include <string>
#include <unordered_map>
#include <locale> // для setlocale

using namespace std;

// Структура пользователя
struct User {
    string password;
    double balance;
};

// Хранилище пользователей
unordered_map<string, User> users;

// Регистрация нового пользователя
void registerUser() {
    string username, password;
    cout << "Введите имя пользователя: ";
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "Пользователь с таким именем уже существует.\n";
        return;
    }

    cout << "Введите пароль: ";
    cin >> password;

    User newUser;
    newUser.password = password;
    newUser.balance = 0.0;
    users[username] = newUser;

    cout << "Пользователь успешно зарегистрирован!\n";
}

// Авторизация пользователя
int loginUser() {
    string username, password;
    cout << "Введите имя пользователя: ";
    cin >> username;
    cout << "Введите пароль: ";
    cin >> password;

    if (users.find(username) != users.end() && users[username].password == password) {
        cout << "Вход выполнен успешно!\n";
        return 1; // или можно возвращать индекс, если список
    } else {
        cout << "Неверное имя пользователя или пароль.\n";
        return -1;
    }
}

int main() {
    // Включение русского языка в консоли
    setlocale(LC_ALL, "Russian");

    int choice;
    while (true) {
        cout << "\n--- Главное меню ---\n";
        cout << "1. Регистрация\n";
        cout << "2. Вход\n";
        cout << "3. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Выход из программы...\n";
                return 0;
            default:
                cout << "Неверный выбор. Повторите попытку.\n";
        }
    }
}


