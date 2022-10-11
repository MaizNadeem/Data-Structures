#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

void basicTasks();
void structsAndArrays2D();
void stackApplications();
void queueApplications();

void factorial();
void fibonacci();
void gcd();
void numOfDigits();
void reverseOfNum();
void lcm();
void primeNumbers();
void sqrt();
void profitLoss();
void sumOfSquares();
void sumOfFactorials();
void matrixMult();
void transpose();
void studentsStruct();
void deciToBinary();
void balancedExp();
void infixtoPostfix();
void infixtoPrefix();
void evaluatePostfix();
void towerOfHanoi();
void trafficLights();


int main() {

    int num;

    do {
        cout << "\nSelect a category:" << endl;
        cout << "\n\t1: Basic Tasks.\n\t2: Structs and 2D Arrays.\n\t3: Stack Applications.\n\t4: Queue Applications.\n\t0: Exit." << endl << endl;

        cin >> num;

        system("CLS");

        switch (num) {
        case 1:
            basicTasks();
            break;
        case 2:
            structsAndArrays2D();
            break;
        case 3:
            stackApplications();
            break;
        case 4:
            queueApplications();
            break;
        case 0:
            break;
        default:
            break;
        }
        if (!(num >= 0 && num <= 4))
            cout << "\nCorresponding number is incorrect.";

    } while (num != 0);

    return 0;
}

void basicTasks() {
    int num;

    do {
        std::cout << "\nEnter the corresponding number: " << endl;
        std::cout << "\n\t01: Factorial of an integer.\n\t02: Print Fibonacci Series till a range.\n\t03: Greatest Common Divisor of two integers.\n\t04: Number of Digits in an integer.\n\t05: Reverse of an integer.\n\t06: Least Common Multiple of two numbers.\n\t07: Print Prime numbers between 1-100.\n\t08: Square root of an integer.\n\t09: Profit-Loss calculator.\n\t10: Sum of squares of natural number.\n\t11: Sum of inverse of Factorials.\n\t00: Main Menu." << endl << endl;

        std::cin >> num;

        system("CLS");

        switch (num) {
        case 1:
            factorial();
            break;
        case 2:
            fibonacci();
            break;
        case 3:
            gcd();
            break;
        case 4:
            numOfDigits();
            break;
        case 5:
            reverseOfNum();
            break;
        case 6:
            lcm();
            break;
        case 7:
            primeNumbers();
            break;
        case 8:
            sqrt();
            break;
        case 9:
            profitLoss();
            break;
        case 10:
            sumOfSquares();
            break;
        case 11:
            sumOfFactorials();
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

void stackApplications() {
    int num;

    do {
        std::cout << "\nEnter the corresponding number: " << endl;
        std::cout << "\n\t1: Decimal to Binary Converter.\n\t2: Check balanced paranthesis of an expression.\n\t3: Infix to Postfix.\n\t4: Infix to Prefix.\n\t5: Evaluate Postfix.\n\t6: Tower of Hanoi.\n\t0: Main Menu." << endl << endl;

        std::cin >> num;

        system("CLS");

        switch (num) {
        case 1:
            deciToBinary();
            break;
        case 2:
            balancedExp();
            break;
        case 3:
            infixtoPostfix();
            break;
        case 4:
            infixtoPrefix();
            break;
        case 5:
            evaluatePostfix();
            break;
        case 6:
            towerOfHanoi();
            break;
        case 0:
            break;
        default:
            break;
        }

        if (!(num <= 6 && num >= 0))
            std::cout << "\nCorresponding number is incorrect." << endl;
    } while (num != 0);
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



void factorial() {
    int num;
    int fact = 1;
    cout << "\nEnter an integer: ";
    cin >> num;
    if (num < 0)
        cout << "Factorial of a negative number doesn't exist.\n" << endl;
    else {
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }
        cout << "Factorial of " << num << " = " << fact << endl << endl;
    }
}

void fibonacci() {

    int term;
    int num1 = 0;
    int num2 = 1;
    int next;

    cout << "\nEnter the number of terms: ";
    cin >> term;

    for (int i = 0; i < term; i++) {
        cout << num1 << " ";
        next = num1 + num2;
        num1 = num2;
        num2 = next;
    }
    cout << "\n" << endl;
}

void gcd() {
    int num1;
    int num2;
    int gcd;

    cout << "\nEnter the first integer: ";
    cin >> num1;
    cout << "Enter the second integer: ";
    cin >> num2;

    for (int i = 1; i <= num1 && i <= num2; i++) {
        if (num1 % i == 0 && num2 % i == 0)
            gcd = i;
    }
    cout << "G.C.D of " << num1 << " and " << num2 << " is: " << gcd << endl << endl;
}

void numOfDigits() {
    int num;
    int count;
    cout << "\nEnter the number: ";
    cin >> num;
    count = log10(num) + 1;
    cout << "Number of digits: " << count << endl << endl;
}

void reverseOfNum() {
    int num = 0;
    int reverse = 0;
    cout << "\nEnter a number for ts reverse: ";
    cin >> num;

    while (num != 0) {
        reverse *= 10;
        reverse += num % 10;
        num /= 10;
    }

    cout << "Reverse of the number = " << reverse << endl << endl;
}

void lcm() {
    int num1;
    int num2;
    int gcd;

    cout << "\nEnter the first integer: ";
    cin >> num1;
    cout << "Enter the second integer: ";
    cin >> num2;

    for (int i = 1; i <= num1 && i <= num2; i++) {
        if (num1 % i == 0 && num2 % i == 0)
            gcd = i;
    }
    int lcm = (num1 * num2) / gcd;
    cout << "L.C.M of " << num1 << " and " << num2 << " is: " << lcm << endl << endl;
}

void primeNumbers() {
    int i;
    int count;
    int a = 1;

    while (a <= 100) {
        i = 2;
        count = 0;

        while (i <= a / 2) {
            if (a % i == 0) {
                count++;
                break;
            }
            i++;
        }
        if (count == 0 && a != 1) {
            cout << a << " ";
        }
        a++;
    }
    cout << endl << endl;
}

void sqrt() {
    int num;
    float root = 1;
    int count = 0;
    cout << "\nEnter a number: ";
    cin >> num;
    while (1) {
        count++;
        root = (num / root + root) / 2;
        if (count > num) {
            break;
        }
    }
    printf("%.2f\n\n", root);
}

void profitLoss() {
    int amt;
    int total;

    cout << "\nEnter the total amount: ";
    cin >> total;
    cout << "Enter the earnings: ";
    cin >> amt;

    if ((amt - total) < 0) {
        double loss = -1 * (amt - total);
        double lossPercent = (loss / total) * 100;
        printf("Total loss is: %.0f", loss);
        printf("\nTotal loss percentage is: %.2f\n\n", lossPercent);
    }
    else if ((amt - total) >= 0) {
        double profit = amt - total;
        double profitPercent = (profit / total) * 100;
        printf("Total profit is: %.0f", profit);
        printf("\nTotal profit percentage is: %.2f\n\n", profitPercent);
    }
}

void sumOfSquares() {
    int num;
    int count = 1;
    int sum = 0;
    cout << "Enter the number: ";
    cin >> num;
    while (count <= num) {
        sum += count * count;
        count++;
    }
    cout << "Sum of Squares is: " << sum << endl << endl;
}

void sumOfFactorials() {
    float num;
    float count = 1;
    float sum = 0;
    cout << "\nEnter the number: ";
    cin >> num;
    while (count <= num) {
        float fact = 1;
        for (int i = 1; i <= count; i++) {
            fact *= i;
        }
        sum += 1 / fact;
        count++;
    }
    cout << "Sum of all Factorials is: " << sum << endl << endl;
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

template <class T> class GenericStack {
    int top = -1;
    T array[50];

public:

    int prec(char c) {
        if (c == '^') {
            return 3;
        }
        else if (c == '/' || c == '*') {
            return 2;
        }
        else if (c == '+' || c == '-') {
            return 1;
        }
        else {
            return -1;
        }
    }

    void push(T num) {
        if (top == (sizeof(array) / sizeof(array[0])) - 1) {
            cout << "Stack is full." << endl;
        }
        else {
            top++;
            array[top] = num;
        }
    }

    T pop() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        }
        else {
            T popped = array[top];
            array[top] = 0;
            top--;
            return popped;
        }
    }

    bool empty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    char first() {
        return array[top];
    }

    void display(int n) {
        cout << "Rod " << n << "-> " << "\t";
        for (int i = 0; i <= top; i++) {
            cout << array[i] << "  ";
        }
        cout << endl;
    }

};

void deciToBinary() {

    int num;
    GenericStack<int> s;
    cout << "\nEnter a decimal number: ";
    cin >> num;
    cout << "The Binary representation is: ";

    while (num >= 1) {
        s.push(num % 2);
        num /= 2;
    }
    while (!s.empty()) {
        cout << s.pop();
    }
    cout << endl << endl;
}

void balancedExp() {

    GenericStack<char> s;
    string str;
    cout << "\nEnter the expression: ";
    cin.ignore();
    std::getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(' || str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (s.empty()) {
                s.push(str[i]);
            }
            else if ((s.first() == '(' && str[i] == ')') || (s.first() == '{' && str[i] == '}') || (s.first() == '[' && str[i] == ']')) {
                s.pop();
            }
            else {
                s.push(str[i]);
            }
        }
    }

    if (s.empty()) {
        cout << "The Expression is Balanced." << endl << endl;
    }
    else {
        cout << "The Expression is not Balanced." << endl << endl;
    }
}

void infixtoPostfix() {

    string str;
    string postfix = "";
    GenericStack<char> s;
    cout << "Enter an expression: ";
    cin.ignore();
    std::getline(cin, str);

    for (int i = 0; i < str.length(); i++) {

        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) {
            postfix += str[i];
        }

        else if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.push(str[i]);
        }

        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (str[i] == ')') {
                while (s.first() != '(') {
                    postfix += s.pop();
                }
                s.pop();
            }
            else if (str[i] == '}') {
                while (s.first() != '{') {
                    postfix += s.pop();
                }
                s.pop();
            }
            else if (str[i] == ']') {
                while (s.first() != '[') {
                    postfix += s.pop();
                }
                s.pop();
            }
        }

        else {
            while (!s.empty() && s.prec(str[i]) <= s.prec(s.first())) {
                postfix += s.pop();
            }
            s.push(str[i]);
        }
    }

    while (!s.empty()) {
        postfix += s.pop();
    }

    cout << postfix << endl << endl;

}

void infixtoPrefix() {

    string str;
    string rev;
    string prefix = "";
    GenericStack<char> s;
    cout << "Enter an expression: ";
    cin.ignore();
    std::getline(cin, rev);
    for (int i = rev.length() - 1; i >= 0; i--) {
        str.push_back(rev[i]);
    }
    for (int i = 0; i <= str.length() - 1; i++) {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
        else if (str[i] == '{')
            str[i] = '}';
        else if (str[i] == '}')
            str[i] = '{';
        else if (str[i] == '[')
            str[i] = ']';
        else if (str[i] == ']')
            str[i] = '[';
    }

    for (int i = 0; i < str.length(); i++) {

        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) {
            prefix += str[i];
        }

        else if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.push(str[i]);
        }

        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (str[i] == ')') {
                while ((s.first() != '(') && (!s.empty())) {
                    prefix += s.pop();
                }
                s.pop();
            }
            else if (str[i] == '}') {
                while ((s.first() != '{') && (!s.empty())) {
                    prefix += s.pop();
                }
                s.pop();
            }
            else if (str[i] == ']') {
                while ((s.first() != '[') && (!s.empty())) {
                    prefix += s.pop();
                }
                s.pop();
            }
        }

        else {
            if (s.empty()) {
                s.push(str[i]);
            }
            else {
                if (s.prec(str[i]) > s.prec(s.first())) {
                    s.push(str[i]);
                }
                else if ((s.prec(str[i]) == s.prec(s.first())) && (str[i] == '^')) {
                    while ((s.prec(str[i]) == s.prec(s.first())) && (str[i] == '^')) {
                        prefix += s.first();
                        s.pop();
                    }
                    s.push(str[i]);
                }
                else if (s.prec(str[i]) == s.prec(s.first())) {
                    s.push(str[i]);
                }
                else {
                    while (!s.empty() && s.prec(str[i]) <= s.prec(s.first())) {
                        prefix += s.pop();
                    }
                    s.push(str[i]);
                }
            }
        }
    }

    while (!s.empty()) {
        prefix += s.pop();
    }

    std::reverse(prefix.begin(), prefix.end());
    cout << prefix << endl << endl;

}

void evaluatePostfix() {

    int answer = 0;
    GenericStack<int> s;
    string str = "";
    cout << "\nSeparate with spaces like: 4 55 + 62 23 - *" << endl;
    cout << "Enter a postfix expression: ";
    cin.ignore();
    std::getline(cin, str);


    for (int i = 0; i < str.length(); i++) {

        if (isdigit(str[i])) {
            string temp = "";
            while (isdigit(str[i])) {
                temp += str[i];
                i++;
            }
            int num = std::stoi(temp);
            s.push(num);
        }

        else if (str[i] == ' ') {
            continue;
        }

        else {

            int  b = s.pop();
            int a = s.pop();
            if (str[i] == '+') {
                answer = a + b;
            }
            else if (str[i] == '-') {
                answer = a - b;
            }
            else if (str[i] == '/') {
                answer = a / b;
            }
            else if (str[i] == '*') {
                answer = a * b;
            }
            else if (str[i] == '^') {
                answer = pow(a, b);
            }
            s.push(answer);
        }
    }

    cout << "The answer is: " << answer << endl << endl;
}

void towerOfHanoi() {

    GenericStack <int> s1, s2, s3;

    int n;
    cout << "\nEnter the number of Disks: ";
    cin >> n;
    for (int i = n; i >= 1; i--) {
        s1.push(i);
    }
    cout << endl;

    for (int i = 0; i < (pow(2, n)); i++) {

        s1.display(1);
        s2.display(2);
        s3.display(3);
        cout << endl << endl;

        if (i % 2 == 0) {
            if (s1.first() == 1)
                s3.push(s1.pop());
            else if (s2.first() == 1)
                s1.push(s2.pop());
            else if (s3.first() == 1)
                s2.push(s3.pop());
        }
        else {

            if (s1.first() == 1) {
                if (!s2.empty() && !s3.empty()) {
                    if (s2.first() < s3.first()) {
                        s3.push(s3.pop());
                        s3.push(s2.pop());
                    }
                    else if (s2.first() > s3.first()) {
                        s2.push(s2.pop());
                        s2.push(s3.pop());
                    }
                }
                else if (s3.empty()) {
                    s3.push(s2.pop());
                }
                else if (s2.empty()) {
                    s2.push(s3.pop());
                }
            }

            else if (s2.first() == 1) {
                if (!s1.empty() && !s3.empty()) {
                    if (s1.first() < s3.first()) {
                        s3.push(s3.pop());
                        s3.push(s1.pop());
                    }
                    else if (s1.first() > s3.first()) {
                        s1.push(s1.pop());
                        s1.push(s3.pop());
                    }
                }
                else if (s3.empty()) {
                    s3.push(s1.pop());
                }
                else if (s1.empty()) {
                    s1.push(s3.pop());
                }
            }

            else if (s3.first() == 1) {
                if (!s1.empty() && !s2.empty()) {
                    if (s1.first() < s2.first()) {
                        s2.push(s2.pop());
                        s2.push(s1.pop());
                    }
                    else if (s1.first() > s2.first()) {
                        s1.push(s1.pop());
                        s1.push(s2.pop());
                    }
                }
                else if (s2.empty()) {
                    s2.push(s1.pop());
                }
                else if (s1.empty()) {
                    s1.push(s2.pop());
                }
            }

        }

    }

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
        if (front == -1 && rear == -1) {
            cout << "Queue Underflow" << endl;
        }
        else if (front == rear) {
            value  = array[front];
            array[front] = 0;
            front = -1;
            rear = -1;
        }
        else if (front > rear) {
            if (front == size - 1) {
                value = array[front];
                array[front] = 0;
                front = 0;
            }
            else {
                value = array[front];
                array[front] = 0;
                front++;
            }
        }
        else if (front < rear) {
            value = array[front];
            array[front] = 0;
            front++;
        }
        return value;
    }

    void display() {
        int f = front;
        int r = rear;
        if (f == r) {
            cout << array[f] << " ";
        }
        else if (f > r) {
            while ((f > r) && (f != size-1)) {
                cout << array[f] << " ";
                f++;
            }
            cout << array[f] << " ";
            f = 0;
            while (f <= r) {
                cout << array[f] << " ";
                f++;
            }
        }
        else if (f < r) {
            while (f < r) {
                cout << array[f] << " ";
                f++;
            }
            cout << array[f] << " ";
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
        for (int j=0; j<4; j++) {
            cout << q.array[j] << " ";
        }
        cout << endl;
    }
}

