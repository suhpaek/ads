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

    const int MAX = 20000;
    int primes[MAX];
    int count = 0;

    for (int i = 2; count < MAX; i++) {
        if (isPrime(i)) {
            primes[count] = i;
            count++;
        }
    }

    int nth_prime = primes[n - 1];         
    int superprime = primes[nth_prime - 1]; 
    cout << superprime << endl;

    return 0;
}