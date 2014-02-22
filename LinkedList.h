#ifndef _LinkedList
#define _LinkedList
#include <iostream>

class LinkedList {

    private:
        class Node {

            public:
                int data;
                Node* next = NULL;
                Node(int d) {
                    data = d;
                }
                ~Node() {}
                void appendToTail(int d) {
            
                    Node* n = this; 
    
                    while (n->next != NULL) {
                        n = n->next;
                    }

                    Node* next = new Node(d);
                    n->next = next;
            
                }
                Node* remove(Node* head, int d) {
                    if (head == NULL) {
                        return NULL;
                    }

                    if (head->data == d) {
                        return head->next;
                    }

                    Node* n = head;
                    while (n->next != NULL) {
                        if (n->next->data == d) {
                            n->next = n->next->next;
                            break;
                        }
                        n = n->next;
                    }

                    return head;

                }

        };

        Node* head = NULL;
        

    public:
        LinkedList();
        ~LinkedList();
        void append(int d);
        void printMe();
        void remove(int d);

};

LinkedList::LinkedList() {

}

LinkedList::~LinkedList() {

    Node* next;

    while (head != NULL) {
        next = head->next;
        delete head;
        head = next;
    }

}

void LinkedList::append(int d) {

    if (head == NULL) {
        head = new Node(d);
        return;
    }

    head->appendToTail(d);

}

void LinkedList::printMe() {

    Node* n = head;

    while (n != NULL) {
        
        std::cout << n->data << " ";
        n = n->next;
    }

    std::cout << std::endl;
}

void LinkedList::remove(int d) {

    head = head->remove(head, d);
    
}

#endif
