# include <stdio.h>

/* 
!   IF THE ARRAY IS ALREADY SORTED, THEN THE NORMAL SORT WILL STILL HAVE TIME COMPLEXITY OF O(n^2)
!   SO TO MAKE OUR PROGRAM ADAPTIVE AND DECREASE ITS TIME COMPLEXITY IF THE ARRAY IS ALREADY SORTED 

*   WE WILL MAKE A VARIABLE AND IT COULD HAVE 2 VALUES , 0 AND 1
?   0 REPRESENTING ARRAY IS NOT SORTED
?   1 REPRESENTING ARRAY IS SORTED

*   WE WILL PUT VAR OUTSIDE J-FOR LOOP AS VALUE 1 
*   AND WE WILL PUT VAR INSIDE THE J-FOR LOOP AS VALUE 0

*   IF THE ARRAY IS UNSORTED THE LOOP J-FOR WILL RUN AND THE VAR WILL BECOME 0 MEANING THE ARRRAY IS NOT SORTED
*   IF THE J-FOR DOESN'T RUN, MEANS ARRAY IS SORTED AND IT WILL RETURN OUT OF THE LOOP SAVING THE TIME
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

    int t;   // FOR SWAPPING

    int SORTED ;    // 0 IS UNSORTED , 1 IS SORTED

    for( int i=0; i < size-1 ; i++){    // for passes 

        SORTED = 1;   
     
        for ( int j=0; j < size - 1 - i ; j++){    // for internal comparison in each pass
            // the logic for size-1-i came from the fact that after each pass the comparison decrease by 0,1,2,etc
            // passes have comparison like size-2, size 3, etc 
            // so for size-2 => size-1-i ( i being 0,1,2,...but here i=1 ) = size-1-1 => size-2

            // IF THE FIRST ELEMENT IS BIGGER THAN SECOND MEANS THE ARRAY IS NOT SORTED AND THE IF LOOP WILL RU
            if( arr[ j ] > arr[ j+1 ] ){    
                // this means if the first element is greater than the second element

                // we can use the swap function here as well but for now we will keep the things simple
                t= arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;

                SORTED = 0; 
            }

        }

        if ( SORTED ){  // if the value of sorted is 1 , means the array is sorted, the loop will return
            return;     // if value is 0 means the array is not sorted and so the program will continue
        }

    }

}


int main(){
    
    int A[10]= { 1,2,3,4,5,6,7,8,9,10};

    int size = 10;

    // FUNCTION TO PRINT THE ARRAY

    printf("\n ARRAY BEFORE SORTING \n\n");
    ARRAY( A , size );

    BUBBLE_SORT( A , size );
    
    printf("\n ARRAY AFTER SORTING \n\n");
    ARRAY( A , size );


    return 0;
}

