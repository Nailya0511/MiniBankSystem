#include <iostream>
#include <string>
#include <unordered_map>
#include <locale>     // для setlocale

using namespace std;

// Структура для хранения данных о клиенте
struct User {
    string password;
    double balance;
};

// Глобальное хранилище пользователей
unordered_map<string, User> users;

// Функция регистрации
void registerUser() {
    string username, password;
    cout << "Придумайте логин: ";
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "Пользователь с таким логином уже существует.\n";
        return;
    }

    cout << "Придумайте пароль: ";
    cin >> password;

    users[username] = { password, 0.0 };
    cout << "Регистрация прошла успешно!\n";
}

// Функция входа
void loginUser() {
    string username, password;
    cout << "Логин: ";
    cin >> username;
    cout << "Пароль: ";
    cin >> password;

    if (users.find(username) != users.end() && users[username].password == password) {
        cout << "Вы вошли в аккаунт " << username << "!\n";
        cout << "Ваш баланс: $" << users[username].balance << "\n";
    }
    else {
        cout << "Неверный логин или пароль.\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем русскую локаль

    int choice;

    while (true) {
        cout << "\n--- Мини-Банк ---\n";
        cout << "1. Зарегистрироваться\n";
        cout << "2. Войти\n";
        cout << "3. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        }
        else if (choice == 2) {
            loginUser();
        }
        else if (choice == 3) {
            cout << "Выход из программы.\n";
            break;
        }
        else {
            cout << "Неверный выбор. Повторите.\n";
        }
    }

    return 0;
}


