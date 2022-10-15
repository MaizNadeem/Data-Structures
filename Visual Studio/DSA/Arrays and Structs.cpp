#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

void structsAndArrays2D();
void matrixMult();
void studentsStruct();
void transpose();

void structsAndArrays2D() {
    int num;

    do {
        std::cout << "\nEnter the corresponding number: " << endl;
        std::cout << "\n\t1. Matrix Multiplication.\n\t2. Transpose of a matrix.\n\t3. Structure of Students.\n\t0: Main Menu." << endl << endl;

        std::cin >> num;

        system("CLS");

        switch (num) {
        case 1:
            matrixMult();
            break;
        case 2:
            transpose();
            break;
        case 3:
            studentsStruct();
            break;
        case 0:
            break;
        default:
            break;
        }

        if (!(num <= 11 && num >= 0))
            std::cout << "\nCorresponding number is incorrect." << endl;
    } while (num != 0);
}

void matrixMult() {
    int row1, column1, row2, column2;

    cout << "\nEnter the rows for first Matrix: ";
    cin >> row1;
    cout << "Enter the columns for first Matrix: ";
    cin >> column1;
    cout << "Enter the rows for second Matrix: ";
    cin >> row2;
    cout << "Enter the columns for second Matrix: ";
    cin >> column2;

    cout << endl << endl;

    if (column1 != row2) {
        cout << "These matrices cannot be multiplied" << endl << endl;
    }
    else {
        int** arr = new int* [row1];
        for (int i = 0; i < row1; i++) {
            arr[i] = new int[column2];
        }
        int** arr1 = new int* [row1];
        for (int i = 0; i < row1; i++) {
            arr1[i] = new int[column1];
        }
        int** arr2 = new int* [row2];
        for (int i = 0; i < row2; i++) {
            arr2[i] = new int[column2];
        }

        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column1; j++) {
                cout << "[" << i + 1 << "][" << j + 1 << "] = ";
                cin >> arr1[i][j];
            }
        }
        cout << endl;
        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < column2; j++) {
                cout << "[" << i + 1 << "][" << j + 1 << "] = ";
                cin >> arr2[i][j];
            }
        }
        cout << endl;
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column2; j++) {
                arr[i][j] = 0;
            }
        }

        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column2; j++) {
                for (int k = 0; k < column1; k++) {
                    arr[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }

        cout << endl << "Output Matrix: " << endl;
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column2; j++) {
                cout << "[" << i + 1 << "][" << j + 1 << "] = " << arr[i][j] << endl;
            }
        }

        cout << endl << endl;

        //Deleted Dynamic Arrays made previously.

        for (int i = 0; i < row1; i++) {
            delete[] arr1[i];
            delete[] arr[i];
            arr1[i] = NULL;
            arr[i] = NULL;
        }
        for (int i = 0; i < row2; i++) {
            delete[] arr2[i];
            arr2[i] = NULL;
        }
        delete[] arr;
        delete[] arr1;
        delete[] arr2;
        arr = NULL;
        arr1 = NULL;
        arr2 = NULL;
    }
}

void studentsStruct() {
    struct Student {
        string name;
        string subject;
        double cgpa;
    };

    Student s1, s2, s3;

    s1.name = "John";
    s1.subject = "DSA";
    s1.cgpa = 3.4;

    s2.name = "Mary";
    s2.subject = "LA";
    s2.cgpa = 2.7;

    s3.name = "Amir Liaqat";
    s3.subject = "OOP";
    s3.cgpa = 3.7;

    Student s[3] = { s1, s2, s3 };

    for (int i = 0; i < 3; i++) {
        if (s[i].subject == "DSA" && s[i].cgpa > 3.0) {
            cout << s[i].name << endl << endl;
        }
    }
}

void transpose() {

    int row, column;

    cout << "\nEnter the rows for Matrix: ";
    cin >> row;
    cout << "Enter the columns for Matrix: ";
    cin >> column;
    cout << endl;

    int** arr = new int* [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[column];
    }
    int** trans = new int* [row];
    for (int i = 0; i < row; i++) {
        trans[i] = new int[column];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> arr[i][j];
        }
    }
    cout << endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            trans[i][j] = arr[j][i];
        }
    }


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << "[" << i + 1 << "][" << j + 1 << "] = " << trans[i][j] << endl;
        }
    }
    cout << endl;

    //Deleting Dynamic Arrays made previously.

    for (int i = 0; i < row; i++) {
        delete[] arr[i];
        delete[] trans[i];
    }
    delete[] arr;
    delete[] trans;
    arr = NULL;
    trans = NULL;
}