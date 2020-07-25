//问题描述：
//  给定一序列 -- 表示后面N天一只股票每天的价格
//  可以最多买一股卖一股
//  求最大利润

//思路：枚举
//  假定一只股票第i天买，一定是第j天卖，j > i，美剧每只股票的情况即可

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& v){
    int n = v.size();
    if(n == 0){
        return 0;
    }
    int res = 0;        //当前的最大利润
    int minV = v[0];    //当前为止的最小值
    for(int i = 1;i < n;++i){
        res = max(res, v[i] - minV);
        minV = min(minV, v[i]);
    }
}

int main(){
    return 0;
}