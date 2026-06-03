#include <iostream>
using namespace std;

#define MaxEl 100

struct MaxHeap {
    int data[MaxEl];
    int size;
};

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void InsertHeap(MaxHeap *H, int x) {
    if (H->size >= MaxEl) return;

    H->data[H->size] = x;
    int i = H->size;
    H->size++;

    while (i != 0 && H->data[parent(i)] < H->data[i]) {
        Swap(&H->data[parent(i)], &H->data[i]);
        i = parent(i);
    }
}

void Heapify(MaxHeap *H, int i) {
    int size = H->size;
    int largest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < size && H->data[l] > H->data[largest]) {
        largest = l;
    }

    if (r < size && H->data[r] > H->data[largest]) {
        largest = r;
    }

    if (largest != i) {
        Swap(&H->data[largest], &H->data[i]);
        Heapify(H, largest);
    }
}

void DeleteRoot(MaxHeap *H) {
    if (H->size <= 0) {
        cout << "Antrean Kosong!" << endl;
        return;
    }

    H->data[0] = H->data[H->size - 1];
    H->size--;
    Heapify(H, 0);
}

void DisplayHeap(MaxHeap *H) {
    if (H->size == 0) {
        cout << "Antrian Kosong!" << endl;
        return;
    }

    cout << "Antrian: " << endl;
    for (int i = 0; i < H->size; i++) {
        int level = 0;
        int tempIdx = i;
        while (tempIdx > 0) {
            tempIdx = parent(tempIdx);
            level++;
        }
        for (int j = 0; j < level; j++) cout << "   ";
        cout << "|--[" << H->data[i] << "]" << endl;
    }
}

int main() {
    MaxHeap antrean;
    antrean.size = 0;

    InsertHeap(&antrean, 10);
    InsertHeap(&antrean, 20);
    InsertHeap(&antrean, 5);
    InsertHeap(&antrean, 35);
    InsertHeap(&antrean, 40);

    DisplayHeap(&antrean);

    DeleteRoot(&antrean);
    cout << "\nAntrian Setelah DeleteRoot: " << endl;
    DisplayHeap(&antrean);

    return 0;
}
