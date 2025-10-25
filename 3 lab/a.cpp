#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    int* queries = new int[t];
    for (int i = 0; i < t; i++) cin >> queries[i];

    int n, m;
    cin >> n >> m;

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) matrix[i] = new int[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    for (int k = 0; k < t; k++) {
        int q = queries[k];
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == q) {
                    cout << i << " " << j << "\n";
                    found = true;
                    break;
                }
            }
        }
        if (!found) cout << -1 << "\n";
    }

    for (int i = 0; i < n; i++) delete[] matrix[i];
    delete[] matrix;
    delete[] queries;
    return 0;
}
