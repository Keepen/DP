//问题描述：
//  类似于 -- 弹弹堂，二维数组地图中有W（墙）、E（敌人）、0（空位置）
//  炸弹只能放在空位置，炸弹能炸死同行同列的所有敌人，
//  有墙的话会被挡住
//问：最多能炸死多少个敌人

//思路：
//  1.假设可以在有敌人的地方放炸弹
//      在（i，j）格放一个炸弹向上能炸死的敌人数目
//      (i, j)空地：(i - 1, j)向上能炸死的敌人数目
//      (i, j)敌人：(i - 1, j)向上能炸死的敌人数目 + 1
//      (i, j)墙  ：0
//  初始条件：(0, j)格是敌人 -- 1；是空地 -- 0
//  2.向下能炸死的Down -- 从下向上计算
//  3.向左能炸死的Left -- 从左向右
//  4.向右能炸死的Right -- 从右向左

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxKilledEnemies(vector<vector<char>>& A) {
    if (A.size() == 0 || A[0].size() == 0) {
        return 0;
    }
    int m = A.size();       //行数
    int n = A[0].size();    //列数
    vector<vector<int>> up(m, vector<int>(n, 0));
    vector<vector<int>> down(m, vector<int>(n, 0));
    vector<vector<int>> left(m, vector<int>(n, 0));
    vector<vector<int>> right(m, vector<int>(n, 0));
    //up
    for(int i = 0;i < m;++i){
        for(int j = 0;j < n;++j){
            if(A[i][j] == 'W'){
                up[i][j] = 0;
                continue;
            }
            up[i][j] = A[i][j] == 'E' ? 1 : 0;
            if(i > 0){
                up[i][j] += up[i - 1][j];
            }
        }
    }
    //down
    for(int i = m - 1;i >= 0;--i){
        for(int j = 0;j < n;++j){
            if(A[i][j] == 'W'){
                down[i][j] = 0;
                continue;
            }
            down[i][j] = A[i][j] == 'E' ? 1 : 0;
            if(i < m - 1){
                down[i][j] += down[i + 1][j];
            }
        }
    }
    //left
    for(int i = 0;i < m;++i){
        for(int j = 0;j < n;++j){
            if(A[i][j] == 'W'){
                left[i][j] = 0;
                continue;
            }
            left[i][j] = A[i][j] == 'E' ? 1 : 0;
            if(j > 0){
                left[i][j] += left[i][j - 1];
            }
        }
    }
    //right
    for(int i = 0;i < m;++i){
        for(int j = n - 1;j >= 0;--j){
            if(A[i][j] == 'W'){
                right[i][j] = 0;
                continue;
            }
            right[i][j] = A[i][j] == 'E' ? 1 : 0;
            if(j < n - 1){
                right[i][j] += right[i][j + 1];
            }
        }
    }
    int res = 0;
    for(int i = 0;i < m;++i){
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == '0') {
                int ret = up[m - 1][n - 1] + down[m - 1][n - 1] +
                          left[m - 1][n - 1] + right[m - 1][n - 1];
                res = max(ret, res);
            }
        }
    }
    return res;
}

int main(){
    
    return 0;
}