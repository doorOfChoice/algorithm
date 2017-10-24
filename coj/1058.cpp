#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <math.h>
#include <memory.h>
#define FILE_IN "D:\\linuxshare\\c\\algorithm\\data.in"
#define FILE_OUT "D:\\linuxshare\\c\\algorithm\\data.out"
using namespace std;

bool is_circle(vector<int> num)
{
    for (int i = 0, size = num.size(); i < size / 2; i++)
        if (num[i] != num[size - i - 1])
            return false;
    return true;
}

vector<int> radix(int x, int r)
{
    vector<int> num;
    while (x >= r)
    {
        num.push_back(x % r);
        x /= r;
    }
    num.push_back(x);
    return num;
}

void run()
{
    int n, s;
    cin >> n >> s;
    for (int i = s + 1; ; i++)
    {
        if (!n)break;
        int count = 0;
        for (int r = 10; r >= 2; r--)
        {
            vector<int> radix_i = radix(i, r);
            if (is_circle(radix_i)) 
                count++;
            if (count == 2)
            {
                cout << i << endl;
                n--;
                break;
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
 1058: [USACO 1.2.5]双重回文数

时间限制: 1 Sec  内存限制: 64 MB

题目描述

如果一个数从左往右读和从右往左读都是一样，那么这个数就叫做“回文数”。例如，12321就是一个回文数，而77778就不是。当然，回文数的首和尾都应是非零的，因此0220就不是回文数。事实上，有一些数（如21），在十进制时不是回文数，但在其它进制（如二进制时为10101）时就是回文数。 编一个程序，从文件读入两个十进制数 N (1 <= N <= 15) S (0 < S < 10000) 然后找出前N个满足大于S且在两种以上进制（二进制至十进制）上是回文数的十进制数，输出到文件上。 本问题的解决方案不需要使用大于4字节的整型变量。
输入

只有一行，用空格隔开的两个数N和S。
输出

N行, 每行一个满足上述要求的数，并按从小到大的顺序输出。
样例输入

3 25 
样例输出

26
27
28

===========
水題，思路就是枚舉每個數并且判斷各個進制是否是回文。
提交的時候出現了一點坑，題目中是說1<S<10000, 但是我想成了求數的範圍只在10000以内了
**/