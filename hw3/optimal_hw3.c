#include <stdio.h>
#include <stdlib.h>
volatile int main()
{
	volatile int nums[] = {0,1,0,3,12};
	volatile int numsSize = 5;
	volatile int i;
	volatile int index=0;
	
	printf("\nBefore move zeroes = ");
	for(i = 0; i < numsSize; ++i){
		printf("%d ", nums[i]);
	}

	if(nums[0]){nums[index++] = nums[0];}
	if(nums[1]){nums[index++] = nums[1];}
	if(nums[2]){nums[index++] = nums[2];}
	if(nums[3]){nums[index++] = nums[3];}
	if(nums[4]){nums[index++] = nums[4];}
   	
   	while(index < numsSize){
   		nums[index++] = 0;
   	}
	
	printf("\nAfter  move zeroes = ");
	for(i = 0; i < numsSize; ++i){
		printf("%d ", nums[i]);
	}
	printf("\n");
}