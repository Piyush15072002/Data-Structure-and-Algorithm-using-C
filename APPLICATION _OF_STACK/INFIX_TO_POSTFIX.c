// * THIS PROGRAM IS GIVING A MINOR ERROR WHEN PRINTING THE OPERATOR BUT IT'S DOING POST FIX

# include <stdio.h>
# include <stdlib.h>
# include <string.h>  // for the ' strlen ' function we used 
    
// COMPUTER TAKES MORE TIME WHEN IT COMES TO SOLVING THE INFIX PROBLEMS THAN THE PREFIX OR POSTFIX 
// AND SO WE ARE LEARNING HOW TO CONVERT THE INFIX TO THE POSTFIX
struct STACK{
    int Size ; 

    int index;

    char * ptr;

};

// REQUIRED FUNCTIONS
int Is_Full( struct STACK *stack );
int Is_Empty( struct STACK * stack );
struct STACK * PUSH( struct STACK * stack, char value );
char POP( struct STACK * stack );
int STACK_TOP(struct STACK * stack);


int Is_operator( char c){
    
    if( c == '/' || c == '*' || c == '+' || c == '-' ){
        return 1;
    }
    else{
        return 0;
    }
}

int Precedence( char  c){

    if( c== '*' || c=='/' ){ // highest precedence
        return 3;
    }
    else if( c=='+' || c=='-' ){ // second highest precedence
        return 2;
    }
    else{
        return 0;
    }

}


// NOW WE WILL WRITE THE FUNCTION FOR THE INFIX TO POSTFIX

char * INFIX_TO_POSTFIX( char * infix){

    
    struct STACK * stack=(struct STACK * ) malloc ( sizeof(struct STACK));
    stack->Size = 100;
    stack->index = -1;
    stack->ptr = (char * ) malloc (stack->Size * sizeof(char));

    // now we will make a char array for postfix which will allocate the memory for our postfix expression
    char * postfix = ( char *) malloc( (strlen( infix ) + 1 ) * sizeof(char)); // same size array as INFIX but this is empty

    // * Now we will make two counters to traverse both infix and postfix

    int i =0 ; // infix scanner
    int j =0 ; // postfix fill

    while( infix[i] != '\0'){ // Makes the loop run until the end of the expression

        if( !Is_operator( infix[i]) ){  // This condition means that if the infix element is not an operator ie. +,-,etc then get inside loop
            postfix[j]= infix[i] ;  // if the element is not an operator means it is an operand and hence we will put it in postfix stack
            i++; 
            j++; // now they will point to the next element of their respective infix and postfix stack
        }
        else{   // It will come here if the element is not an operand and hence is an operator
            char a= infix[i], b= STACK_TOP(stack);
            if( Precedence(a) > Precedence(b)){ 
                PUSH ( stack , infix[i]);
                i++;
            }
            else{
                postfix[j]= POP( stack);
                j++;
            }
        }

    }

    while( !Is_Empty( stack)){   // This will run till the stack is not empty
        postfix[j]= POP( stack );
        j++;
    }

    postfix[j]= '\0';

    return postfix;

}   


int main(){

    // INFIX 
    char * Infix = "a+b-t*g";
    
    printf("\n\nTHE POSTFIX IS %s\n\n", INFIX_TO_POSTFIX( Infix));


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
int STACK_TOP(struct STACK * stack){
    return stack -> ptr[stack->index];    
}