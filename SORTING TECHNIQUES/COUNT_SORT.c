# include<stdio.h>
# include<stdlib.h>
# include<limits.h> // LIBRARY FOR FINDING MIN AND MAX ELEMENT

// THE THEORY OF COUNT SORT IS ALL WRITTEN IN THE NOTEBOOK SO PLEASE REFER IT FIRST, THEN COME TO THE CODING


int Maximum( int arr[] , int size ){
    int max = INT_MIN; // INT_MIN is the function used from the above limits.h library

    // now we will make a loop to traverse all the element of the array and find the maximum
    for ( int i = 0 ; i < size ; i ++ ){
         
        if( max < arr[i] ){
            max = arr[i];
        }
    }
    return max ;
}

//* COUNT SORT 

int COUNT_SORT( int arr[] , int size ){

    int  i , j ;
    int max = Maximum( arr , size ); 

    int * count = ( int * ) malloc ( ( max + 1 ) * sizeof( int) );
    // MAKING A NEW ARRAY WHOSE SIZE IS EQUAL TO THE MAX ELEMENT OF THE ARRAY + 1 AND ALLOCATING MEMEORY TO IT 

    // NOW WE WILL MAKE ALL THE ELEMENTS OF THE ARRAY COUNT TO 0 
    for( i = 0 ; i < max+1 ; i ++){
        count[i]=0;   // Making all the elements i
    }

    // Incrementing the corresponding index in the COUNT array
    for( i = 0 ; i < size ; i++){
        count[arr[i]] = count[arr[i]]+1;
    }

    i=0;    // Pointer for COUNT array
    j=0;    // Pointer for given array
     
    while( i <= max ){
        
        if( count[i] > 0 ){
            arr[j]=i;
            count[i]= count[i] - 1 ;
            j++;     
        }
        else{
            i++; 
        }
        
    }

}


// FUNCTION TO PRINT THE ARRAY
int array( int  arr[] , int  size );

int main(){

    int A[]= {9, 3, 5 , 6 , 8, 2 , 1 , 7 , 4 , 10};
    int size = 10 ;

    printf(" THE ARRAY BEFORE SORTING IS : ");
    array(A , size  );
    printf("\n\n");

    COUNT_SORT( A , size );

    printf(" THE ARRAY AFTER  SORTING IS : ");
    array(A , size  );
    printf("\n\n");

    return 0;
}


int array( int  arr[] , int  size ){

    for( int i = 0 ; i < size ; i++){
        printf(" %d\t", arr[i]);
    }
    printf("\n");

}