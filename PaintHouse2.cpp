//问题描述：
//  和PaintHouse类似，不过油漆房子的颜色变成了K种
//  但是复杂度就变成了 O（NK*K）
//  1.i: 0 ~ N
//  2.j: 1 ~ K
//  3.k: 1 ~ K

//思路：
//  第i栋房子粉刷成j号颜色的最小费用
//  f[i][j] = min {f[i - 1][k]} + a[i][j];   j != k
//  由于每次都要找到最小的值 -- 除了自己以外的其他颜色的最小费用
//  那么就将这些费用的最小值和次小值找出来，如果此次选的是最小值，那么除了它之外的最小值就是次小值
//  否则，就是所有费用的最小值

//时间复杂度降为 O（NK）
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minCost(vector<vector<int>>& c){
    int n = c.size();
    int K = c[0].size();
    if(n == 0){
        return 0;
    }
    vector<vector<int>> f(n + 1, vector<int>(K, 0));
    int i, j, k;
    //最小值和次小值
    int min1, min2;
    //最小值和次小值的下标
    int id1 = 0, id2 = 0;
    //初始化第0行
    for(i = 0;i < K;++i){
        f[0][i] = 0;
    }
    for(i = 1;i < n + 1;++i){
        //每一栋房子费用的最小值和次小值
        min1 = min2 = INT_MAX;
        for(j = 0;j < K;++j){
            if(f[i - 1][j] < min1){
                min2 = min1;
                id2 = id1;
                min1 = f[i- 1][j];
                id1 = j;
            }
            else{
                if(f[i - 1][j] < min2){
                    min2 = f[i - 1][j];
                    id2 = j;
                }
            }
        }

        for(j = 0;j < K;++j){
            f[i][j] = c[i - 1][j];
            if(j != id1){
                f[i][j] += min1;
            }
            else{
                f[i][j] += min2;
            }

        }
    }
    int ret = INT_MAX;
    for(i = 0;i < K;++i){
        ret = min(ret, f[n][i]);
    }
    return ret;
}

int main(){
    return 0;
}