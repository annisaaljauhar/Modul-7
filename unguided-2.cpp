#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    string studentID;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isFull() {
        return false;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string name, string studentID) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->studentID = studentID;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }


    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
    }

    int count() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void view() {
        cout << "Queue Student Data:" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". Name: " << current->name << ", NIM: " << current->studentID << endl;
            current = current->next;
            index++;
        }
        if (index == 1) {
            cout << "(empty)" << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue("Andi", "2023001");
    q.enqueue("Naya", "2023002");
    q.view();
    cout << "Queue Size = " << q.count() << endl;

    q.dequeue();
    q.view();
    cout << "Queue Size = " << q.count() << endl;

    q.clear();
    q.view();
    cout << "Queue Size = " << q.count() << endl;

    return 0;
}
