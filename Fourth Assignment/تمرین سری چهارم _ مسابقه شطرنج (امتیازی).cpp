#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int n, m;
string s[305];
int result = 0;
int tmp[305];
vector<vector<bool>> boolean_board(305, vector<bool>(305));

bool bipartiteMatching(int i, bool seen[], int tmp[], int m) {
    for (int j = 0; j < m; j++) {
        if (boolean_board[i][j] && !seen[j]) {
            seen[j] = true;

            if (tmp[j] == -1 || bipartiteMatching(tmp[j], seen, tmp, m)) {
                tmp[j] = i;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                boolean_board[i][j] = 1;
            } else {
                boolean_board[i][j] = 0;
            }
        }
    }
    memset(tmp, -1, sizeof(tmp));
    for (int i = 0; i < n; i++) {
        bool seen[m];
        memset(seen, 0, sizeof(seen));
        bool is_chosen = bipartiteMatching(i, seen, tmp, m);
        if (is_chosen) {
            result++;
        }
    }

    cout << result;
    return 0;
}