/*
* nomPrograma:
* descripcion:
*
*
*
*
* autor:
* fecha:
* Version 1
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h> // libreria no standard
#include <string.h>

#define MAX_TREE_HT 100
#define MAX_CHARS 256

using namespace std;

// Nodo del árbol de Huffman
struct MinHeapNode {
    char data;
    unsigned frequency;
    struct MinHeapNode *left, *right;
};

// Estructura para la cola de prioridad (Min Heap)
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

struct MinHeapNode* newNode(char data, unsigned frequency);
struct MinHeap* createMinHeap(unsigned capacity);
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);
void minHeapify(struct MinHeap* minHeap, int idx);
struct MinHeapNode* extractMin(struct MinHeap* minHeap);
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode);
void buildMinHeap(struct MinHeap* minHeap);
int isLeaf(struct MinHeapNode* root);
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size);
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size);
void printCodes(struct MinHeapNode* root, int arr[], int top);
void HuffmanCodes(char text[]);
void encabezado0();
void raya1();
void raya2();

int main()
{
    char text[] = "estructura de datos";
    printf("Texto a procesar: \"%s\"\n\n", text);
    HuffmanCodes(text);

    //system("pause");
    return 0;
}




// Crear un nuevo nodo
struct MinHeapNode* newNode(char data, unsigned frequency)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->frequency = frequency;
    return temp;
}

// Crear un min heap de capacidad dada
struct MinHeap* createMinHeap(unsigned capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Intercambiar dos nodos del heap
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Reordenar el heap (Heapify)
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Extraer el nodo con el valor mínimo
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insertar un nuevo nodo en el min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Construir el min heap con todos los nodos iniciales
void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

// Verificar si el nodo es una hoja
int isLeaf(struct MinHeapNode* root)
{
    return !(root->left) && !(root->right);
}

// Crear un min heap e insertar todos los caracteres
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = newNode(data[i], freq[i]);
    }
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// Función principal que construye el árbol de Huffman
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Imprimir Letra, Frecuencia y Código recorriendo el árbol
void printCodes(struct MinHeapNode* root, int arr[], int top)
{
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        // Formato alineado: muestra el caracter, su frecuencia y su binario
        printf("   %-5c |   %-6d | ", root->data, root->frequency);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Automatizar el cálculo de frecuencias y detonar el árbol
void HuffmanCodes(char text[])
{
    int freq[MAX_CHARS] = {0};
    int len = strlen(text);

    for (int i = 0; i < len; i++) {
        freq[(unsigned char)text[i]]++;
    }

    char data[MAX_CHARS];
    int finalFreq[MAX_CHARS];
    int size = 0;

    for (int i = 0; i < MAX_CHARS; i++) {
        if (freq[i] > 0) {
            data[size] = (char)i;
            finalFreq[size] = freq[i];
            size++;
        }
    }

    struct MinHeapNode* root = buildHuffmanTree(data, finalFreq, size);
    int arr[MAX_TREE_HT], top = 0;

    // Encabezado de la tabla modificado
    printf(" Letra   |  Freq   | Código Huffman\n");
    printf("----------------------------------\n");
    printCodes(root, arr, top);
}

void encabezado0()
{
    char tit[] = "CODIGO DE FUFFMAN";
    char num[] = "No";
    char car[] = "Letra";
    char fre[] = "Frecuencia";
    char cod[] = "Codigo";
    printf("\n\t\t\t %s\n\n", tit);
    raya2();
    printf("%6s %10s %12s %12s\n",num,car,fre,cod);
    raya1();
}
void raya1()
{
    int i, n=40;
    for(i=0;i<n;i++){
        printf("-");
    }
    printf("\n");
}
void raya2()
{
    int i, n=40;
    for(i=0;i<n;i++){
        printf("=");
    }
    printf("\n");
}

