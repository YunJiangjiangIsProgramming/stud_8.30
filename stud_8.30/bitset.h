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
//		  size_t index = x / 32;//���xӳ���ڵڼ�������
//		  size_t pos = x % 32;//���x��������εڼ�λ
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

    // ����һ��λ�����࣬ʹ�� vector<char> ���洢λ
    template<size_t N>
    class bitset {
    public:
        // ���캯������ʼ��������С
        bitset() {
            // ʹ����λ������������������Ч��
            _bits.resize((N >> 3) + 1, 0);
        }

        // ����λ x
        void set(size_t x) {
            size_t i = x >> 3;    // ���� i = x / 8
            size_t j = x % 8;     // λ j
            // ���õ� j λΪ 1
            _bits[i] |= (1 << j);
        }

        // ����λ x
        void reset(size_t x) {
            size_t i = x >> 3;    // ���� i = x / 8
            size_t j = x % 8;     // λ j
            // ͨ����λ���������� j λ
            _bits[i] &= ~(1 << j);
        }

        // ����λ x �Ƿ�Ϊ 1
        bool test(size_t x) {
            size_t i = x >> 3;    // ���� i = x / 8
            size_t j = x % 8;     // λ j
            // ���� j λ�Ƿ�Ϊ 1
            return _bits[i] & (1 << j);
        }

    private:
        std::vector<char> _bits; // λ����
    };

    // ���Ժ���
    void test_bitset() {
        bitset<0xffffffff> bs2;   // ����һ����λ����

        // ����һЩλ
        bs2.set(10);
        bs2.set(10000);
        bs2.set(8888);

        // ���Բ���ӡ
        std::cout << bs2.test(10) << std::endl;
        std::cout << bs2.test(10000) << std::endl;
        std::cout << bs2.test(8888) << std::endl;
        std::cout << bs2.test(8887) << std::endl;
        std::cout << bs2.test(9999) << std::endl << std::endl;

        // ���ò��ٴ�����
        bs2.reset(8888);
        bs2.set(8887);

        // �ٴβ��Բ���ӡ
        std::cout << bs2.test(10) << std::endl;
        std::cout << bs2.test(10000) << std::endl;
        std::cout << bs2.test(8888) << std::endl;
        std::cout << bs2.test(8887) << std::endl;
        std::cout << bs2.test(9999) << std::endl;
    }

    // ����һ��˫λ�����࣬�����ҳ�ֻ����һ�ε�Ԫ��
    template<size_t N>
    class twobitset {
    public:
        // ����λ x
        void set(size_t x) {
            if (!_bs1.test(x) && !_bs2.test(x)) { // 00 -> 01
                _bs2.set(x);
            }
            else if (!_bs1.test(x) && _bs2.test(x)) { // 01 -> 10
                _bs1.set(x);
                _bs2.reset(x);
            }
            // 10 ����
        }

        // ��ӡֻ����һ�ε�Ԫ��
        void PrintOnce() {
            for (size_t i = 0; i < N; ++i) {
                if (!_bs1.test(i) && _bs2.test(i)) {
                    std::cout << i << std::endl;
                }
            }
            std::cout << std::endl;
        }

    private:
        bitset<N> _bs1; // ��һ��λ����
        bitset<N> _bs2; // �ڶ���λ����
    };

    // ���Ժ���
    void test_twobitset() {
        twobitset<100> tbs;
        int a[] = { 3, 5, 6, 7, 8, 9, 33, 55, 67, 3, 3, 3, 5, 9, 33 };

        // ����Ԫ��
        for (auto e : a) {
            tbs.set(e);
        }

        // ��ӡֻ����һ�ε�Ԫ��
        tbs.PrintOnce();
    }

} // namespace bit
