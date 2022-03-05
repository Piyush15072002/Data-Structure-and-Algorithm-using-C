# include <stdio.h>

int Linear_Search( int arr[], int size, int search){
    for(int i=0; i < size; i++){
        if( arr[i] == search ){
            printf("\n\tYES, ROLL NO. %d HAVE ALREADY SUBMITTED THE ASSIGNMENT !\n\n", arr[i]);
            printf("\tHIS NAME IS ON THE LIST ON NUMBER %d FROM STARTING\n", i+1);
            return 1; // Using return here will make the compiler go out of function straight if successful
        }
    }
    printf("\n\t NO, THE STUDENT DIDN'T SUBMIT THE ASSIGNMENT !\n");
}


int Display(int arr[], int elements ){
    for(int i = 0; i < elements; i++){
        printf("\t\tROLL NUMBER : %d\n",arr[i]);
    }
}

int main(){

    // Array of the students with their Roll number who submitted their assignments before deadline
    int Rollno[]={1,34,33,54,56,57,34,23,67,99,100,4,8,70,43,45,48,39,87,83,96,84,22,20,25,16};

    // Sometimes the number of Elements in an array are huge to count and for such cases, we will use this method
    int size= sizeof(Rollno) / sizeof(int);     // 26 students
    printf("\nTHE NUMBER OF STUDENTS WHO SUBMITTED WORK IS :  %d\n\n", size);

    // Now if i wanna check Roll no. of a student to confirm if he submitted the project or not
    printf("***THE ROLL NUMBER OF STUDENT WHO SUBMITTED ASSIGNMENTS ARE***\n");
    
    Display(Rollno, size);

    // Diving back into the Linear search, Now we will ask the user for roll no. of a student

    int element;
    printf("ENTER THE ROLL NUMBER OF STUDENT YOU WANNA CONFIRM FOR ASSIGNMENT SUBMISSION OR NOT  :  ");
    scanf("%d",& element);

    Linear_Search( Rollno, size, element);


    return 0;
}