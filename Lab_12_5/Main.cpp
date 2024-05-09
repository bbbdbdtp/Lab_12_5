#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

// ������� ��� ��������� ���� �����
bool compareStacks(stack<int>& stack1, stack<int>& stack2) {
    // ��������� ���� �����
    stack<int> stack1Copy = stack1;
    stack<int> stack2Copy = stack2;

    if (stack1Copy.size() != stack2Copy.size()) // ���� ������ ����� �����������, ���� ����� ���������
        return false;

    // ��������� ������� �������� ��������� ��� ��������� ��
    while (!stack1Copy.empty()) {
        if (stack1Copy.top() != stack2Copy.top())
            return false;
        stack1Copy.pop();
        stack2Copy.pop();
    }
    return true; // ���� ������� ��������� � �� ������� ������, ����� �������
}

// ������� ��� ������ �����
void invertStack(stack<int>& s) {
    stack<int> temp;
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    s = temp;
}

// ������� ��� ��������� ������ ����� � ��'������ ���������� ���� �����
stack<int> createNegativeStack(stack<int>& stack1, stack<int>& stack2) {
    stack<int> result;
    while (!stack1.empty()) {
        result.push(-stack1.top());
        stack1.pop();
    }
    while (!stack2.empty()) {
        result.push(-stack2.top());
        stack2.pop();
    }
    return result;
}

// ������� ��� ��������� �������� ����� �� �����
void printStack(stack<int> s) {
    cout << "Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// ������� ��� ���������� ����� � ����� �� ��������� �� �� �����
void readNumbersFromFile(const string& filename, stack<int>& s) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }
    int num;
    while (file >> num) {
        s.push(num);
    }
    file.close();
}

int main() {
    stack<int> stack1, stack2;

    // ���������� ����� � ��������� �� � �����
    int num;
    cout << "Enter numbers for Stack 1 (enter 0 to stop): ";
    while (cin >> num && num != 0) {
        stack1.push(num);
    }
    readNumbersFromFile("text.txt", stack2);

    // ��������� ����� �� ���������
    cout << "Before comparison:" << endl;
    printStack(stack1);
    printStack(stack2);

    // ��������� ����� �� ��������� ��������� ��
    if (compareStacks(stack1, stack2)) {
        cout << "Stacks are equal. Inverting Stack 2." << endl;
        stack<int> stack2Copy = stack2; // ������� stack2
        invertStack(stack2Copy);
        stack2 = stack2Copy; // ���������� ������ �������� ����� �� stack2
    }
    else {
        cout << "Stacks are not equal. Creating new stack with negative elements." << endl;
        stack<int> negativeStack = createNegativeStack(stack1, stack2);
        printStack(negativeStack);
    }

    // ��������� ����� ���� ������������
    cout << "After transformation:" << endl;
    printStack(stack1);
    printStack(stack2);

    return 0;
}