#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> res(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '*') {
                res[i][j] = -1; // 标记地雷
                // 更新周围的格子
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue; // 跳过自己
                        int ni = i + di;
                        int nj = j + dj;
                        // 检查边界
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && res[ni][nj] != -1) {
                            res[ni][nj]++;
                        }
                    }
                }
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res[i][j] == -1) {
                cout << '*';
            } else {
                cout << res[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}