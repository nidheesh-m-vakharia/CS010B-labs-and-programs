#include "IntList.h"

using namespace std;

//Default Constructor
IntList::IntList()
    : head(nullptr), tail(nullptr)
{}


//Destructor
IntList::~IntList() {
    if (head != nullptr || tail != nullptr) {
        IntNode* current = head;
        while (current != tail) {

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
const int & IntList::front() const { 
        return head->value;
}

const int & IntList::back() const { return tail->value;}

//Methods

bool IntList::empty() const {
    if (head == nullptr || tail == nullptr) 
        return true;
    else 
        return false;
}

void IntList::push_front(int value) {
    IntNode* newNode = new IntNode(value);
    newNode->next = head;
    head = newNode;

    if (tail == nullptr)
        tail = newNode;
}

void IntList::pop_front() {
    if (head == nullptr || tail == nullptr)
        return;
    IntNode* frontItem = head;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    }
    else {
    head = frontItem->next;

    }
    delete frontItem;
}

void IntList::clear() {

    if (head != nullptr || tail != nullptr) {
        IntNode* current = head;
        while (current != tail) {

            IntNode* next = current->next;
            delete current;
            current = next;
            next = nullptr;

        }
        head = nullptr;
        tail = nullptr;
    }
}

ostream& operator<<(ostream& out, const IntList& sLinkedList) {

    if (sLinkedList.head != nullptr || sLinkedList.tail != nullptr) {
        IntNode* current = sLinkedList.head;

        do  {
            out << current->value;
            if (current != sLinkedList.tail) {
                out << " ";
            }
            current = current->next;
        } while (current != nullptr);
    }
    
    return out;
}