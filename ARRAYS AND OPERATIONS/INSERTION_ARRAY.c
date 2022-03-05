# include<stdio.h>

void Display(int arr[], int size){
    for(int i=0; i < size ;i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int Insert(int arr[], int a, int b, int c, int d ){
    if(a >= b){ // if elements are already equal to capacity or more then return can't add
        return -1;  // this will tell if array have capacity or not to hold another element
    } 
    for(int i = a-1; i >= d; i--){ // This code will push the elements to the next index so that new space can be made
        arr[i+1] = arr[i];      
    }
    arr[d]= c;
    return 1;
}

int main(){

    int rank[100] = {1,2,3,5,6,7};
    int elements =6;     // total number of elements in our array
    int capacity =100;   // to know how much space is left in our array
    int element_to_be_added =4;  // element to be inserted
    int index =3;

    Display(rank,elements);

    Insert(rank, elements, capacity, element_to_be_added, index);

    elements+=1;

    Display(rank,elements);

    return 0;
}