# include <stdio.h>
# include <stdlib.h>

struct STACK{
    int Size;   // SIZE OF THE STACK
    int Top;    // TOP ELEMENT OF THE STACK ( FOR OPERATIONS LIKE PUSH, POP, ETC)
    int *ptr;   // POINTER THAT REQUEST MEMORY FROM THE HEAP FOR OUR STACK
};

// Before we do Push and Pop, We must know/check if the stack is empty or full 
// Now i will write functions to check if the stack is full or empty

int Is_Empty( struct STACK * stack ){

    if( stack->Top == -1 ){
        return 1;   // Successful
    }
    else{
        return 0;   // Unsuccessful
    }
}

int Is_Full( struct STACK * stack ){

    // The stack will be full if the top of the stack is equals to the size of the stack 
    // if the size is 100 than since we start the indexing from 0 so the number of elements will be N-1 => 99

    if( stack-> Top == stack->Size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    struct STACK * A;

    A->Size = 100;  // Size of stack A is  100
    A->Top =  -1;   // The Top element index is -1 which shows that the STACK IS EMPTY
    A->ptr = (int *) malloc (A->Size * sizeof(int));    // Request memory from heap for our stack

    // *** PUSHING AN ELEMENT MANUALLY INTO STACK 

    A->ptr[0]= 10;   // The first element is 10 with index 0

    A->Top++; // Since we pushed, Now stack isn't empty and hence cannot be -1 and so we Increased it by 1 i.e top=0
    

    // ***CHECKING IF THE STACK IS EMPTY OR NOT 

    if( Is_Empty(A) ){  // If the function returned 1, then it is true 
        printf("THE STACK IS EMPTY\n");
    }
    else{               // If the function returned 0, then it is false and fall in else condition
        printf("THE STACK IS NOT EMPTY\n");
    }


    // *** CHECKING IF THE STACK IS FULL

    if( Is_Full(A)){ // If function return 1 for success than stack will be full
        printf("THE STACK IS FULL\n");
    }
    else{
        printf("THE STACK IS NOT fULL\n"); // If the function returns 0 for unsuccessful that means stack isn't full
    }


    // Some coding to make the program better for user to understand

    if( Is_Empty(A)== 0 && Is_Full(A) == 0){
        printf("\nTHE STACK IS READY TO PERFORM BOTH PUSH AND POP OPERATIONS\n");
    }
    else if( Is_Empty(A)==1 && Is_Full(A)==0){
        printf("\nTHE STACK CANNOT PERFORM POP BUT CAN DO PUSH CUZ IT IS EMPTY");
    }
    else if( Is_Empty(A)==0 && Is_Full(A)==1){
        printf("\nTHE STACK CANNOT PERFORM PUSH BUT CAN DO POP CUZ IT IS FULL");
    }
    else{
        printf("\nTHERE IS AN ERROR WITH THE PROGRAM\nPLEASE CHECK IT AND RUN THE THE CODE AGAIN\n");
    }


    return 0;

    
}
