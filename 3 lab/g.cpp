#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, f;
    if (!(cin >> n >> f)) return 0;

    long long c[100000]; // предположим, что n <= 100000
    long long hi = 0;
    for (long long i = 0; i < n; ++i) {
        cin >> c[i];
        if (c[i] > hi) hi = c[i];
    }

    long long lo = 1;
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        long long flights = 0;
        for (long long i = 0; i < n; ++i) {
            flights += (c[i] + mid - 1) / mid;
            if (flights > f) break;
        }
        if (flights <= f) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << '\n';
    return 0;
}
