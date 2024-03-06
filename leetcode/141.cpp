// 141. Linked List Cycle

#include <unordered_set>


// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};

class Solution
{
  public:
    bool hasCycle(ListNode* head)
    {
        std::unordered_set<ListNode*> list_of_uniqe_addresses;
        ListNode* current = head;
        while (current != nullptr) {
            if (list_of_uniqe_addresses.insert(current).second == false) {
                return true;
            }
            current = current->next;
        }
        return false;
    }


    bool fastHasCycle(ListNode* head)
    {
        ListNode* tortoise = head;
        ListNode* hare = head;
        while (hare != nullptr && hare->next != nullptr) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) {
                return true;
            }
        }
        return false;
    }
};


int main(int argc, char** argv)
{

    return 0;
}
