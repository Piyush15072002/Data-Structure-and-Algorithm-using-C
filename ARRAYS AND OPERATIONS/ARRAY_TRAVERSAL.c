# include<stdio.h>

int main(){

    int array[100];
    
    for(int i=0; i<10; i++){
        printf("enter the %d element of array : ", i+1);
        scanf("%d", &array[i]);
    }
   
    for(int i=0; i<10; i++){
        printf("\t\t\t%d\n\n\n",array[i]);
    }


    return 0;
}