#include <stdio.h>
#include <stdlib.h>

void moveZeroes(volatile int nums[], volatile int numsSize){
    volatile int index=0;
    for(volatile int i = 0; i < numsSize; ++i){
        if(nums[i])
            nums[index++] = nums[i];
    }
    while(index < numsSize)
        nums[index++] = 0;
}

volatile int main()
{    
    volatile int nums[] = {0,1,0,3,12};
    volatile int numsSize = 5;
    printf("\nBefore move zeroes = ");
    for(volatile int i = 0; i < numsSize; ++i){
        printf("%d ", nums[i]);
    }
    moveZeroes(nums, numsSize);
    printf("\nAfter  move zeroes = ");
    for(volatile int i = 0; i < numsSize; ++i){
        printf("%d ", nums[i]);
    }
    printf("\n\n");
}


