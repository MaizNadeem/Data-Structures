#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

void queueApplications();
void trafficLights();
void dequeFunc();
void stackQueue();

int main() {

    queueApplications();
    return 0;

}

void queueApplications() {
    int num;

    do {
        std::cout << "\nEnter the corresponding number: " << endl;
        std::cout << "\n\t1: Traffic Lights.\n\t2: Deque (Double Ended Queue).\n\t3: Stack Implementation with 2 queues.\n\t0: Main Menu." << endl << endl;

        std::cin >> num;

        system("CLS");

        switch (num) {
        case 1:
            trafficLights();
            break;
        case 2:
            dequeFunc();
            break;
        case 3:
            stackQueue();
            break;
        case 0:
            break;
        default:
            break;
        }

        if (!(num <= 3 && num >= 0))
            std::cout << "\nCorresponding number is incorrect." << endl;
    } while (num != 0);
}

template <class T> class GenericQueue {

public:
    int front = -1;
    int rear = -1;
    int size = 4;
    T array[10] = {};

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
        if (front == -1) {
            cout << "Queue is Empty." << endl;
        }
        else {
            int i;
            for (i = front; i != rear; i = (i + 1) % size)
                cout << array[i] << " ";
            cout << array[i] << endl;
        }
    }

    bool empty() {
        if (front != -1) {
            return false;
        }
        else {
            return true;
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
    cout << "\tAt 0->\t";
    for (int i = 0; i < 4; i++) {
        cout << q.array[i] << " ";
    }
    cout << endl;

    q.enqueue(1);

    cout << endl;
    cout << "\tAt 1->\t";
    for (int i = 0; i < 4; i++) {
        cout << q.array[i] << " ";
    }
    cout << endl;

    for (int i = 1; i <= 7; i++) {

        q.enqueue(1);
        q.dequeue();

        cout << endl;
        cout << "\tAt " << i + 1 << "->\t";
        for (int j = 0; j < 4; j++) {
            cout << q.array[j] << " ";
        }
        cout << endl;
    }
}

void stackQueue() {

    class StackQueue {

    public:
        GenericQueue <int> q1;
        GenericQueue <int> q2;
        GenericQueue <int> q;

        void push(int value) {
            q2.enqueue(value);

            while (!q1.empty()) {
                q2.enqueue(q1.dequeue());
            }

            q = q1;
            q1 = q2;
            q2 = q;
        }

        int pop() {
            return q1.dequeue();
        }
    };

    StackQueue s;
    s.push(5);
    s.push(6);
    s.push(7);
    cout << s.pop() << " ";
    cout << s.pop() << " ";
    cout << s.pop() << " ";
    s.push(5);
}

template <class T> class Deque {

public:
    int front = -1;
    int rear = -1;
    int size = 50;
    T* array = new T[size];

public:

    Deque(int size) {
        this->size = size;
        for (int i = 0; i < size; i++)
            array[i] = 9999;
    }

    ~Deque() {
        delete[] array;
    }

    void insertRear(T value) {
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

    void insertFront(T value) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            cout << "Queue Overflow" << endl;
        }
        else if (front == -1) {
            front = 0;
            rear = 0;
            array[front] = value;
        }
        else {
            if (front == 0) {
                front = size - 1;
            }
            else {
                front--;
            }
            array[front] = value;
        }
    }

    T deleteFront() {
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

    T deleteRear() {
        T value = 0;
        if (front == -1) {
            cout << "Queue Underflow" << endl;
        }
        else if (front == rear) {
            value = array[rear];
            array[rear] = 0;
            front = -1;
            rear = -1;
        }
        else if (rear == 0) {
            value = array[rear];
            array[rear] = 0;
            rear = size - 1;
        }
        else {
            value = array[rear];
            array[rear] = 0;
            rear--;
        }
        return value;
    }

    void display() {
        if (front == -1) {
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

void dequeFunc() {

    Deque <int> q(5);
    q.insertFront(3);
    q.insertRear(4);
    q.insertFront(2);
    q.insertFront(1);
    q.insertRear(5);
    q.deleteFront();
    q.deleteRear();

    q.display();

}