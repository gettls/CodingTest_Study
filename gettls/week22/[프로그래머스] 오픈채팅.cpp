#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

// Impl UID ID
vector<string> solution(vector<string> record) {
    map<string, string> id_list; // uid, id
    map<string, int> log; // uid, times
    vector<pair<string, string>> seq; // uid, log
    vector<string> answer;
    string buffer;
    for (int i = 0; i < record.size(); i++) {
        vector<string> tmp;
        istringstream ss(record[i]);
        while (getline(ss, buffer, ' ')) {
            tmp.push_back(buffer);
        }
        string uid = tmp[1];
        if (tmp[0] == "Enter") {
            id_list[uid] = tmp[2];
            //log[uid]++;
            seq.push_back({ tmp[1],"Enter" });
        }
        else if (tmp[0] == "Leave") {
            //log[uid]++;
            seq.push_back({ tmp[1],"Leave" });
        }
        else if (tmp[0] == "Change") {
            id_list[uid] = tmp[2];
        }
    }

    for (int i = 0; i < seq.size(); i++) {
        string uid = seq[i].first;
        string ans;
        if (seq[i].second == "Leave") {
            ans = id_list[uid] + "���� �������ϴ�.";
            answer.push_back(ans);
        }
        else if (seq[i].second == "Enter") {
            ans = id_list[uid] + "���� ���Խ��ϴ�.";
            answer.push_back(ans);
        }
    }

    return answer;
}

/*
    ["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan", "Change uid4567 Ryan"]
    ["Prodo���� ���Խ��ϴ�.","Ryan���� ���Խ��ϴ�.","Prodo���� �������ϴ�.","Prodo���� ���Խ��ϴ�."]
*/