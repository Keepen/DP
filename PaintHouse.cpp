#include <iostream>
#include  <algorithm>
#include <vector>
#include <climits>
using namespace std;

//问题描述：
// 这里有n个房子在一列直线上，现在我们需要给房屋染色，分别有红色蓝色和绿色。
//  每个房屋染不同的颜色费用也不同，你需要设计一种染色方案使得相邻的房屋颜色不同，并且费用最小。
//  费用通过一个nx3 的矩阵给出，
//      比如cost[0][0]表示房屋0染红色的费用，cost[1][2]表示房屋1染绿色的费用。
// 样例
// costs = [[14,2,11],[11,14,5],[14,3,10]] return 10
// 房屋 0 蓝色, 房屋 1 绿色, 房屋 2 蓝色， 2 + 5 + 3 = 10

//思路：记录下前i个房子染成红色、蓝色、绿色分别所需的最小花费
//  状态：
//  1.表示第i个房子染成红色的最小花费
//      f[i][0] = min{f[i - 1][1], f[i - 1][2]} + cost[i - 1][0];
//  2.表示第i个房子染成蓝色的最小花费
//      f[i][1] = min{f[i - 1][0], f[i - 1][2]} + cost[i - 1][1];
//  3.表示第i个房子染成绿色的最小花费
//      f[i][2] = min{f[i - 1][0], f[i - 1][1]} + cost[i - 1][2];

//初始状态 ：f[0][0] = f[0][1] = f[0][2] = 0;   //表示前0栋房子染成三种颜色的花费都是0

int money(vector<vector<int>>& cost) {
	vector<vector<int>> ret(cost.size() + 1, vector<int>(cost[0].size(), INT_MAX));
	for (size_t i = 0; i < cost[0].size(); ++i) {
		ret[0][i] = 0;
	}
	size_t n = cost.size();
	cout << n << endl;
	for (size_t i = 1; i <= cost.size(); ++i) {
		for (size_t j = 0; j < cost[0].size(); ++j) {
			for (size_t k = 0; k < cost[0].size(); ++k) {
				if (j != k) {
					ret[i][j] = min(ret[i][j], ret[i - 1][k] + cost[i - 1][j]);
				}
			}
			
		}
	}
	int Min = ret[n][0];
	for (size_t i = 0; i < cost[0].size(); ++i) {
		if (Min > ret[n][i])
			Min = ret[n][i];
	}
	return Min;
}

int main() {
	vector<vector<int>> cost = { {1,4},{2,3},{3,5} };
	money(cost);
	return 0;
}
