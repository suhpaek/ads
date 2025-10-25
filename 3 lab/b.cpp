#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    long long a[100000]; 
    long long lo = 0, hi = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > lo) lo = a[i];
        hi += a[i];
    }

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        int blocks = 1;
        long long cur = 0;

        for (int i = 0; i < n; i++) {
            if (cur + a[i] <= mid)
                cur += a[i];
            else {
                blocks++;
                cur = a[i];
            }
        }

        if (blocks <= k)
            hi = mid;
        else
            lo = mid + 1;
    }

    cout << lo;
    return 0;
}
