#ifndef _SPARSE_POLYNOMIAL_LINKED_LIST_H
#define _SPARSE_POLYNOMIAL_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int coefficient;
    int exponent;
} Term;

typedef struct PolynomialLinkedList {
    Term term;
    struct PolynomialLinkedList *next;
} PolynomialLinkedList;

PolynomialLinkedList *createPolynomialLinkedList();

#endif
