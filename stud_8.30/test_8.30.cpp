#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>


using namespace std;
#include"bitset.h"

//https://leetcode.cn/problems/reverse-integer/description/(������ת)
class Solution0{
public:


    int reverse(int x) {
        int ans = 0; // ��ʼ�����Ϊ0
        while (x) { // ��x��Ϊ0ʱ����ѭ��
            // ����Ƿ����
            // ������������ans*(10) + (x%10) > INT_MAX����ᷢ�����
            // ���ڸ�������ans*(10) + (x%10) < INT_MIN����ᷢ�����
            if (x > 0 && ans > (INT_MAX - x % 10) / 10) {
                return 0; // �������������0
            }
            if (x < 0 && ans < (INT_MIN - x % 10) / 10) {
                return 0; // �������������0
            }
            ans = ans * 10 + x % 10; // ��x�����һλ������ӵ������
            x /= 10; // ����x
        }
        return ans; // ���ط�ת�������
    }
};
int main()
{
    
    luow::test_bitset();
    luow::test_twobitset();
	return 0;
}

