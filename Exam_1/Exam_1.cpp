#include <iostream>
#include <list>
#include <string>

using namespace std;

class Stack {
private:
    list<int> l;
    int c_size;
public:
    Stack()
    {
        c_size = 0;
    }
    Stack(Stack &s)
    {
        this->l = s.l;
        this->c_size = s.c_size;
    }
    ~Stack()
    {

    }
    void push(int value)
    {
        c_size++;
        l.push_front(value);
    }

    void pop()
    {
        if (c_size <= 0) {
            
            cout << "Stack empty" << endl;
        }
        else {
            c_size--;
            l.pop_front();
        }
    }

    int top() { return l.front(); }
    int size()
    {
        return c_size;
    }
    void mergeStack(Stack& otherStack)
    {
        while (otherStack.c_size > 0) {
            int element = otherStack.top();
            otherStack.pop();
            push(element);
        }
    }
    void printStack()
    {
        cout << "Elements in stack: ";
        for (int element : l) {
            cout << element << " ";
        }
        cout << endl;
    }
};
int main()
{
    string value;
    int valueInt;
    Stack s1;
    Stack s2;
    while (true)
    {
        cout << "Enter value: " << endl;
        cin >> value;
        if (value == "stop")
        {
            break;
        }
        else
        {
            valueInt = stoi(value);
        }
        if (valueInt % 2 == 0) {
            s1.push(valueInt);
        }
        else  {
            s2.push(valueInt);
        }
    }
    if (s1.size() < s2.size())
    {
        s1.mergeStack(s2);
        s1.printStack();
    }
    else
    {
        s2.mergeStack(s1);
        s2.printStack();
    }
    cout << "end";
}