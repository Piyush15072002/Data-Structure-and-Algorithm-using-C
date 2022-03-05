# include <stdio.h>
# include <stdlib.h>

struct STACK{
    int Size;
    int Top;
    int * ptr;
};

// To Perfrom PUSH and POP operation, We must check our stack whether if it is full or Empty 
// If it is full, It is STACK OVERFLOW and if it is empty, It is STACK UNDERFLOW
// When we write Code, we must check such situations as well

int FULL(struct STACK * stack);

int EMPTY(struct STACK * stack);

// WE HAVE CREATED THE FUNCTION TO CHECK FOR STACK FLOWS, NOW WE WILL PERFORM POP
// TO PERFORM POP, WE MUST PUSH THE ELEMENTS TO OUR STACK FIRST 

int PUSH ( struct STACK * stack, int value);

// Now we will code for POP function

int POP( struct STACK * stack){
    // We don't need any value from user to pop here cuz stack can only pop the topmost element

    if( EMPTY(stack)){
        printf("\n\t                 !!! STACK UNDERFLOW !!!\n\tSORRY, WE CANNOT REMOVE FROM STACK BECAUSE IT IS EMPTY");
        return -1;
    }
    else{
        // To remove the top element, first we have to shift the value of that element to a variable
        // So that we can decrease Top and will not loose the element

        int To_Be_Popped = stack -> ptr[stack->Top];    // since pop can happen only to the topmost element
        // Now the value of that element is stored in the New variable we made
        // Now we will decrease the top to pop that element

        stack-> Top--; //  stack-> Top = stack-> Top - 1

        return To_Be_Popped;

    }
}


int main(){

    // Now we will make a Pointer which is called as Sptr ie. STRUCTURE POINTER
    // Sptr is a Pointer which will store the address of our structure;   

    struct STACK * Sptr;   // Pointer for STACK structure 

    Sptr =  (struct STACK *) malloc ( sizeof( struct STACK ) );   

    Sptr->Size = 10;
    Sptr->Top = -1; // Empty stack 
    Sptr->ptr = (int *) malloc ( Sptr->Size * sizeof( int ));
    
    // PUSHING ELEMENTS TO OUR STACK

    PUSH( Sptr , 10 );
    PUSH( Sptr , 20 );
    PUSH( Sptr , 30 );
    PUSH( Sptr , 40 );
    PUSH( Sptr , 50 );
    PUSH( Sptr , 60 );
    PUSH( Sptr , 70 );
    PUSH( Sptr , 80 );
    PUSH( Sptr , 90 );
    PUSH( Sptr , 100 );

    // Now we will POP the ELEMENTS

    printf("    POPPED ELEMENT :  %d\n", POP( Sptr));
    // IF THE STACK IS NOT EMPTY THEN ONE ELEMENT WILL BE POPPED AND 
    // SINCE THE FUNCTION RETURNS TO_BE_POPPED VARIABLE AND THAT'S WHAT IT WILL RETURN HERE WHEN WE CALL IT

    printf("    POPPED ELEMENT :  %d\n", POP( Sptr));
    printf("    POPPED ELEMENT :  %d\n", POP( Sptr));
    printf("    POPPED ELEMENT :  %d\n", POP( Sptr));
    printf("    POPPED ELEMENT :  %d\n", POP( Sptr));
    printf("    POPPED ELEMENT :  %d\n", POP( Sptr));
    printf("    POPPED ELEMENT :  %d\n", POP( Sptr));
    printf("    POPPED ELEMENT :  %d\n", POP( Sptr));
    printf("    POPPED ELEMENT :  %d\n", POP( Sptr));
    printf("    POPPED ELEMENT :  %d\n", POP( Sptr));

    // NOW OUR STACK IS EMPTY AND SO WE CANNOT POP, IF WE RUN FUNCTION, IT WILL TELL US THAT STACK IS UNDERFLOWED

    POP( Sptr);

    return 0;
}

int FULL( struct STACK * stack){
    if(stack->Top == stack->Size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int EMPTY(struct STACK * stack){
    if(stack->Top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int PUSH ( struct STACK * stack, int value){
    if(FULL(stack)){    // If it returns is 1 
        printf("\n\t         !!!STACK OVERFLOW !!!\n\n\t SORRY ! WE CANNOT ADD %d TO THE STACK", value);
    }
    else{ 
        // Now we will increment Top so that we can Push our element to that top index 
        stack -> Top++;

        // Now we will Push the element to the INDEX OF OUR NEW TOP using POINTER
        stack -> ptr[stack->Top] = value;   // ptr[stack->Top] can be written as ptr[0] or ptr[1] and so on

        // The logic is Before we Push any element, We must arrange space for it in our stack so that we can put it there
        // We Use top to arrange space for that element on top of the Stack by incrementing
        // Then we tell Pointer to put that VALUE in place of incremented Top
    }
}