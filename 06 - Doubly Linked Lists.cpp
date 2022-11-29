#include <iostream>

using namespace std;

void doublylinkedListApps();
void doublylinkedListFunc();

int main() {

    doublylinkedListApps();

}

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

};


void doublylinkedListFunc() {

    CircularDoublyList* list = new CircularDoublyList();

    list->insertAtFront(2);
    list->insertAtFront(1);
    list->insertAtLast(4);
    list->insertAtLast(5);
    list->insertAtLast(6);
    list->deleteAtFront();
    list->deleteAtLast();
    list->insertAtData(3, 2);
    list->insertAtData(6, 5);
    list->deleteAtData(4);

    list->display();

    delete list;

}