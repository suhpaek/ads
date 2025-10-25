#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    long long x;
    cin >> x;
    long long cur = x, best = x;

    for (int i = 1; i < n; ++i) {
        cin >> x;
        if (cur + x > x) cur = cur + x;
        else cur = x;
        if (cur > best) best = cur;
    }

    cout << best << '\n';
    return 0;
}