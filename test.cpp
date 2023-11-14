/*
 * @Author       : konglc
 * @Date         : 2023-11-05 10:05:24
 * @LastEditors  : Please set LastEditors
 * @LastEditTime : 2023-11-10 14:19:22
 * @Description  : version 1.1
 */
#include "test.h"
#include <iostream>
int32 test_longestCommonSubSequence()
{
    char str[64];
    memset(str,0,sizeof(str));
    char* s1 = itoa_(-90000,str);
    cout << "str : " << s1 << endl;
    return 0;
}

int32 test_split_valToList()
{
    std::string str = "10001|10002|10003";
    std::set<int32> setSplit;
    split_valToList(str,"|",setSplit);
    for(std::set<int32>::const_iterator iter = setSplit.begin();iter != setSplit.end();++iter)
    {
        cout << * iter << " " ;
    }
    cout << endl;
    return 0;
}