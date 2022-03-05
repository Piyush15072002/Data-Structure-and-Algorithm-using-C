# include <stdio.h>

// WE HAVE LEARNT THE THEORY OF BUBBLE SORT AND NOW WE WILL LEARN THE LOGIC OF ITS CODING

/* THE LOGIC IS 

*    1. FIRSTLY WE NEED AN ARRAY AND A VAR CONTAINING THE SIZE OF THE ARRAY
*
*    2. THEN WE WILL MAKE TWO FUNCTIONS
*
?        1.1 THE SWAP FUNCTION -> SWAP FUNCTION IS JUST THE HELPER OF OUR MAIN FUNCTION FOR BUBBLE SORT 
*
?        1.2 THE BUBBLE SORT -> THIS IS THE MAIN FUNCTION, THIS FUNCTION LOGIC IS
*
*            1.2.1 FIRST WE WILL START A FOR LOOP WHICH WILL ACT AS THE NUMBER OF PASSES FOR BUBBLE SORT
*                  IT WILL RUN SIZE-1 TIMES AS THE PASSES ARE N-1 FOR AN ARRAY OF SIZE N
*
*            1.2.2 THEN WE WILL MAKE ANOTHER FOR LOOP INSIDE OUR OLD FOR LOOP AND THIS FOR LOOP WILL ACT
*                  AS THE INTERNAL COMPISONS BETWEEN THE ELEMENT IN EACH PASS
*                  
*            1.2.3 LASTLY, WE WILL USE AN IF CONDITION INSIDE THE FOR-FOR LOOP FOR
*                  "IF THE ELEMENT IS BIGGER THAN SWAP IT" CONCPEPT AND
*                   HERE WE WILL USE OUR SWAP FUNCTION AS WELL 
*/

// FUNCTION TO PRINT THE ELEMENTS OF THE ARRAY

void ARRAY( int  arr[] , int  size ){

    for( int i = 0 ; i < size ; i++){
        printf(" %d\t", arr[i]);
    }
    printf("\n");

}

// BUBBLE SORT

void BUBBLE_SORT( int  arr[] , int  size ){
    int t;
    for( int i=0; i < size-1 ; i++){    // for passes 
        
        for ( int j=0; j < size - 1 - i ; j++){    // for internal comparison in each pass
            // the logic for size-1-i came from the fact that after each pass the comparison decrease by 0,1,2,etc
            // passes have comparison like size-2, size 3, etc 
            // so for size-2 => size-1-i ( i being 0,1,2,...but here i=1 ) = size-1-1 => size-2

            if( arr[ j ] > arr[ j+1 ] ){    
                // this means if the first element is greater than the second element

                // we can use the swap function here as well but for now we will keep the things simple
                t= arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;

            }

        }

    }

}


int main(){
    
    int A[10]= { 100 , 90 , 80 , 70 , 60 , 50 , 40 , 30 , 20 , 10 };

    int size = 10;

    // FUNCTION TO PRINT THE ARRAY

    printf("\n ARRAY BEFORE SORTING \n\n");
    ARRAY( A , size );

    BUBBLE_SORT( A , size );
    
    printf("\n ARRAY AFTER SORTING \n\n");
    ARRAY( A , size );


    return 0;
}

