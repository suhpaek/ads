#include <iostream>
using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int N;
        cin >> N;

        char q[10000];
        int front = 0, rear = 0;
        int cnt[26] = {0};

        for (int i = 0; i < N; ++i) {
            char c;
            cin >> c;

            cnt[c - 'a']++;
            q[rear++] = c;

            while (front < rear && cnt[q[front] - 'a'] > 1) front++;

            if (front == rear) cout << -1;
            else cout << q[front];

            if (i + 1 < N) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}