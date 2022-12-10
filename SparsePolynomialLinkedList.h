#ifndef _SPARSE_POLYNOMIAL_LINKED_LIST_H
#define _SPARSE_POLYNOMIAL_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int coefficient;
    int exponent;
} Term;

typedef struct Node {
    Term term;
    struct Node *next;
} PolynomialLinkedList;

PolynomialLinkedList *createPolynomialLinkedList();

#endif
