# include <stdio.h>
# include <stdlib.h>

/* Paranthesis matching is an Application of Stack where we see if the equation is balanced or not i.e.
 The paranthesis are coupled well or not in that equation
   
 * The procedure is...

    When we find an opening Paranthesis, We Push it into the stack 

    When we find a closing Paranthesis, We Pop the Opening paranthesis out of the stack 

 * The condition for a Balanced equation 
 
    1. While Popping, The stack should not Underflow ( means the stack should not be empty when we wanna pop )

    2. At End OF Expression ( EOE ), The stack must be empty

    # if these condition do not meet than the equation is unbalanced 
*/

struct STACK{
    int Size ; 
    // Size of the stack should be equal to the total number of characters in the stack so 
    // that our stack will not over flow if we continue to push elements

    int index;

    char * ptr;
    // Pointer to allocate memory for our stack dynamically from heap ! 
    // Here the ptr will be in char because we are going
    // to push and store paranthesis which is considered chat and not integer type
};

// REQUIRED FUNCTIONS
int Is_Full( struct STACK *stack );
int Is_Empty( struct STACK * stack );
struct STACK * PUSH( struct STACK * stack, char value );
char POP( struct STACK * stack );

// FUNCTION FOR PARANTHESIS MATCHING

int PARANTHESIS_MATCH(struct STACK * stack, char * expression ){

    struct STACK * S = stack;

    for( int i=0 ; expression[i] != '\0' ; i++){   // '\0' denotes the NULL 
        // This condition will run until the expression char is not equal to NULL

        if( expression[i] == '(' )
        {
            PUSH( stack , '(');  
        }
        // Logic is that 
        // If the char of expression is equal to the opening Paranthesis '(' then we will push it into stack

        else if( expression[i] == ')')
        {
            if( Is_Empty(stack)){   // If the stack is already empty, so we cannot pop anything
                return 0;
            }
            // if it is empty, return function will take the compiler out
            // if it is not empty than we will perform POP
            else{
                POP( stack );
            }
        }
        // Logic is that
        // If the Char of expression is equal to the Closing Paranthesis ')' then we will Pop out of stack
        

    }
    
    // CONDITION FOR CHECKING MATCHING
    if(Is_Empty( stack )){ 
        return 1;   // if the stack is empty then the paranthesis is matched
    }
    else{
        return 0;   // if the stack is not empty then the paranthesis is not matched
    }

}

int main(){

    struct STACK * A;

    A->Size = 100;  // Considering that the Expression have less than 100 char in it 
    A->index = -1;
    A->ptr = ( char * ) malloc ( A->Size * sizeof(char));

    // NOW WE WILL MAKE OUR EXPRESSION 

    char * exp1 = "3*(1)+(4";

    char * exp2 = "3*(1)+(4)*(1)*(1)*(1)*(1)*(1))))";

    char * exp3 = "(9)*(8+3)*(100)";

    char * exp4 = "((8)*(9))";

    char * exp5 = "(1)";


    if( PARANTHESIS_MATCH ( A , exp4 )){
        printf("\n\n\n\t ! ! ! THE PARANTHESIS ARE BALANCED ! ! !\n\n\n");
    }
    else{
        printf("\n\n\n\t ! ! ! THE PARANTHESIS ARE   N O T   BALANCED ! ! !\n\n\n");
    }


// * NOTE THAT THIS PARATHESIS MATCH APPLICATION JUST TELLS ABOUT BALANCING AND NOT ABOUT *VALIDITY* OF EXPRESSION




    return 0;
}


int Is_Full( struct STACK * stack ){
    if( stack-> index == stack-> Size -1 ){
        return 1;
    }
    else{
        return 0;
    }
}
int Is_Empty( struct STACK * stack ){
    if( stack->index == -1){
        return 1;
    }
    else{
        return 0;
    }
}
struct STACK * PUSH( struct STACK * stack, char value ){
    if( Is_Full(stack)){
        printf("\nSTACK OVERFLOW !\n\n");
    }
    else{
        stack->index++;
        stack->ptr[stack->index] = value;
        //printf("\n\t SUCCESSFULLY PUSHED %c\n", value);
    }
}

char POP( struct STACK * stack ){
    if( Is_Empty(stack)){
        printf("\nSTACK UNDERFLOW !\n\n");
    }
    else{
        char x = stack->ptr[stack->index];
        stack->index--;
        //printf("\n\t SUCCESSFULLY POPPED %c\n",x);
        return x;
    }

}


    