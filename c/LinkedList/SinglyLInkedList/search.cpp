#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *next;
};

typedef struct node Node;

Node *start = NULL , *end = NULL;

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
    if(start == NULL){
        start = newNode;
        end= newNode;
    }
    else{
        end->next = newNode;
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

//funciton to print list
void printList(){
    Node *itr = start;
    printf("\nThe list is : ");
    while(itr != NULL){
        printf("%d ->" ,itr->data);
        itr = itr->next;
    }
    printf("Null");
}

//function to check if the list contains a value
int contains(int val){
    Node *itr = start;
    while(itr != NULL){
        if(itr->data == val) return 1;
        itr = itr->next;
    }
    return 0;
}

int main(){

	int ser;
    createList();
        printList();
    printf("\nEnter the Value you want to search : ");
    scanf("%d" , &ser);
	printf(contains(ser) ? "Data Found" :"Data Not Found");

return 0;
}
