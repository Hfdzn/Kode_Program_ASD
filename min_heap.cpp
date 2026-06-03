#include <iostream>
using namespace std;

#define MaxEl 100

struct MinHeap {
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

void InsertHeap(MinHeap *H, int x) {
    if (H->size >= MaxEl) return;

    H->data[H->size] = x;
    int i = H->size;
    H->size++;

    // Elemen naik JIKA parent lebih besar dari elemen saat ini ( > )
    while (i != 0 && H->data[parent(i)] > H->data[i]) {
        Swap(&H->data[parent(i)], &H->data[i]);
        i = parent(i);
    }
}

void Heapify(MinHeap *H, int i) {
    int size = H->size;

    int smallest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    // Cari anak yang LEBIH KECIL dari parent ( < )
    if (l < size && H->data[l] < H->data[smallest]) {
        smallest = l;
    }

    if (r < size && H->data[r] < H->data[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        Swap(&H->data[smallest], &H->data[i]);
        Heapify(H, smallest);
    }
}

void DeleteRoot(MinHeap *H) {
    if (H->size <= 0) {
        cout << "Antrean Kosong!" << endl;
        return;
    }

    H->data[0] = H->data[H->size - 1];
    H->size--;
    Heapify(H, 0);
}

void DisplayHeap(MinHeap *H) {
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
    MinHeap antrean;
    antrean.size = 0;

    InsertHeap(&antrean, 10);
    InsertHeap(&antrean, 20);
    InsertHeap(&antrean, 5);
    InsertHeap(&antrean, 35);
    InsertHeap(&antrean, 40);

    DisplayHeap(&antrean);

    DeleteRoot(&antrean);
    cout << "\nAntrian Setelah Delete Root: " << endl;
    DisplayHeap(&antrean);

    return 0;
}
