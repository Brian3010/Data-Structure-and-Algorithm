#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        this->length = 1;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        Node *temp = head;

        if (temp)
        {
            cout << temp->value;
            temp = temp->next;
        }
        while (temp)
        {
            cout << " - " << temp->value;
            temp = temp->next;
        }
    }

    void getHead()
    {
        cout << "Head: " << head->value << endl;
    }

    void getTail()
    {
        cout << "Tail: " << tail->value << endl;
    }

    void getLength()
    {
        cout << "Length: " << this->length << endl;
    }

    void append(int value)
    {
        // create a new node
        Node *newNode = new Node(value);

        // append a new node if the linkedlist empty
        if (tail == nullptr && head == nullptr)
        {
            head = newNode;
            tail = newNode;
            this->length = 1;
        }

        // append a new Node to the list if not empty
        tail->next = newNode;
        tail = newNode;
        this->length += 1;
    }

    void deleteLast()
    {
        // if linkedlist is empty
        if (this->length == 0)
            return;

        Node *pre, *temp;
        // point pre, temp to head
        pre = head;
        temp = head;

        // if only 1 node left in the list
        if (this->length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            // check temp->next != nullptr
            while (temp->next)
            {
                pre = temp; // set temp to the previous node from the last node
                temp = temp->next;
            }
            tail = pre; // point pre to tail;
            tail->next = nullptr;
        }
        this->length--;
        delete temp;
    }

    void prepend(int value)
    {
        Node *newNode = new Node(value);

        // if list empty
        if (this->length == 0)
        {
            head = newNode;
            tail = newNode;
        }

        // there're nodes in the list
        newNode->next = head;
        head = newNode;
        this->length++;
    }

    void deleteFist()
    {
        // if there list empty
        if (this->length == 0)
            return;

        // if 1 node in the list
        if (this->length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }

        // there're nodes in the list
        Node *temp = head; // point temp to head

        // move head to next node
        head = head->next;
        this->length--;
        delete temp; // delete temp
    }

    Node *get(int index)
    {
        // if index is out of range
        if (index >= this->length || index < 0)
        {
            return nullptr;
        }

        // (4)->(2)->(22)->nullptr;
        // 0->1->2->nullptr - length = 3

        Node *temp = head;

        for (int i = 0; i < index; i++)
        {
            temp = temp->next; // move temp to next node if index fulfilled
        }

        // int i = 0;
        // while (i < index)
        // {
        //     temp = temp->next;
        //     i++;
        // }

        return temp;
    }

    bool set(int index, int value)
    {
        // get value from index
        Node *temp = get(index);
        // if nullptr returned
        if (!temp)
            return false;

        // set value in temp to the new value
        temp->value = value;
        return true;
    }
};

int main()
{
    LinkedList *myLinkedList = new LinkedList(4);

    // append new node
    myLinkedList->append(22);
    myLinkedList->append(1);
    myLinkedList->append(34);
    myLinkedList->append(52);

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

    myLinkedList->printList();

    // delete last node
    cout << endl;
    myLinkedList->deleteLast();
    myLinkedList->deleteLast();
    // myLinkedList->deleteLast();
    // myLinkedList->deleteLast();
    cout << "\nafter deleleLast(): ";
    myLinkedList->getLength();
    myLinkedList->printList();

    // prepend a node
    cout << endl;
    myLinkedList->prepend(5);
    myLinkedList->prepend(6);
    cout << "after prepend: ";
    myLinkedList->getLength();
    myLinkedList->printList();

    // delete first node
    cout << endl;
    myLinkedList->deleteFist();
    cout << "after deteteFist: ";
    myLinkedList->getLength();
    myLinkedList->printList();

    // get value using index;
    cout << endl;
    cout << "get index at 2:  " << myLinkedList->get(2)->value << endl;
    cout << "get index at 0:  " << myLinkedList->get(0)->value << endl;
    cout << "get index at 1:  " << myLinkedList->get(1)->value << endl;
    // cout << "get index at 1:  " << myLinkedList->get(4)->value << endl;

    // set value at index
    cout << endl;
    cout << "set 40 at index 2:  " << myLinkedList->set(2, 40) << endl;
    cout << "set 65 at index 1:  " << myLinkedList->set(1, 65) << endl;
    myLinkedList->getLength();
    myLinkedList->printList();

    delete myLinkedList;
}
