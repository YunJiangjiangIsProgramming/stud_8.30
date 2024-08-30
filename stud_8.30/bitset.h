#pragma once
#include<vector>

//namespace luow
//{
//	class bitset
//  {
//private:
//	std::vector<int>  _bits;
//	size_t _num;
//  public:
//	  bitset(size_t N)
//	  {
//		  _bits.resize(N / 32 + 1, 0);
//		  _num = 0;
//	  }
//	  void set(size_t x)
//	  {
//		  size_t index = x / 32;//算出x映射在第几个整形
//		  size_t pos = x % 32;//算出x在这个整形第几位
//
//		  _bits[index] |= (1 << pos);
//   	}
//
//	/*  void test_bit()
//	  {
//		  bitset bs(100);
//		  bs.set(99);
//		  bs.set(98);
//		  bs.set(97);
//
//		  for (size_t i = 0; i < 100; i++)
//		  {
//			  printf("[%d]:%d", i, bs.set(i));
//		  }
//	  }*/
//
//  };
//
//
//
//}
#include <vector>
#include <iostream>

namespace luow {

    // 定义一个位集合类，使用 vector<char> 来存储位
    template<size_t N>
    class bitset {
    public:
        // 构造函数，初始化向量大小
        bitset() {
            // 使用移位操作来代替除法，提高效率
            _bits.resize((N >> 3) + 1, 0);
        }

        // 设置位 x
        void set(size_t x) {
            size_t i = x >> 3;    // 索引 i = x / 8
            size_t j = x % 8;     // 位 j
            // 设置第 j 位为 1
            _bits[i] |= (1 << j);
        }

        // 重置位 x
        void reset(size_t x) {
            size_t i = x >> 3;    // 索引 i = x / 8
            size_t j = x % 8;     // 位 j
            // 通过按位与操作清除第 j 位
            _bits[i] &= ~(1 << j);
        }

        // 测试位 x 是否为 1
        bool test(size_t x) {
            size_t i = x >> 3;    // 索引 i = x / 8
            size_t j = x % 8;     // 位 j
            // 检查第 j 位是否为 1
            return _bits[i] & (1 << j);
        }

    private:
        std::vector<char> _bits; // 位向量
    };

    // 测试函数
    void test_bitset() {
        bitset<0xffffffff> bs2;   // 构造一个大位集合

        // 设置一些位
        bs2.set(10);
        bs2.set(10000);
        bs2.set(8888);

        // 测试并打印
        std::cout << bs2.test(10) << std::endl;
        std::cout << bs2.test(10000) << std::endl;
        std::cout << bs2.test(8888) << std::endl;
        std::cout << bs2.test(8887) << std::endl;
        std::cout << bs2.test(9999) << std::endl << std::endl;

        // 重置并再次设置
        bs2.reset(8888);
        bs2.set(8887);

        // 再次测试并打印
        std::cout << bs2.test(10) << std::endl;
        std::cout << bs2.test(10000) << std::endl;
        std::cout << bs2.test(8888) << std::endl;
        std::cout << bs2.test(8887) << std::endl;
        std::cout << bs2.test(9999) << std::endl;
    }

    // 定义一个双位集合类，用于找出只出现一次的元素
    template<size_t N>
    class twobitset {
    public:
        // 设置位 x
        void set(size_t x) {
            if (!_bs1.test(x) && !_bs2.test(x)) { // 00 -> 01
                _bs2.set(x);
            }
            else if (!_bs1.test(x) && _bs2.test(x)) { // 01 -> 10
                _bs1.set(x);
                _bs2.reset(x);
            }
            // 10 不变
        }

        // 打印只出现一次的元素
        void PrintOnce() {
            for (size_t i = 0; i < N; ++i) {
                if (!_bs1.test(i) && _bs2.test(i)) {
                    std::cout << i << std::endl;
                }
            }
            std::cout << std::endl;
        }

    private:
        bitset<N> _bs1; // 第一个位集合
        bitset<N> _bs2; // 第二个位集合
    };

    // 测试函数
    void test_twobitset() {
        twobitset<100> tbs;
        int a[] = { 3, 5, 6, 7, 8, 9, 33, 55, 67, 3, 3, 3, 5, 9, 33 };

        // 设置元素
        for (auto e : a) {
            tbs.set(e);
        }

        // 打印只出现一次的元素
        tbs.PrintOnce();
    }

} // namespace bit
