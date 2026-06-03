#include <ios>
#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *left;
    Node *right;
};

// Membuat Node
Node *AlokNode(int x) {
    Node *P = new Node;
    if (P != nullptr) {
        P->info = x;
        P->left = P->right = nullptr;
    }
    return P;
}

// Membuat Tree
Node *Tree(int x, Node *L, Node *R) {
    Node *P = AlokNode(x);
    if (P != nullptr) {
        P->left = L;
        P->right = R;
    }
    return P;
}

bool isTreeEmpty(Node *P) {
    return P == nullptr;
}

bool isTreeOneElmt(Node *P) {
    return P != nullptr && P->left == nullptr && P->right == nullptr;
}

bool isUnerLeft(Node *P) {
    return P != nullptr && P->left != nullptr && P->right == nullptr;
}

bool isUnerRight(Node *P) {
    return P != nullptr && P->left == nullptr && P->right != nullptr;
}

bool isBiner(Node *P) {
    return P!= nullptr && P->left != nullptr && P->right != nullptr;
}

int NbElmt(Node *P) {
    if (isTreeEmpty(P)) return 0;
    return 1 + NbElmt(P->left) + NbElmt(P->right);
}

int NbDaun(Node *P) {
    if (isTreeEmpty(P)) return 0;
    if (isTreeOneElmt(P)) return 1;
    return NbDaun(P->left) + NbDaun(P->right);
}

int Level(Node *P) {
    if (isTreeEmpty(P)) return 0;

    int tLeft = Level(P->left);
    int tRight = Level(P->right);

    if (tLeft >= tRight) {
        return 1 + tLeft;
    } else {
        return 1 + tRight;
    }
}

bool SearchTree(Node *P, int x) {
    if (isTreeEmpty(P)) return false;
    if (P->info == x) return true;
    return SearchTree(P->left, x) || SearchTree(P->right, x);
}

bool SearchDaun(Node *P, int x) {
    if (isTreeEmpty(P)) return false;
    if (isTreeOneElmt(P)) {
        if (P->info == x) {
            return true;
        } else {
            return false;
        }
    }

    if (isUnerLeft(P)) {
        return SearchDaun(P->left, x);
    } else if (isUnerRight(P)) {
        return SearchDaun(P->right, x);
    } else if (isBiner(P)) {
        return SearchDaun(P->left, x) || SearchDaun(P->right, x);
    }

    return false;
}

void DelDaunTerkiri(Node *&P) {
    if (isTreeEmpty(P)) return;
    if (isTreeOneElmt(P)) {
        Node *PDel = P;
        P = nullptr;
        delete PDel;
        return;
    }

    if (isUnerLeft(P) || isBiner(P)) {
        DelDaunTerkiri(P->left);
    } else if (isUnerRight(P)) {
        DelDaunTerkiri(P->right);
    }
}

void DelDaunTerkanan(Node *&P) {
    if (isTreeEmpty(P)) return;
    if (isTreeOneElmt(P)) {
        Node *PDel = P;
        P = nullptr;
        delete PDel;
        return;
    }

    if (isUnerRight(P) || isBiner(P)) {
        DelDaunTerkanan(P->right);
    } else if (isUnerLeft(P)) {
        DelDaunTerkanan(P->left);
    }
}

bool isSkewLeft(Node *P) {
    if (isTreeEmpty(P)) return false;
    if (isTreeOneElmt(P)) return true;
    if (isUnerLeft(P)) {
        return isSkewLeft(P->left);
    } else {
        return false;
    }
}

bool isSkewRight(Node *P) {
    if (isTreeEmpty(P)) return false;
    if (isTreeOneElmt(P)) return true;
    if (isUnerRight(P)) {
        return isSkewRight(P->right);
    } else {
        return false;
    }
}

bool isPerfectSkew(Node *P) {
    return isSkewLeft(P) || isSkewRight(P);
}

// Akar -> Kiri -> Kanan
void PreOrder(Node *P) {
    if (P != nullptr) {
        cout << P->info << " ";
        PreOrder(P->left);
        PreOrder(P->right);
    }
}

// Kiri -> Akar -> Kanan
void InOrder(Node *P) {
    if (P != nullptr) {
        InOrder(P->left);
        cout << P->info << " ";
        InOrder(P->right);
    }
}

// Kiri -> Kanan -> Akar
void PostOrder(Node *P) {
    if (P != nullptr) {
        PostOrder(P->left);
        PostOrder(P->right);
        cout << P->info << " ";
    }
}
int main() {

    // === CONTOH TREE ===
    //       (6)
    //       / \
    //     (9) (7)
    //     /
    //   (3)
    //   / \
    // (2) (5)

    Node *dua = Tree(2, nullptr, nullptr);
    Node *lima = Tree(5, nullptr, nullptr);
    Node *tiga = Tree(3, dua, lima);
    Node *sembilan = Tree(9, tiga, nullptr);
    Node *tujuh = Tree(7, nullptr, nullptr);

    // Root
    Node *enam = Tree(6, sembilan, tujuh);

    cout << "Hasil Pre-Order: ";
    PreOrder(enam);

    cout << "\nHasil In-Order: ";
    InOrder(enam);

    cout << "\nHasil Post-Order: ";
    PostOrder(enam);

    int totalNode = NbElmt(enam);
    cout << "\nTotal Node: " << totalNode;

    int totalDaun = NbDaun(enam);
    cout << "\nTotal Daun: " << totalDaun;

    int levelDaun = Level(enam);
    cout << "\nLevel Pohon: " << levelDaun;

    // "1" = True; "2" = False;
    cout << "\nSearch 9: " << boolalpha << SearchTree(enam, 9);

    cout << "\nSearch 5 (Daun): " << boolalpha << SearchDaun(enam, 5);

    DelDaunTerkiri(enam);
    cout << "\nSetelah Menghapus Daun Paling Kiri (2): ";
    PreOrder(enam);

    return 0;
}
