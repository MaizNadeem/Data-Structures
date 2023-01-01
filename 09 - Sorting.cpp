#include <iostream>

using namespace std;

void sortingAlgorithms();
void mergeSort();

int main() {
    sortingAlgorithms();
}

void sortingAlgorithms() {
    int num;
    do {
        cout << "\nEnter the corresponding number: " << endl;
        cout << "\n\t1: Merge Sort.\n\t0: Exit." << endl << endl;
        std::cin >> num;
        system("CLS");
        switch (num) {
        case 1:
            mergeSort();
            break;
        default:
            break;
        }
        if (!(num <= 1 && num >= 0))
            cout << "\nCorresponding number is incorrect." << endl;
    } while (num != 0);
}

#define size 5
int arr[size];

void Merge(int low, int mid, int high) {
    int t[50];
    int i = low, j = mid+1, k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            t[k++] = arr[i++];
        else
            t[k++] = arr[j++];
    }

    while (i <= mid)
        t[k++] = arr[i++];

    while (j <= high)
        t[k++] = arr[j++];

    for (i = low, j = 0; i <= high; i++, j++)
        arr[i] = t[j];
}

void Sort(int low, int high) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2;
        Sort(low, mid);
        Sort(mid + 1, high);
        Merge(low, mid, high);
    }
}

void mergeSort() {
    int i;
    cout << "\nEnter " << size << " elements for Sorting : " << endl;
    for (i = 0; i < size; i++)
        cin >> arr[i];

    cout << "\nEntered Data:\t";
    for (i = 0; i < size; i++) {
        cout << " " << arr[i];
    }

    Sort(0, size - 1);

    cout << "\nSorted Data:\t";
    for (i = 0; i < size; i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}