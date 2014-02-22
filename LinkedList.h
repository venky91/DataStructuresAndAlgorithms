#ifndef _LinkedList
#define _LinkedList
#include <iostream>
#include <map>
#include <stack>

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
                        Node* dummy = head;
                        head = head->next;
                        delete dummy;
                        return head;
                    }

                    Node* n = head;
                    while (n->next != NULL) {
                        if (n->next->data == d) {
                            Node* dummy = n->next;
                            n->next = n->next->next;
                            delete dummy;
                            break;
                        }
                        n = n->next;
                    }

                    return head;

                }
                void removeDups() {

                    Node* n = this;

                    if (n == NULL) {
                        return;
                    }
                    std::map<int,bool> m;
                    m[n->data] = true;

                    while (n->next != NULL) {
                        if (m.find(n->next->data) != m.end()) { // duplicate entry
                            Node* dummy = n->next;                            
                            n->next = n->next->next;
                            delete dummy;
                        }
                        else {
                            m[n->next->data] = true;
                            n = n->next;
                        }
                    }

                }

                void removeDups2() {

                    Node* n = this;
                    
                    if (n == NULL) {
                        return;
                    }

                    Node* runner;

                    while (n != NULL) {
                        runner = n;
                        
                        while (runner->next != NULL) {
                            if (runner->next->data == n->data) {
                                Node* dummy = runner->next;
                                runner->next = runner->next->next;
                                delete dummy;
                            }
                            else {
                                runner = runner->next;
                            }
                        }

                        n = n->next;
                        
                    }
                }


        };

        Node* head = NULL;
        

    public:
        LinkedList();
        ~LinkedList();
        void append(int d);
        void printMe();
        void remove(int d);
        void removeDups(); // removes duplicates
        void removeDups2(); // no buffer used
        bool isPalindrome();

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

void LinkedList::removeDups() {

    head->removeDups();

}

void LinkedList::removeDups2() {

    head->removeDups2();
}

bool LinkedList::isPalindrome() {

    Node* current = head;
    Node* runner = head;

    std::stack<int> sq;

    while (runner != NULL && runner->next != NULL) {
        sq.push(current->data);
        current = current->next;
        runner = runner->next->next;
    }

    if (runner != NULL) { // Linked List has an odd number of elements
        current = current->next; // move current to be the middle element of the list
    }

    while (current != NULL) {
        if (current->data != sq.top()) {
            return false;
        }
        current = current->next;
    }

    return true;

}

#endif
