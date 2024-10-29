#include <iostream>
#include <string>
using namespace std;

string RemoveBrackets(const string& s) {
    string result;
    size_t start = 0;

    while (start < s.length()) {
        size_t openBracket = s.find("(", start);
        size_t closeBracket = s.find(")", openBracket + 1);

        // Якщо немає більше відкритих або закритих дужок, додаємо залишок рядка
        if (openBracket == string::npos || closeBracket == string::npos) {
            result += s.substr(start);
            break;
        }

        // Перевірка на вкладені дужки
        if (s.find("(", openBracket + 1) < closeBracket) {
            cout << "Помилка: Вкладені дужки виявлені." << endl;
            return "";
        }

        // Додаємо текст перед відкритою дужкою
        result += s.substr(start, openBracket - start);

        // Переміщаємо старт на позицію після закритої дужки
        start = closeBracket + 1;
    }

    return result;
}

int main() {
    string str;
    cout << "Введіть рядок:" << endl;
    getline(cin, str);

    string modifiedString = RemoveBrackets(str);
    if (!modifiedString.empty()) {
        cout << "Рядок після видалення груп символів між дужками: " << modifiedString << endl;
    }

    return 0;
}