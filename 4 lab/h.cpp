#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    long long* a = new long long[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] < a[j]) {
                long long tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    long long pref = 0;
    for (int i = 0; i < n; ++i) {
        pref += a[i];
        if (i) cout << ' ';
        cout << pref;
    }
    cout << '\n';
    delete[] a;
    return 0;
}
