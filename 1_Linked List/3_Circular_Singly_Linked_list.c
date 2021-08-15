#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
} *head;

void Insert_Beginning();
void Insert_Last();
void Insert_Random();
void Delete_Key();
void Delete_Begin();
void Delete_Last();
void Delete_Random();
void Search();
void Display();


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
            Insert_Beginning();
            break;
        case 2:
            Insert_Last();
            break;
        case 3:
            Insert_Random();
            break;
        case 4:
            Delete_Key();
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

void Insert_Beginning(){
    int item;
    printf("\n\nInserting Node in beginning : ");
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("\nOverflow");
    else{
        printf("\nEnter Data Value : ");
        scanf("%d",&item);
        ptr->data = item;
        if(head == NULL){
            head = ptr;
            ptr->link = head;
        }
        else{
            temp = head;
            while (temp->link != head)
                temp = temp->link;
            ptr->link = head;
            temp->link = ptr;
            head = ptr;
        }
        printf("Node Inserted...!"); 
    }
}

void Insert_Last(){
    printf("\n\nInserting Node at last : ");
    int n;
    printf("\nHow many node to insert : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        struct node *ptr, *temp;
        int item;
        ptr = (struct node *)malloc(sizeof(struct node));
        if(ptr == NULL) 
            printf("\nOverflow");
        else{
            printf("\nEnter Data Value : ");
            scanf("%d",&item);
            ptr->data = item;
            if(head == NULL){
                head = ptr;
                ptr->link = head;
            }
            else{
                temp = head;
                while (temp->link != head){
                    temp = temp->link;
                }
                temp->link = ptr;
                ptr->link = head;
            }
        }
        printf("Node Inserted...!");
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
        ptr->link = temp->link;
        temp->link = ptr;
        printf("\nNode Inserted");
    }
}

void Delete_Key(){
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

void Delete_Begin(){
    struct node *temp;
    printf("\n\nDeleting Node from beginning : ");
    if(head == NULL)
        printf("\nUnderflow");
    else if(head->link == head){
        free(head);
        head = NULL;
        printf("\nOnly node deleted...!");
    }
    else{
        temp = head;
        while (temp->link != head){
            temp = temp->link;
        }
        temp->link = head->link;
        free(head);
        head = temp->link;
        printf("\nNode Deleted...!");
    }
}

void Delete_Last(){
    printf("\n\nDeleting node from last : ");
    struct node *temp, *ptr;
    if(head == NULL)
        printf("\nUnderflow");
    else if(head->link == head){
        free(head);
        head = NULL;
        printf("\nOnly Node deleted...!");
    }
    else{
        ptr = head;
        while(ptr->link != head){
            temp = ptr;
            ptr = ptr->link;
        }
        temp->link = head;
        free(ptr);
        printf("\nNode Deleted...!");
    }
}

void Delete_Random(){
    struct node *ptr, *temp;
    int position;
    printf("\n\nDeleting Node of random position : ");
    printf("\nEnter position : ");
    scanf("%d",&position);
    ptr = head;
    while(position != 1){
        temp = ptr;
        ptr = ptr->link;
        if(ptr == NULL){
            printf("Node Can't be deleted...!");
            return;
        }
        position --;
    }
    temp->link = ptr->link;
    free(ptr);
    printf("Node Deleted...!");
}

void Search(){
    printf("\n\nSearch position of key : ");
    struct node *temp;
    int key, flag = 0, i=1;
    temp = head;
    if(temp == NULL)   
        printf("\nEnpty List");
    else{
        printf("\nEnter key : ");
        scanf("%d",&key);
        if(temp->data == key){
            printf("Item found at position : %d",i);
            flag = 0;
        }
        else{
            while(temp->link != head){
                if(temp->data == key){
                    printf("Item found at location : %d",i);
                    flag = 0;
                    break;
                }
                i++;
                temp = temp->link;
            }
        }
    }
    if(flag != 0)
        printf("Item not found...!");
}

void Display(){
    struct node *ptr;
    ptr = head;
    if(head == NULL)
        printf("\n\nEmpty list");
    else{
        printf("\n\nDisplaying element : \n");
        while (ptr->link != head){
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
        printf("%d",ptr->data);
    }
}