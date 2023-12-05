#include <iostream>
#include <queue>

using namespace std;

class StackUsingQueue {
private:
    queue<int> q1, q2;

public:
    bool empty() {
        return q1.empty();
    }

    int size() {
        return q1.size();
    }

    int top() {
        if (empty()) {
            cerr << "Stack is empty." << endl;
            exit(EXIT_FAILURE);
        }

        // Move all elements from q1 to q2 except the last one
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Top element is the only element left in q1
        int topElement = q1.front();

        // Move the top element back to q1
        q1.pop();
        q2.push(topElement);

        // Swap the names of q1 and q2 to maintain the original order
        swap(q1, q2);

        return topElement;
    }

    void push(int i) {
        q1.push(i);
    }

    void pop() {
        if (empty()) {
            cerr << "Stack is empty." << endl;
            exit(EXIT_FAILURE);
        }

        // Move all elements from q1 to q2 except the last one
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Remove the top element from q1
        q1.pop();

        // Swap the names of q1 and q2 to maintain the original order
        swap(q1, q2);
    }

    void display() {
        queue<int> tempQ = q1;

        cout << "Stack elements (from last to first): ";
        while (!tempQ.empty()) {
            cout << tempQ.front() << " ";
            tempQ.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingQueue stack;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int value;
            cout << "Enter the value to push: ";
            cin >> value;
            stack.push(value);
            break;

        case 2:
            stack.pop();
            cout << "Top element popped." << endl;
            break;

        case 3:
            if (!stack.empty())
                cout << "Top element: " << stack.top() << endl;
            break;

        case 4:
            cout << "Size of stack: " << stack.size() << endl;
            break;

        case 5:
            stack.display();
            break;

        case 6:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
