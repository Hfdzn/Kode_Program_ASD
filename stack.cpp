#include <iostream>
using namespace std;

#define Nil 0
#define MaxEl 10

struct Stack {
    int Data[MaxEl + 1];
    int TOP;
};

void CreateEmpty(Stack *S) {
    S->TOP = Nil;
}

bool isEmpty(Stack *S) {
    return S->TOP == Nil;
}

bool isFull(Stack *S) {
    return S->TOP == MaxEl;
}

void Push(Stack *S, int x) {
    if (!isFull(S)) {
        S->TOP++;
        S->Data[S->TOP] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

void Pop(Stack *S, int *x) {
    if (!isEmpty(S)) {
        *x = S->Data[S->TOP];
        S->TOP--;
    } else {
        cout << "Stack Kosong!" << endl;
    }
}

void DisplayStack(Stack *S) {
    if (!isEmpty(S)) {
        for (int i = S->TOP; i > 0; i--) {
            cout << "[ " << S->Data[i] << " ] ";
        }
        cout << endl;
    }
}

int main() {
    Stack urutanPrioritas;
    CreateEmpty(&urutanPrioritas);

    // variable untuk menampung hasil dari pemanggilan prosedur Pop
    int ambil;

    for (int i : {30, 10, 20, 40, 20}) {
       Push(&urutanPrioritas, i);
    }

    cout << "Urutan stack: " << endl;
    DisplayStack(&urutanPrioritas);

    // contoh penggunaan prosedur Pop
    Pop(&urutanPrioritas, &ambil);
    cout << "Data yang diambil: " << ambil << endl;

    return 0;
}
