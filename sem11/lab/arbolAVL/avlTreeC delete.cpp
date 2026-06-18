/*
* nomPrograma: avlTreeC delete.cpp
* descripcion: Operaciones basicas de arbol AVL
*
*               TAREA
*
* 0. Analice el codigo, luego compile, ejecute y analice lois resutados
* 1. Compare esta implementacion con arbolAVLcc.cpp
* 2. Analice el uso de la clase Node
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
#include <bits/stdc++.h>


using namespace std;

// La clase se usa similar al struct de C
class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k){
        key    = k;
        left   = nullptr;
        right  = nullptr;
        height = 1;
    }
};

void createTree(Node **cab);
int height(Node *N);

Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
int getBalance(Node *N);
Node* insert(Node* node, int key);
Node * minValueNode(Node* node);
Node* deleteNode(Node* root, int key);
void preOrder(Node *root);

// Driver Code
int main()
{
    Node *root = nullptr;

    // Constructing tree given in the
    // above figure
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    cout << "Preorder traversal of the constructed AVL tree is \n";
    preOrder(root);

    root = deleteNode(root, 10);

    cout << "\nPreorder traversal after deletion of 10 \n";
    preOrder(root);

    //system("pause");
    return 0;
}


void createTree(Node **cab)
{
    *cab = NULL;
}

// A utility function to get the height
// of the tree
int height(Node *N)
{
    if (N == nullptr) {
        return 0;
    }
    return N->height;
}

// A utility function to right rotate subtree rooted with y
// Función para rotar a la derecha un subárbol con raíz en x
Node *rightRotate(Node *y)
{
    Node *x,*T2;
    x  = y->left;
    T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(height(y->left), height(y->right));
    // Fixed line below:
    x->height = 1 + max(height(x->left), height(x->right));

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// Función para rotar a la izquierda un subárbol con raíz en x
Node *leftRotate(Node *x)
{
    Node *y, *T2;
    y  = x->right;
    T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
    if (N == nullptr) {
        return 0;
    }
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{
    // 1. Perform the normal BST rotation
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else{
        if (key > node->key) {
            node->right = insert(node->right, key);
        }
        else { // Equal keys not allowed
            return node;
        }
    }

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get the balance factor of this
    // ancestor node to check whether this
    // node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // return the (unchanged) node pointer
    return node;
}

// Given a non-empty binary search tree,
// return the node with minimum key value
// found in that tree. Note that the entire
// tree does not need to be searched.
Node * minValueNode(Node* node)
{
    Node* current = node;

    // loop down to find the leftmost leaf
    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

// Recursive function to delete a node with
// given key from subtree with given root.
// It returns root of the modified subtree.
Node* deleteNode(Node* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == nullptr) {
        return root;
    }

    // If the key to be deleted is smaller
    // than the root's key, then it lies in
    // left subtree
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }

    // If the key to be deleted is greater
    // than the root's key, then it lies in
    // right subtree
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }

    // if key is same as root's key, then
    // this is the node to be deleted
    else {
        // node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else { // One child case
                Node *temp = root->left ? root->left : root->right;
            }
            delete root; // delete the current node
            return temp; // return the child to be linked to the parent
        }
        else {
            // node with two children: Get the
            // inorder successor (smallest in
            // the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's
            // data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == nullptr) {
        return root;
    }

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left), height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS
    // NODE (to check whether this node
    // became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// A utility function to print preorder
// traversal of the tree.
void preOrder(Node *root)
{
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

