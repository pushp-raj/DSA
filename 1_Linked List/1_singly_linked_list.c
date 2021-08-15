#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
} *head;

void Insert_Begining();
void Insert_Last();
void Display();
void Insert_Random();
void Delete_Begin();
void Delete_Last();
void Delete_Random();
void Search();
void Delete();

int main()
{
    int option=0;
    while(option != 10){
        printf("\n\n=================================");
        printf("\nChoose the following option\n");
        printf("1.  Inserting Node at begining\n");
        printf("2.  Inserting Node at last\n");
        printf("3.  Inserting Node at random position\n");
        printf("4.  Delete Node\n");
        printf("5.  Delete Node form begining\n");
        printf("6.  Delete Node from last\n");
        printf("7.  Delete Node from random position\n");
        printf("8.  Search for an element\n");
        printf("9.  Display Data\n");
        printf("10. Exit\n");
        printf("Enter your choice : ");
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
            Delete_Begin();
            break;
        case 6:
            Delete_Last();
            break;
        case 7:
            Delete_Random();
            break;
        case 8:
            Search();
            break;
        case 9:
            Display();
            break;
        case 10:
            printf("\nExiting.....!");
            exit(0);
            break;
        default:
            printf("\n\nWrong Option");
            break;
        }
    }
}

void Insert_Begining(){
    int item;
    struct node *ptr;
    printf("Inserting Node in begining :");
        ptr = (struct node *)malloc(sizeof(struct node));
        if(ptr == NULL){
            printf("\nOverflow\n");
        }
        else{
            printf("\nEnter data value : ");
            scanf("%d",&item);
            ptr->data = item;
            ptr->link = head;
            head = ptr;
            printf("Node Inserted");
        }
}

void Insert_Last(){
    printf("\n\nInserting Node at last :");
    int i,n;
    printf("\nHow many node to be inserted : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        struct node *temp, *ptr;
        int item;
        ptr = (struct node *)malloc(sizeof(struct node));
        if(ptr == NULL)
            printf("\noverflow");
        else{
            printf("\nEnter data value : ");
            scanf("%d",&item);
            ptr->data = item;
            ptr->link = NULL;
            if(head == NULL){
                head = ptr;
                printf("Node Inserted");
            }
            else{
                temp = head;
                while(temp->link != NULL){
                    temp = temp->link;
                }
                temp->link = ptr;
                printf("Node Inserted");
            }
        }
    }
}

void Insert_Random()
{
    printf("\nInserting Node at random position :\n");
    int i, location, item;
    struct node *ptr, *temp;
    printf("Enter Data value : ");
    scanf("%d",&item);
    printf("Enter the position : ");
    scanf("%d",&location);
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = item;
    if(ptr == NULL){
        printf("\nOverflow");
    }   
    else{
        temp = head;
        location --;
        while(location != 1){
            temp = temp->link;
            location--;
        }
        // printf("\n1 here");
        // for(i=0;i<location;i++){
        //     temp = temp->link;
        //     if(temp = NULL){
        //         printf("\nNode Can't be Inserted"); 
        //         return;
        //     }
        // }
        ptr->link = temp->link;
        temp->link = ptr;
        printf("\nNode Inserted");
    }
}

void Delete_Begin(){
    struct node *temp;
    printf("\n\nDeleting Node from begining :");
    if(head == NULL)
        printf("\nList is empty");
    else{
        temp = head;
        head = temp->link;
        free(temp);
        printf("\nNode deleted from begining...!");
    }
}

void Delete_Last(){
    printf("\n\nDeleting Node from last :");
    struct node *ptr, *ptr1;
    if(head == NULL)
        printf("\nList is EMPTY.. !");
    else if(head->link == NULL){
        free(head);
        head = NULL;
        printf("\nOnly Node of the Linked List is deleted .. !");
    }
    else{
        ptr = head;
        while(ptr->link != NULL){
            ptr1 = ptr;
            ptr = ptr->link;
        }
        ptr1->link = NULL;
        free(ptr);
        printf("\nLast Node deleted from the list.. !");
    }
}

void Delete_Random(){
    struct node *ptr, *ptr1;
    int position,i;
    printf("\n\nEnter the position of the node to delete : ");
    scanf("%d",&position);
    ptr = head;
    while(position != 1){
        ptr1 = ptr;
        ptr = ptr->link;
        if(ptr == NULL){
            printf("\nNode Can't be deleted");
            return;
        }
        // temp = temp->link;
        position--;
    }
    // for(i=0;i<position;i++)
    // {
    //     ptr1 = ptr;
    //     ptr = ptr->link;
    //     if(ptr == NULL){
    //         printf("\nNode Can't be deleted");
    //         return;
    //     }
    // }
    ptr1->link = ptr->link;
    free(ptr);
    printf("Node Deleted");
}

void Search(){
    printf("\n\nSearching element in list : ");
    struct node *ptr;
    int value, flag=1,i=1;
    ptr = head;
    if(ptr == NULL){
        printf("\nEnpty List");
    }
    else{
        printf("\nEnter key to search : ");
        scanf("%d",&value);
        while(ptr != NULL){
            if(ptr->data == value){
                printf("Item found at position : %d",i);
                flag = 0;
                // count = 1;
            }
            // else{
            //     flag = 1;
            // }
            i++;
            ptr = ptr->link;
        }
        if(flag != 0)
        {
            printf("Item not found");
        }
    }
}

void Display(){
    struct node *ptr;
    ptr = head;
    printf("\n\nDisplaying Data from Linked List :\n");
    if(ptr == NULL)
        printf("\nOverflow");
    else{
        while(ptr != NULL){
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
    }
}

void Delete(){
    struct node *ptr, *temp;
    int key,i;
    printf("\n\nDeleting Node : ");
    printf("\nEnter key to delete : ");
    scanf("%d",&key);
    temp = head;
    while(temp->data != key){
        ptr = temp;
        temp = temp->link;
    }
    ptr->link = temp->link;
    // printf("%d",ptr->data);
    free(temp);
    printf("Node Deleted..!");
    // void Display();
}