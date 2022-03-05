# include<stdio.h>
# include<stdlib.h>

struct STACK {
    int size;
    int Top;
    int * ptr;
};
// PERFORMING BASIC STACK OPERATIONS BEFORE PEEKING

int EMPTY(struct STACK * stack );
int FULL(struct STACK * stack );
int PUSH(struct STACK * stack , int value);
int POP(struct STACK * stack );

// NOW WE WILL WRITE THE PEEK FUNCTION

int PEEK( struct STACK * stack , int i ){
    // here 'i' is the number of elements from the TOP To the BOTTOM of the stack
    // so the top element is 1, then second top is 2, third is 3 and so now and the last bottom element of the stack is Top-i+1
    // *** With Top-i+1 , we can get the index at which our i is pointing to

    int Position = stack->Top-i+1;

    if( Position < 0){  // if the postion given is going below index 0 that shows stack is empty so which would be wrong
        printf("\n\n\t I N V A L I D   P O S I T I O N \n\n");
    }
    else{
        return stack->ptr[Position];    
        // This will give us the Element at that position
        // the logic is... the position i is given by user which is converted to the stack index of that element using Top-i+1
        // Then after we get the stack index of that element, We return that element using ptr
        // *** GO TO LINE 63 FOR THE NEXT PART OF CODING FOR PEEKING
    }
}

int main(){

    struct STACK * a;
    a = (struct STACK *) malloc(sizeof(struct STACK));

    a->size= 10;
    a->Top=-1;
    a->ptr= (int *) malloc(a->size * sizeof(int));

    // PUSHING
    printf("\n\n. . . . . . . PUSHING ELEMENTS INTO THE STACK. . . . . . . . \n\n");
    printf("     THE PUSHED ELEMENT IS :  %d\n", PUSH( a , 10));
    printf("     THE PUSHED ELEMENT IS :  %d\n", PUSH( a , 20));
    printf("     THE PUSHED ELEMENT IS :  %d\n", PUSH( a , 30));
    printf("     THE PUSHED ELEMENT IS :  %d\n", PUSH( a , 40));
    printf("     THE PUSHED ELEMENT IS :  %d\n", PUSH( a , 50));
    printf("     THE PUSHED ELEMENT IS :  %d\n", PUSH( a , 60));
    printf("     THE PUSHED ELEMENT IS :  %d\n", PUSH( a , 70));
    printf("     THE PUSHED ELEMENT IS :  %d\n", PUSH( a , 80));

    // POPPING
    printf("\n\n. . . . . . . POPPING ELEMENTS OF THE STACK. . . . . . . . \n\n");
    printf("\n\n     THE POPPED ELEMENT IS :  %d\n", POP(a));
    printf("     THE POPPED ELEMENT IS :  %d\n", POP(a));
    printf("     THE POPPED ELEMENT IS :  %d\n\n", POP(a));

    // PEEKING INTO OUR STACK

    printf("\n\n..........P E E K I N G.............\n\n");
    for(int k = 1 ; k <= a->Top+1; k++){
        printf("     ELEMENT AT POSITION %d IS %d\n", k, PEEK( a , k));
    }

   return 0;
}

int EMPTY(struct STACK * stack){
    if(stack->Top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int FULL(struct STACK * stack ){
    if(stack->Top == stack->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int PUSH(struct STACK * stack , int value){
    if(FULL(stack)){
        printf("\n\n\t\tS T A C K  O V E R F L O W \n\n");
        return 1;
    }
    else{
        stack -> Top++;
        stack -> ptr[stack->Top] = value;  
    }
}

int POP(struct STACK * stack ){
    if(EMPTY(stack)){
        printf("\n\n\t\tS T A C K  U N D E R F L O W\n\n");
        return 1;
    }
    else{
        int var =  stack->ptr[stack->Top];
        stack->Top--;
        return var; // if we don't write this RETURN here, it wont tell us the element it removed
    }
}