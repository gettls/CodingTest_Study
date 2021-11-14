#include <string>
#include <vector>
#include <stack>
using namespace std;
// �������� ��ȣ ���ڿ�, �ùٸ� ��ȣ ���ڿ�
// 1. �� ������ -> �� ���ڿ� ��ȯ
// 2. w => u(�� �̻� �и� �Ұ�), v(�� ���ڿ� ����) �и� (�������� ��ȣ ���ڿ�)

// 3. u (�ùٸ� ���ڿ�) -> v�� 1������
// 3-1. u �� ����� ���� ����

// 4. u (�ùٸ� ���ڿ� X)
// 4.1. �� ���ڿ��� '(' ����
// 4.2 v �� 1 ������ ������ ����� '('�� ���� ����
// 4.3 ')' ����
// 4.4 u �� ó��, ������ ���� �����ϰ� ������ ���� �ٲ㼭 �ڿ� ����
// 4.5 ��ȯ
string answer = "";
string w;
bool isBalanced(string str) { // �������� ���ڿ�
    stack<char> a, b;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ')') a.push(str[i]);
        else b.push(str[i]);
    }
    if (a.size() == b.size()) return true;
    return false;
}

bool isCorrect(string str) { // �ùٸ� ���ڿ�
    stack<char> s;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') s.push(str[i]);
        else {
            if (s.empty()) return false;
            s.pop();
        }
    }
    if (!s.empty()) return false;
    return true;
}

string convert(string str) {
    str.erase(0, 1);
    str.erase(str.end() - 1, str.end());
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') str[i] = ')';
        else str[i] = '(';
    }
    return str;
}

string go(string u) {
    if (u == "") return u;
    else {
        string a, b;
        for (int i = 0; i < u.size(); i++) {
            a = u.substr(0, i + 1);
            if (i + 1 < u.size())b = u.substr(i + 1);
            else b = "";
            if (isCorrect(a)) {
                return a += go(b);
            }
            else if (isBalanced(a)) {
                string tmp = "(";
                tmp += go(b) + ")";
                tmp += convert(a);
                return  a = tmp;
            }
        }
    }
}


string solution(string p) {
    w = p;
    answer = go(p);
    return answer;
}


int main() {
    solution("()))((()");
}