#include <iostream>
#include <string>

using namespace std;

int **getCounterMatrix(int n, int a[], int start, int end) {
    int **res = new int *[n];
    for (int i = 0; i < n; i++) {
        res[i] = new int[n];
        res[i][i] = 1;

    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j + i < n; j++) {
            if (i == 1) {
                if (a[j] < a[j + i]) {
                    res[j + i][j] = 1;
                } else if (a[j] > a[j + i]) {
                    res[j + i][j] = 3;
                }
            } else {
                int k;
                if (i % 2 == 0)
                    k = i / 2;
                else
                    k = i / 2 + 1;
                if (a[j + k - 1] < a[j + k] && res[j + k - 1][j] == 1 && res[j + i][j + k] == 1) {
                    res[j + i][j] = 1;

                } else {
                    res[j + i][j] = res[j + k - 1][j] + res[j + i][j + k] + 1;

                }
            }
        }
    }
    return res;

}

int main() {
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int **matrix = getCounterMatrix(n, a, 0, n - 1);
    for (int i = 0; i < q; i++) {
        int start, end;
        cin >> start >> end;
        cout << matrix[end - 2][start - 1] << endl;
    }
    return 0;
}
