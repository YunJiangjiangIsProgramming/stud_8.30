#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>


using namespace std;
#include"bitset.h"

//https://leetcode.cn/problems/reverse-integer/description/(整数反转)
class Solution0{
public:


    int reverse(int x) {
        int ans = 0; // 初始化结果为0
        while (x) { // 当x不为0时继续循环
            // 检查是否溢出
            // 对于正数：若ans*(10) + (x%10) > INT_MAX，则会发生溢出
            // 对于负数：若ans*(10) + (x%10) < INT_MIN，则会发生溢出
            if (x > 0 && ans > (INT_MAX - x % 10) / 10) {
                return 0; // 正数溢出，返回0
            }
            if (x < 0 && ans < (INT_MIN - x % 10) / 10) {
                return 0; // 负数溢出，返回0
            }
            ans = ans * 10 + x % 10; // 将x的最后一位数字添加到结果中
            x /= 10; // 遍历x
        }
        return ans; // 返回反转后的整数
    }
};
int main()
{
    
    luow::test_bitset();
    luow::test_twobitset();
	return 0;
}

