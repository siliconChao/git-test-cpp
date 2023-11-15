/*
 * @Author       : konglc
 * @Date         : 2023-10-25 20:14:52
 * @LastEditors  : Please set LastEditors
 * @LastEditTime : 2023-10-28 10:12:06
 * @Description  : version 1.1
 */
#include <iostream>
namespace NABESPACE_TEST
{
    // 定义引用
    int num = 100;
    // 定义类型
    typedef int int32;
// 定义宏
#define NUM 100;

    // 定义类
    class CNameSpace
    {
        char *name;
        int32 size;
    };

    // 定义静态方法
    static int32 static_func_test()
    {
        std::cout << "this is a static function" << std::endl;
        return 0;
    }

    // 定义普通方法
    int32 sum(int32 a, int32 b)
    {
        return a + b;
    }

    int32 forTest() 
    {
        using namespace std;
        int i = 100;
        cout << i << endl;
        for (int i = 0; i < 10;i++)
        {
            cout << i << endl;
        }
        cout << "i = " << i << endl;
        return 0;
    }

} // 最后没有分号
