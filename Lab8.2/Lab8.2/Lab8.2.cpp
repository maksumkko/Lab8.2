#include <iostream>
#include <string>
using namespace std;

string RemoveBrackets(const string& s) {
    string result;
    size_t start = 0;

    while (start < s.length()) {
        size_t openBracket = s.find("(", start);
        size_t closeBracket = s.find(")", openBracket + 1);

        // ���� ���� ����� �������� ��� �������� �����, ������ ������� �����
        if (openBracket == string::npos || closeBracket == string::npos) {
            result += s.substr(start);
            break;
        }

        // �������� �� ������� �����
        if (s.find("(", openBracket + 1) < closeBracket) {
            cout << "�������: ������� ����� �������." << endl;
            return "";
        }

        // ������ ����� ����� �������� ������
        result += s.substr(start, openBracket - start);

        // ��������� ����� �� ������� ���� ������� �����
        start = closeBracket + 1;
    }

    return result;
}

int main() {
    string str;
    cout << "������ �����:" << endl;
    getline(cin, str);

    string modifiedString = RemoveBrackets(str);
    if (!modifiedString.empty()) {
        cout << "����� ���� ��������� ���� ������� �� �������: " << modifiedString << endl;
    }

    return 0;
}