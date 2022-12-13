#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

void stackApplications();
void deciToBinary();
void balancedExp();
void infixtoPostfix();
void infixtoPrefix();
void evaluatePostfix();
void towerOfHanoi();

int main() {

    stackApplications();

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

template <class T> class GenericStack {
    int top = -1;
    int size;
    T* array = new T[size];

public:

    GenericStack(int size) {
        this->size = size;
    }

    ~GenericStack() {
        delete[] array;
    }

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
    GenericStack<int> s(50);
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

    GenericStack<char> s(50);
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
    GenericStack<char> s(50);
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
    GenericStack<char> s(50);
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
    GenericStack<int> s(50);
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

    GenericStack <int> s1(50), s2(50), s3(50);

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
