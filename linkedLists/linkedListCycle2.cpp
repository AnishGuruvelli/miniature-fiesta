/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;

        ListNode *slow = head, *fast = head, *curr = head, *temp = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                temp = slow;
                break;
            }
        }

        if (!fast || !fast->next)
            return NULL;

        // this case is mindblowing: specially for 3,2,0,-4; pos = 1; dry run to get to know
        while (curr != temp)
        {
            curr = curr->next;
            temp = temp->next;
        }

        return temp;
    }
};