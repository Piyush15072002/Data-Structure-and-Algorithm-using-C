# include <stdio.h>
# include <stdlib.h>

/*
The working of this program is same as the previous program of Paranthesis matching

*The various kinds of brackets are 
    1. Paranthesis - ()
    2. Square Brackets - []
    3. Curly Brackets - {}

In this program, The logic is that

*I. Push the Opening Bracket of any kind

*II. If Closing bracket is found then there are 2 condition to check
    !1. To see if the stack is empty and if it is, then the expression is not balanced since bracket is getting closed without opening

    !2. If the stack is not empty then we will check further two more conditions

        a. If the Closing bracket is equal to the Opening bracket of the Top of stack than Pop the Opening bracket of stack
            ? I Made a function for that on line 87, it will check is the opening bracket is of same kind as closing one or not

        b. Else if They aren't Equal than the Equation is not balanced since the Opening bracket didn't close and another braket came in between

*III.At last if the function continues since the case was 'a' ie. popped an element and expression ended
*    then we will check is the stack is empty or not

        a. If the stack is empty then the Expression is balanced

        b. If the stack is not empty that means opening bracket aren't closed and hence it is not balanced

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


// FUNCTION FOR BRACKET MATCHING 

int BRACKET_MATCH( struct STACK *stack , char * expression){


    // *! Now we will write the code for our balance checking

    for( int i = 0; expression[i] != '\0'; i++){
        if( expression[i] == '(' || expression[i]== '[' || expression[i]== '{'){
            PUSH( stack , expression[i]);   // Push the Expression[i] into the stack
        }   
        else if( expression[i]== ')' || expression[i]== ']' || expression[i]== '}'){
            if( Is_Empty(stack)){
                printf("stack is empty");
            }
            if( Match( stack , expression[i] ) ){   // Function on line 87
                POP( stack );
            }  
            else{
                return 0;
            }
        }             
    }

    if(Is_Empty(stack)){
        return 1;
    }
    else{
        return 0;
    }
}

int Match( struct STACK * stack , char * a ){
    char  b = a;
    if(b ==')' && stack->ptr[stack->index]=='('){
        return 1;
    }
    else if(b ==']' && stack->ptr[stack->index]=='['){
        return 1;
    }
    else if(b =='}' && stack->ptr[stack->index]=='{'){
        return 1;
    }
    else{
        return 0;
    }
}



int main(){

    
    // Creating a stack to store bracket
    struct STACK * stk;
    stk->Size = 100;
    stk->index = -1;
    stk->ptr = (char * ) malloc (stk->Size * sizeof(char));



    char * exp0 = "(2){8}";
    char * exp1 = "(2){8}}}";
    char * exp2 = "(}}}{}{}{}{}{}{}";
    char * exp3 = "(2)[5[3]]{142}";
    char * exp4 = "()";

    if (BRACKET_MATCH( stk , exp3 )){
        printf("\n\n\t!!! THE EXPRESSION IS BALANCED !!!\n\n");
    }
    else{
        printf("\n\n\t!!! THE EXPRESSION IS NOT BALANCED !!!\n\n");
    }


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
        stack->ptr[stack->index];
        stack->index--;
        //printf("\n\t SUCCESSFULLY POPPED %c\n",x);
    }

}