# include <stdio.h>
# include <stdlib.h>

struct STACK{
    int Size;   // SIZE OF THE STACK
    int Top;    // TOP ELEMENT OF THE STACK ( FOR OPERATIONS LIKE PUSH, POP, ETC)
    int *ptr;   // POINTER THAT REQUEST MEMORY FROM THE HEAP FOR OUR STACK
};

    /* The Stack Performs LIFO and so it needs a top to traverse the stack or perform any Operations
       For such cases we have Index for element of the stack
       if the stack is EMPTY, index is -1 
       The first element of the stack have index of 0, 1, 2 and so on */

int main(){

    // struct STACK A;

    // A.Size = 100;
    // A.Top =  -1;
    // A.ptr = (int *) malloc (A.Size * sizeof(int));

    // We can use the above code as well but if we make a pointer like below, it would be much easier to perform stack operations

    struct STACK * A;

    A->Size = 100;  // Size of stack A is  100
    A->Top =  -1;   // The Top element index is -1 which shows that the STACK IS EMPTY
    A->ptr = (int *) malloc (A->Size * sizeof(int));    // Request memory from heap for our stack

    return 0;
}