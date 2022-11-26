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
    Node* next;
    Node* prev;

    Node() {}

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {
        delete next;
        delete prev;
    }

};

class CircularDoublyList {

    Node* head = new Node();

};


void doublylinkedListFunc() {



}