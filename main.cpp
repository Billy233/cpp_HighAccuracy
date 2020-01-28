#include <bits/stdc++.h>
using namespace std;

int main() {
    
    cout << "Greetings~ This is a program to review the cpp \"High Accuracy Algorithm\"  " << endl;
    cout << "Put in format: num1 + space + operator(including + - and *) + space + num2" << endl;
    cout << "attention: Num1 and num2 can be up to quite large, but don't more than 200 bytes" << endl;
    string num1, op, num2;
    cin >> num1 >> op >> num2;

    int a1[200], len1, a2[200], len2;
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    

    cout << "Here is the result: ";

    if (op == "+") {


        len1 = num1.size();
        len2 = num2.size();
    
        for (int i = 1; i <= len1; i++) {
            a1[i] = num1[len1 - i] - '0';
        }
        for (int i = 1; i <= len2; i++) {
            a2[i] = num2[len2 - i] - '0';
        }

        len1 = max(len1, len2);

        for (int i = 1; i <= len1; i++) {
            a1[i] += a2[i];
            a1[i + 1] += a1[i] / 10;
            a1[i] %= 10;
        }

        while (a1[len1 + 1]) {
            len1++;
            a1[len1 + 1] += a1[len1] / 10;
            a1[len1] %= 10;
        }

        for (int i = len1; i >= 1; i--) {
            cout << a1[i];
        }

    } else if (op == "-") {

        if (num1.size() < num2.size() || num1.size() == num2.size() && num1 < num2) {

            swap(num1, num2);
            cout << '-';
        }
            

        len1 = num1.size();
        len2 = num2.size();
        for (int i = 1; i <= len1; i++) {
            a1[i] = num1[len1 - i] - '0';
        }
        for (int i = 1; i <= len2; i++) {
            a2[i] = num2[len2 - i] - '0';
        }

        len1 = max(len1, len2);

        for (int i = 1; i <= len1; i++) {
            a1[i] -= a2[i];
            if (a1[i] < 0) {
                a1[i + 1]--;
                a1[i] += 10;
            }
        }

        while (len1 > 1 && a1[len1] == 0) {
            len1--;
        }

        for (int i = len1; i >= 1; i--) {
            cout << a1[i];
        }

    } else if (op == "*") {

        len1 = num1.size();
        len2 = num2.size();

        for (int i = 1; i <= len1; i++) {
            a1[i] = num1[len1 - i] - '0';
        }
        for (int i = 1; i <= len2; i++) {
            a2[i] = num2[len2 - i] - '0';
        }

        int a[500], len;
        memset(a, 0, sizeof (a));

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                a[i + j - 1] += a1[i] * a2[j];
            }
        }
        len = len1 + len2 - 1;

        for (int i = 1; i <= len; i++) {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;;
        }

        while (a[len + 1]) {
            len++;
            a[len + 1] += a[len] / 10;
            a[len] %= 10;
        }

        for (int i = len; i >= 1; i--) {
            cout << a[i];
        }

    } else {
        cout << "The op is not supported!!";
    }


    cout << endl;
    system("pause");
    return 0;
}
