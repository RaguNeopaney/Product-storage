#pragma once
#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

/*
    This is the class for the node
*/
template<typename T>
class Node
{
public:
    T data;
    int sku,QOH;
    double price;
    T UOM;
    Node<T>* next;
    Node<T>* prev;
    Node() { next = prev = nullptr; data = sku = QOH = 0; price = 0.00; UOM = "NONE"; };
};

/*
    This is the class for doubly liked list
*/
template <typename T>
class Linkedlist
{
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* location_Node;
    int size;
public:
    Linkedlist();
    ~Linkedlist();

    // Errors
    class seeEmptyError {};
    class getEmptyError {};
    class IsInEmptyError {};
    class seeAtError {};

    void AddItem(int,T,double,T,int);
    T GetItem(int);
    bool IsEmpty();
    bool IsInlist(int);
    int SeeNext();
    int SeePrev();
    T SeeAt(int);
    void Reset();

    // Test
    void display();


};
template<typename T>
Linkedlist<T>::Linkedlist()
{
    head = nullptr;
    tail = nullptr;
    location_Node = nullptr;
    size = 0;
}

template<typename T>
void Linkedlist<T>::AddItem(int sk,T user_data,double pri,T Unit, int quan)
{
    size++;
    Node<T>* newNode;
    Node<T>* nodeptr;

    newNode = new Node<T>;
    newNode->data = user_data;		// this will add the data user passes to the list
    newNode->next = nullptr;
    newNode->sku = sk;			// this will be the key for each node that is added
    newNode->price = pri;
    newNode->UOM = Unit;
    newNode->QOH = quan;


    // if there are no node on the list this will make the node that was just created the fist node of the list
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    // else it will go through the whole list until if find the null pointer and append the node to the end of the list
    else
    {
        nodeptr = head;				// This will be our pointer that will move through the list
        while (nodeptr->next != nullptr)
        {
            nodeptr = nodeptr->next;
        }
        nodeptr->next = newNode;
        newNode->prev = nodeptr;
        tail = newNode;
    }

}
template<typename T>
T Linkedlist<T>::GetItem(int user_num)
{
    T retval;
    Node<T>* ptr;
    Node<T>* found = nullptr;							// This will replace with the node holding the value user wants to return
    Node<T>* current_prev = nullptr;					// This will hold the address for the previous before deleting
    Node<T>* current_next = nullptr;					// This will hold the address for the next before deleting


    ptr = head;

    if (ptr == nullptr)
    {
        throw getEmptyError();
    }
    else
    {


        while (ptr->sku != user_num)							// This loop will go until end of the the linked list
        {
            if (ptr->next == nullptr)
            {
                return NULL;
            }
            ptr = ptr->next;
            found = ptr;

        }


        if (found == head)										// This is for if the value user want to return is at the beginning of the list
        {
            size--;
            retval = found->data;
            head = head->next;
            head->prev = nullptr;
            delete found;
            return retval;
        }

        // if the value user is searching to remove is at the end of the list than this if case will execute

        if (ptr->next == nullptr && ptr->sku == user_num)
        {
            size--;
            found = ptr;
            retval = found->data;
            current_prev = found->prev;
            current_prev->next = nullptr;
            tail = current_prev;
            delete found;
            return retval;
        }

        // These are the lines to return and delete a node from the middle of the list

        retval = found->data;
        current_next = found->next;
        current_prev = found->prev;
        current_next->prev = current_prev;
        current_prev->next = current_next;
        delete found;
        size--;
        return retval;
    }
}
template<typename T>
bool Linkedlist<T>::IsInlist(int user_item)
{
    Node<T>* temp;

    temp = head;
    if (temp == nullptr)
    {
        throw IsInEmptyError();
    }
    else
    {
        bool retval = false;
        while (temp != nullptr)
        {
            if (temp->sku == user_item)
            {
                retval = true;
                return retval;
            }
            temp = temp->next;
        }
        return retval;
    }
}
template <typename T>
bool Linkedlist<T>::IsEmpty()
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename T>
T Linkedlist<T>::SeeAt(int location_num)
{
    if (IsEmpty())
    {
        throw seeAtError();
    }
    else
    {
        Node<T>* ptr;
        ptr = head;

        T retval;

        while (ptr->sku != location_num)
        {
            if (ptr->sku != location_num && ptr->next == nullptr)
            {
                throw seeAtError();
            }
            ptr = ptr->next;

        }
        retval = ptr->data;
        location_Node = ptr;
        return retval;
    }
}
template <typename T>
int Linkedlist<T>::SeeNext()
{
    int reteval;
    if (IsEmpty())
    {
        throw seeEmptyError();
    }
    else
    {
        if (location_Node == nullptr)
        {
            location_Node = head;
        }
        if (location_Node->next == nullptr)
        {
            reteval = NULL;
            return reteval;
        }
        reteval = location_Node->next->sku;
        location_Node = location_Node->next;
        return reteval;
    }
}
template <typename T>
int Linkedlist<T>::SeePrev()
{
    int reteval;
    if (IsEmpty())
    {
        throw seeEmptyError();
    }
    else
    {
        if (location_Node->prev == nullptr)
        {
            return NULL;
        }
        reteval = location_Node->prev->sku;
        location_Node = location_Node->prev;
        return reteval;
    }
}
template <typename T>
void Linkedlist<T>::Reset()
{
    location_Node = head;
}

template <typename T>
void Linkedlist<T>::display()
{
    Node<T>* temp;
    temp = head;
    while (temp != nullptr)
    {
        cout << endl<< "sku: " << temp->sku << "\nDescription: " << temp->data << "\nPrice: "<< temp->price << "\nUOM: " << temp->UOM<< "\nQOH: " << temp->QOH << endl;
        temp = temp->next;
    }
}

template <typename T>
Linkedlist<T>::~Linkedlist()
{
    Node<T>* temp;
    Node<T>* next;
    temp = head;

    while (temp != nullptr)
    {
        next = temp->next;
        delete temp;
        temp = next;
    }
}

#endif // ORDEREDLIST_H
