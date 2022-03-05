# include <stdio.h>
# include <stdlib.h>

struct STACK{
    int Size;
    int Top;
    int * ptr;
};

int FULL(struct STACK * stack);
int EMPTY(struct STACK * stack);
int PUSH ( struct STACK * stack, int value);

// STACK TOP IS THE TOPMOST ELEMENT OF THE STACK
// STACK BOTTOM IS THE BOTTOM MOST OR THE FIRST-in ELEMENT OF THE STACK

int STACK_TOP(struct STACK * stack){
    return stack -> ptr[stack->Top];    
}

int STACK_BOTTOM(struct STACK * stack){
    return stack -> ptr[0];
}

int main(){

    // Now we will make a Pointer which is called as Sptr ie. STRUCTURE POINTER
    // Sptr is a Pointer which will store the address of our structure;   

    struct STACK * Sptr;   // Pointer for STACK structure 

    Sptr =  (struct STACK *) malloc ( sizeof( struct STACK ) );   

    Sptr->Size = 10;
    Sptr->Top = -1; // Empty stack 
    Sptr->ptr = (int *) malloc ( Sptr->Size * sizeof( int ));

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
    
    // STACKTOP
    printf("\n\n\t***THE TOPMOST ELEMENT OF THE STACK IS %d ***\n\n", STACK_TOP(Sptr));

    // STACKBOTTOM
    printf("\n\n\t***THE BOTTOMMOST ELEMENT OF THE STACK IS %d ***\n\n", STACK_BOTTOM(Sptr));

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