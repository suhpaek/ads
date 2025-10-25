#include <iostream>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    long long* a = new long long[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int left = 0;
    long long sum = 0;
    int min_len = n + 1;

    for (int right = 0; right < n; right++) {
        sum += a[right];

        while (sum >= k) {
            int len = right - left + 1;
            if (len < min_len) min_len = len;
            sum -= a[left];
            left++;
        }
    }

    cout << min_len << "\n";

    delete[] a;
    return 0;
}
