#include <iostream>
using namespace std;

#define Nil 0
#define MaxEl 5

struct Queue {
    int Data[MaxEl + 1];
    int HEAD;
    int TAIL;
};

void CreateEmpty(Queue *Q) {
    Q->HEAD = Q->TAIL = Nil;
}

bool isEmpty(Queue *Q) {
    return ((Q->HEAD == Nil) && (Q->TAIL == Nil));
}

int NbElmt(Queue *Q) {
    if (isEmpty(Q)) return 0;
    if (Q->HEAD <= Q->TAIL) {
        return (Q->TAIL - Q->HEAD + 1);
    } else {
        return (MaxEl - Q->HEAD + Q->TAIL + 1);
    }
}

bool isFull(Queue *Q) {
    return NbElmt(Q) == MaxEl;
}

void Enqueue(Queue *Q, int x) {
// atau bisa pake void Add

    if (isFull(Q)) {
        cout << "Queue Penuh!" << endl;
        return;
    }
    if (isEmpty(Q)) {
        Q->HEAD = 1;
        Q->TAIL = 1;
    } else {
        if (Q->TAIL == MaxEl) {
            Q->TAIL = 1;
        } else {
            Q->TAIL++;
        }
    }
    Q->Data[Q->TAIL] = x;
}

void Dequeue(Queue *Q) {
    if (isEmpty(Q)) {
        cout << "Queue Kosong!" << endl;
        return;
    } else {
        Q->Data[Q->HEAD] = 0;
        if (Q->HEAD == Q->TAIL) {
            Q->HEAD = Nil;
            Q->TAIL = Nil;
        } else {
            if (Q->HEAD == MaxEl) {
                Q->HEAD = 1;
            } else {
                Q->HEAD++;
            }
        }
    }
}

void DisplayQueue(Queue *Q) {
    if (isEmpty(Q)) {
        cout << "Queue Kosong!" << endl;
        return;
    }

    int i = Nil + 1;
    for(int i = Nil + 1; i < MaxEl + 1; i++) {
        if (Q->Data[i] == 0) {
            cout << "[ ] ";
        } else {
            cout << "[ " << Q->Data[i] << " ] ";
        }
    }
    cout << "\nHEAD: " << Q->Data[Q->HEAD] << "\nTAIL: " << Q->Data[Q->TAIL] << endl;
}

int main() {
    Queue urutanPrioritas;
    CreateEmpty(&urutanPrioritas);

    for (int i : {10, 5, 20, 45, 10}) {
        Enqueue(&urutanPrioritas, i);
    }

    DisplayQueue(&urutanPrioritas);

    Dequeue(&urutanPrioritas);
    cout << "\nSetelah Dequueu!" << endl;
    DisplayQueue(&urutanPrioritas);

    return 0;
}
