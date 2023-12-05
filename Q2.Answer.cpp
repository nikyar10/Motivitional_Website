#include <iostream>
#include <stack>

using namespace std;

class QueueUsingStack {
private:
    stack<int> s1, s2;

public:
    bool empty() {
        return s1.empty() && s2.empty();
    }

    int size() {
        return s1.size() + s2.size();
    }

    int front() {
        if (empty()) {
            cerr << "Queue is empty." << endl;
            exit(EXIT_FAILURE);
        }

        if (s2.empty()) {
            // Move elements from s1 to s2 to reverse the order
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    void enqueue(int i) {
        s1.push(i);
    }

    void dequeue() {
        if (empty()) {
            cerr << "Queue is empty." << endl;
            exit(EXIT_FAILURE);
        }

        if (s2.empty()) {
            // Move elements from s1 to s2 to reverse the order
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    void display() {
        // Display elements from s1
        stack<int> tempS = s1;
        while (!tempS.empty()) {
            cout << tempS.top() << " ";
            tempS.pop();
        }

        // Display elements from s2 in reverse order
        tempS = s2;
        while (!tempS.empty()) {
            cout << tempS.top() << " ";
            tempS.pop();
        }

        cout << endl;
    }
};

int main() {
    QueueUsingStack queue;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Size\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int value;
            cout << "Enter the value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;

        case 2:
            queue.dequeue();
            cout << "Front element dequeued." << endl;
            break;

        case 3:
            if (!queue.empty())
                cout << "Front element: " << queue.front() << endl;
            break;

        case 4:
            cout << "Size of queue: " << queue.size() << endl;
            break;

        case 5:
            queue.display();
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
