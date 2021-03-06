#include <stdio.h>
#include <stdlib.h>
void moveZeroes(int* nums, int numsSize);

int main()
{    
    int nums[] = {0,1,0,3,12};
    int numsSize = 5;
    printf("\nBefore move zeroes = ");
    for(int i = 0; i < numsSize; ++i){
        printf("%d ", nums[i]);
    }
    moveZeroes(nums, numsSize);
    printf("\nAfter  move zeroes = ");
    for(int i = 0; i < numsSize; ++i){
        printf("%d ", nums[i]);
    }
    printf("\n\n");
}

void moveZeroes(int nums[], int numsSize){
    int index=0;
    for(int i = 0; i < numsSize; ++i){
        if(nums[i])
            nums[index++] = nums[i];
    }
    while(index < numsSize)
        nums[index++] = 0;
}