# include<stdio.h>

/*
*    IN THE MERGE SORT, WE DIVIDE ONE ARRAY INTO ARRAYS WHCIH ARE SORTED AND THEN WE MERGE THEM
*    WHILE MERGING THEM WE MUST HAVE SOME CONCEPT CLEAR 
*
*    LETS CALL THE DIVIDED ARRAYS AS A1 AND A2 
*
*    WE WILL MAKE 3 POINTER I,J AND K WHERE I AND J WILL POINT TO THE FIRST ELEMENT OF EACH SUB ARRAY AND WILL TRAVERSE THEIR RESPECTIVE ARRAY
*    WHILE K POINTER WILL POINT TO THE NEW ARRAY WHERE WE WILL STORE OUR MERGED AND SORTED ARRAY
*
*    THEN FIRST ELEMENT OF BOTH THE SUB ARRAYS WILL COMPARE AND WHOEVER IS SMALLER WILL GET STORED IN OUR NEW ARRAY
*    LETS SAY ELEMENT I IS SMALLER THAN ELEMENT J, THEN WE WILL STORE I IN NEW ARRAY IN PLACE OF POINTER K
*
*    THEN WE WILL MOVE BOTH I AND K POINTER TO NEXT ELEMENT WHILE J WILL STAY AT SAME PLACE UNTIT J BECOMES SMALLER THAN I
*    WHEN THAT HAPPENS, J WILL GET STORED IN K AND BOTH J AND K WILL INCREMENT AND MOVE TO NEXT ELEMENT
*
*    THIS WILL CONTINUE UNTIL ELEMENT OF ONE SUB ARRAY ENDS,
*    IF OTHER ARRAY STILL HAVE ELEMENTS LEFT THAN THEY WILL GET ADDEED TO END OF  NEW ARRAY AUTOMATICALLY
*/


// FUNCTION TO PRINT THE ARRAY
int array( int  arr[] , int  size ){

    for( int i = 0 ; i < size ; i++){
        printf(" %d\t", arr[i]);
    }
    printf("\n");

}


// * FUNCTION TO MERGE THE ARRAYS ( THIS IS SUB PART OF THE MAIN FUNCTION OF MERGE SORT)

int MERGE(int arr[], int low , int mid , int high ){

    int i ; //  POINING TO THE ARRAY 1 
    int j ; //  POINING TO THE ARRAY 2

    int B[100] ; // ARRAY TO STORE THE ELEMENTS AFTER WE MERGE ARRAY 1 AND ARRAY 2
    int k ; //  POINING TO THE ARRAY B

    i = low ;       // first element of the sub array 1
    j = mid+1 ;     // first element of the sub array 2 
    //( remember that the array is divided into 2 from mid and so the subarray 2 will start after mid which is mid+1)

    k = low ; // k will point to the first/low element of the array B

    while( i <= mid && j <= high ){
        //* since our array A is divided into 2 subarrays from MID and so this loop will run until
        //*     i reaches the last element of its subarray which is mid and
        //*     j reaches the last element of its subarray which is high


        if( arr[i] < arr[j] ){

            B[k] = arr[i];  // smaller element getting stored into array B at index k
            i++;    // Incrementing i to move to next index
            k++;    // Incrementing k to move to next index
        }

        if( arr[j] < arr[i] ){

            B[k]= arr[j];   // smaller element getting stored into array B at index k
            j++;    // Incrementing j to move to next index
            k++;    // Incrementing k to move to next index
        }
    }
    // After the while loop ended means one of the subarray ended and its all elements are in array B 
    // if another array still have some element left than they will be transferred to the array B at last and so we will write code for it

    while( i <= mid ){ // true if i didnt reach the end and still have elements in it
        B[k] = arr[i];
        k++; 
        i++;
    }
    while( j <= high ){ // true if j didnt reach the end and still have elements in it
        B[k] = arr[j];
        k++; 
        j++;
    }

    // since our merging is done so now we will paste our array B back to A which is sorted now

    for( int i = low ; i <= high ; i++ ){
        arr[i] = B[i];
    }
}

//* FUNCTION FOR MERGESORT

int MERGE_SORT( int arr[] , int low , int high ){
    
    int mid ; // We will create and find mid so that we can pass this to the MERGE function above

    if( low < high ){   // This function is made so that array have atleast more than 2 elements, otherwise we won't be able to find mid
        mid = ( low + high ) / 2;   // We can set mid anywhere we want , but to easy to understand we will do this

        // NOW WE WILL USE MERGESORT ITSELF ON TWO PARTS OF OUR ARRAY

        MERGE_SORT( arr , low , mid );      // Sub array 1 
        
        MERGE_SORT( arr , mid+1 , high);    // Sub array 2

        // Now we will call our MERGE function to merge our subarrays      
        MERGE( arr , low , mid , high );
    }
}


int main(){

    int A[]= {6,3,5,9,4,2};
    int size = 6;

    printf(" THE ARRAY BEFORE SORTING IS : ");
    array(A , size  );
    printf("\n\n");

    MERGE_SORT(  A , 0 , 5); //

    printf(" THE ARRAY AFTER  SORTING IS : ");
    array(A , size  );
    printf("\n\n");

    return 0;
}
