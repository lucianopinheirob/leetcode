#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* vetor_retornado = NULL;
    *returnSize = 2;
    vetor_retornado = malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < numsSize; i++){
        for(int j = i+1; j < numsSize; j++){
            if (nums[i] + nums[j] == target){
                *vetor_retornado = i;
                *(vetor_retornado + 1) = j;
                return vetor_retornado;
            }
        }
    }
    return vetor_retornado;
}

int main(){
    int* vet_ret;
    int target = 6, numsSize = 3;
    int nums[] = {3, 2, 4};
    int returnSize;

    vet_ret = twoSum(nums, numsSize, target, &returnSize);

    printf("%d\n", vet_ret[0]);
    printf("%d\n", vet_ret[1]);
    

    return 0;
}

/*solution.c: In function ‘twoSum’
Line 14: Char 1: error: control reaches end of non-void function [-Werror=return-type] [solution.c]
 }
 ^
cc1: some warnings being treated as errors*/