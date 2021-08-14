#include<stdio.h>
#include<stdlib.h>

struct node {
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
    printf("\n\nInserting node in begining...!");
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("\nOverflow");
    else{
        printf("\nEnter data value : ");
        scanf("%d",&item);

        if(head == NULL){
            ptr->prev = NULL;
            ptr->next = NULL;
            ptr->data = item;
            head = ptr;
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

void Insert_Last(){
    printf("\n\nInserting Node at last : ");
    int n;
    printf("\nHow many node to be inserted : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        struct node *ptr, *temp;
        int data;
        ptr = (struct node *)malloc(sizeof(struct node));
        if(ptr == NULL)
            printf("\nOverflow");
        else{
            printf("Enter data value : ");
            scanf("%d",&data);
            ptr->data = data;
            if(head == NULL){
                ptr->next = NULL;
                ptr->prev = NULL;
                head = ptr;
            }
            else{
                temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = ptr;
                ptr->prev = temp;
                ptr->next = NULL;
            }
            printf("Node Inserted...!\n");
        }
    }
}

void Insert_Random(){
    printf("\n\nInserting node at a specific position : ");
    struct node *ptr, *temp;
    int data, position, i;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
        printf("\nOverflow");
    else{
        printf("\nEnter position : ");
        scanf("%d",&position);
        temp = head;
        int c = 1,location = position-1;
        while(c != location){
            temp = temp->next;
            if(temp == NULL){
                // printf("%d ",position);
                printf("There are less than %d elements",position);
                return;
            }
            c++;
        }
        printf("Enter data value : ");
        scanf("%d",&data);
        ptr->data = data;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        temp->next->prev = ptr;
        printf("Node Inserted...!");
    }
}

void Delete(){
    printf("\n\nDeleting a node : ");
    struct node *ptr, *temp;
    int position,c=1;
    printf("\nEnter position : ");
    scanf("%d",&position);
    temp = head;
    while(c != position)
    {
        ptr = temp;
        temp = temp->next;
        if(temp == NULL){
            printf("Node can't be deleted");
            return;
        }
        c++;
    }
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    printf("Node Deleted...!");
}

void Delete_Begining(){
    struct node *ptr;
    printf("\n\nDeleting Node from begining : ");
    if(head == NULL)
        printf("\nUnderflow");
    else if(head->next == NULL){
        free(head);
        head == NULL;
        printf("\nOnly node of the list deleted");
    }
    else{
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\nNode Deleted...!");
    }
}

void Delete_Last(){
    printf("\n\nDeleting node from last : ");
    struct node *ptr;
    if(ptr == NULL)
        printf("\nUnderflow");
    else if(head->next == NULL){
        free(head);
        head == NULL;
        printf("\nOnly node of the list deleted");
    }
    else{
        ptr = head;
        if(ptr->next != NULL)
            ptr = ptr->next;
        ptr->prev->next = NULL;
        free(ptr);
        printf("\nNode Deleted...!");
    }
}

void Delete_Key(){
    printf("\n\nDeleting Node using Key : ");
    struct node *ptr, *temp;
    int key;
    printf("\nEnter key to delete : ");
    scanf("%d",&key);
    temp = head;
    while(temp->data != key){
        ptr = temp;
        temp = temp->next;
    }
    temp->next->prev = ptr;
    ptr->next = temp->next;
    free(temp);
    printf("Node Deleted...!");
}

void Search_Key(){
    printf("\n\nSearching position of key : ");
    struct node *temp;
    int key, flag,i=1;
    temp = head;
    if(temp == NULL)   
        printf("\nEmpty List");
    else{
        printf("\nEnter Key : ");
        scanf("%d",&key);
        while (temp != NULL){
            if(temp->data == key){
                printf("Item found at position : %d", i);
                flag = 0;
            }
            i++;temp = temp->next;
        }
        if (flag != 0){
            printf("Item not FOUND....!");
        }
    }
}

void Display(){
    struct node *temp;
    printf("\n\nDisplaying data : ");
    temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}