#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myFunctions.h"
typedef struct Node Nodeptr;

typedef struct Node
{
    int data;
    Nodeptr* next;
    Nodeptr* previous;
} Nodeptr;

extern Nodeptr * StartNode;
extern Nodeptr * endNode;

int main(int argc, char *argv[])
{
    //it may give you some error or warnings for some compilers
    //no init
    int choice;
    StartNode = NULL;
    endNode = NULL;

    do
    {

        printf("1 - add (left) | 2- add (right) | 3 - add Middle After | 4 - add Middle Before |  5 - print | 6 - print backward | 7 - delete node from StartNode | 8 - Delete All | 9 - Delete Any | 11 - Odd Numbers | 12 - Replace A Number | ");
        puts(" 13 - Sort the list | 15 - Random Numbers | 99 - extend the menu | ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 99:
                menu();
                break;
            case 1:
                puts("under construction");
                addToLeft();
                break;
            case 2:
                puts("under construction");
                addToRight();
                break;
            case 3:
                puts("under construction");
                addMiddleAfter();
                break;
            case 4:
                puts("under construction");
                addMiddleBefore();
                break;
            case 5:
                puts("under construction");
                printTheNodes();
                break;
            case 6:
                puts("under construction");
                printTheNodesBackwards();
                break;
            case 0:
                break;
                case 7:
               DeleteNodeFromStartNode();
                break;
            case 8 :
                DeleteAll();
                break;
            case 9 :
                DeleteAny();
                break;
            case 11 :
                printOdd();
                break;
            case 12 :
                ReplaceIt();
                break;
            case 13 :
                SortTheList();
                break;
            case 14 :
                SizeOfN();
                break;
            case 15 :
                PrintRandomNumbers();
                break;
            default:
                printf("please enter a valid number\n\n");
                break;
        }

    } while (choice != 0);



    return 0;
}

