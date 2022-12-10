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

/**
 * @brief Add a Term object
 * 
 * @param polynomialLinkedList 
 * @param term 
 */
void addTerm(PolynomialLinkedList *polynomialLinkedList, Term term)
{
    PolynomialLinkedList *newNode = (PolynomialLinkedList *)malloc(sizeof(PolynomialLinkedList));
    newNode->term = term;
    newNode->next = NULL;
    PolynomialLinkedList *current = polynomialLinkedList;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

/**
 * @brief Print a Polynomial Linked List object
 * 
 * @param polynomialLinkedList 
 */
void printPolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList)
{
    PolynomialLinkedList *current = polynomialLinkedList->next;
    while (current != NULL)
    {
        printf("%dx^%d", current->term.coefficient, current->term.exponent);
        current = current->next;
        if (current != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

/**
 * @brief Destroy a Polynomial Linked List object
 * 
 * @param polynomialLinkedList 
 */
void destroyPolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList)
{
    PolynomialLinkedList *current = polynomialLinkedList;
    while (current != NULL)
    {
        PolynomialLinkedList *temp = current;
        current = current->next;
        free(temp);
    }
}

/**
 * @brief Add two Polynomial Linked List object
 * 
 * @param polynomialLinkedList1 
 * @param polynomialLinkedList2 
 * @return PolynomialLinkedList* 
 */
PolynomialLinkedList *addPolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList1, PolynomialLinkedList *polynomialLinkedList2)
{
    PolynomialLinkedList *polynomialLinkedList = createPolynomialLinkedList();
    PolynomialLinkedList *current1 = polynomialLinkedList1->next;
    PolynomialLinkedList *current2 = polynomialLinkedList2->next;
    while (current1 != NULL && current2 != NULL)
    {
        if (current1->term.exponent == current2->term.exponent)
        {
            Term term;
            term.coefficient = current1->term.coefficient + current2->term.coefficient;
            term.exponent = current1->term.exponent;
            addTerm(polynomialLinkedList, term);
            current1 = current1->next;
            current2 = current2->next;
        }
        else if (current1->term.exponent > current2->term.exponent)
        {
            addTerm(polynomialLinkedList, current1->term);
            current1 = current1->next;
        }
        else
        {
            addTerm(polynomialLinkedList, current2->term);
            current2 = current2->next;
        }
    }
    while (current1 != NULL)
    {
        addTerm(polynomialLinkedList, current1->term);
        current1 = current1->next;
    }
    while (current2 != NULL)
    {
        addTerm(polynomialLinkedList, current2->term);
        current2 = current2->next;
    }
    return polynomialLinkedList;
}

/**
 * @brief Subtract two Polynomial Linked List object
 * 
 * @param polynomialLinkedList1 
 * @param polynomialLinkedList2 
 * @return PolynomialLinkedList* 
 */
PolynomialLinkedList *subtractPolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList1, PolynomialLinkedList *polynomialLinkedList2)
{
    PolynomialLinkedList *polynomialLinkedList = createPolynomialLinkedList();
    PolynomialLinkedList *current1 = polynomialLinkedList1->next;
    PolynomialLinkedList *current2 = polynomialLinkedList2->next;
    while (current1 != NULL && current2 != NULL)
    {
        if (current1->term.exponent == current2->term.exponent)
        {
            Term term;
            term.coefficient = current1->term.coefficient - current2->term.coefficient;
            term.exponent = current1->term.exponent;
            addTerm(polynomialLinkedList, term);
            current1 = current1->next;
            current2 = current2->next;
        }
        else if (current1->term.exponent > current2->term.exponent)
        {
            addTerm(polynomialLinkedList, current1->term);
            current1 = current1->next;
        }
        else
        {
            Term term;
            term.coefficient = -current2->term.coefficient;
            term.exponent = current2->term.exponent;
            addTerm(polynomialLinkedList, term);
            current2 = current2->next;
        }
    }
    while (current1 != NULL)
    {
        addTerm(polynomialLinkedList, current1->term);
        current1 = current1->next;
    }
    while (current2 != NULL)
    {
        Term term;
        term.coefficient = -current2->term.coefficient;
        term.exponent = current2->term.exponent;
        addTerm(polynomialLinkedList, term);
        current2 = current2->next;
    }
    return polynomialLinkedList;
}
