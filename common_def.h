/*
 * @Author       : konglc
 * @Date         : 2023-10-29 14:26:18
 * @LastEditors  : Please set LastEditors
 * @LastEditTime : 2023-11-14 12:40:29
 * @Description  : version 1.1
 */
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#ifndef __COMMON_DEF_H__
#define __COMMON_DEF_H__

typedef int int32;
typedef long long int64;
#define FUNCTION_BGEIN cout << __FILE__ << " : " << __FUNCTION__ << " : " << __LINE__ << endl;
const int32 month_days[2][13] =
    {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // 平年每月天数
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  // 闰年每月天数

};