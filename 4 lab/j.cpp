#include <iostream>
using namespace std;

long long a[2000000], ans[2000000];

void merge(long long* arr, int l, int m, int r, long long* temp) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (i = l; i <= r; ++i) arr[i] = temp[i];
}

void merge_sort(long long* arr, int n) {
    long long* temp = new long long[n];
    for (int sz = 1; sz < n; sz *= 2) {
        for (int l = 0; l < n; l += 2*sz) {
            int m = l + sz - 1;
            if (m >= n) m = n-1;
            int r = l + 2*sz - 1;
            if (r >= n) r = n-1;
            if (m < r) merge(arr, l, m, r, temp);
        }
    }
    delete[] temp;
}

struct Node { int l, r; int idx; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int n = (1 << N) - 1;
    for (int i = 0; i < n; ++i) cin >> a[i];

    merge_sort(a, n);

    int head = 0, tail = 0;
    Node q[2000000];
    q[tail++] = {0, n-1, 0};
    int p = 0;

    while (head < tail) {
        Node cur = q[head++];
        int m = (cur.l + cur.r) / 2;
        ans[p++] = a[m];
        if (cur.l <= m-1) q[tail++] = {cur.l, m-1, 0};
        if (m+1 <= cur.r) q[tail++] = {m+1, cur.r, 0};
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
