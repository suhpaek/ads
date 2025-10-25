#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    long long* a = new long long[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long x;
    cin >> x;

    int lo = 0, hi = n - 1;
    bool found = false;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == x) {
            found = true;
            break;
        } else if (a[mid] < x) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << (found ? "Yes" : "No") << '\n';
    delete[] a;
    return 0;
}
