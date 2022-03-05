# include<stdio.h>

// REMINDER IS THAT THIS IS GONNA BE DIFFICULT TO UNDERSTAND

/*
*    THE QUICK SORT ARRAY WORKS ON PARTITION METHOD IN WHICH 
*    
*    1.  AN ARRAY GETS DIVIDED INTO INTO TWO PARTS FROM AN INDEX SELECTED BY THE CONDITION
*        AND THAT INDEX IS CALLED AS *REFERENCE* !
*
*    2.  THEN FROM THAT REFERENCE WE MAKE TWO PARTITIONS OF THAT ARRAY AND WE TAKE 
*        HIGH AND LOW INDEXES OF EACH SUB ARRAY EXCLUDING THE REFERENCE FROM EACH SO 
*
?            A. FOR SUB ARRAY 1, THE LOW IS INDEX ' 0 ' AND THE HIGH IS INDEX 'REFERENCE-1' (since we are not taking reference)
?            B. FOR SUB ARRAY 2, THE LOW IS ' REFERENCE + 1' AND HIGH IS INDEX ' SIZE - 1 '
*
*    3.  IN EACH PARTITION OF SUB ARRAY, TWO POINTER i AND j WILL BE CREATED WHERE
*
?            A. POINTER i WILL START FROM LOW/NEAR REF - TO SEARCH THE NUMBER GREATER THAN REFERENCE 
?            B. POINTER j WILL START FROM HIGH/FARTHEST FROM REF - TO SEARCH THE NUMBER SMALLER THAN REFERNCE
*
*    4.  IF i FINDS A GREATER NUMBER AND j FINDS A SMALLER NUMBER THAN
*    
?            A. IF i < j, THEN THE ELEMENTS AT THE INDEX OF i AND j WILL SWAP
?            B. IF i >= j, THEN THE ELEMENT OF j WILL SWAP WITH THE ELEMENT OF REFERENCE    
*
*    THIS PROCESS WILL CONTINUE AND THE REF, HIGH, LOW WILL CHANGE IN EACH PARTITION UNTIL THE ARRAY IS SORTED
*/

// FUNCTION TO PRINT THE ARRAY
int array( int arr[], int size ){
    int i =0;
    while( i < size ){
        printf("  %d ", arr[i]);
        i++;
    }

}

//  WE WILL WRITE TWP FUNCTION FOR THE QUICKSORT, FIRST IS THE MAIN QUICKSORT AND SECOND IS PARTITION FUNCTION

int PARTITION( int arr[], int low , int high ){

    int ref = arr[low];
    int t; // for swap

    int i = low + 1 ;
    int j = high;


    do{
        while( arr[i] < ref ){ // since i finds the number greater than the reference so if the element is smaller than ref the move to next element
            i++;
        }

        while( arr[j] > ref ){ // since j finds the number smaller than reference so if the elemnet is smaller than reference than move to next element by drecrement cuz j runs in oppostite of i
            j--;
        }

        if( i < j ){
            t = arr[i];
            arr[i]= arr[j];
            arr[j]=t;
        }

    } while( i < j );

    // ABOVE CONDTION WILL RUN AS LONG AS i IS SMALLER THAN J BUT WHEN j WILL CROSS i AND BECOME SMALLER THAN i 
    // THEN WE WILL SWAP ELEMENT OF j WITH REFERENCE

    t = arr[low];
    arr[low] = arr[j];
    arr[j]= t;

    return j;
}

int QUICK_SORT( int arr[] , int low , int high ){

    int Partition_Index ; // Index of the reference after the partition 

    if ( low < high ){

        Partition_Index = PARTITION( arr  , low , high );

        QUICK_SORT( arr , low , Partition_Index-1 ); // for LEFT SUB ARRAY         
        QUICK_SORT( arr , Partition_Index + 1 , high  ); // for RIGHT SUB ARRAY
    }


}


int main(){

    int A[]= {30 , 20, 50, 10, 90, 100 , 60, 80, 70, 40};

    int size = 10;

    printf(" THE ARRAY BEFORE SORTING IS : ");
    array( A, size );
    printf("\n\n");
    QUICK_SORT( A , 0 , size - 1 ); // low is 0 index and highest index is size -1 

    printf(" THE ARRAY AFTER  SORTING IS : ");
    array( A, size );
    printf("\n\n");

    return 0;
}