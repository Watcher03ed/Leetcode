

/**
 * 1. Two Sum
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int compare1 = nums[0];
    int compare2 = nums[1];
    int *returnLst; 
    *returnSize = 2;
    returnLst = (int *)malloc(sizeof(int) * (*returnSize)); // Memory located
    int loopIdx1 = 0;
    int loopIdx2 = 1;
    for(loopIdx1 = 0; loopIdx1<numsSize-1; loopIdx1++)
    {
        compare1 = nums[loopIdx1];
        
        for(loopIdx2 = loopIdx1+1; loopIdx2<numsSize; loopIdx1++)
        {
            compare2 = nums[loopIdx2];
            if((compare1+compare2)==target)
            {
                returnLst[0] = loopIdx1;
                returnLst[1] = loopIdx2;
                return(returnLst);
                }
        }
    }
    return(returnLst);
}
    
    