#include <iostream>
#include <string>

using namespace std;

long merge(long a[], long p, long q, long r) {
    long counter = 0;
    long n1 = q - p + 1;
    long n2 = r - q;
    long left[n1], right[n2];
    for (int i = 0; i < n1; i++) {
        left[i] = a[p + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = a[q + i + 1];
    }
    long i = 0;
    long j = 0;
    long k = p;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
            counter += q + 1 - (p + i);
        }
        k++;
    }
    while (i < n1) {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = right[j];
        j++;
        k++;
    }
    return counter;
}

long mergeSort(long a[], long p, long r) {
    long res = 0;
    long q;
    if (p < r) {
        q = p + ((r - p) / 2);
        res += mergeSort(a, p, q);
        res += mergeSort(a, q + 1, r);
        res += merge(a, p, q, r);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    long a[n];
    long result = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    result = mergeSort(a, 0, n - 1);
    cout << result % 1000000007;
    return 0;
}