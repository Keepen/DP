#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//问题描述：
//  给定一个数组v，求出该数组中最长连续单调子序列的长度

//方法：
//  1.求出最长连续递增子序列长度
//  2.数组反转，再求一次
//  3.取两者较大值

int maxIncrease(vector<int>& v){
    int size = v.size();
    if(size <= 1){
        return 1;
    }
    int ret = 0;
    vector<int> ans(size, 1);
    for(int i = 0;i < size;++i){
        if(i > 1 && v[i] > v[i - 1]){
            ans[i] = ans[i - 1] + 1;
        }
        ret = max(ans[i], ret);
    }
    return ret;
}

int maxSeq(vector<int>& v){
    if(v.size() < 2){
        return 1;
    }
    int ret1 = 0, ret2 = 0;
    ret1 = maxIncrease(v);
    cout << ret1 << endl;
    //逆置
    int i = 0, j = v.size() - 1, t;
    while(i < j){
        t = v[i];
        v[i] = v[j];
        v[j] = t;
        ++i;
        --j;
    }
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
    ret2 = maxIncrease(v);
    cout << ret2 << endl;
    return ret1 > ret2 ? ret1 : ret2;
}

int main(){
    vector<int> v = {1, 2, 3, 2, 4, 5, 3, 6, 7, 8, 4, 2, 3};
    cout << maxSeq(v) << endl;
    return 0;
}