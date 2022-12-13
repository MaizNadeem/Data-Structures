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

void maxHeap(int* arr, int k, int n) {
    int p, q;
    p = arr[k];
    q = 2 * k;
    while (q <= n) {
        if (q < n && arr[q + 1] > arr[q])
            q++;
        if (p > arr[p])
            break;
        else if (p <= arr[q]) {
            arr[q / 2] = arr[q];
            q = 2 * q;
        }
    }
    arr[q / 2] = p;
    return;
}

void buildMaxHeap(int* arr, int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        maxHeap(arr, k, n);
    }
}

void heapTree() {
    int n, i;
    cout << "Enter no. of elements of arrays: ";
        cin >> n;
    int arr[30];
    for (i = 1; i <= n; i++) {
        cout << "Enter element " << (i) << ": ";
        cin >> arr[i];
    }
    buildMaxHeap(arr, n);
    cout << "\nMax Heap:" << endl;
    for (i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}