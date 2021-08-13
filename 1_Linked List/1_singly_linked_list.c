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

int main()
{
    int option=0;
    while(option != 9){
        printf("\n\n=================================");
        printf("\nChoose the following option\n");
        printf("1. Inserting Node at begining\n");
        printf("2. Inserting Node at last\n");
        printf("3. Inserting Node at random position\n");
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

void Insert_Random(){
    printf("\n\nInsert node at random Position :\n");
    int i,position,item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("\nOverflow");
    else{
        printf("Enter data value : ");
        scanf("%d",item);
        ptr->data = item;
        printf("Enter the position at which node to be inserted : ");
        scanf("%d",position);
        temp = head;
        for(i=0;i<position;i++){
            temp = temp->link;
            if(temp == NULL){
                printf("Node Can't be inserted\n");
                return ;
            }
        }
        ptr->link = temp->link;
        temp->link = ptr;
        printf("Node Inserted");
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