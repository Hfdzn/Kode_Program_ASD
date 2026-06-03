#include <iostream>
#include <string>
using namespace std;

#define MaxVertex 5

struct EdgeNode {
    int destVertex;
    EdgeNode *next;
};

struct GraphList {
    EdgeNode* firstEdge[MaxVertex];
    string vertices[MaxVertex];
    int numVertices;
};

void CreateEmpty(GraphList *G) {
    G->numVertices = 0;
    for (int i = 0; i < MaxVertex; i++) {
        G->firstEdge[i] = nullptr;
    }
}

void AddVertex(GraphList *G, string name) {
    if (G->numVertices < MaxVertex) {
        G->vertices[G->numVertices] = name;
        G->numVertices++;
    }
}

EdgeNode *Allocation(int dest) {
    EdgeNode *P = new EdgeNode;
    if (P != nullptr) {
        P->destVertex = dest;
        P->next = nullptr;
    }
    return P;
}

void AddEdge(GraphList *G, int src, int dest) {
    if (G->numVertices >= MaxVertex) return;
    EdgeNode* P1 = Allocation(dest);
    P1->next = G->firstEdge[src];
    G->firstEdge[src] = P1;

    EdgeNode* P2 = Allocation(src);
    P2->next = G->firstEdge[dest];
    G->firstEdge[dest] = P2;
}

void DisplayGraphList(GraphList *G) {
    for (int i = 0; i < G->numVertices; i++) {
        cout << "[" << G->vertices[i] << "] berteman dengan: ";

        EdgeNode *temp = G->firstEdge[i];
        while (temp != nullptr) {
            cout << G->vertices[temp->destVertex] << " -> ";
            temp = temp->next;
        }

        cout << endl;
    }
}

int main() {
    GraphList jaringanSosial;
    CreateEmpty(&jaringanSosial);

    AddVertex(&jaringanSosial, "Hafidzon");
    AddVertex(&jaringanSosial, "Alif");
    AddVertex(&jaringanSosial, "Farell");
    AddVertex(&jaringanSosial, "Gilang");

    AddEdge(&jaringanSosial, 0, 1);
    AddEdge(&jaringanSosial, 0, 2);
    AddEdge(&jaringanSosial, 1, 3);
    AddEdge(&jaringanSosial, 2, 3);

    cout << "Daftar Graph List: " << endl;
    DisplayGraphList(&jaringanSosial);

    return 0;
}
