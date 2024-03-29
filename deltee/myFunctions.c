//
//  myFunctions.c
//  project1
//
//  Created by Saygin Guven on 2019-07-16.
//  Copyright � 2019 Saygin Guven. All rights reserved.
//

#include "myFunctions.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Node Nodeptr;

typedef struct Node
{
    int data;
    Nodeptr* next;
    Nodeptr* previous;
} Nodeptr;

Nodeptr * StartNode;
Nodeptr * endNode;
int count = 0;

void printTheNodes() {
    Nodeptr * currentNode = (Nodeptr *)malloc(sizeof(Nodeptr));
    if(StartNode ==NULL && endNode == NULL)
        {
        puts("No Node to print");

    }else{
        Nodeptr * currentPtr = StartNode;
        while(currentPtr != NULL){



        printf("%d ->",currentPtr->data);
        currentPtr= currentPtr->next;

        }
        printf("NULL\n");
        puts("------------");
    }
    puts("");

}

void printTheNodesBackwards() {
    Nodeptr * currentNode = (Nodeptr *)malloc(sizeof(Nodeptr));
    if(StartNode ==NULL && endNode == NULL)
        {
        puts("No Node to print");

    }else{
        Nodeptr * currentPtr = endNode;
        while(currentPtr != NULL){



            printf("%d ->",currentPtr->data);
            currentPtr= currentPtr->previous;

        }
        printf("NULL\n");
        puts("------------");
    }
    puts("");

}

void addToLeft() {
    Nodeptr * currentNode = (Nodeptr *)malloc(sizeof(Nodeptr));
    if(StartNode == NULL && endNode == NULL){
        StartNode = currentNode;
        endNode = currentNode;
        printf("What is the data ? :");
        scanf("%d",&currentNode->data);
        currentNode->next = NULL;
        currentNode->previous =NULL;
    }else{
        puts("add one more node");
        scanf("%d",&currentNode->data);
        currentNode->previous = NULL;
        currentNode->next = StartNode;
        StartNode->previous =currentNode;
        StartNode = currentNode;

    }


}

void addToRight(){
Nodeptr * currentNode = (Nodeptr *)malloc(sizeof(Nodeptr));

    if(StartNode ==NULL && endNode == NULL){
        StartNode = currentNode;
        endNode = currentNode;
        printf("what is the data? :");
        scanf("%d",&currentNode->data);
       // currentNode->data=PrintRandomNumbers();
        currentNode->next = NULL;
        currentNode->previous = NULL;
    }else{
        puts("add one more node");
        printf("what is the data? :");
        scanf("%d",&currentNode->data);
       // currentNode->data=PrintRandomNumbers();
        currentNode->previous = endNode;
        currentNode->next = NULL;
        endNode->next =currentNode;
        endNode = currentNode;

    }
}

void addMiddleAfter() {
    if(StartNode ==NULL && endNode==NULL){
        printTheNodes();

        return;
    }
    int data;
    puts("which data you are looking for?");
    scanf("%d",&data);
    //search
    Nodeptr * current = StartNode;

    while(current != NULL){
            if(data == current->data){
                //found it!
                if(current == endNode){
                    addToRight();
                    break;
                }
                Nodeptr * newNode =(Nodeptr *)malloc(sizeof(Nodeptr));
                printf("what is the data");
                scanf("%d",&newNode->data);
                Nodeptr * currentNext = current->next;
                current->next = newNode;
                newNode->previous = current;
                newNode->next = currentNext;
                currentNext->previous = newNode;
                printTheNodes();
                return;

            }
        current = current->next;

    }
    if(StartNode==endNode){

        addToRight();
        return;
    }
puts("check your data it`s not in the list");
}


void addMiddleBefore() {
 if(StartNode ==NULL && endNode==NULL){
        printTheNodes();

        return;
    }
    int data;
    puts("which data you are looking for? ");
    scanf("%d",&data);
    //search
    Nodeptr * current = StartNode;

    while(current != NULL){
            if(data == current->data){
                //found it!
                if(current == endNode){
                    addToLeft();
                    break;
                }
                Nodeptr * newNode =(Nodeptr *)malloc(sizeof(Nodeptr));
                printf("what is the data ? ");
                scanf("%d",&newNode->data);
                Nodeptr * currentPre = current->previous;
                current->previous = newNode;
                newNode->next = current;
                newNode->previous = currentPre;
                currentPre->next = newNode;
                printTheNodes();
                return;

            }
        current = current->next;

    }
    if(StartNode==endNode){

        addToLeft();
        return;
    }
puts("check your data it`s not in the list");
}





void DeleteNodeFromStartNode(void){


    if( StartNode == endNode)
        {
        free(StartNode);
        StartNode= NULL;
        endNode = NULL;

        puts("cant delete the node!!");
    }else{
        Nodeptr * temPtr;
        temPtr = StartNode->next;
        temPtr->previous = NULL;
        free(StartNode);
        StartNode = temPtr;
        printTheNodes();
        }
}
void DeleteAll(){
StartNode=NULL;
endNode=NULL;
puts("All Nodes Deleted Successfully");

}
void DeleteAny(){

    if(StartNode ==NULL && endNode==NULL){
        puts("No Nodes Too Delete");
        return;
    }


    int data;
    puts("Which Node You Are Going To Delete?");
    scanf("%d",&data);
    //search
    Nodeptr * current = StartNode;

    if(StartNode == endNode){

        DeleteAll();
        printTheNodes();
        return;
    }

    while(current != NULL){
            if(data == current->data){
                //found it!
                if(current == endNode){
                    Nodeptr * temPtr;
                    temPtr = endNode->previous;
                    temPtr->next = NULL;
                    free(endNode);
                    endNode = temPtr;
                    printTheNodes();
                    break;
                }
                Nodeptr * currentNext = current->next;
                Nodeptr * currentPre = current->previous;
                currentNext->previous=currentPre;
                currentPre->next=currentNext;
                free(current);
                printTheNodes();

                return;

            }
        current = current->next;

    }


}
printOdd(){
      Nodeptr * current = StartNode;

 while(current != NULL){
        if(current->data %2 != 0){
           printf("%d -->",current->data);

        }


     current = current->next;
     if(StartNode==endNode){
        return;
     }
 }
puts("NUll");

}
ReplaceIt(){
    int data;
    puts("Which data Do you want to replace ? ");
    scanf("%d",&data);
    //search
    Nodeptr * current = StartNode;

    while(current != NULL){
            if(data == current->data){
                //found it!
                puts("type the new Data");
                scanf("%d",&current->data);
                 printTheNodes();

                return;

            }
        current = current->next;

    }
puts("sorry it does`n exist in the list");

}
//BUbble Sort Funtion is right below
void SortTheList(){
    Nodeptr * current;
    current = StartNode;
    Nodeptr * secondN;
    int tmp;
    count=SizeOfN();
    for(int i=0;i<=count;i++){
        current = StartNode;
        for(int j=0;j<count-1;j++){
            secondN = current->next;
            if(current->data > secondN->data){
                tmp = current->data;
                current->data = secondN->data;
                secondN->data = tmp;
            printTheNodes();
            }
            current = current->next;
            }
    }
    puts("*****************");
 printTheNodes();
 }
 //find the size and count is a global var
int SizeOfN(){

    Nodeptr * current = StartNode;
    while(current!=NULL){
        current = current->next;
        count=count+1;


    }
    printf("The size of This ,is : %d \n",count);
    return count;
}
int PrintRandomNumbers(){
    //srand to gice numbers but the reason that in printf we use rand is to get numbers we can not get number s by srand
  //  srand((signed int)time(NULL));


       // printf("%d \n",rand()%10);

  //     return rand()%100;
}
int PrintPrimeNumbers(long number){

    if(number<2){return 0;}
    if(number==2){
    return 1;
}
    for(int i=2;i<=sqrt(number);i++){
        if(number%i==0)
            return 0;


    }
    return 1;
}
void test(){
    int j=0;
    for(int i=0;j<10002;i++){

        if(PrintPrimeNumbers(i)==1){
            j++;
            if(j>10000 && j<10002){
                printf("%d th prime number is : %d\n",j,i);
                puts("");
                puts("_|-|_|-|_|-|_|-|_|-|_|-|_|-|_|-|_|-|_|-|_|-|_|-|_|-|");
                puts("");
            }
        }
    }
}
void HowMany(){
    int data;
    puts("How many of What Node?<Enter the Node To See : ");
    scanf("%d",&data);
    //search
    Nodeptr * current = StartNode;


    while(current != NULL){
            if(data == current->data){
                //found it!
                puts("Number found");
                count++;
                //return;
          }
          current = current->next;
    }
    printf("there is %d , %d in this Link List \n",count,data);
    if(count==0){
        puts("Number not found");
    }
}
void RemoveDuplicate(){
int data;
    puts("Which Node You Are Going To Remove the Duplicate?");
    scanf("%d",&data);
    //search
    Nodeptr * current = StartNode;


    while(current != NULL){
            if(data == current->data){
                //found it!
                current = NULL;

                free(current);
                count++;
                return;
          }


          current = current->next;
    }




}


void menu() {
    puts("");
    printf("\t\twelcome, please select one\n");
    printf("\t\t1- add a node to left\n");
    printf("\t\t2- add a node to right\n");
    printf("\t\t3- add a node to middle after a node\n");
    printf("\t\t4- add a node to middle before a node\n");
    printf("\t\t5- printf the list forward\n");
    printf("\t\t6- printf the list backward\n");
    printf("\t\t7- delete a node (front)\n");
    printf("\t\t8- delete a node (back)\n");
    printf("\t\t0- exit\n");
    printf("? :  ");
}
