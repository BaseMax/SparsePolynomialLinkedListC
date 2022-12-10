# Sparse Polynomial Linked-List C

This is a C implementation of a sparse polynomial linked-list. This is a good example of how to use a linked-list in C. By using a linked-list, we can store a sparse polynomial in a memory efficient way. Sparse polynomials are polynomials that have a lot of terms with a coefficient of 0. For example, the polynomial `2x^3 + 3x^2 + 4x + 5` has 4 terms, but only 2 of them have a non-zero coefficient. This means that we can store this polynomial in a linked-list with only 2 nodes. This is a lot more memory efficient than storing the polynomial in an array.

## Structure

**Methods:**

- `PolynomialLinkedList *createPolynomialLinkedList()`: Create a Polynomial Linked List object
- `bool isEmpty(PolynomialLinkedList *polynomialLinkedList)`: Check if a Polynomial Linked List is empty
- `void addTerm(PolynomialLinkedList *polynomialLinkedList, Term term)`: Add a Term object
- `void printPolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList)`: Print a Polynomial Linked List object
- `void destroyPolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList)`: Destroy a Polynomial Linked List object
- `PolynomialLinkedList *addPolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList1, PolynomialLinkedList *polynomialLinkedList2)`: Add two Polynomial Linked List object
- `PolynomialLinkedList *subtractPolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList1, PolynomialLinkedList *polynomialLinkedList2)`: Subtract two Polynomial Linked List object
- `PolynomialLinkedList *multiplyPolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList1, PolynomialLinkedList *polynomialLinkedList2)`: Multiply two Polynomial Linked List object
- `PolynomialLinkedList *dividePolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList1, PolynomialLinkedList *polynomialLinkedList2)`: Divide two Polynomial Linked List object
- `float evaluatePolynomialLinkedList(PolynomialLinkedList *polynomialLinkedList, int x)`: Evaluate a Polynomial Linked List object

**Types:**

```c
typedef struct {
    int coefficient;
    int exponent;
} Term;

typedef struct PolynomialLinkedList {
    Term term;
    struct PolynomialLinkedList *next;
} PolynomialLinkedList;
```

## Example

```c
#include "SparsePolynomialLinkedList.h"

int main(int argc, char **argv)
{
    // Create polynomial linked list
    PolynomialLinkedList *polynomialLinkedList1 = createPolynomialLinkedList()`: 

    // Add term
    Term term1;
    term1.coefficient = 2;
    term1.exponent = 3;
    addTerm(polynomialLinkedList1, term1)`: 

    Term term2;
    term2.coefficient = 3;
    term2.exponent = 2;
    addTerm(polynomialLinkedList1, term2)`: 

    Term term3;
    term3.coefficient = 4;
    term3.exponent = 1;
    addTerm(polynomialLinkedList1, term3)`: 

    Term term4;
    term4.coefficient = 5;
    term4.exponent = 0;
    addTerm(polynomialLinkedList1, term4)`: 

    // Print polynomial linked list
    printPolynomialLinkedList(polynomialLinkedList1)`: 

    // Create polynomial linked list
    PolynomialLinkedList *polynomialLinkedList2 = createPolynomialLinkedList()`: 

    // Add term
    Term term5;
    term5.coefficient = 1;
    term5.exponent = 3;
    addTerm(polynomialLinkedList2, term5)`: 

    Term term6;
    term6.coefficient = 2;
    term6.exponent = 2;
    addTerm(polynomialLinkedList2, term6)`: 

    Term term7;
    term7.coefficient = 3;
    term7.exponent = 1;
    addTerm(polynomialLinkedList2, term7)`: 

    Term term8;
    term8.coefficient = 4;
    term8.exponent = 0;
    addTerm(polynomialLinkedList2, term8)`: 

    // Print polynomial linked list
    printPolynomialLinkedList(polynomialLinkedList2)`: 

    // Add two polynomial linked list
    PolynomialLinkedList *polynomialLinkedList3 = addPolynomialLinkedList(polynomialLinkedList1, polynomialLinkedList2)`: 
    printPolynomialLinkedList(polynomialLinkedList3)`: 

    // Subtract two polynomial linked list
    PolynomialLinkedList *polynomialLinkedList4 = subtractPolynomialLinkedList(polynomialLinkedList1, polynomialLinkedList2)`: 
    printPolynomialLinkedList(polynomialLinkedList4)`: 
    
    // Multiply two polynomial linked list
    PolynomialLinkedList *polynomialLinkedList5 = multiplyPolynomialLinkedList(polynomialLinkedList1, polynomialLinkedList2)`: 
    printPolynomialLinkedList(polynomialLinkedList5)`: 

    // Divide two polynomial linked list
    PolynomialLinkedList *polynomialLinkedList6 = dividePolynomialLinkedList(polynomialLinkedList1, polynomialLinkedList2)`: 
    printPolynomialLinkedList(polynomialLinkedList6)`: 

    // Print polynomial linked list
    printPolynomialLinkedList(polynomialLinkedList1)`: 

    // Evaluate a polynomial linked list
    float result = evaluatePolynomialLinkedList(polynomialLinkedList1, 2)`: 
    printf("Result: %f\n", result)`: 

    return 0;
}
```

## License

This project is licensed under the GPL-3.0 License - see the [LICENSE](LICENSE) file for details.

© Copyright 2022, Max Base
