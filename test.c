#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//�� 쳲�������
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
//�жϺ��� 1�Ǻ��� 0������
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

//���n������
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