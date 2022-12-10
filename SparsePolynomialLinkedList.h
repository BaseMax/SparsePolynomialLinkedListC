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

/**
 * @brief Create a Polynomial Linked List object
 * 
 * @return PolynomialLinkedList* 
 */
PolynomialLinkedList *createPolynomialLinkedList();

/**
 * @brief Add a Term object
 * 
 * @param polynomialLinkedList 
 * @param term 
 */
void addTerm(PolynomialLinkedList *polynomialLinkedList, Term term);

/**
 * @brief Print a Polynomial Linked List object
 * 
 * @param polynomialLinkedList 
 */
void printPolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList);

/**
 * @brief Destroy a Polynomial Linked List object
 * 
 * @param polynomialLinkedList 
 */
void destroyPolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList);

/**
 * @brief Add two Polynomial Linked List object
 * 
 * @param polynomialLinkedList1 
 * @param polynomialLinkedList2 
 * @return PolynomialLinkedList* 
 */
PolynomialLinkedList *addPolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList1, PolynomialLinkedList *polynomialLinkedList2);

/**
 * @brief Subtract two Polynomial Linked List object
 * 
 * @param polynomialLinkedList1 
 * @param polynomialLinkedList2 
 * @return PolynomialLinkedList* 
 */
PolynomialLinkedList *subtractPolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList1, PolynomialLinkedList *polynomialLinkedList2);

#endif
