#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int count = 0, num = 1;
    while (count < n) {
        num++;
        if (isPrime(num)) count++;
    }
    cout << num;
}
