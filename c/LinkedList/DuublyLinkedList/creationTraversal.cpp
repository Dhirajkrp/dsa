#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

typedef struct node Node;

Node *start = NULL , *end = NULL;

//function to create a new Node
Node* createNode(){
    Node* newNode = (Node*) malloc(sizeof(Node));
    printf("Enter the data for the node: ");
    scanf("%d" ,&newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

//function to add node at the end
void insertLast(){
    Node* newNode = createNode();
    if(start == NULL){
        start = newNode;
        end= newNode;
    }
    else{
        end->next = newNode;
        newNode->prev = end;
        end = newNode;
    }
}

//function to create the list
void createList(){
    int choice =1;
    while(choice ==1){
        insertLast();
        printf("Do you want to add more node? 1/0 : ");
        scanf("%d" ,&choice);
    }
}

//funciton to print list from start
void printListStart(){
    Node *itr = start;
    printf("\nThe list From Start is : ");
    while(itr != NULL){
        printf("%d ->" ,itr->data);
        itr = itr->next;
    }
    printf("Null");
}

//funciton to print list from end
void printListEndt(){
    Node *itr = end;
    printf("\nThe list From Start is : ");
    while(itr != NULL){
        printf("%d ->" ,itr->data);
        itr = itr->prev;
    }
    printf("Null");
}
int main(){

    createList();
    printListStart();
    printListEndt();

return 0;
}
