#include <iostream>
#include <string>
#include <stack>

//Use arrays: Fixed size,random access, less overhead(size,pointers)
//Use LinkedList:Dynamic size,

using namespace std;

typedef struct Node{
        int val;
    struct Node *next;
}NODE;

//returns a node if its circular else NULL
//how to check for a list with one node.
NODE * findIfCircular(NODE *head)
{
    NODE * slow = head;
    NODE * fast = head ;

    while(slow != NULL && fast != NULL && slow != fast) {
        slow = slow->next;
        fast = ( fast->next  != NULL) ? fast->next->next : NULL  ;
    }

    if(slow==fast)
        return slow;
    else
        return NULL ;

}
NODE * findCircularStartPoint(NODE * head,NODE * ret)
{
NODE * first = head;
while(first != ret)
{
    first = first->next;
    ret = ret->next;

}
    return first;


}

//implement LRU cache
//delete a node in a given linked list
//linked list..sorted: how to find an element quickly
//egg falling from 100th floor
//flatten a multi level singly linked list. do this


//implement stack that also maintains min value at any point.
//also think of case when values repeat.
class myStack : stack {
    stack<int> s;
    stack<int> minStack;



    void push(int n)
    {
        s.push(n);
        if(minStack.size() >0 && minStack.top() >= n)
            minStack.push(n);
    }

    int pop()
    {
        if(!s.empty()) {
            int val = s.top();
            s.pop();
            if (minStack.top() == val)
                minStack.pop();

        }
    }

    int getMin()
    {
        return minStack.top();
    }

    int pop()
    {
        if(top)
        {
            int ret = top->val;
            top = top->next;
            return ret;
        }
        else
            return -1;
    }

    int min






};

int main() {
    std::cout << "Hello, World!" << std::endl;

    NODE *head = NULL;
    head = new Node();
    head->val = 0;
    head->next = NULL;

    NODE * ret = findIfCircular(head);

    findCircularStartPoint(head,ret);


    return 0;
}