/*
Author: Swarit Pandey
USN: 4VV19IS108
Date: 13/10/2020
Task: Implementation of Stack ADT 
IDE Used: OnlineGDB
Written In: C11
Compiler: GNU GCC 10.x
Dependencies: NONE
*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define allocate(t, n) (t*)malloc((n)*sizeof(t))

// Structure of Stack 
struct Stack {
    int size;
    int top;
    int *s;
};

// This method will create stack dynamically CONSTRUCTOR
void create(struct Stack *st) {
    printf(" >> Enter the required size of stack: \n >>> ");
    scanf("%d", &st -> size);
    st -> top = -1;
    st -> s = allocate(int, st -> size);
    printf("---------------------DONE----------------------\n");
}

// Method to display stack 
void display(struct Stack st) {
    int i;
    printf(" >>> Elments present in stack are: \n");
    if(st.top == -1){
        printf("LOG_MESSAGE: The stack is empty!\n");
    }
    for(i = st.top; i >= 0; i--) {
        printf("\n__\n|%d|", st.s[i]);
    }
    printf("\n");
}

// Method to push an integer type element in the stack 
void push(struct Stack* st, int x) {
    if(st -> top == st -> size - 1) {
        printf("LOG_MESSAGE: Stack Overflow! \n");
        return;
    }
    else {
        st -> top++;
        st -> s[st -> top] = x;
        printf("---------------------DONE----------------------\n");
    }
}

// Method to pop an element from stack 
int pop(struct Stack* st) {
    int x = -1;
    if(st -> top == -1) {
        printf("LOG_MESSAGE: Stack Underflow! \n");
    }
    else {
        x = st -> s[st -> top--];
    }
    return x;
}

// Method to peek at a particalar element in the stack
int peek(struct Stack st, int index) {
    int x = -1;
    if(st.top - index + 1 < 0) {
        printf("LOG_MESSAGE: Invalid Index!");
    }
    x = st.s[st.top - index + 1];
    return x;
}

// Method to check if the elements in the stack are palindrome
bool palindrome(struct Stack st) {
    int arr[st.top];
    for(int i = 0; i < st.top + 1; ++i) {
        arr[i] = peek(st, i + 1);
    }   
    int n = sizeof(arr) / sizeof(arr[0]);
    int flag = 0;
    
    for(int i = 0, j = n; i < j; i++, j--) {
        if(arr[i] != arr[j]) {
            flag = 1;
            break;
        }
    }
    
    if(flag == 1) {
        return false;
    }
    else {
        return true;
    }
}


// DRIVER MEHTOD
int main() {
    int choice;
    printf("Welcome to the Stack ADT based console application!\n");
    printf("NOTE: In order to avoid segmentation fault please initialise stack before doing operations.\n");
    while(1) {
        printf("----------------------------------------------------------------------------\n");
        printf("1> To initiate a new stack please press '1'.\n");
        printf("2> To push an element to the stack press '2'.\n");
        printf("3> To pop an element from the stack press '3'.\n");
        printf("4> To peek an element already present in the stack press '4'.\n");
        printf("5> To check if the elements present in the stack form palindrome press '5'.\n");
        printf("6> To check the current status of stack press '6'.\n");
        printf("7> To exit from the application press '7'.\n");
        printf("----------------------------------------------------------------------------\n >> ");
        scanf("%d", &choice);
        switch(choice) {
            case 1 : ;
                struct Stack st;
                create(&st);
                printf("LOG_MESSAGE: Stack has been initialised successfully!\n");
                break;
            case 2 : ;
                int item;
                printf(" >>> Enter the element you want to push in the stack: \n >>>> ");
                scanf("%d", &item);
                push(&st, item);
                display(st);
                break;
            case 3 : ;
                int popped = pop(&st);
                printf("LOG_MESSAGE: Element %d has been successfully popped from stack.\n", popped);
                display(st);
                break;
            case 4 : ;
                int index;
                printf(" >>> Enter the index you want to peek at: \n >>>> ");
                scanf("%d", &index);
                int ret = peek(st, index);
                printf("LOG_MESSAGE: The element at index %d is %d. \n", index, ret);
                break;
            case 5 : ;
                bool check;
                check = palindrome(st);
                if(check == true) {
                    printf("LOG_MESSAGE: The elements in the stack form a palindrome.\n");
                }
                else {
                    printf("LOG_MESSAGE: The elements in the stack do not form a palindrome. \n");
                }
                break;
            case 6 : ;
                display(st);
                break;
            case 7 : ;
                printf("-------------------------------THANKS!----------------------------------\n");
                printf("This application is written by Swarit in C11 standards, thanks for using!");
                exit(0);
                break;
            default : printf("LOG_MESSAGE: Invalid Choice!\n");
        }
    }
    printf("This application is written by Swarit in C11 standards, thanks for using!");
    return 0;
}
