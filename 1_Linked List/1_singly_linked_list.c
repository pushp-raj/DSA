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

int main()
{
    int option=0;
    while(option != 9){
        printf("\n\n=================================");
        printf("\nChoose the following option\n");
        printf("1. Inserting Node at begining\n");
        printf("2. Inserting Node at last\n");
        printf("3. Inserting Node at random position\n");
        printf("4. Delete Node form begining\n");
        printf("5. Delete Node from last\n");
        printf("8. Display Data\n");
        printf("9. Exit\n");
        printf("Enter yout choise : ");
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
            Delete_Begin();
            break;
        case 5:
            Delete_Last();
            break;
        case 8:
            Display();
            break;
        default:
            break;
        }
    }
}

void Insert_Begining(){
    int n, item;
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
    ptr->data = item;
    printf("Enter the position : ");
    scanf("%d",&location);
    ptr = (struct node *)malloc(sizeof(struct node));
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

void Display(){
    struct node *ptr;
    ptr = head;
    printf("\n\nDisplaying Data from Linked List :\n\n");
    if(ptr == NULL)
        printf("\nOverflow");
    else{
        while(ptr != NULL){
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
    }
}