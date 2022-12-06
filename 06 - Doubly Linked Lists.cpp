#include <iostream>

using namespace std;

void doublylinkedListApps();
void doublylinkedListFunc();

void doublylinkedListApps() {
    int num;

    do {
        cout << "\nEnter the corresponding number: " << endl;
        cout << "\n\t1: Doubly Linked List Implementation.\n\t0: Exit." << endl << endl;

        std::cin >> num;

        system("CLS");

        switch (num) {
        case 1:
            doublylinkedListFunc();
            break;
        default:
            break;
        }

        if (!(num <= 1 && num >= 0))
            cout << "\nCorresponding number is incorrect." << endl;
    } while (num != 0);
}

class Node {

public:

    int data;
    Node* prev;
    Node* next;

    Node() {}

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {
        delete prev;
        delete next;
    }

};

class CircularDoublyList {

public:

    Node* head = NULL;

    void insertAtFront(int data) {
        Node* p = new Node(data);
        if (head == NULL) {
            p->next = p->prev = p;
            head = p;
        }
        else {
            p->prev = head->prev;
            head->prev = p;
            p->next = head;
            head = p;
        }
    }

    void insertAtLast(int data) {
        Node* p = new Node(data);
        if (head == NULL) {
            p->next = p->prev = p;
            head = p;
        }
        else {
            p->prev = head->prev;
            head->prev->next = p;
            p->next = head;
            head->prev = p;
        }
    }

    void insertAtData(int data, int index) {
        Node* p = new Node(data);
        int flag = 0;
        Node* q = head;
        while (q->next != head) {
            if (q->data == index) {
                p->next = q->next;
                q->next->prev = p;
                p->prev = q;
                q->next = p;
                flag = 1;
                break;
            }
            q = q->next;
        }
        if (q->data == index && flag == 0) {
            insertAtLast(data);
        }
    }

    void deleteAtFront() {
        if (head == NULL)
            cout << "List is empty." << endl;
        else {
            head->next->prev = head->prev;
            head->prev->next = head->next;
            head = head->next;
        }
    }

    void deleteAtLast() {
        if (head == NULL)
            cout << "List is empty." << endl;
        else {
            head->prev->prev->next = head;
            head->prev = head->prev->prev;
        }
    }

    void deleteAtData(int index) {
        if (head == NULL)
            cout << "List is empty." << endl;
        else {
            int flag = 0;
            Node* q = head;
            while (q->next != head) {
                if (q->data == index) {
                    q->next->prev = q->prev;
                    q->prev->next = q->next;
                    if (q == head)
                        head = head->next;
                    flag = 1;
                    break;
                }
                q = q->next;
            }
            if (q->data == index && flag == 0) {
                deleteAtLast();
            }
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        }
        else {
            Node* p = head;
            while (p->next != head) {
                cout << p->data << " ";
                p = p->next;
            }
            cout << p->data << endl;
        }
    }

    static CircularDoublyList* mergeLists(CircularDoublyList* list1, CircularDoublyList* list2) {
        list1->head->prev->next = list2->head;
        list1->head->prev = list2->head->prev;
        list2->head->prev = list1->head->prev;
        list2->head->prev->next = list1->head;
        return list1;
    }

    void pairwiseSwap() {
        if (head == NULL || head->next == head)
            return;
        Node* p = head;
        while (p->next->next != head) {
            int temp = p->data;
            p->data = p->next->data;
            p->next->data = temp;
            p = p->next->next;
        }
        int temp = p->data;
        p->data = p->next->data;
        p->next->data = temp;
    }

    void deleteDuplicates() {
        Node* p = head;
        Node* q;
        while (p->next != head) {
            q = p->next;
            while (q->next != p) {
                if (q->data == p->data) {
                    if (q == head) {
                        head = q->next;
                    }
                    q->prev->next = q->next;
                    q->next->prev = q->prev;
                }
                q = q->next;
            }
            p = p->next;
        }
    }

};


void doublylinkedListFunc() {

    CircularDoublyList* list = new CircularDoublyList();
    CircularDoublyList* l = new CircularDoublyList();

    list->insertAtLast(1);
    list->insertAtLast(1);
    list->insertAtLast(2);
    list->insertAtLast(2);
    list->insertAtLast(3);
    list->insertAtLast(3);
    list->insertAtLast(4);
    list->insertAtLast(4);

    l->insertAtLast(5);
    l->insertAtLast(6);
    l->insertAtLast(7);
    l->insertAtLast(8);

    list->deleteDuplicates();

    list = CircularDoublyList::mergeLists(list, l);

    list->display();

    list->insertAtLast(9);
    list->pairwiseSwap();
    list->display();

    delete list;

}