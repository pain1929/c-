#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//��ȡ���ֽ���λ��ֺ���ӵĺ�
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
    //�����ڴ�
    int* fist = calloc(hightLimit, 8);
    if (fist == NULL)
    {
        printf("..");
        return;
    }
    for (int i = lowLimit; i <= hightLimit; i++)
    {
        //ÿ��ѭ����ʼǰ����ָ��
        //p1 = ÿ8���ֽڵĵ�4��
        //p2 = ÿ8���ֽڵĸ�4��
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
    //��ʼ����ָ�� ������
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
    //��ʱtemp_p �����������ָ��
    printf("�������%d\n", temp);
    printf("���룺%d", *(temp_p - 1));


    
    
}


int main()
{
    countBalls(1, 10);
    return 0;
}