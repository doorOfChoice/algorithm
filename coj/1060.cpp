#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<set>
#include<algorithm>
#include<math.h>
#include<memory.h>
#define MIN(a,b) a<b?a:b
#define MAX(a,b) a<b?b:a
#define FILE_IN "D:\\linuxshare\\c\\algorithm\\data.in"
#define FILE_OUT "D:\\linuxshare\\c\\algorithm\\data.out"
using namespace std;
bool compare(int a, int b) {return a > b;}
void run()
{
  int M,S,C,t;
  vector<int> d,b;
  cin >> M >> S >> C;
  for(int i = 0; i < C; i++) {
    cin >> t;
    b.push_back(t);
  }
  sort(b.begin(), b.end());
  for(int i = 1; i < C; i++)if(b[i] - b[i - 1] >= 2) {
    d.push_back(b[i] - b[i - 1] - 1);
  }
  sort(d.begin(), d.end(), compare);
  int interval = MIN(M - 1, d.size());
  int sum = b.back() - b.front() + 1;
  for(int i = 0; i < interval; i++)
    sum -= d[i];
  cout << sum << endl;
}
int main()
{
  freopen(FILE_IN, "r", stdin);
  freopen(FILE_OUT, "w", stdout);
  run();
}

/**
1060: [USACO 1.3.2]修理牛棚

时间限制: 1 Sec  内存限制: 64 MB
[提交][状态]
题目描述

在一个暴风雨的夜晚,农民约翰的牛棚的屋顶、门被吹飞了。 
好在许多牛正在度假，所以牛棚没有住满。 剩下的牛一个紧挨着另一个被排成一行来过夜。 
有些牛棚里有牛，有些没有。 
所有的牛棚有相同的宽度。 
自门遗失以后,农民约翰很快在牛棚之前竖立起新的木板。 他的新木材供应者将会供应他任何他想要的长度,但是供应者只能提供有限数目的木板。 
农民约翰想将他购买的木板总长度减到最少。 
给出 M(1<= M<=50),可能买到的木板最大的数目;S(1<= S<=200),牛棚的总数;C(1 <= C <=S) 牛棚里牛的数目,和牛所在的牛棚的编号stall_number(1 <= stall_number <= S),计算拦住所有有牛的牛棚所需木板的最小总长度。 输出所需木板的最小总长度作为的答案。
输入

第 1 行: M ， S 和 C(用空格分开) 第 2 到 C+1行: 每行包含一个整数，表示牛所占的牛棚的编号。
输出

单独的一行包含一个整数表示所需木板的最小总长度。
样例输入

4 50 18
3
4
6
8
14
15
16
17
21
25
26
27
30
31
40
41
42
43
样例输出

25 

====================================
這道題剛開始有一點懞逼，仔細想了想就是一道簡單的貪心問題.

(1).設牛的最後一個欄和第一個欄差加1為sum
(2).然後找出最多用多少木板能把牛圍起來且不圍上空欄比如
1 2 3 4 5 6 8 9 10
最多用3個木板能鏈接起來,空隙為3 - 1 = 2
(3).由於木板數量有上限,那麽題目提供的模板為M, 空隙為M - 1
(4).那麽現在就是來挖空隙了，我們已經知道了一塊模板的長度為sum, 那麽就用sum減去最大的x個空隙的長度
x為max(M - 1, 實際空隙)
**/