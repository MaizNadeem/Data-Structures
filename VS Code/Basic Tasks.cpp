#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

void basicTasks();
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

