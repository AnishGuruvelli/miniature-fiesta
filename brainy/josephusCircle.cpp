class Solution
{
public:
    void josephus(vector<int> &v, int start, int k)
    {
        if (v.size() == 1) // Return last standing person
            return;

        start += k; // Position of person form start which is to be eliminated
        int s = v.size();
        start %= s;                 // Taking remainder so that index does not go above the size of array
        v.erase(v.begin() + start); // Eliminating the person
        josephus(v, start, k);      // Recusive call
        return;
    }

    int findTheWinner(int n, int k)
    {
        vector<int> v(n, -1);

        k--;

        for (int i = 1; i <= n; i++)
            v[i - 1] = i;

        josephus(v, 0, k);
        return v[0];
    }
};

class Solution
{
public:
    int helper(ListNode *head, int k)
    {
        ListNode *temp = head; // For traversing through the List and delete every kth Node
        while (head->next != head)
        { // Till the last Node remains in the list i.e. the winner
            ListNode *pre = NULL;
            for (int i = 1; i < k; i++)
            {
                pre = temp;
                temp = temp->next;
            }
            // Deletion procedure
            if (temp == head)
                head = head->next;
            pre->next = temp->next;
            delete (temp);
            temp = pre->next;
        }
        // The last node remaining becomes the head of the Circular Linked List i.e. Winner
        return head->val;
    }
    int findTheWinner(int n, int k)
    {
        if (k == 1)
            return n;
        // Designing Circular Linked List for Node 1,2,3,4,.....,n
        ListNode *head = NULL, *tail = NULL;
        for (int i = 1; i <= n; i++)
        {
            ListNode *node = new ListNode(i);
            if (head == NULL)
                head = tail = node;
            else
            {
                tail->next = node;
                tail = node;
            }
            tail->next = head;
        }
        // Helper function will eliminate the nodes and give us the winner
        return helper(head, k);
    }
};

class Solution
{
public:
    int helper(int n, int k)
    {
        if (n == 1)
            return 0;
        return (helper(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k)
    {
        return helper(n, k) + 1; //+1 is for converting 0-based indexing to 1-based indexing
    }
};

class Solution
{
public:
    int helper(int n, int k)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans + k) % i;
        }
        return ans;
    }
    int findTheWinner(int n, int k)
    {
        return helper(n, k) + 1; //+1 is for conterting 0-based indexing to 1-based indexing
    }
};