/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution
// {
// public:
//     ListNode *oddEvenList(ListNode *head)
//     {
//         ListNode *node = head;
//         while (head && head->next)
//         {
//             node->next = head->next->next;
//             head = head->next->next;
//         }
//         return node;
//         // this should return 1,3,5 right? if head = [1,2,3,4,5]; but its returning only 1
//     }
// };

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *odd = NULL, *headodd = NULL, *even = NULL, *headeven = NULL;

        if (!head || !head->next || !head->next->next)
            return head;

        odd = head;
        headodd = odd;
        even = head->next;
        headeven = even;

        while (even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = headeven;
        return headodd;
    }
};