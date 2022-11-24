class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head, *prev, *temp;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        prev = slow, slow = slow->next, prev->next = NULL;
        while (slow)
            temp = slow->next, slow->next = prev, prev = slow, slow = temp;
        fast = head, slow = prev;
        while (slow)
            if (fast->val != slow->val)
                return false;
            else
                fast = fast->next, slow = slow->next;
        return true;
    }
};

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

// BAD SOLUTION: VERY TIME AND SPACE INEFFICIENT
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> ans1;
        vector<int> ans;
        while (head != NULL)
        {
            ans.push_back(head->val);
            ans1.push_back(head->val);
            head = head->next;
        }

        for (auto i : ans)
        {
            cout << i;
        }
        int n = ans.size();

        reverse(ans1.begin(), ans1.end());

        if (ans == ans1)
            return true;

        return false;
    }
};