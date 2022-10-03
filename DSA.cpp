#include <iostream>
#include <cmath>
#include <string>

using namespace std;

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
void InfixtoPostfix();
void InfixtoPrefix();


int main() {

    int num;

    do {

        cout << "Enter the action you want to perform:\n\t01: Factorial.\n\t02: Fibonacci Series.\n\t03: Greatest Common Divisor.\n\t04: Number of Digits.\n\t05: Reverse of a number.\n\t06: Least Common Multiple.\n\t07: Prime numbers between 1-100.\n\t08: Square root of a number.\n\t09: Profit-Loss calculator.\n\t10: Sum of Squares of natural number.\n\t11: Sum of Factorials.\n\t12. Matrix Multiplication.\n\t13. Transpose of a matrix.\n\t14. Student Structures.\n\t15: Decimal to Binary Converter.\n\t16: Check balanced paranthesis of an expression.\n\t17: Infix to Postfix.\n\t18: Infix to Prefix.\n\t00: Exit." << endl << endl;

        cin >> num;

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
            case 12:
                matrixMult();
                break;
            case 13:
                transpose();
                break;
            case 14:
                studentsStruct();
                break;
            case 15:
                deciToBinary();
                break;
            case 16:
                balancedExp();
                break;
            case 17: 
                InfixtoPostfix();
                break;
            case 18: 
                InfixtoPrefix();
                break;
            case 0:
                break;
            default:
                cout << "\nCorresponding number is incorrect.";
        }

    } while (num != 0);

    return 0;
}

void factorial () {
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
        cout << "Factorial of " << num <<  " = " << fact << endl << endl;
    }
}

void fibonacci () {

    int term;
    int num1 = 0;
    int num2 = 1;
    int next;

    cout << "\nEnter the number of terms: ";
    cin >> term;

    for (int i=0; i<term; i++) {
        cout << num1 << " ";
        next = num1 + num2;
        num1 = num2;
        num2 = next;
    }
    cout << "\n" << endl;
}

void gcd () {
    int num1;
    int num2;
    int gcd;

    cout << "\nEnter the first integer: ";
    cin >> num1;
    cout << "Enter the second integer: ";
    cin >> num2;

    for(int i=1; i<=num1 && i<=num2; i++) {
        if(num1%i==0 && num2%i==0)
            gcd = i;
    }
    cout << "G.C.D of " << num1 << " and " << num2 << " is: " << gcd << endl << endl;
}

void numOfDigits () {
    int num;
    int count;
    cout << "\nEnter the number: ";
    cin >> num;
    count = log10(num) + 1;
    cout << "Number of digits: " << count << endl << endl;
}

void reverseOfNum () {
    int num = 0;
    int reverse = 0;
    cout << "\nEnter a number for ts reverse: ";
    cin >> num;

    while (num != 0) {
        reverse *= 10;
        reverse += num%10;
        num /= 10;
    }

    cout << "Reverse of the number = " << reverse << endl << endl;
}

void lcm () {
    int num1;
    int num2;
    int gcd;

    cout << "\nEnter the first integer: ";
    cin >> num1;
    cout << "Enter the second integer: ";
    cin >> num2;

    for(int i=1; i<=num1 && i<=num2; i++) {
        if(num1%i==0 && num2%i==0)
            gcd = i;
    }
    int lcm = (num1*num2)/gcd;
    cout << "L.C.M of " << num1 << " and " << num2 << " is: " << lcm << endl << endl;
}

void primeNumbers() {
    int i;
    int count;
    int a = 1;

    while(a <= 100) {
        i = 2;
        count = 0;

        while(i <= a/2) {
            if(a%i == 0) {
                count++;
                break;
            }
            i++;
        }
        if(count==0 && a!=1) {
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

    if ((amt-total) < 0) {
        double loss = -1*(amt-total);
        double lossPercent = (loss/total)*100;
        printf("Total loss is: %.0f", loss);
        printf("\nTotal loss percentage is: %.2f\n\n", lossPercent);
    }
    else if ((amt-total) >= 0){
        double profit = amt-total;
        double profitPercent = (profit/total)*100;
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
    while(count<=num) {
        sum += count*count;
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
    while(count<=num) {
        float fact = 1;
        for (int i = 1; i <= count; i++) {
            fact *= i;
        }
        sum += 1/fact;
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
        int **arr = new int *[row1];
        for (int i=0; i<row1; i++) {
            arr[i] = new int [column2];
        }
        int **arr1 = new int *[row1];
        for (int i=0; i<row1; i++) {
            arr1[i] = new int [column1];
        }
        int **arr2 = new int *[row2];
        for (int i=0; i<row2; i++) {
            arr2[i] = new int [column2];
        }
        
        for (int i=0; i<row1; i++) {
            for (int j=0; j<column1; j++) {
                cout << "[" << i+1 << "][" << j+1 << "] = ";
                cin >> arr1[i][j];
            }
        }
        cout << endl;
        for (int i=0; i<row2; i++) {
            for (int j=0; j<column2; j++) {
                cout << "[" << i+1 << "][" << j+1 << "] = ";
                cin >> arr2[i][j];
            }
        }
        cout << endl;
        for (int i=0; i<row1; i++) {
            for (int j=0; j<column2; j++) {
                arr[i][j] = 0;
            }
        }

        for (int i=0; i<row1; i++) {
            for (int j=0; j<column2; j++) {
                for (int k=0; k<column1; k++) {
                    arr[i][j] += arr1[i][k]*arr2[k][j];
                }
            }
        }

        cout << endl << "Output Matrix: " << endl;
        for (int i=0; i<row1; i++) {
            for (int j=0; j<column2; j++) {
                cout << "[" << i+1 << "][" << j+1 << "] = " << arr[i][j] << endl;
            }
        }

        cout << endl << endl;

        //Deleted Dynamic Arrays made previously.

        for (int i=0; i<row1; i++) {
            delete[] arr1[i];
            delete[] arr[i];
            arr1[i] = NULL;
            arr[i] = NULL;
        }
        for (int i=0; i<row2; i++) {
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

void transpose() {

    int row, column;

    cout << "\nEnter the rows for Matrix: ";
    cin >> row;
    cout << "Enter the columns for Matrix: ";
    cin >> column;
    cout << endl;

    int **arr = new int *[row];
    for (int i=0; i<row; i++) {
        arr[i] = new int [column];
    }
    int **trans = new int *[row];
    for (int i=0; i<row; i++) {
        trans[i] = new int [column];
    }

    for (int i=0; i<row; i++) {
        for (int j=0; j<column; j++) {
            cout << "[" << i+1 << "][" << j+1 << "] = ";
            cin >> arr[i][j];
        }
    }
    cout << endl;

    for (int i=0; i<row; i++) {
        for (int j=0; j<column; j++) {
            trans[i][j] = arr[j][i];
        }
    }


    for (int i=0; i<row; i++) {
        for (int j=0; j<column; j++) {
            cout << "[" << i+1 << "][" << j+1 << "] = " << trans[i][j] << endl;
        }
    }
    cout << endl;

    //Deleting Dynamic Arrays made previously.

    for (int i=0; i<row; i++) {
        delete[] arr[i];
        delete[] trans[i];
    }
    delete[] arr;
    delete[] trans;
    arr = NULL;
    trans = NULL;
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

    Student s[3] = {s1, s2, s3};

    for (int i=0; i<3; i++) {
        if (s[i].subject == "DSA" && s[i].cgpa>3.0) {
            cout << s[i].name << endl << endl;
        }
    }
}

void deciToBinary() {

    struct Stack {
        int top = -1;
        int array[100];

        void push(int num) {
            if (top == (sizeof(array)/sizeof(array[0]))-1) {
                cout << "Sorry, stack is full." << endl;
            }
            else {
                top++;
                array[top] = num;
            }
        }

        int pop() {
            if (top == -1) {
                cout << "Sorry, stack is empty." << endl;
            }
            else {
                int popped = array[top];
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
    };

    int num;
    Stack s;
    cout << "\nEnter a decimal number: ";
    cin >> num;
    cout << "The Binary representation is: ";

    while (num >= 1) {
        s.push(num%2);
        num /= 2;
    }
    while (!s.empty()) {
        cout << s.pop();
    }
    cout << endl << endl;
}

void balancedExp() {

    struct Stack {
        int top = -1;
        char array[100];

        void push(char symbol) {
            if (top == (sizeof(array)/sizeof(array[0]))-1) {
                cout << "Sorry, stack is full." << endl;
            }
            else {
                top++;
                array[top] = symbol;
            }
        }

        char pop() {
            if (top == -1) {
                cout << "Sorry, stack is empty." << endl;
            }
            else {
                char popped = array[top];
                array[top] = 0;
                top--;
                return popped;
            }
        }

        char first() {
            return array[top];
        }

        bool empty() {
            if (top == -1) {
                return true;
            }
            else {
                return false;
            }
        }
    };

    Stack s;
    string str;
    cout << "\nEnter the expression: ";
    cin.ignore();
    std::getline(cin, str);

    for (int i=0; i<str.length(); i++) {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(' || str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (s.empty()) {
                s.push(str[i]);
            }
            else if ((s.first() == '(' && str[i] == ')')  || (s.first() == '{' && str[i] == '}') || (s.first() == '[' && str[i] == ']')) {
                s.pop();
            }
            else {
                s.push(str[i]);
            }
        }
    }

    if(s.empty()) {
        cout << "The Expression is Balanced." << endl << endl;
    }
    else {
        cout << "The Expression is not Balanced." << endl << endl;
    }
}

void InfixtoPostfix() {

    struct Stack {
        int top = -1;
        char array[100];

        int prec (char c) {
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

        void push(char symbol) {
            if (top == (sizeof(array)/sizeof(array[0]))-1) {
                cout << "Sorry, stack is full." << endl;
            }
            else {
                top++;
                array[top] = symbol;
            }
        }

        char pop() {
            if (top == -1) {
                cout << "Sorry, stack is empty." << endl;
            }
            else {
                char popped = array[top];
                array[top] = 0;
                top--;
                return popped;
            }
        }

        char first() {
            return array[top];
        }

        bool empty() {
            if (top == -1) {
                return true;
            }
            else {
                return false;
            }
        }
    };

    string str;
    string postfix = "";
    Stack s;
    cout << "Enter an  expression: ";
    cin.ignore();
    std::getline(cin, str);

    for (int i=0; i<str.length(); i++) {

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

void InfixtoPrefix() {

    struct Stack {
        int top = -1;
        char array[100];

        int prec (char c) {
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

        void push(char symbol) {
            if (top == (sizeof(array)/sizeof(array[0]))-1) {
                cout << "Sorry, stack is full." << endl;
            }
            else {
                top++;
                array[top] = symbol;
            }
        }

        char pop() {
            if (top == -1) {
                cout << "Sorry, stack is empty." << endl;
            }
            else {
                char popped = array[top];
                array[top] = 0;
                top--;
                return popped;
            }
        }

        char first() {
            return array[top];
        }

        bool empty() {
            if (top == -1) {
                return true;
            }
            else {
                return false;
            }
        }
    };

    string str;
    string postfix = "";
    Stack s;
    cout << "Enter an  expression: ";
    cin.ignore();
    std::getline(cin, str);

    string rev = "";
    for (int i = str.length()-1; i >= 0; i--)
        rev.push_back(str[i]);

    str = rev;

    for (int i=0; i<str.length(); i++) {

        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) {
            postfix += str[i];
        }

        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            s.push(str[i]);
        }
 
        else if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            if (str[i] == '(') {
                while (s.first() != ')') {
                    postfix += s.pop();
                }
                s.pop();
            }
            else if (str[i] == '{') {
                while (s.first() != '}') {
                    postfix += s.pop();
                }
                s.pop();
            }
            else if (str[i] == '[') {
                while (s.first() != ']') {
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

    string prefix = "";
    for (int i = postfix.length()-1; i >= 0; i--)
        prefix.push_back(postfix[i]);
    cout << prefix << endl << endl;

}