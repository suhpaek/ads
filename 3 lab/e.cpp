#include <iostream>
using namespace std;

void quickSelect(long long arr[], int l, int r, int k) {
    while (l < r) {
        long long pivot = arr[r];
        int i = l;
        for (int j = l; j < r; j++) {
            if (arr[j] < pivot) {
                long long tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
            }
        }
        long long tmp = arr[i];
        arr[i] = arr[r];
        arr[r] = tmp;
        if (i == k) return;
        else if (i < k) l = i + 1;
        else r = i - 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    long long* s = new long long[N];
    for (int i = 0; i < N; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        s[i] = x2 > y2 ? x2 : y2;
    }

    quickSelect(s, 0, N - 1, K - 1);
    cout << s[K - 1] << "\n";

    delete[] s;
    return 0;
}
