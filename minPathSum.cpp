//问题描述：
//  二维数组地图，每个格子中都有一个数字，只能向下或者向右走
//  求要走到右下角的格子，并且使得和最小，求最小和

//思路：最后一步一定是从上边或者左边来的，求两者较小的即可
//  从第一步开始
//     f[0][0] = 0; f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
//滚动数组做法
int minPathSum(vector<vector<int>>& A){
    int m = A.size();
    int n = A[0].size();
    if(m ==0 || n == 0){
        return 0;
    }
    vector<vector<int>> ret(2, vector<int>(n, 0));
    vector<vector<int>> pi(m, vector<int>(n, 0));
    vector<int> path(m + n - 1, 0);
    int old = 1, news = 0;
    for(int i = 0;i < m;++i){
        swap(old, news);
        for(int j = 0;j < n;++j){
            if(i == 0 && j == 0){
                ret[news][j] = A[i][j];
                continue;
            }
            int t = INT_MAX;
            if(i > 0){
                t = min(t, ret[old][j]);
                if(t == ret[old][j]){
                    pi[i][j] = 0;   //如果是从上一行来的，就标记该位置是0
                }
            }
            if(j > 0){
                t = min(t, ret[news][j - 1]);
                if(t == ret[news][j - 1]){
                    pi[i][j] = 1;   //如果是从上一列来的，就标记该位置为1
                }
            }
            ret[news][j] = t + A[i][j];
        }
    }
    int x = m - 1, y = n - 1;
    for (int i = 0; i < m + n - 1; ++i) {
        path[i] = A[x][y];
        if (pi[x][y] == 0) {
            --x;
        } else {
            --y;
        }
    }

    for (int i = m + n - 2; i >= 0; --i) {
        cout << path[i] << " ";
    }

    return ret[news][n - 1];
}

int minPathSum(vector<vector<int>>& A){
    int m = A.size();       //行
    int n = A[0].size();    //列
    if(m == 0 || n == 0){
        return 0;
    }
    vector<vector<int>> ret(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) {
                ret[i][j] = A[i][j];
                continue;
            }
            int t = INT_MAX;
            if(i > 0){
                t = min(t, ret[i - 1][j]);
            }
            if(j > 0){
                t = min(t, ret[i][j - 1]);
            }
            ret[i][j] = t + A[i][j];
        }
    }
    return ret[m - 1][n - 1];
}
