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
    ListNode *sortList(ListNode *head)
    {
        vector<int> nums;

        while (head != NULL)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        sort(nums.begin(), nums.end());

        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        for (auto i : nums)
        {
            ListNode *node = new ListNode(i);
            curr->next = node;
            curr = curr->next;
        }

        return dummy->next;
    }
};