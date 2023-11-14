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

template <class T>
T CArr<T>::operator[](int index)
{
    return this->m_pT[index];
}

template <class T>
void CArr<T>::push_back(const T &v)
{
    // 数组非空
    if (this->m_pT)
    {
        T *temp = new T[this->m_size + 1];
        // 拷贝原数组的内容
        memcpy(temp, this->m_pT, sizeof(T) * this->m_size);
        delete[] this->m_pT;
        this->m_pT = temp;
    }
    else
    {
        this->m_pT = new T[1];
    }
    this->m_pT[this->m_size++] = v;
}

template <class T>
int32 CArr<T>::lenth() const
{
    return this->m_size;
}

template <class T>
CArr<T>::~CArr()
{
    if (this->m_pT)
    {
        delete[] this->m_pT;
        this->m_pT = NULL;
    }
}

void test_CArr()
{
    CArr<int32> arr;
    for (int index = 0; index < 10; index++)
    {
        arr.push_back(index * 10);
    }

    for(int index = 0; index < 10;index++)
    {
        cout << arr[index] << endl; 
    }
}
