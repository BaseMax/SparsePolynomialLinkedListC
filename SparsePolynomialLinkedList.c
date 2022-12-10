/**
 * 
 * @file SparsePolynomialLinkedList.c
 * @author Max Base (maxbasecode@gmail.com)
 * @brief Working with sparse polynomial with a linked list data structure.
 * @version 0.1
 * @date 2022-12-10
 * @repostiory https://github.com/BaseMax/SparsePolynomialLinkedListC
 * @copyright Copyright (c) 2022
 * 
 */
#include "SparsePolynomialLinkedList.h"

/**
 * @brief Create a Polynomial Linked List object
 * 
 * @return PolynomialLinkedList* 
 */
PolynomialLinkedList *createPolynomialLinkedList()
{
    PolynomialLinkedList *polynomialLinkedList = (PolynomialLinkedList *)malloc(sizeof(PolynomialLinkedList));
    polynomialLinkedList->next = NULL;
    return polynomialLinkedList;
}
