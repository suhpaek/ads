#include <iostream>
using namespace std;

bool canSteal(long long nums[], long long h, int n, long long mid) {
    long long totalH = 0;
    for(int i = 0; i < n; i++) {
        totalH += (nums[i] + mid - 1)/mid;
        if (totalH > h) return false;
    }
    return true;
}

int main() {
    int n; 
    long long h;
    cin >> n >> h;
    long long* a = new long long[n];
    long long r = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > r) r = a[i];
    }
    long long l = 1, mid, res;
    while(l <= r) {
        mid = l + (r - l) / 2;
        if(canSteal(a, h, n, mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res << '\n';
    delete[] a;
    return 0;
}
