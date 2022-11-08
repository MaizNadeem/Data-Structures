#include <iostream>

using namespace std;

void linkedListApps();
void linkedListFunc();
void separatePrimeNumbers();
void circularLinkedList();

int main() {

    linkedListApps();

}

void linkedListApps() {
    int num;

    do {
        cout << "\nEnter the corresponding number: " << endl;
        cout << "\n\t1: Linked List Implementation.\n\t2: Separate Prime Numbers from a list.\n\t3: Circular Linked List.\n\t0: Main Menu." << endl << endl;

        std::cin >> num;

        system("CLS");

        switch (num) {
        case 1:
            linkedListFunc();
            break;
        case 2:
            separatePrimeNumbers();
            break;
        case 3:
            circularLinkedList();
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

template <class T> class LinkedList {

public:
    Node <T>* head;

    LinkedList() {
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
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        else if (head->next == NULL) {
            head = NULL;
        }
        else {
            Node <T>* n = head;
            Node <T>* temp = n;
            while (n->next != NULL) {
                temp = n;
                n = n->next;
            }
            temp->next = NULL;
        }
    }

    void displayList() {
        Node <T>* n = head;
        while (n != NULL) {
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
    }

    void insertAtIndex(T data, int index) {
        Node <T>* temp1 = head;
        Node <T>* temp2 = head;
        Node <T>* n = new Node<T>(data);
        if (index == 1) {
            n->next = head;
            head = n;
        }
        else {
            for (int i = 1; i < index; i++) {
                if (temp2 == NULL)
                    break;
                temp1 = temp2;
                temp2 = temp2->next;
            }
        }
        temp1->next = n;
        n->next = temp2;
    }

    void deleteAtIndex(int index) {
        Node <T>* n = head;
        if (index == 1) {
            n = n->next;
            head = n;
        }
        else {
            Node <T>* temp1;
            Node <T>* temp2 = head;
            for (int i = 1; i < index; i++) {
                if (temp2 == NULL)
                    break;
                temp1 = temp2;
                temp2 = temp2->next;
                temp1->next = temp2->next;
                delete temp2;
            }
        }
    }

    bool searchNode(int key) {
        Node <T>* n = head;
        while (n != NULL) {
            if (n->data == key)
                return true;
            n = n->next;
        }
        return false;
    }

    void sortLinkedList() {
        if (head == NULL)
            return;
        else {
            Node <T>* temp1 = head;
            Node <T>* temp2;
            T temp;
            while (temp1 != NULL) {
                temp2 = temp1->next;
                while (temp2 != NULL) {
                    if (temp1->data > temp2->data) {
                        temp = temp1->data;
                        temp1->data = temp2->data;
                        temp2->data = temp;
                    }
                    temp2 = temp2->next;
                }
                temp1 = temp1->next;
            }
        }
    }

    static void mergeLinkedLists(LinkedList<T>* list1, LinkedList<T>* list2) {
        Node <T>* n = list1->head;
        while (n->next != NULL)
            n = n->next;
        n->next = list2->head;
    }

    void reverseLinkedList() {
        Node <T>* previous = NULL;
        Node <T>* current = head;
        Node <T>* next;
        while (current != NULL) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    static Node<T>* reverseLinkedList(Node<T>* head) {
        if (head == NULL || head->next == NULL)
            return head;

        Node<T>* rest = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }

};



void linkedListFunc() {

    LinkedList<int>* list1 = new LinkedList<int>();
    LinkedList<int>* list2 = new LinkedList<int>();

    list1->insertAtLast(1);
    list1->insertAtBegin(2);
    list1->insertAtIndex(3, 2);
    list1->insertAtLast(4);                                               // 2 3 1 4

    list2->insertAtLast(5);
    list2->insertAtLast(6);
    list2->insertAtLast(7);
    list2->insertAtLast(8);                                               // 5 6 7 8

    list1->sortLinkedList();                                              // 1 2 3 4
    LinkedList<int>::mergeLinkedLists(list1, list2);                      // 1 2 3 4 5 6 7 8
    list1->reverseLinkedList();                                           // 8 7 6 5 4 3 2 1
    list1->head = LinkedList<int>::reverseLinkedList(list1->head);        // 1 2 3 4 5 6 7 8

    list1->displayList();

    delete list1, list2;
}


bool checkPrime(int n) {

    if (n == 1 || n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    else {
        for (int i = 3; i < n / 2; i = i + 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

}


void separatePrimeNumbers() {

    LinkedList<int>* list = new LinkedList<int>();
    LinkedList<int>* prime = new LinkedList<int>();

    for (int i = 1; i <= 100; i++)
        list->insertAtLast(i);

    while (checkPrime(list->head->data)) {
        prime->insertAtLast(list->head->data);
        list->deleteAtBegin();
    }

    Node<int>* p = NULL;
    Node<int>* n = list->head;
    p = n;
    n = n->next;

    while (n->next->next != NULL) {

        if (checkPrime(n->data)) {
            prime->insertAtLast(n->data);
            Node<int>* q = n;
            p->next = n->next;
            p = n->next;
            n = n->next->next;
            delete q;
        }
        else {
            p = n;
            n = n->next;
        }
    }

    if (checkPrime(n->data)) {
        prime->insertAtBegin(n->data);
        list->deleteAtLast();
    }

    list->displayList();
    cout << endl;
    prime->displayList();

}


template <class T> class CircularLinkedList {

public:
    Node <T>* head;

    CircularLinkedList() {
        head = NULL;
    }

    void insertAtBegin(T data) {
        Node <T>* n = new Node<T>(data);
        Node <T>* temp = head;
        while (temp->next != head)
            temp = temp->next;
        n->next = head;
        head = n;
        temp->next = head;
    }

    void insertAtLast(T data) {
        Node <T>* n = new Node<T>(data);
        if (head == NULL) {
            head = n;
            n->next = head;
            return;
        }
        Node <T>* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    void deleteAtBegin() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node <T>* temp = head;
        while (temp->next != head)
            temp = temp->next;
        Node <T>* n = head;
        head = n->next;
        temp->next = head;
        delete n;
    }

    void deleteAtLast() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        else if (head->next == head) {
            head = NULL;
        }
        else {
            Node <T>* n = head;
            Node <T>* temp = n;
            while (n->next != head) {
                temp = n;
                n = n->next;
            }
            temp->next = head;
            delete n;
        }
    }

    void displayList() {
        Node <T>* n = head;
        while (n->next != head) {
            cout << n->data << " ";
            n = n->next;
        }
        cout << n->data << " " << endl;
    }

    bool searchNode(int key) {
        Node <T>* n = head;
        while (n->next != head) {
            if (n->data == key)
                return true;
            n = n->next;
        }
        if (n->data == key)
            return true;
        return false;
    }

    static void mergeLinkedLists(CircularLinkedList<T>* list1, CircularLinkedList<T>* list2) {
        Node <T>* n = list1->head;
        Node <T>* p = list2->head;
        while (n->next != list1->head)
            n = n->next;
        n->next = list2->head;
        while (p->next != list2->head)
            p = p->next;
        p->next = list1->head;
    }

};


void circularLinkedList() {

    CircularLinkedList <int>* c1 = new CircularLinkedList<int>();
    CircularLinkedList <int>* c2 = new CircularLinkedList<int>();

    c1->insertAtLast(5);
    c1->insertAtLast(6);
    c1->insertAtBegin(4);
    c1->insertAtLast(7);
    c1->insertAtLast(8);
    c1->insertAtLast(9);
    c1->insertAtLast(10);
    c1->deleteAtBegin();
    c1->deleteAtLast();

    c2->insertAtLast(5);
    c2->insertAtLast(6);
    c2->insertAtBegin(4);
    c2->insertAtLast(7);
    c2->insertAtLast(8);
    c2->insertAtLast(9);
    c2->insertAtLast(10);
    c2->deleteAtBegin();
    c2->deleteAtLast();


    CircularLinkedList<int>::mergeLinkedLists(c1, c2);

    c1->displayList();

}