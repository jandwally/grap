
#include<iostream>
using namespace std;

template <class E> class List {

private:
    class ListNode {

        E item;
        ListNode* next;
        ListNode* prev;

        ListNode(E i) {
            next = NULL;
            prev = NULL;
            item = i;
        }

        void setNext(ListNode* newNext) {
            next = newNext;
        }

        void setPrev(ListNode* newPrev) {
            prev = newPrev;
        }

    };

    int length;
    ListNode* head;     // pointer to the first node in the deque
    ListNode* tail;     // pointer to the last node in the deque

public:
    List() {
        length = 0;
        head = NULL;
        tail = NULL;
    }

    void test() {
        cout << "hi\n";
    }

    // size
    int size() {
        return this.length;
    }

    // add
    void add(E elt) {
        ListNode* node = new ListNode(elt);
        node.next = head;
        head = node;
        this.length++;
    }

    // remove
    E remove() {
        ListNode* node = head;
    }

};

/*template <class E>
void printList(const List& list) {
    cout << "[ ";

    while (true) {
        E elt = list.get();
    }

    cout << "]" << endl;
}*/




// insert
// peek
// get