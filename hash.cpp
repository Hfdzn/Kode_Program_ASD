#include <iostream>
using namespace std;

#define MaxEl 10

struct Node {
    int info;
    Node* next;
};

struct Bucket {
    Node *first;
};

void CreateEmpty(Bucket table[]) {
    for (int i = 0; i < MaxEl; i++) {
        table[i].first = nullptr;
    }
}

Node* Allocation(int x) {
    Node *P = new Node;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

void InsertValue(Bucket table[], int x) {
    int index = x % MaxEl;
    Node *newNode = Allocation(x);

    if (table[index].first == nullptr) {
        table[index].first = newNode;
    } else {
        newNode->next = table[index].first;
        table[index].first = newNode;
    }
}

void GetValue(Bucket table[], int x) {
    int index = x % MaxEl;
    Node *temp = table[index].first;
    while (temp != nullptr) {
        if (temp->info == x) {
            cout << "Data [" << x << "] ditemukan di index [" << index << "]." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Data [" << x << "] tidak ditemukan." << endl;
}

void DeleteValue(Bucket table[], int x) {
    int index = x % MaxEl;
    if (table[index].first == nullptr) {
        cout << "Data [" << x << "] tidak ditemukan." << endl;
        return;
    }

    if (table[index].first->info == x) {
        Node *PDel = table[index].first;
        table[index].first = table[index].first->next;
        delete PDel;
        cout << "Berhasil menghapus data [" << x << "]." << endl;
        return;
    }

    Node *pred = table[index].first;
    Node *temp = table[index].first->next;
    while (temp != nullptr) {
        if (temp->info == x) {
            pred->next = temp->next;
            delete temp;
            cout << "Berhasil menghapus data [" << x << "]." << endl;
            return;
        }
        pred = temp;
        temp = temp->next;
    }
    cout << "Data [" << x << "] tidak ditemukan." << endl;
}

void DisplayHash(Bucket table[]) {
    for (int i = 0; i < MaxEl; i++) {
        cout << "Index " << i << ": ";
        Node *temp = table[i].first;
        if (temp == nullptr) {
            cout << "(Kosong)";
        }
        while (temp != nullptr) {
            cout << "[ " << temp->info << " ] -> ";
            temp = temp->next;
        }
        if (table[i].first != nullptr) cout << "NULL";
        cout << endl;
    }
}

int main() {
    Bucket tableData[MaxEl];
    CreateEmpty(tableData);

    InsertValue(tableData, 50);
    InsertValue(tableData, 20);
    InsertValue(tableData, 35);
    InsertValue(tableData, 42);

    cout << "Data Hash Awal: " << endl;
    DisplayHash(tableData);

    cout << endl;
    DeleteValue(tableData, 20);
    cout << "Data Hash Setelah Menghapus Data 20: " << endl;
    DisplayHash(tableData);

    return 0;
}
