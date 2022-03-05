# include <stdio.h>

int Binary_Search(int array[], int size, int element){
    // We must understand the concept and logic of these searches
    // so that we can get to know our requried variables
    int low, mid, high;
    low= 0;        // This is the index of the first element in the array
    high= size-1;  // This is the index of the last element in the array

    while( low <= high){
        // Logic is - This loop will work as long as the low element is smaller than high
        // This will continue until the last element when low = high

        mid = (low + high) / 2;
        // This will give us mid even if divison is in fractions

        if( array[mid] == element ){
            printf("THE %d ELEMENT IS PRESENT ON INDEX %d \n",element, mid);
            return 1;
        }
        if( array[mid] < element ){
            low = mid+1;
        }
        else{
            high=mid-1;
        }
    }
    printf("SORRY ! THE GIVEN NUMBER ISN'T PRESENT IN THE TABLE\n");
}

int main(){
    // For Binary Search we must have a sorted array
    int Table[]= {5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100};

    int size = sizeof(Table) /  sizeof(int);
    printf("THE TOTAL NUMBER OF ELEMENTS IN THE TABLE ARE %d\n\n", size);
    
    int element;
    printf("Enter the Number you wanna find in the table of 5 :  ");
    scanf("%d", &element);

    Binary_Search(Table, size, element);

    return 0;
}