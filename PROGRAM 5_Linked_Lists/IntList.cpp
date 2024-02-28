#include "IntList.h"
#include <iostream>

using namespace std;

//Default Constructor
IntList::IntList()
    : head(nullptr), tail(nullptr)
{}

//Copy Constructor
IntList::IntList(const IntList &cpy)
:head(nullptr), tail(nullptr)
{
    if (cpy.head != nullptr || cpy.tail != nullptr) {
        IntNode* current = cpy.head;
        IntNode* newNode = new IntNode(current->value);
        head = newNode;
        current = current->next;
        while (current != nullptr) {
            newNode->next = new IntNode(current->value);
            newNode = newNode->next;
            current = current->next;
        }
        tail = newNode;
        newNode = nullptr;
        current = nullptr;
    }    
}

//Assignment Operator
IntList& IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        clear();
        if (rhs.head != nullptr || rhs.tail != nullptr) {
            IntNode* current = rhs.head;
            IntNode* newNode = new IntNode(current->value);
            head = newNode;
            current = current->next;
            while (current != nullptr) {
                newNode->next = new IntNode(current->value);
                newNode = newNode->next;
                current = current->next;
            }
            tail = newNode;
            newNode = nullptr;
            current = nullptr;
        }
    }
    return *this;

}


//Destructor
IntList::~IntList() {
    if (head != nullptr || tail != nullptr) {
        IntNode* current = head;
        while (current != nullptr) {

            IntNode* next = current->next;
            delete current;
            current = next;
            next = nullptr;

        }
        head = nullptr;
        tail = nullptr;
    }
}

//Accessor
const int & IntList::front() const 
{ 
    return head->value; 
}
const int & IntList::back() const 
{ 
    return tail->value; 
}

//Methods

bool IntList::empty() const {
    if (head == nullptr || tail == nullptr) 
        return true;
    else 
        return false;
}


void IntList::push_front(int value) {
    IntNode* newNode = new IntNode(value);
    if (head == nullptr || tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void IntList::push_back(int value) {
    IntNode* newNode = new IntNode(value);
    if (head == nullptr || tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void IntList::pop_front() {
    if (head == nullptr || tail == nullptr) {
        return;
    }
    else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        IntNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void IntList::clear() {

    if (head != nullptr || tail != nullptr) {
        IntNode* current = head;
        head = nullptr;
        tail = nullptr;
        while (current != nullptr) {

            IntNode* next = current->next;
            delete current;
            current = next;
            next = nullptr;

        }
        
    }
}

ostream& operator<<(ostream& out, const IntList& sLinkedList) {
    IntNode* current = sLinkedList.head;
    while (current != nullptr) {
        out << current->value;
        if (current->next != nullptr) {
            out << " ";
        }
        current = current->next;
    }
    return out;
}

void IntList::selection_sort() {
    for(IntNode* i = head; i != nullptr && i->next != nullptr; i = i->next) {
        IntNode* min = i;
        for(IntNode* j = i->next; j != nullptr; j = j->next) {
            if(j->value < min->value) {
                min = j;
            }
        }
        if(min != i) {
            swap(min->value, i->value);
        }
    }
}

void IntList::insert_ordered(int value) {
    if(head == nullptr || tail == nullptr) {
        push_front(value);
    }
    else if(head->value >= value) {
        push_front(value);
    }
    else if(tail->value <= value) {
        push_back(value);
    }
    else {
        IntNode* current = head;
        while(current->next != nullptr && current->next->value < value) {
            current = current->next;
        }
        IntNode* newNode = new IntNode(value);
        newNode->next = current->next;
        current->next = newNode;
    }
}

//review
void IntList::remove_duplicates() {
    for(IntNode* i = head; i != nullptr; i = i->next) {
        IntNode* current = i;
        while(current->next != nullptr) {
            if(current->next->value == i->value) {
                if (current->next == tail) {
                    tail = current;
                }
                IntNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else {
                current = current->next;
            }
        }
    }
}
