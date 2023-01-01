#include <iostream>

using namespace std;

void heapTreeApps();
void heapTree();

int main() {
    heapTreeApps();
}

void heapTreeApps() {
    int num;
    do {
        cout << "\nEnter the corresponding number: " << endl;
        cout << "\n\t1: Heap Tree Implementation.\n\t0: Exit." << endl << endl;
        std::cin >> num;
        system("CLS");
        switch (num) {
        case 1:
            heapTree();
            break;
        default:
            break;
        }
        if (!(num <= 1 && num >= 0))
            cout << "\nCorresponding number is incorrect." << endl;
    } while (num != 0);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MaxHeap {

public:
    int* arr;
    int size;
    int capacity;

    MaxHeap(int capacity);

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int getMax() { return arr[0]; }

    void insertKey(int value);
    int deleteMax();
    void displayHeap();

    void MaxHeapify(int);
    void heapSort();
    
};

MaxHeap::MaxHeap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->arr = new int[capacity];
}

void MaxHeap::insertKey(int value) {
    if (size == capacity) {
        cout << "\nOverflow: Could not insert in heap.\n";
        return;
    }
    size++;
    int i = size - 1;
    arr[i] = value;
    while (i != 0 && arr[parent(i)] < arr[i]) {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

int MaxHeap::deleteMax() {
    if (size <= 0) {
        cout << "\nUnderflow: Could not delete from heap.\n";
        return INT_MAX;
    }
    else if (size == 1) {
        size--;
        return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[size - 1];
    size--;
    MaxHeapify(0);
    return root;
}

void MaxHeap::MaxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < size && arr[l] > arr[i])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        MaxHeapify(largest);
    }
}

void MaxHeap::displayHeap() {
    cout << "Max Heap:\t";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class T> class Stack {
    int top = -1;
    T array[20];

public:
    void push(T num) {
        if (top == (sizeof(array) / sizeof(array[0])) - 1) {
            cout << "Sorry, stack is full." << endl;
        }
        else {
            top++;
            array[top] = num;
        }
    }
    T pop() {
        if (top == -1) {
        }
        else {
            T popped = array[top];
            array[top] = 0;
            top--;
            return popped;
        }
    }
    void display() {
        cout << "Stack:\t";
        for (int i = 0; i <= top; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

};

void MaxHeap::heapSort() {
    Stack<int> s;
    int currentSize = size;
    for (int i = 0; i < currentSize; i++) {
        s.push(deleteMax());
    }
    size = currentSize;
    for (int i = 0; i < currentSize; i++) {
        arr[i] = s.pop();
    }
}

void heapTree() {
    MaxHeap* heap = new MaxHeap(10);
    heap->insertKey(1);
    heap->insertKey(2);
    heap->insertKey(3);
    heap->insertKey(4);
    heap->insertKey(5);
    heap->insertKey(6);
    heap->insertKey(7);
    heap->insertKey(8);
    heap->insertKey(9);
    heap->displayHeap();
    heap->heapSort();
    heap->displayHeap();
}

