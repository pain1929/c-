#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//  ����һ������arr  ����һ����target  ������arr�� ����������� = target ���������������±�
//

int* twoSum(int* nums,int size,int target) {
    //�����ڴ�
    static int arr[] = { 0,0,'\0' };
    int* fist = calloc(size, 4);
    int* arrFist = nums;
    int* p = fist;
    int j = 0;
    //��������
    for (int i = 0; i < size; i++)
    {
        int num = *nums;
        
        if (target - num > 0)
        {
            int another = target - num;
            *p = another;
        }
        p++;
        nums++;
    }
    //�����ڴ��е�����
    //�Ƚ���ָ�뻹ԭ
    p = fist;
    
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        //��ԭָ��
        nums = arrFist;
        if (flag == 1)
        {
            break;
        }
        for ( j = 0; j < size; j++)
        {
            
            int num = *nums;
            if (num == ( * p))
            {
                arr[0] = j;
                arr[1] = i;
                flag = 1;
                break;
            }
            nums++;
       }
        p++;
    }
    return arr;
}


int main()
{

    int arr[] = { 1,2,3,4,5,34,6,7,'\0' };

    int* p  = twoSum(arr, 8,40);
    printf("%d\n", *p);
    printf("%d", *(p + 1));
    
    return 0;
}