#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int ans = 0;
    vector<vector<bool>> arr(n, vector<bool>(m, 0));
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (!arr[x][y]) {
            ans++;
            arr[x][y] = true;
        }
    }
    cout << n * m - ans << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!arr[i][j]) {
                cout << j + 1 << ' ' << i + 1 << '\n';
            }
        }
    }
}
