#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    const int MAXA = 1000;

    long long cnt[MAXA + 1] = {0}, prefCnt[MAXA + 1] = {0}, prefSum[MAXA + 1] = {0};

    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        ++cnt[a];
    }

    for (int v = 1; v <= MAXA; ++v) {
        prefCnt[v] = prefCnt[v - 1] + cnt[v];
        prefSum[v] = prefSum[v - 1] + cnt[v] * 1LL * v;
    }

    int P;
    cin >> P;
    while (P--) {
        int p; cin >> p;
        if (p < 1) { cout << "0 0\n"; continue; }
        if (p > MAXA) p = MAXA;
        cout << prefCnt[p] << ' ' << prefSum[p] << '\n';
    }

    return 0;
}
