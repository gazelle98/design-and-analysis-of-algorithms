#include <iostream>
#include <string>

using namespace std;

int getMaxPaperForJavad(int *a, int n) {
    int matrix[n][4000 + 1];
    for (int i = 2000; i < 4000 + 1; i++) {
        matrix[0][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2000; j++) {
            matrix[i][j] = matrix[i - 1][a[i] + j];
        }
        for (int j = 2000; j < 4000 + 1; j++) {
            matrix[i][j] = max(matrix[i - 1][j - a[i]] + 1, matrix[i - 1][a[i] + 2000]);
        }

    }
    return matrix[n - 1][2000];
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << getMaxPaperForJavad(a, n);
    return 0;
}

