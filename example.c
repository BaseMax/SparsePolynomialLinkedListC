#include "SparsePolynomialLinkedList.h"

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
    
    // Multiply two polynomial linked list
    PolynomialLinkedList *polynomialLinkedList5 = multiplyPolynomialLinkedList(polynomialLinkedList1, polynomialLinkedList2);
    printPolynomialLinkedList(polynomialLinkedList5);

    // Divide two polynomial linked list
    PolynomialLinkedList *polynomialLinkedList6 = dividePolynomialLinkedList(polynomialLinkedList1, polynomialLinkedList2);
    printPolynomialLinkedList(polynomialLinkedList6);

    // Print polynomial linked list
    printPolynomialLinkedList(polynomialLinkedList1);

    // Evaluate a polynomial linked list
    float result = evaluatePolynomialLinkedList(polynomialLinkedList1, 2);
    printf("Result: %f\n", result);

    return 0;
}
