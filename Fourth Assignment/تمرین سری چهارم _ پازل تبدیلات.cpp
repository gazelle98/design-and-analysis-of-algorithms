#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 150 + 7;

map<string, int> words;
map<string, int> lower_words;
vector<int> result[MAXN][MAXN];
int adj[MAXN][MAXN];
string s[MAXN];

void BFS(int word) {
    bool visited[MAXN] = {false};


    queue<int> Queue;

    visited[word] = true;

    Queue.push(word);

    while (!Queue.empty()) {
        int s = Queue.front();
        Queue.pop();
        for (int i = 0; i < MAXN; i++) {
            if (adj[s][i] == 1) {
                if (!visited[i]) {
                    visited[i] = true;
                    if (s != word) {
                        result[i][word].pop_back();
                        result[i][word] = result[s][word];
                        result[i][word].push_back(i);
                        Queue.push(i);
                    } else {
                        result[i][word].pop_back();
                        result[i][word].push_back(i);
                        Queue.push(i);
                    }
                }

            }
        }
    }
}

string lower(string str) {
    for (char &m : str) {
        m = char(tolower(int(m)));
    }
    return str;
}

bool isAdjacent(string &a, string &b) {
    int count = 0;
    int a_len = a.length();
    int b_len = b.length();
    string a_lower = lower(a);
    string b_lower = lower(b);


    if (a_len == b_len) {
        for (int i = 0; i < a_len; i++) {
            if (a_lower[i] != b_lower[i]) count++;
            if (count > 1) return false;
        }
        return count == 1;

    } else if (a_len == b_len + 1) {
        int j = 0;
        for (int i = 0; i < a_len; i++) {
            if (i == a_len - 1) {
                return true;
            }
            if (a_lower[i] != b_lower[j++]) {
                a_lower.erase(a_lower.begin() + i);
                break;
            }
        }
        return a_lower == b_lower;

    } else if (b_len == a_len + 1) {
        int j = 0;
        for (int i = 0; i < b_len; i++) {
            if (i == b_len - 1) {
                return true;
            }
            if (b_lower[i] != a_lower[j++]) {
                b_lower.erase(b_lower.begin() + i);
                break;
            }
        }
        return a_lower == b_lower;
    }

    return false;
}


int main() {
    int k, q;
    cin >> k >> q;
    string start, target;
    for (int i = 1; i <= k; i++) {
        cin >> s[i];
        words[s[i]] = i;
        lower_words[lower(s[i])] = i;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = i + 1; j <= k; j++) {
            if (isAdjacent(s[i], s[j])) {
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            result[i][j].push_back(-1);
        }
    }
    for (int i = 1; i <= k; i++) {
        BFS(i);
    }
    for (int i = 0; i < q; i++) {
        cin >> start >> target;
        if (lower(start) == lower(target)) {
            cout << s[lower_words[lower(start)]] << " " << s[lower_words[lower(start)]] << endl;
            continue;
        }
        string lower_start = lower(start);
        string lower_target = lower(target);
        if (result[lower_words[lower_target]][lower_words[lower_start]][0] == -1) {
            cout << "*" << endl;
        } else {
            auto start_word = lower_words[lower(start)];
            auto target_word = lower_words[lower(target)];
            cout << s[start_word] << " ";
            for (int p = 0; p < result[target_word][start_word].size(); p++) {
                int id = result[target_word][start_word][p];
                cout << s[id] << " ";
            }
            cout << endl;

        }
    }
    return 0;
}