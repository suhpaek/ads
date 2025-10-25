#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    long long* pref = new long long[N];
    for (int i = 0; i < N; ++i) {
        long long ai;
        cin >> ai;
        pref[i] = ai + (i ? pref[i-1] : 0);
    }

    while (M--) {
        long long b;
        cin >> b;
        int lo = 0, hi = N - 1, idx = N;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (pref[mid] >= b) {
                idx = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout << (idx + 1) << '\n';
    }

    delete[] pref;
    return 0;
}
