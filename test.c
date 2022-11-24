#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//获取数字进制位拆分后相加的和
int getCharSum(int num)
{
    int s = 1;
    int sum = 0;

    if (num >= 10 && num % 10 == 0)
    {
        int a = 10;
        while ((num / a) > 10)
        {
            a *= 10;
        }
        return num / a;
    }
    
    while ((num / s) % 10 != 0)
    {
        sum += (num / s) % 10;
        s *= 10;
    }
    
    return sum;
}



int countBalls(int lowLimit, int hightLimit)
{
    //分配内存
    int* fist = calloc(hightLimit, 8);
    if (fist == NULL)
    {
        printf("..");
        return;
    }
    for (int i = lowLimit; i <= hightLimit; i++)
    {
        //每次循环开始前重置指针
        //p1 = 每8个字节的低4个
        //p2 = 每8个字节的高4个
        int* p1 = fist;
        int* p2 = fist + 1;
        int sum = getCharSum(i);
        while (1)
        {
            if (*p1 == 0)
            {
                *p1 = sum;
                (*p2)++;
                break;
            }
            else if (*p1 == sum)
            {
                (*p2)++;
                break;
            }
            p1 += 2;
            p2 += 2;
        }
        
    }
    //开始遍历指针 求出最高
    int temp = 0;
    int* temp_p = NULL;
    int* p2 = fist + 1;
    for (int i = 0; i < hightLimit; i++)
    {
        if (*p2 > temp)
        {
            temp = *p2;
            temp_p = p2;
        }
        p2 += 2;
    }
    //此时temp_p 就是最高数的指针
    printf("最高数：%d\n", temp);
    printf("号码：%d", *(temp_p - 1));


    
    
}


int main()
{
    countBalls(1, 10);
    return 0;
}