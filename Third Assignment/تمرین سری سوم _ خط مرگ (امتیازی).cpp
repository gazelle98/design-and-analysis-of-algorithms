#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> lesson;

bool compare_pair(lesson a, lesson b) {
    return (a.second.first * b.second.second) > (a.second.second * b.second.first);
}

vector<int> penaltySorted(vector<int> p, vector<int> w, int first, int last) {
    vector<lesson> list;
    vector<int> result;
    for (int i = first; i <= last; i++) {
        list.push_back(make_pair(i + 1, make_pair(w[i], p[i])));
    }
    stable_sort(list.begin(), list.end(), compare_pair);
    for (int i = 0; i < list.size(); i++) {
        result.push_back(list[i].first - 1);
    }
    return result;
}


int main() {
    int n;
    cin >> n;
    int k[n];
    vector<int> p;
    vector<int> w;
    vector<int> each_lesson[n];
    vector<int> sum_of_w;
    vector<int> sum_of_p;
    vector<int> result;
    int total_sum = 0;
    int total_p = 0;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        each_lesson[i] = vector<int>();
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < k[i]; j++) {
            int tmp;
            cin >> tmp;
            p.push_back(tmp);
            sum += tmp;
        }
        sum_of_p.push_back(sum);
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < k[i]; j++) {
            int tmp;
            cin >> tmp;
            w.push_back(tmp);
            sum += tmp;
        }
        sum_of_w.push_back(sum);
    }
    for (int i = 0; i < n; i++) {
        counter += k[i];
        each_lesson[i] = penaltySorted(p, w, counter - k[i], counter - 1);
    }

    result = penaltySorted(sum_of_p, sum_of_w, 0, n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k[result[i]]; j++) {
            total_sum += (p[each_lesson[result[i]][j]] + total_p) * w[each_lesson[result[i]][j]];
            total_p += p[each_lesson[result[i]][j]];
        }
    }
    cout << total_sum << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k[result[i]]; j++) {
            cout << each_lesson[result[i]][j] + 1 << endl;
        }
    }

    return 0;
}