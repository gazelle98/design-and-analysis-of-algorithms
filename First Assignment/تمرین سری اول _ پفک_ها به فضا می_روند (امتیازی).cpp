#include <iostream>
#include <string>

using namespace std;

long long merge(long long a[], long long p, long long q, long long r) {
    long long counter = 0;
    long long n1 = q - p + 1;
    long long n2 = r - q;
    long long left[n1], right[n2];
    for (long i = 0; i < n1; i++) {
        left[i] = a[p + i];
    }
    for (long i = 0; i < n2; i++) {
        right[i] = a[q + i + 1];
    }
    long long i = 0;
    long long j = 0;
    long long k = p;
    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
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

long long mergeSort(long long a[], long long p, long long r) {
    long long res = 0;
    long long q;
    if (p < r) {
        q = p + ((r - p) / 2);
        res += mergeSort(a, p, q);
        res += mergeSort(a, q + 1, r);
        res += merge(a, p, q, r);
    }
    return res;
}

int main() {
    long long n;
    cin >> n;
    long long a[n];
    long long result = 0;
    for (long i = 0; i < n; i++) {
        cin >> a[i];
    }
    result = mergeSort(a, 0, n - 1);
    cout << result % 1000000007;
    return 0;
}