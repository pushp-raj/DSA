#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head;

void Insert_Begining();
void Insert_Last();
void Insert_Random();
void Delete();
void Delete_Begining();
void Delete_Last();
void Delete_Key();
void Search_Key();
void Display();

void main()
{
    int option;
    while(option != 10){
        printf("\n\n========================================");
        printf("\n\nChoose the following operations : ");
        printf("\n 1. Inserting a node at the begining");
        printf("\n 2. Inserting a node at the end");
        printf("\n 3. Inserting a node at random position");
        printf("\n 4. Deleting Node from any position");
        printf("\n 5. Deleting Node from begining");
        printf("\n 6. Deleting Node from last");
        printf("\n 7. Deleting Node using Key");
        printf("\n 8. Search position of an element");
        printf("\n 9. Display");
        printf("\n10. Exit");
        printf("\nEnter your choise : ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            Insert_Begining();
            break;
        case 2:
            Insert_Last();
            break;
        case 3:
            Insert_Random();
            break;
        case 4:
            Delete();
            break;
        case 5:
            Delete_Begining();
            break;
        case 6:
            Delete_Last();
            break;
        case 7:
            Delete_Key();
            break;
        case 8:
            Search_Key();
            break;
        case 9:
            Display();
            break;
        case 10:
            printf("\nExiting.....!\n");
            exit(0);
            break;
        default:
            printf("\n\nWrong Option");
            break;
        }
    }
}


void Insert_Begining(){
    printf("\n\nInserting node iin begining...!");
    struct node *ptr;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("\nOverflow");
    else{
        printf("\nEnter data value : ");
        scanf("%d",&item);

        if(head == NULL){
            ptr->prev = NULL;
            ptr->next = head;
            head = ptr;
            ptr->data = item;
        }
        else{
            ptr->data = item;
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("Node Inserted...!");
    }
}
