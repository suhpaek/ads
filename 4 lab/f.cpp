#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    int* a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int* L = new int[n + 1];
    int* R = new int[n + 1];
    for (int i = 0; i <= n; i++) { L[i] = 0; R[i] = 0; }

    int root = a[0];
    for (int i = 1; i < n; i++) {
        int x = a[i], cur = root;
        while (true) {
            if (x < cur) {
                if (!L[cur]) { L[cur] = x; break; }
                cur = L[cur];
            } else {
                if (!R[cur]) { R[cur] = x; break; }
                cur = R[cur];
            }
        }
    }

    int ans = 0;
    for (int v = 1; v <= n; v++)
        if (L[v] && R[v]) ans++;

    cout << ans << '\n';

    delete[] a;
    delete[] L;
    delete[] R;
    return 0;
}
