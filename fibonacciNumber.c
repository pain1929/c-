#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//求 斐波那契数
int doSome(int n) {
    int fist = 1;
    int second = 1;
    int third = fist + second;

    if(n>2)
    {
        for (int i = 3; i < n; i++)
        {
            fist = second;
            second = third;
            third = fist + second;
        }
        return third;
    }
    else {
        return fist;
    }

}
//判断合数 1是合数 0是素数
int IsHeShu(int num)
{
    if (num <= 2)
    {
        return 0;
    }
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0) 
        {
            return 1;
        }
        
    }
    return 0;
}

//求第n个合数
int HeShu(int num)
{
    int i = 1;
    int sum = 0;
    while(1)
    {
        int back = IsHeShu(doSome(i));
        if (back == 1)
        {
            sum++;
        }
        if (sum == num)
        {
            return doSome(i);
        }
        i++;
    }
}
int main()
{
   int back =  HeShu(2);
   printf("%d\n", back);
    return 0;
}
