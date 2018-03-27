#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    long long unsigned int key;
    struct Node *left;
    struct Node *right;
    int height;
} noh;

int height(struct Node *N);
int maximo(long long unsigned int a, long long unsigned int b);
struct Node* newNode(long long unsigned int key);
struct Node *rightRotate(struct Node *y);
struct Node *leftRotate(struct Node *x);
int getBalance(struct Node *N);
struct Node* insert(struct Node* node, long long unsigned int key);
void fprintfERD(FILE *fp, noh *tree);
short temRepeticao(noh* tree, long long unsigned int num);

#endif //AVL_H_INCLUDED
