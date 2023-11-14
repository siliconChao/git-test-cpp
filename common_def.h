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

/**
 * @name:
 * @msg:
 * @param {int32} days 距离1970年的天数
 * @return {*}
 */
static int32 getDate(int32 days)
{
    int32 year = 1970;
    if (days > 14610)
    {
        // 2010年距离1970年 14610天
        days -= 14610;
        year = 2010;
    }
    else if (days > 10957)
    {
        // 2000年距离 1970年 10957天
        days -= 10957;
        year = 2000;
    }

    // 年份分摊天数 够一年天数 则年份 +1 天数 - 一年天数
    while (year <= 2100)
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) // 闰年
        {
            // 剩余天数超过 366 天
            if (days > 366)
            {
                days -= 366;
                year++;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (days > 365)
            {
                days -= 365;
                year++;
            }
            else
            {
                break;
            }
        }
    }
    // 因为传进来的天数少一天 因此加 1
    // days += 1;

    int32 mon = 1;

    int flag = 0; // 平年标记
    if (year % 4 == 0 && year % 400 != 0 || year % 400 == 0)
    {
        flag = 1; // 闰年标记
    }

    // 计算月份数
    while (mon <= 12)
    {
        if (days > month_days[flag][mon])
        {
            days -= month_days[flag][mon];
            ++mon;
        }
        else
        {
            break;
        }
    }

    return year * 10000 + mon * 100 + days;
}

/**
 * @name:
 * @msg:
 * @param {string} &strTime
 * @return {*}
 */
static int64 timeToDateTime_int64(const std::string &strTime)
{
    double time_zone = 8;
    int64 time = atoll(strTime.c_str());
    int64 tmp_time = time + int32(time_zone * 3600);
    // 当前时间距离1970年有多少天
    int32 days = tmp_time / 86400;
    // 转换成日期
    int32 date = getDate(days + 1);
    int32 sec = tmp_time - days * 86400;
    int32 hour = sec / 3600;
    int32 min = (sec - hour * 3600) / 60;
    sec -= (hour * 3600 + min * 60);

    return date * 1000000LL + hour * 10000LL + min * 100LL + sec;
}
