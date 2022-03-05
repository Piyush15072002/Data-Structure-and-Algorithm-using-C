# include<stdio.h>
void Display(int arr[], int elements){
    for(int i = 0; i < elements; i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");

}

void Deletion(int arr[], int elements ,int index){
    for(int i= index; i <= elements-1 ; i++){
        arr[i]=arr[i+1];
    }
}
int main(){

    int Rank[100]= {1,2,2,3,4,5};
    int elements= 6;
    int index= 2;

    Display(Rank, elements);

    Deletion(Rank, elements, index);
    elements-=1;

    Display(Rank, elements);

    return 0;
}