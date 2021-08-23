#include <iostream>
#include <string>
#include <stack>

using namespace std;

long *getBracketsResult(string s) {
    stack<long> index;
    long n = s.length();
    stack<char> stack;
    long *matrix = new long[n];
    char top;
    for (long i = n - 1; i >= 0; i--) {
        if (s[i] == '>' || s[i] == '}' || s[i] == ']' || s[i] == ')') {
            matrix[i] = 0;
            stack.push(s[i]);
            index.push(i);
            continue;
        }
        if (stack.empty() == false)
            top = stack.top();
        else {
            matrix[i] = 0;
            stack.push(s[i]);
            continue;
        }

        if (s[i] == '(') {
            if (top == ')') {
                matrix[i] = index.top() - i + 1 + matrix[index.top() + 1];
                stack.pop();
                index.pop();
            } else {
                stack.push(s[i]);
                matrix[i] = 0;
            }
        } else if (s[i] == '{') {
            if (top == '}') {
                matrix[i] = index.top() - i + 1 + matrix[index.top() + 1];
                stack.pop();
                index.pop();
            } else {
                stack.push(s[i]);
                matrix[i] = 0;

            }
        } else if (s[i] == '[') {
            if (top == ']') {
                matrix[i] = index.top() - i + 1 + matrix[index.top() + 1];
                stack.pop();
                index.pop();
            } else {
                stack.push(s[i]);
                matrix[i] = 0;

            }
        } else if (s[i] == '<') {
            if (top == '>') {
                matrix[i] = index.top() - i + 1 + matrix[index.top() + 1];
                stack.pop();
                index.pop();
            } else {
                stack.push(s[i]);
                matrix[i] = 0;
            }
        }
    }
    return matrix;
}


int main() {
    long n;
    cin >> n;
    string bracket;
    cin >> bracket;
    long *result = getBracketsResult(bracket);
    if (bracket.length() == 0) {
        cout << "0";
        return 0;
    }
    for (long i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
