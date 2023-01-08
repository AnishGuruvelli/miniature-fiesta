// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution
// {
// public:
//     ListNode *reverse(ListNode *head)
//     {
//         ListNode *prevNode = NULL, *nextNode = NULL;
//         while (!head || !head->next)
//             return head;

//         while (head)
//         {
//             nextNode = head->next;
//             head->next = prevNode;
//             prevNode = head;
//             head = nextNode;
//         }
//         return prevNode;
//     }
//     ListNode *removeN(ListNode *head, int n)
//     {
//         ListNode *dummy = new ListNode(-1);
//         dummy->next = head;
//         ListNode *temp = dummy;

//         while (n > 1)
//         {
//             n--;
//             temp = temp->next;
//         }

//         ListNode *node = NULL;

//         node = temp->next;
//         temp->next = temp->next->next;
//         delete (node);

//         return dummy->next;
//     }
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         ListNode *reversedLL = reverse(head);
//         ListNode *removedLL = removeN(reversedLL, n);
//         return reverse(removedLL);
//     }
// };

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *fast = start;
        ListNode *slow = start;

        for (int i = 1; i <= n; ++i)
            fast = fast->next;

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return start->next;
    }
};
