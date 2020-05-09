#include <stdio.h>
#include <sys/time.h>

void COMMON_StartRecordTime(struct timeval *pstTimeStart)
{
    gettimeofday(pstTimeStart, NULL);
}

unsigned long COMMON_EndRecordTime(struct timeval *pstTimeStart)
{
    struct timeval stTimeEnd;
    gettimeofday(&stTimeEnd, NULL);
    return 1000000 * (stTimeEnd.tv_sec - pstTimeStart->tv_sec) + (stTimeEnd.tv_usec - pstTimeStart->tv_usec);
}
