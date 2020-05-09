#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

#include "common.h"

struct ArrayData
{
    int iLen;
    int Array[0];
};

void swap(int *a, int *b)
{
    int iTmp;
    iTmp = *a;
    *a = *b;
    *b = iTmp;
}

void bubble_sort(int *iArray, int len)
{
    for(int index = 0; index < len - 1; index++)
    {
	for(int j = 0; j < len-1-index; j++)
	{
	    if(iArray[j] > iArray[j+1])
	    {
		swap(&iArray[j], &iArray[j+1]);
	    }
	}
    }
}

int main(int argc, char **argv)
{
    //int iArray[10000] = {0};
    int size = atoi(argv[1]);
    struct ArrayData *iArrayData = NULL;
    struct timeval stTimeStart;
    iArrayData = malloc(sizeof(struct ArrayData) + size * sizeof(int));
    iArrayData->iLen = size;
    int *iArray = iArrayData->Array;    
    unsigned long ulTimeUse = 0;

    memset(&stTimeStart, 0, sizeof(stTimeStart));

    /* 初始化随机数发生器 */
    srand((unsigned)time(NULL));

    for(int i = 0; i < size; i++)
    {
	iArray[i] = rand() % 200 - 100;
    }

    //printf("冒泡排序前：\r\n");
    //for(int i = 0; i < size; i++)
    //{
	//printf("%d ", iArray[i]);
    //}

    COMMON_StartRecordTime(&stTimeStart);
    bubble_sort(iArray, size);
    ulTimeUse = COMMON_EndRecordTime(&stTimeStart);

    printf("排序%d个数据，耗时%ld usec.\r\n", size, ulTimeUse);
    //printf("\r\n冒泡排序后：\r\n");
    //for(int i = 0; i < size; i++)
    //  {
//	printf("%d ", iArray[i]);
    //}
    //printf("\r\n");

    return 1;
}
