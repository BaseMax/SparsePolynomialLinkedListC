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

int main(int argc, char **argv)
{
    // Create polynomial linked list
    PolynomialLinkedList *polynomialLinkedList1 = createPolynomialLinkedList();

    // Add term
    Term term1;
    term1.coefficient = 2;
    term1.exponent = 3;
    addTerm(polynomialLinkedList1, term1);

    Term term2;
    term2.coefficient = 3;
    term2.exponent = 2;
    addTerm(polynomialLinkedList1, term2);

    Term term3;
    term3.coefficient = 4;
    term3.exponent = 1;
    addTerm(polynomialLinkedList1, term3);

    Term term4;
    term4.coefficient = 5;
    term4.exponent = 0;
    addTerm(polynomialLinkedList1, term4);

    // Print polynomial linked list
    printPolynomialLinkedList(polynomialLinkedList1);

    // Create polynomial linked list
    PolynomialLinkedList *polynomialLinkedList2 = createPolynomialLinkedList();

    // Add term
    Term term5;
    term5.coefficient = 1;
    term5.exponent = 3;
    addTerm(polynomialLinkedList2, term5);

    Term term6;
    term6.coefficient = 2;
    term6.exponent = 2;
    addTerm(polynomialLinkedList2, term6);

    Term term7;
    term7.coefficient = 3;
    term7.exponent = 1;
    addTerm(polynomialLinkedList2, term7);

    Term term8;
    term8.coefficient = 4;
    term8.exponent = 0;
    addTerm(polynomialLinkedList2, term8);

    // Print polynomial linked list
    printPolynomialLinkedList(polynomialLinkedList2);

    // Add two polynomial linked list
    PolynomialLinkedList *polynomialLinkedList3 = addPolynomialLinkedList(polynomialLinkedList1, polynomialLinkedList2);
    printPolynomialLinkedList(polynomialLinkedList3);

    // Subtract two polynomial linked list
    PolynomialLinkedList *polynomialLinkedList4 = subtractPolynomialLinkedList(polynomialLinkedList1, polynomialLinkedList2);
    printPolynomialLinkedList(polynomialLinkedList4);

    return 0;
}
