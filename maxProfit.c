#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//��Ŀ�� ����һ������ prices ����һ֧��Ʊ����ʷ�۸� ����������Ƕ��٣�

int maxProfit(int* prices , int size)
{
    int* fist = prices;
    int min = *fist;
    int difference = 0;
    for (int i = 0; i < size; i++)
    {
        int price = *prices;

        if (price < min)
        {
            min = price;
        }
        else {
            if (price - min > difference)
            {
                difference = price - min;
             }
        }
        prices++;
    }
    return difference;
}
int main()
{
    int arr[] = { 6,7,4,3,1,5,3,5,3,9,33,1,66 };
    int max = maxProfit(arr, 13);
    printf("%d", max);
    return 0;
}