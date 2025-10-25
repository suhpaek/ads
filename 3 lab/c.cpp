#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    long long a[100000]; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((l1 <= a[i] && a[i] <= r1) || (l2 <= a[i] && a[i] <= r2)) {
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
