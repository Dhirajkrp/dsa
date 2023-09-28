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

//function to insert at first
void insertFirst(){
    Node* newNode = createNode();
    if(tail == NULL){
    	 tail = newNode;
        tail->next = newNode;
    
    }
    else{
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

//funtion to add at position
void insertPos(){
int pos = 1;
printf("Enter the position you want to insert the node");
scanf("%d" ,&pos);
Node* newNode = createNode();

    //empty list
    if(tail == NULL){
    	tail = newNode;
    	tail->next = newNode;
    	return;
    }

    //insertFirst Logic
    if(pos ==1){
        newNode->next = tail->next;
        tail->next = newNode;
        return;
    }

    Node *itr = tail->next;
    for(int i =1 ; i< pos-1 ;i++){
    	itr = itr->next;
    }
    newNode->next = itr->next;
    itr->next = newNode;

}


//function to add node at the last
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
