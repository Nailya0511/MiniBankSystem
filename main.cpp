#include <iostream>
#include <string>
#include <unordered_map>
#include <locale>     // ��� setlocale

using namespace std;

// ��������� ��� �������� ������ � �������
struct User {
    string password;
    double balance;
};

// ���������� ��������� �������������
unordered_map<string, User> users;

// ������� �����������
void registerUser() {
    string username, password;
    cout << "���������� �����: ";
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "������������ � ����� ������� ��� ����������.\n";
        return;
    }

    cout << "���������� ������: ";
    cin >> password;

    users[username] = { password, 0.0 };
    cout << "����������� ������ �������!\n";
}

// ������� �����
void loginUser() {
    string username, password;
    cout << "�����: ";
    cin >> username;
    cout << "������: ";
    cin >> password;

    if (users.find(username) != users.end() && users[username].password == password) {
        cout << "�� ����� � ������� " << username << "!\n";
        cout << "��� ������: $" << users[username].balance << "\n";
    }
    else {
        cout << "�������� ����� ��� ������.\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); // ������������� ������� ������

    int choice;

    while (true) {
        cout << "\n--- ����-���� ---\n";
        cout << "1. ������������������\n";
        cout << "2. �����\n";
        cout << "3. �����\n";
        cout << "��� �����: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        }
        else if (choice == 2) {
            loginUser();
        }
        else if (choice == 3) {
            cout << "����� �� ���������.\n";
            break;
        }
        else {
            cout << "�������� �����. ���������.\n";
        }
    }

    return 0;
}


