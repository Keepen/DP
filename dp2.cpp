//问题描述：
//  在一个数组中，给定一个目标数字S，求在该数组中能否找到几个数的和刚好等于目标数字
//  能：true；不能：false

//思路：
//  还是要与不要的原则
//  如果要当前数字  ：就看前i - 1个数字能否拼成  S - v[i]
//  如果不要当前数字：就看前 i - 1个数字能否拼成 S


#include <iostream>
#include <vector>
using namespace std;

//递归版本
bool isOK(vector<int>& v, int i, int s){
    if(s == 0){
        return true;
    }
    else if(i == 0){
        return v[0] == s;
    }
    else if (v[i] > s){
        return isOK(v, i - 1, s);
    }
    else{
        //要当前数字
        bool a = isOK(v, i - 1, s - v[i]);
        //不要当前数字
        bool b = isOK(v, i - 1, s);
        return a || b;
    }
}

//非递归版本
//利用二维数组：v.size() * s --- v.size()行，s列的数组
//  ret[i][j]表示，前i个数字能否拼成和为数字j
bool unrec_isOK(vector<int>& v, int s){
    vector<vector<bool>> ret(v.size(), vector<bool>(s + 1, false));
    ret[0][v[0]] = true;    //初始化了第一行的值
    for(int i = 1;i < v.size();++i){
        for(int j = 0;j <= s;++j){
            if(j == 0){
                ret[i][j] = true;
            }
            //如果出现比目标数字大的就不要选
            if(v[i] > j){
                ret[i][j] = ret[i - 1][j];
            }
            //等于目标数字就是true
            else if(v[i] == j){
                ret[i][j] = true;
            }
            else{
                //                     选               不选
                ret[i][j] = ret[i - 1][j - v[i]] || ret[i - 1][j];
            }
        }
    }
    return ret[v.size() - 1][s];
}

void solu(){
    vector<int> v = {3,34,4,12,5,2};
    int s = 9;
    while(cin >> s){
        //bool key = isOK(v, v.size() - 1, s);
        bool key = unrec_isOK(v, s);
        if(key){
            cout << "true" << endl;
        }
        else{
            cout << "false" << endl;
        }
    }
}

int main(){
    solu();
    return 0;
}