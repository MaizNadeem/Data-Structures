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

    static void mergeLinkedLists(LinkedList<T>*list1, LinkedList<T>*list2) {
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

};



void linkedListFunc() {

    LinkedList<int>* list1 = new LinkedList<int>();
    LinkedList<int>* list2 = new LinkedList<int>();

    list1->insertAtLast(1);                     
    list1->insertAtBegin(2);
    list1->insertAtIndex(3, 2);
    list1->insertAtLast(4);                                 // 2 3 1 4

    list2->insertAtLast(5);
    list2->insertAtLast(6);
    list2->insertAtLast(7);
    list2->insertAtLast(8);                                 // 5 6 7 8

    list1->sortLinkedList();                                // 1 2 3 4
    LinkedList<int>::mergeLinkedLists(list1, list2);        // 1 2 3 4 5 6 7 8
    list1->reverseLinkedList();                             // 8 7 6 5 4 3 2 1


    list1->displayList();

    delete list1, list2;
}