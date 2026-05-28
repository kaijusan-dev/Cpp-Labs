#include <iostream>
#include "TNode.h"
#include "Dynamic14.h"

class Queue {
    private:
        TNode* head;
        TNode* tail;

    public:
        Queue() : head(nullptr), tail(nullptr) {}

        ~Queue() {
            while (!QueueIsEmpty()) {
                Pop();
            }
        }

        void Push(int D) {
            TNode* newNode = new TNode(D);
            if (tail) {
                tail->next = newNode;
            }
            tail = newNode;
            if (!head) {
                head = tail;
            }
        }

        int Pop() {
            TNode* temp = head;
            int value = temp->Data;
            head = head->next;
            if (!head) {
                tail = nullptr;
            }
            delete temp;
            return value;
        }

        bool QueueIsEmpty() {
            return head == nullptr;
        }

        int Peek() {
            if (head) {
                return head->Data;
            }
        }

        void printQueue() {
            TNode* current = head;
            while (current) {
                std::cout << current->Data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }

        TNode* getHead() {
            return head;
        }
        TNode* getTail() {
            return tail;
        }
};

// Дан набор из 10 чисел. Создать очередь, содержащую данные числа в указанном
// порядке (первое число будет размещаться в начале очереди, последнее — в конце), и вывести
// указатели P1 и P2 на начало и конец очереди

void Dynamic14() {
    using namespace std;

    Queue* queue = new Queue();

    cout << "Enter 10 numbers to add to the queue: ";
    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        queue->Push(x);

        if (cin.fail()) {
             throw 1;
        }
    }

    cout << "Original queue: ";
    queue->printQueue();

    cout << "P1 (head of queue): " << queue->getHead()->Data << endl;
    cout << "P2 (tail of queue): " << queue->getTail()->Data << endl;

    delete queue;
}