

/**
 * 1. Two Sum
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int compare1 = 0;
    int compare2 = 0;
    int *returnLst; 
    *returnSize = 2;
    returnLst = (int *)malloc(sizeof(int) * (*returnSize)); // Memory located
    int loopIdx1 = 0;
    int loopIdx2 = 1;
    for(loopIdx1 = 0; loopIdx1<(numsSize-1); loopIdx1++)
    {
        compare1 = nums[loopIdx1];
        
        for(loopIdx2 = loopIdx1+1; loopIdx2<numsSize; loopIdx2++)
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

/**
 * 2. Add Two Numbers**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
[2,4,3]
[5,6,4]
    struct ListNode* l3 = NULL;
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    struct ListNode *p3 = l3;
    struct ListNode *p3_prev = NULL;

*p3: Cannot access memory at address 0x0
*p1: {val = 2, next = 0x602000000050}
*((*p1).next): {val = 4, next = 0x602000000070}
*p2: {val = 5, next = 0x6020000000d0}
&(*p2): 0x6020000000b0
(*p2)->val: 5

&((*p1)->next): 0x602000000038
&((*p1)->val): 0x602000000030
 */

// Overflow sample
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *returnStru = NULL;
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    struct ListNode *returnStruNex = NULL;
    struct ListNode *returnStruPre = NULL;
    
    bool loops = 1;
    int carry = 0; 
    int carryNex = 0; 
    int decmal = 1;
    while(loops)
    {
        if(p1 == NULL)
        {
            break;
        }
        carry =carry + (p1->val)*decmal;
        p1 = p1->next;
        decmal=decmal*10;
    }
    decmal = 1;
    while(loops)
    {
        if(p2 == NULL)
        {
            break;
        }
        carry =carry + (p2->val)*decmal;
        p2 = p2->next;
        decmal=decmal*10;
    }
    decmal = 1;
    carryNex = carry;
    returnStruPre = (struct ListNode *) malloc(sizeof(struct ListNode));
    returnStru = returnStruPre;
    returnStru->val = 0;
    returnStru->next = NULL;
    
    while(loops)
    {
        if(carryNex!=0)
        {
            returnStruPre->val = carryNex%10;
            carryNex = carryNex/10;
            if(carryNex!=0)
            {
                returnStruNex = (struct ListNode *) malloc(sizeof(struct ListNode));
                returnStruPre->next = returnStruNex;
                returnStruPre = returnStruNex; // Update ptr
            }
        }
        else
        {
            returnStruPre->next = NULL;
            break;
        }
    }
    
    return returnStru;
}
//Correct sample, add by element
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode* l3 = NULL;
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    struct ListNode* p3 = l3;
    struct ListNode* p3_prev = NULL;
    int carry = 0; 
    int turn = 0;
    
    while(p1 || p2 || carry) 
    {
        int val1 = 0, val2 = 0, val3 = 0;
        if (p1) 
        {
          val1 = p1->val;
          p1 = p1->next;
        }
        if (p2) 
        {
          val2 = p2->val;
          p2 = p2->next;
        }
        val3 = val1 + val2 + carry;
        carry = val3 / 10;
        p3 = (struct ListNode *) malloc(sizeof(struct ListNode)); p3->val = val3 % 10; p3->next = NULL;
        if (!turn)
        {
          l3 = p3;
        }
        else
        {
          p3_prev->next = p3;
        }
        p3_prev = p3;
        turn++;
  }
  return l3;
}
    