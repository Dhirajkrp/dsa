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

//function to insert at first
void insertFirst(){
Node* newNode = createNode();
    if(start == NULL){
        start = newNode;
        end = newNode;
    }
    else{
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
}

//funtion to add at position
void insertPos(){
int pos = 1;
printf("Enter the position you want to insert the node");
scanf("%d" ,&pos);
Node* newNode = createNode();

    if(start == NULL){
        start = newNode;
        end = newNode;
        return;
    }
    if(pos ==1){
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
        return;
    }
    Node *itr = start;
    for(int i =1 ; i< pos-1 ;i++){
        itr = itr->next;
    }
    newNode->next = itr->next;
    itr->next->prev = newNode;
    itr->next = newNode;
    newNode->prev = itr;

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


int main(){
    
    bool flag = true;
	int choice =1;
	while(flag){
		
		switch (choice){
			case 1:
				insertFirst();
				break;
				
			case 2:
				insertLast();
				break;
			case 3:
				insertPos();
				break;
			case 4:
				printList();
				break;
			case 5:
				flag  = false;
				break;
			default:
				printf("Please enter a valid choice");
				break;
		}
	
		
		if(flag){
			printf("\nPlease Enter you choice :\n ");
			printf("\n1.insertFirst\n2.insertLast\n3.insertPos\n4.printList\n5 Exit\n");
			printf("Your choice : ");
			scanf("%d" , &choice);
		}
	}

return 0;
}
