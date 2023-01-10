#include <iostream>

using namespace std;

void algorithms();
void mergeSort();
void selectSort();
void quickSort();
void insertionSort();

int main() {
    algorithms();
}

void algorithms() {
    int num;
    do {
        cout << "\n1: Merge Sort.\n2: Select Sort.\n3: Quick Sort.\n4: Insertion Sort.\n0: Exit." << endl << endl;
        cout << "Enter the corresponding number: ";
        std::cin >> num;
        system("CLS");
        switch (num) {
        case 1:
            mergeSort();
            break;
        case 2:
            selectSort();
            break;
        case 3:
            quickSort();
            break;
        case 4:
            insertionSort();
            break;
        default:
            break;
        }
        if (!(num <= 4 && num >= 0))
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

void selectSort() {
    int arr[] = {5, 4, 3, 2, 1};

    int s = 5;
    int minj = 0;
    int minx = s;

    for(int i=0; i<size - 1; i++) {
        minj = i;
        minx = arr[i];
        for (int j = i+1 ;j < size; j++) {
            if (arr[j] < minx) {
                minj = j;
                minx = arr[j];
            }
        }
        arr[minj] = arr[i];
        arr[i] = minx;
    }

    for (int i = 0; i < s; i++) {
        cout << arr[i] << " ";
    }
}

void quick(int arr[], int down, int up) {

    if (down >= up) {
        for (int i=0; i<9; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    int a = down;
    int first = down;
    int last = up;

    while (arr[first] <= arr[a] && first < up) {
        first++;
    }
    while (arr[last] > arr[a] && last > down) {
        last--;
    }
    if (last > first) {
        int temp = arr[first];
        arr[first] = arr[last];
        arr[last] = temp;
    }

    int temp = arr[a];
    arr[a] = arr[last];
    arr[last] = temp;

    if (a == last)
        a = first;
    else if (a == first)
        a = last;

    quick(arr, down, a-1);
    quick(arr, a, up);
}

void quickSort() {
    int arr[] = {0, 1, 8, 2, 3, 5, 6, 7, 9};
    int s = 9;

    cout << "Initial Array:" << endl;
    for (int i=0; i<s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Processed:" << endl;
    quick(arr, 0, s-1);

    cout << "Sorted Array:" << endl;
    for (int i=0; i<s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort() {
    int arr[] = {0, 1, 8, 2, 3, 5, 6, 7, 9};
    int s = 9;

    cout << "Initial Array:" << endl;
    for (int i=0; i<s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int count = 1; count < size; count++) {
        int temp, j;
        temp = arr[count];
        j = count-1;
        while ((j >= 0) && (temp < arr[j])) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    cout << "Sorted Array:" << endl;
    for (int i=0; i<s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}