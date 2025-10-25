#include <iostream>
using namespace std;

void quickSort(long long arr[], int l, int r) {
    if (l >= r) return;
    long long pivot = arr[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    quickSort(arr, l, i - 1);
    quickSort(arr, i + 1, r);
}

int lowerBound(long long arr[], int n, long long x) {
    int l = 0, r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}

int upperBound(long long arr[], int n, long long x) {
    int l = 0, r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] <= x) l = m + 1;
        else r = m;
    }
    return l;
}

long long countIn(long long arr[], int n, long long L, long long R) {
    if (L > R) return 0;
    int left = lowerBound(arr, n, L);
    int right = upperBound(arr, n, R);
    return right - left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    long long* a = new long long[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    quickSort(a, 0, n - 1);

    while (q--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        long long c1 = countIn(a, n, l1, r1);
        long long c2 = countIn(a, n, l2, r2);
        long long overL = max(l1, l2);
        long long overR = min(r1, r2);
        long long overlap = countIn(a, n, overL, overR);

        cout << (c1 + c2 - overlap) << '\n';
    }

    delete[] a;
    return 0;
}
