#include <iostream>
using namespace std;

class linked_list
{
private:
    int val;
    linked_list *next;

public:
    linked_list() : val(0), next(nullptr) {} // Default constructor to initialize the head node.

    int depth()
    {
        int counter = 0;
        linked_list *runner = this;
        while (runner != nullptr)
        {
            counter++;
            runner = runner->next;
        }
        return counter;
    }

    void insert(int val)
    {
        linked_list *runner = this;
        // Traverse until the last node
        while (runner->next != nullptr)
        {
            runner = runner->next;
        }
        // Create a new node
        linked_list *newNode = new linked_list();
        newNode->val = val;
        runner->next = newNode; // Set the next of the last node to the new node
    }

    void erase(int val)
    {
        linked_list *runner = this;
        if (runner == nullptr)
        {
            cout << "hooson husnegtees element ustgah oroldlogo ";
        }
        while (runner->next != nullptr)
        {
            runner = runner->next;
        }
        if (runner->next->val == val)
        {
            linked_list *temp = runner->next;
            runner->next=runner->next->next;
            free(temp);
        }
    }
};

int main()
{
    linked_list head; // Initialize the head node
    cout << " 1. ADD 2. FIND DEPTH ";
    char c;
    int too;
    while (1)
    {
        cin >> c;
        if (c == '1') // Add a value to the linked list
        {
            cin >> too;
            head.insert(too);
        }
        else if (c == '2') // Print the depth of the linked list
        {
            cout << head.depth() << " ";
        }
    }
}
