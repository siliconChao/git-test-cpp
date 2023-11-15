/*
 * @Author       : konglc
 * @Date         : 2023-10-25 20:46:14
 * @LastEditors  : Please set LastEditors
 * @LastEditTime : 2023-10-25 22:00:45
 * @Description  : version 1.1
 */
#include "common_def.h"
// 静态变量只在当前文件可见
static int32 sInum = 100; 
// C++中全局const类型的变量的作用域是当前文件
const static int32 const_gp_inum = 100;//因此多次包含也没有问题

class Interger
{
public:
    Interger() : m_i(0) {}
    Interger(int32 i) : m_i(i) {}
    Interger(const Interger &that)
    {
        this->m_i = that.m_i;
    }

public:
    int32 m_i;
};

class CUserFunc
{
public:
    // C++中 常量必须使用成员初始化列表进行初始化
    CUserFunc() : m_pInt(NULL), m_in(0) {}

public:
    // 指向常量的指针
    const Interger *m_pInt;
    Interger m_in;
};

class Calculer
{
public:
    Calculer() {}

public:
    CUserFunc m_cUserFunc;
};

int32 const_cast_test(const Interger &iTmp);

static int32 const_test()
{
    // C++ 中 const 修饰的变量  类似宏替换
    // 只是宏替换在预处理阶段完成 const在编译阶段完成
    Interger in(100);
    const_cast_test(in);
    const int32 num = 100;
    int32 *pNum = (int *)&num;
    *pNum = 200;
    cout << "num : " << num << endl; // 直接替换
    return 0;
}