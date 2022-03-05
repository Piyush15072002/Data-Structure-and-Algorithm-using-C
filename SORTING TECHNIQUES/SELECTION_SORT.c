# include<stdio.h>

/*
   THE LOGIC OF THE SELECTION SORT IS, IT CONSIDERS THE FIRST ELEMENT OF THE ARRAY TO BE THE SMALLEST AND THEN
   COMPARES IT WITH THE REST OF THE ELEMENTS OF THE ARRAY AND IF IT FINDS AN ELEMENT SMALLER THAN THE FIRST ELEMENT THEN
   IT WILL SWAP THE NEW FOUND SMALLER ELEMENT WITH THE FIRST ELEMENT
*/

// Function to print the array

int array( int arr[], int size ){
    int i =0;
    while( i < size ){
        printf("  %d ", arr[i]);
        i++;
    }
    
} 


//* SELCTION SORT 

int SELECTION_SORT( int arr[], int size ){

    int t; // variable for swapping
    int index_min;  // The index of first element which is considered to be smallest

    for( int i = 0; i < size - 1 ; i++){    // for passes

        int index_min = i; 

        for( int j = i + 1 ; j < size ; j++){
            // j = i + 1 because arr[i] is the first element and the aim of this loop is to compare the rest of the element
            // with arr[i] and so we will start the comparison from i+1

            if( arr[j] < arr[index_min] ){ // if the element is smaller than the first element then true
                index_min = j ; // since the found element is smallest and so we will store its INDEX in our variable
            }
        }
        // Now we need to swap the elements
        t = arr[i] ;
        arr[i] = arr[index_min] ;
        arr[index_min] = t; 

    }


}

int main(){

    int a[]={99,89,69,79,1,100};

    int size = 6;

    printf("THE ARRAY BEFORE SORTING IS : [ ");
    array( a , size );
    printf(" ]\n\n");

    SELECTION_SORT( a , size );

    printf("THE ARRAY AFTER  SORTING IS : [ ");
    array( a , size );
    printf(" ]\n\n");



    return 0;
}