#include <iostream>
#include <string>

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    Stack(const Stack& other) : top(nullptr), size(0) {
        Node* temp = other.top;
        while (temp != nullptr) {
            push(temp->data);
            temp = temp->next;
        }
    }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop() {
        Node* temp = top;
        top = top->next;
        int poppedValue = temp->data;
        delete temp;
        size--;
        return poppedValue;
    }

    int peek() {
        return top->data;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void addStack(Stack& other) {
        while (!other.isEmpty()) {
            push(other.pop());
        }
    }
};

int main() {
    Stack evenStack, oddStack;
    std::string input;

    std::cout << "Enter value:" << std::endl;
    while (std::getline(std::cin, input) && !input.empty()) {
        int value = std::stoi(input);
        if (value % 2 == 0) {
            evenStack.push(value);
        }
        else {
            oddStack.push(value);
        }
    }

    if (evenStack.getSize() < oddStack.getSize()) {
        evenStack.addStack(oddStack);
        while (!evenStack.isEmpty()) {
            std::cout << evenStack.pop() << std::endl;
        }
    }
    else {
        oddStack.addStack(evenStack);
        while (!oddStack.isEmpty()) {
            std::cout << oddStack.pop() << std::endl;
        }
    }

    return 0;
}