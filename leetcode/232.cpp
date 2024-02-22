// leetcode problem no. 232. Implement Queue using Stacks
#include <stack>

class MyQueue
{
  public:
    MyQueue()
        : m_stack()
        , m_queue()
    {
    }

    inline void push(int x) { m_stack.push(x); }


    int pop()
    {
        if (m_queue.empty()) {
            while (!m_stack.empty()) {
                m_queue.push(m_stack.top());
                m_stack.pop();
            }
        }

        int ret_val = m_queue.top();
        m_queue.pop();
        return ret_val;
    }

    int peek()
    {
        if (m_queue.empty()) {
            while (!m_stack.empty()) {
                m_queue.push(m_stack.top());
                m_stack.pop();
            }
        }

        return m_queue.top();
    }

    inline bool empty() { return m_stack.empty() && m_queue.empty(); }
  private:
    std::stack<int> m_queue;
    std::stack<int> m_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main()
{
    MyQueue* a = new MyQueue();

    return 0;
}
