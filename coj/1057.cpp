#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<set>
#include<math.h>
#include<memory.h>
#define FILE_IN "D:\\linuxshare\\c\\algorithm\\data.in"
#define FILE_OUT "D:\\linuxshare\\c\\algorithm\\data.out"
using namespace std;

bool is_circle(vector<int> num) {
  for(int i = 0; i < num.size() / 2; i++) {
    if(num[i] != num[num.size() - i - 1])
      return false;
  }
  return true;
}

vector<int> radix(int x, int r) {
  vector<int> num;
  while(x >= r) {
    num.push_back(x % r);
    x /= r;
  }
  num.push_back(x);
  return num;
}

void print(vector<int> num) {
  for(int i = num.size() - 1; i >= 0; i--) {
    if(num[i] >= 10) {
      cout << char('A' + num[i] - 10);
    }else {
      cout << num[i];
    }
  }
}

void run()
{
  int b;
  while(cin >> b)
  {
    for(int i = 1; i <= 300; i++) {
      int i2 = i * i;
      vector<int> radix_i2 = radix(i2, b);
      if(is_circle(radix_i2)) {
        vector<int> radix_i = radix(i, b);
        print(radix_i);
        cout << " ";
        print(radix_i2);
        cout << endl;
      }
    }
  }
}
int main()
{
  freopen(FILE_IN, "r", stdin);
  freopen(FILE_OUT, "w", stdout);
  run();
}

/**
  1057: [USACO 1.2.4]回文平方数

时间限制: 1 Sec  内存限制: 64 MB

题目描述

回文数是指从左向右念和从右像做念都一样的数。如12321就是一个典型的回文数。 给定一个进制B(2<=B<=20十进制)，输出所有的大于等于1小于等于300且它的平方用B进制表示时是回文数的数。用’A’,’B’……表示10，11等等。
输入

共一行，一个单独的整数B(B用十进制表示)。
输出

每行两个数字，第二个数是第一个数的平方，且第二个数是回文数。(注意:这两个数都应该在B那个进制下)
样例输入

10
样例输出

1 1
2 4
3 9
11 121
22 484
26 676
101 10201
111 12321
121 14641
202 40804
212 44944
264 69696
提示

===========
水題
**/