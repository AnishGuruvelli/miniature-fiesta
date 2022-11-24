/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// MADD QUESTION: CHECK UNORDERED MAP FORMAT

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, int> mp;
        // MAD WAY OF PUTTING IT

        while (headA != NULL)
        {
            mp[headA]++;
            headA = headA->next;
        }

        while (headB != NULL)
        {
            if (mp[headB] > 0)
                return headB;
            headB = headB->next;
        }
        
        return NULL;
    }
};
