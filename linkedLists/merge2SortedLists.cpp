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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//     {
//         ListNode *head;
//         ListNode *ptr;
//         ListNode *cnnctr;
//         vector<int> vec;
//         while (list1)
//         {
//             vec.push_back(list1->val);
//             list1 = list1->next;
//         }
//         while (list2)
//         {
//             vec.push_back(list2->val);
//             list2 = list2->next;
//         }
//         sort(vec.begin(), vec.end());
//         for (int i = 0; i < vec.size(); i++)
//         {
//             ptr = new ListNode();
//             ptr->val = vec[i];
//             if (i == 0)
//             {
//                 head = ptr;
//                 cnnctr = head;
//             }
//             else
//             {
//                 cnnctr->next = ptr;
//                 cnnctr = cnnctr->next;
//             }
//         }
//         return head;
//     }
// };
