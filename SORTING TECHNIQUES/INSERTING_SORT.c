# include<stdio.h>

/* 
    AS WE ALREADY LEARNT ABOUT THE THEORY OF THE INSERTION SORT, NOW WE WILL DIVE INTO SOME CODING
    INSERTION SORT INSERTS AN ELEMENT INTO SORTED ARRAY AND ARRAGE IT IN A WAY SO THAT THE SORTING IS NOT DISTURBED
*/


// FUNCTION TO PRINT THE ARRAY
int array( int arr[], int size ){
    int i =0;
    while( i < size ){
        printf("  %d ", arr[i]);
        i++;
    }
    printf("\n\n");
}

// * INSERTION SORT FUNCTION 

int INSERTION_SORT( int arr[] , int size ){
    int num , j;
    for( int i = 1; i <= size - 1 ; i ++){   // for loop for the PASSES

        // arr[0] is already in the sorted section and so we will not start the loop from 0 but from 1
        // so that we can access arr[1] straight for insertion

        num = arr[i];   // Element that we are gonna insert 
        j = i-1;        // Last element of the sorted section that is why i-1 cuz the next inserting number is next to the last element of sorted list

        while( arr[j] > num && j > -1 ){ // true if the last element of the sorted list is greater than the inserting number
            
            arr[j+1]= arr[j];
            // since the last element of sorted array is bigger than the inserting element,
            /// so it will move one step back to make space for the inserting element

            j--; // j-- cuz if the last element of sorted array is bigger than the inserting element 
            // than the element will check the second last element and if that is bigger also than the third last element and 
            // this will continue until the inserting element find a spot where the sorted element is smaller than it
        } 

        arr[j+1]=num; 
        // if the inserting element is the largest in the sorted list, 
        // then it will just get inserted at last which is its own position arr[i] or arr[j+1]      

    }


}


int main(){

    int A[]= { 2, 1, 5, 9, 7, 6};
    
    int size = 6;

    printf("\nTHE ARRAY BEFORE SORTING IS : ");
    array( A , size );

    INSERTION_SORT( A , size );

    printf("\nTHE ARRAY AFTER SORTING IS : ");
    array( A , size ); 


    return 0;
}


