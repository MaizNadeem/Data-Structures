#include <iostream>

using namespace std;

void linkedListApps();
void linkedListFunc();

int main() {

    linkedListApps();

}

void linkedListApps() {
    int num;

    do {
        cout << "\nEnter the corresponding number: " << endl;
        cout << "\n\t1: Linked List Implementation.\n\t0: Main Menu." << endl << endl;

        std::cin >> num;

        system("CLS");

        switch (num) {
        case 1:
            linkedListFunc();
            break;
        case 0:
            break;
        default:
            break;
        }

        if (!(num <= 3 && num >= 0))
            cout << "\nCorresponding number is incorrect." << endl;
    } while (num != 0);
}

template <class T> class Node {
public:
    T data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

template <class T> class LinkList {

public:
    Node <T>* head;

    LinkList() {
        head = NULL;
    }

    void insertAtBegin(T data) {
        Node <T>* n = new Node<T>(data);
        n->next = head;
        head = n;
    }

    void insertAtLast(T data) {
        Node <T>* n = new Node<T>(data);
        if (head == NULL) {
            head = n;
            return;
        }
        Node <T>* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }

    void deleteAtBegin() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node <T>* n = head;
        head = n->next;
        delete n;
    }

    void deleteAtLast() {
        Node <T>* n = head;
        Node <T>* temp = n;
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        else if (head->next == NULL) {
            head = NULL;
            delete n;
        }
        else {
            while (n->next != NULL) {
                temp = n;
                n = n->next;
            }
            temp->next = NULL;
            delete n;
        }
        
    }

    void displayList() {
        Node <T>* n = head;
        while (n != NULL) {
            cout << n->data << " ";
            n = n->next;
        }
    }

};



void linkedListFunc() {

    LinkList<int>* list = new LinkList<int>();
    
    list->insertAtBegin(5);
    list->insertAtBegin(6);
    list->insertAtBegin(7);
    list->insertAtBegin(8);
    list->deleteAtLast();
    list->deleteAtLast();
    list->displayList();

}