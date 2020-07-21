//问题描述：有面值为2， 5， 7的硬币，每个面额都有足够多的硬币
//  给定一个数字，求用最少的硬币来拼成给定数值

//思路：
//  1.由于是刚好拼成，那么最后一枚硬币一定是上面3种之一
//  2.所以  最后一个是2：27 - 2  子问题就变成了，拼成25
//          最后一个是5：27 - 5                 拼成22
//          最后一个是7：27 - 7                 拼成20
//  3.确定状态：F（x） -- 表示拼成x所需要的最少的硬币数目
//      则以上三种情况对应的状态就是：F(x - 2) + 1, F(x - 5) + 1, F(x - 7) + 1
//      F(x) = min{F(x - 2) + 1, F(x - 5) + 1, F(x - 7) + 1}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int Max = 99999999;

int F(vector<int>& coin, int n){
    vector<int> ret(n + 1, Max);
    ret[0] = 0;
    for(int i = 1;i <= n;++i){
        for(int k = 0;k < coin.size();++k){
            if(i >= coin[k] && ret[i - coin[k]] != Max){
                ret[i] = min(ret[i], ret[i - coin[k]] + 1);
            }
        }
    }
    if(ret[n] == Max){
        return -1;
    }
    return ret[n];
}

void solu(){
    int n;
    vector<int> coin = {2, 5, 7};
    while(cin >> n){
        cout << F(coin, n) << endl;
    }
}

int main(){
    solu();
    return 0;
}