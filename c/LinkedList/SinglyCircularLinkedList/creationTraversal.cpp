#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *next;
};

typedef struct node Node;

Node *tail = NULL;

//function to create a new Node
Node* createNode(){
    Node* newNode = (Node*) malloc(sizeof(Node));
    printf("Enter the data for the node: ");
    scanf("%d" ,&newNode->data);
    newNode->next = NULL;
    return newNode;
}

//function to add node at the end
void insertLast(){
    Node* newNode = createNode();
    if(tail== NULL){
        tail = newNode;
        tail->next = newNode;
    }
    else{
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
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

//funciton to print list
void printList(){
    Node *itr = tail->next;
    printf("\nThe list is : ");
    while(itr->next != tail->next){
        printf("%d ->" ,itr->data);
        itr = itr->next;
    }
    printf("%d -> %d" ,tail->data , tail->next->data);
}

int main(){

    createList();
    printList();

return 0;
}
