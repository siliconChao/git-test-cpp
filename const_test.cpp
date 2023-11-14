/*
 * @Author       : konglc
 * @Date         : 2023-10-25 21:53:39
 * @LastEditors  : Please set LastEditors
 * @LastEditTime : 2023-10-25 21:55:44
 * @Description  : version 1.1
 */
#include "const_test.h"
// 全局变量的作用域是当前文件  在其他文件中也可以引用 使用extern关键字即可
int32 gb_Inum = 1000;
int32 const_cast_test(const Interger &iTmp)
{
    cout << "iTmp.m_i = " << iTmp.m_i << endl;
    Calculer cal;
    // 指向常量的指针
    cal.m_cUserFunc.m_pInt = &iTmp;
    // iTmp 是常量 值不能直接修改 可以通过指针进行修改
    cal.m_cUserFunc.m_in = *(const_cast<Interger *>(cal.m_cUserFunc.m_pInt)); // 去常转换
    cal.m_cUserFunc.m_in = 88;
    cal.m_cUserFunc.m_pInt = &cal.m_cUserFunc.m_in;
    cout << "cal.m_cUserFunc.m_pInt->m_i = " << cal.m_cUserFunc.m_pInt->m_i << endl;
    return 0;
}
