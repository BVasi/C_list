#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data_;
    struct Node* next_;
}Node;

Node* first = NULL;
Node* current = NULL;