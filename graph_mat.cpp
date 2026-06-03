#include <iostream>
#include <string>
using namespace std;

#define MaxVertex 5

struct GraphMat {
    int matrix[MaxVertex][MaxVertex];
    string vertices[MaxVertex];
    int numVertices;
};

void CreateEmpty(GraphMat *G) {
    G->numVertices = 0;
    for (int i = 0; i < MaxVertex; i++) {
        for (int j = 0; j < MaxVertex; j++) {
            G->matrix[i][j] = 0;
        }
    }
}

void AddVertex(GraphMat *G, string name) {
    if (G->numVertices < MaxVertex) {
        G->vertices[G->numVertices] = name;
        G->numVertices++;
    }
}

void DisplayMatrix(GraphMat *G) {
    cout << "    ";
    for (int i = 0; i < G->numVertices; i++) {
        cout << "[" << i << "] ";
    }
    cout << endl;

    for (int i = 0; i < G->numVertices; i++) {
        cout << "[" << i << "]  ";
        for (int j = 0; j < G->numVertices; j++) {
            cout << G->matrix[i][j] << "   ";
        }
        cout << endl;
    }
}

void DisplayConnected(GraphMat *G) {
    if (G->numVertices <= 0) {
        cout << "Peta Kosong!" << endl;
        return;
    }

    for (int i = 0; i < G->numVertices; i++) {
        for (int j = i + 1; j < G->numVertices; j++) {
            if (G->matrix[i][j] == 1) {
                cout << G->vertices[i] << " <-> " << G->vertices[j] << " terhubung." << endl;
            }
        }
    }
}

void AddEdge(GraphMat *G, int src, int dest) {
    // Graf Tak Berarah
    G->matrix[src][dest] = 1;
    G->matrix[dest][src] = 1;
}

int main() {
    GraphMat petaJalan;
    CreateEmpty(&petaJalan);

    AddVertex(&petaJalan, "Lampung");
    AddVertex(&petaJalan, "Palembang");
    AddVertex(&petaJalan, "Krui");
    AddVertex(&petaJalan, "Jambi");
    AddVertex(&petaJalan, "Aceh");

    AddEdge(&petaJalan, 0, 1);
    AddEdge(&petaJalan, 1, 2);
    AddEdge(&petaJalan, 3, 1);

    DisplayConnected(&petaJalan);

    cout << "Display Matrix: " << endl;
    DisplayMatrix(&petaJalan);

    return 0;
}
