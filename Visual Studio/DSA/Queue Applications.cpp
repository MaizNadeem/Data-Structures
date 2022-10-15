#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

void queueApplications();
void trafficLights();

int main() {

    queueApplications();
    return 0;

}

void queueApplications() {
    int num;

    do {
        std::cout << "\nEnter the corresponding number: " << endl;
        std::cout << "\n\t1: Traffic Lights.\n\t0: Main Menu." << endl << endl;

        std::cin >> num;

        system("CLS");

        switch (num) {
        case 1:
            trafficLights();
            break;
        case 0:
            break;
        default:
            break;
        }

        if (!(num <= 1 && num >= 0))
            std::cout << "\nCorresponding number is incorrect." << endl;
    } while (num != 0);
}

template <class T> class GenericQueue {

public:
    int front = -1;
    int rear = -1;
    int size = 4;
    T array[4];

public:
    void enqueue(T value) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            cout << "Queue Overflow" << endl;
        }
        else if (front == -1) {
            front = 0;
            rear = 0;
            array[rear] = value;
        }
        else {
            if (rear == size - 1) {
                rear = 0;
            }
            else {
                rear++;
            }
            array[rear] = value;
        }
    }

    T dequeue() {
        T value = 0;
        if (front == -1) {
            cout << "Queue Underflow" << endl;
        }
        else if (front == rear) {
            value = array[front];
            array[front] = 0;
            front = -1;
            rear = -1;
        }
        else {
            value = array[front];
            array[front] = 0;
            front = (front + 1) % size;
        }
        return value;
    }

    void display() {
        int f = front;
        int r = rear;
        if (f == -1) {
            cout << "Queue is Empty." << endl;
        }
        else {
            int i;
            for (i = front; i != rear; i = (i + 1) % size)
                cout << array[i] << " ";
            cout << array[i] << endl;
        }
    }
};

void trafficLights() {
    GenericQueue <int> q;

    for (int i = 0; i < q.size; i++) {
        q.enqueue(0);
    }
    for (int i = 0; i < q.size; i++) {
        q.dequeue();
    }

    cout << endl;
    cout << "At 0:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << q.array[i] << " ";
    }
    cout << endl;

    q.enqueue(1);

    cout << endl;
    cout << "At 1:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << q.array[i] << " ";
    }
    cout << endl;

    for (int i = 1; i <= 7; i++) {

        q.enqueue(1);
        q.dequeue();

        cout << endl;
        cout << "At " << i + 1 << ":" << endl;
        for (int j = 0; j < 4; j++) {
            cout << q.array[j] << " ";
        }
        cout << endl;
    }
}

