#include <string>
#include <vector>
#include <queue>
using namespace std;

int num[1440]; // 1 ~ 1439
// n ȸ, t ��, m ��
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> v;
    for (int i = 0; i < timetable.size(); i++) {
        string tmp[2];
        tmp[0] = timetable[i].substr(0, 2); // hour
        tmp[1] = timetable[i].substr(3); // min
        num[stoi(tmp[0]) * 60 + stoi(tmp[1])]++;
    }

    int cnt = 0, start = 540, p = 0;
    for (int i = 1; i < 1440; i++) {
        if (num[i] > 0) {
            cnt += num[i];
        }
        if (cnt >= m * n) { // ������ ������ �¿� ������ �ʰ����� ��
            p = i - 1;
            break;
        }
        if (i == start) { // ��߽ð����� ����, ���� Ƚ�� ����
            if (cnt - m > 0) cnt -= m;
            else cnt = 0;
            n--;
            start += t;
        }

        if (n == 0) { // ������ ��Ʋ
            p = i;
        }
    }

    string time, min;
    if (p / 60 >= 10) time = to_string(p / 60);
    else time = "0" + to_string(p / 60);

    if (p % 60 >= 10) min = to_string(p % 60);
    else min = "0" + to_string(p % 60);

    answer = time + ":" + min;

    return answer;
}
int main() {
    solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" });
}