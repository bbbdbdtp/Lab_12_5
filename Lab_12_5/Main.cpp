#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

// Функція для порівняння двох стеків
bool compareStacks(stack<int>& stack1, stack<int>& stack2) {
    // Створення копій стеків
    stack<int> stack1Copy = stack1;
    stack<int> stack2Copy = stack2;

    if (stack1Copy.size() != stack2Copy.size()) // Якщо розміри стеків відрізняються, вони точно неоднакові
        return false;

    // Порівняння кожного елемента почергово без видалення їх
    while (!stack1Copy.empty()) {
        if (stack1Copy.top() != stack2Copy.top())
            return false;
        stack1Copy.pop();
        stack2Copy.pop();
    }
    return true; // Якщо пройшли порівняння і не виявили різниць, стеки однакові
}

// Функція для інверсії стека
void invertStack(stack<int>& s) {
    stack<int> temp;
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    s = temp;
}

// Функція для створення нового стека з від'ємними елементами двох стеків
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

// Функція для виведення елементів стека на екран
void printStack(stack<int> s) {
    cout << "Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

// Функція для зчитування чисел з файлу та додавання їх до стека
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

    // Зчитування чисел з клавіатури та з файлу
    int num;
    cout << "Enter numbers for Stack 1 (enter 0 to stop): ";
    while (cin >> num && num != 0) {
        stack1.push(num);
    }
    readNumbersFromFile("text.txt", stack2);

    // Виведення стеків до порівняння
    cout << "Before comparison:" << endl;
    printStack(stack1);
    printStack(stack2);

    // Порівняння стеків та виконання відповідних дій
    if (compareStacks(stack1, stack2)) {
        cout << "Stacks are equal. Inverting Stack 2." << endl;
        stack<int> stack2Copy = stack2; // Копіюємо stack2
        invertStack(stack2Copy);
        stack2 = stack2Copy; // Присвоюємо змінене значення назад до stack2
    }
    else {
        cout << "Stacks are not equal. Creating new stack with negative elements." << endl;
        stack<int> negativeStack = createNegativeStack(stack1, stack2);
        printStack(negativeStack);
    }

    // Виведення стеків після перетворення
    cout << "After transformation:" << endl;
    printStack(stack1);
    printStack(stack2);

    return 0;
}