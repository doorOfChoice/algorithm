#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<set>
#include<algorithm>
#include<math.h>
#include<memory.h>
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a
#define FILE_IN "D:\\linuxshare\\c\\algorithm\\data.in"
#define FILE_OUT "D:\\linuxshare\\c\\algorithm\\data.out"
using namespace std;
int flag[10];
bool ok(int t) {
  while(t) {
    if(!flag[t % 10])
      return false;
    t /= 10;
  }
  return true;
}
void run()
{
  int N,t;
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> t;
    flag[t] = 1;
  }
  int count = 0;
  for(int i = 111; i <= 999; i++) {
    for(int j = 11; j <= 99; j++) {
      int a = i * j;
      int b = j % 10 * i;
      int c = j / 10 * i;
      if(ok(i) && ok(j) && ok(a) && ok(b) && ok(c) && a < 10000 && b < 1000 & c < 1000)
        count++;
    }
  }
  cout << count << endl;
}
int main()
{
  freopen(FILE_IN, "r", stdin);
  freopen(FILE_OUT, "w", stdout);
  run();
}

/*
1062: [USACO 1.3.4]牛式

时间限制: 1 Sec  内存限制: 64 MB
题目描述

下面是一个乘法竖式，如果用我们给定的那几个数字来取代*，可以使式子成立的话，我们就叫这个式子牛式。


数字只能取代*，当然第一位不能为0。 写一个程序找出所有的牛式。
输入

Line 1: 数字的个数。 Line 2: N个用空格分开的数字（每个数字都∈{1,2,3,4,5,6,7,8,9}） 。
输出

共一行，一个数字。表示牛式的总数。
样例输入

5
2 3 4 6 8
样例输出

1

===============================
真尼玛的坑，刚开始没懂题，卡了半天，不过这题目确实也挺坑。
题目意思就是叫以下的⭐只能是输入数的里面的数,且位数要保持是一样
 ***
X **
----
 ***
***
----
****
乘数3位*2位=3位*3位
*/