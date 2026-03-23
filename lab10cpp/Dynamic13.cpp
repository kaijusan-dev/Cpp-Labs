#include <iostream>
#include "Dynamic13.h"
#include "TNode.h"

class TStack {
    private:
        TNode* top;

    public:
        TStack() : top(nullptr) {}

        TStack(const TStack& other) : top(nullptr) {
            if (other.top == nullptr)
                return;

            TNode* current = other.top;
            int count = 0;

            while (current) {
                count++;
                current = current->next;
            }

            int* temp = new int[count];
            current = other.top;

            for (int i = count - 1; i >= 0; i--) {
                temp[i] = current->Data;
                current = current->next;
            }

            for (int i = 0; i < count; i++) {
                Push(temp[i]);
            }

            delete[] temp;
        }

        ~TStack() {
            while (!StackIsEmpty()) {
                Pop();
            }
        }

        void Push(int D) {
            TNode* newNode = new TNode(D, top);
            top = newNode;
        }

        int Pop() {
            TNode* temp = top;
            int value = temp->Data;
            top = top->next;
            delete temp;
            return value;
        }

        bool StackIsEmpty() {
            return top == nullptr;
        }

        int Peek() {
            return top->Data; 
        }

        void printStack() {
            TNode* current = top;
            while (current) {
                std::cout << current->Data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }

        TNode* getTop() const {
            return top;
        }
};

void generateStack(TStack& stack, int n) {
    for (int i = 1; i <= n; i++) {
        stack.Push(i);
    }
}

void Dynamic13() {
    using namespace std;

    TStack* stack = new TStack();
    generateStack(*stack, 10);
    TNode* P1 = stack->getTop();


    //по условию дан указатель P1 на вершину стека, необходимо удалить 5 элементов, и вывести оставшиеся элементы на экран.
    //сделаем копию стека, чтобы использовать функции класса TStack

    TStack* stackCopy = new TStack();
    while (P1 != nullptr) {
        stackCopy->Push(P1->Data);
        P1 = P1->next;
    }
    cout << "Original stack: ";
    stackCopy->printStack();

    cout << "Removed elements:\n";
    for (int i = 0 ; i < 5; i++) {
        if (!stackCopy->StackIsEmpty()) {
            int value = stackCopy->Pop();
            cout << "\tRemoved element: " << value << endl;
        }
    } 

    if (stackCopy->StackIsEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty. Value and Address of new top:\n";
        cout << "\tValue: " << stackCopy->Peek() << endl;
        cout << "\tAddress: " << stackCopy->getTop() << endl;
    };
    
    delete stack;
    delete stackCopy;
}