#include <iostream>
using namespace std;

// create a node (4)-->nullptr
class Node
{
private:
    int value;
    Node *next;

public:
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
}

// create a LinkedList head-tail --> (value)-->nullptr
class LinkedList
{
private:
    Node *head;
    tail *tail;
    int length = 1;
}
