// Just use a queue where you "push to front" by pushing to back and then rotating the queue until the new element is at the front (i.e., size-1 times move the front element to the back).

class MyStack
{
public:
    queue<int> q;
    MyStack() {}

    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int item = q.front();
        q.pop();
        return item;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};