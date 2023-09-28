#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node *next;
struct node *prev;
};

typedef struct node Node;

Node *tail = NULL;

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
    if(tail == NULL){
        tail = newNode;
        tail->next = newNode;
    }
    else{
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next->prev = newNode;
        tail->next = newNode;
        tail = newNode;
    }
}
//function to delete first node
void deleteFirst(){
    if(tail == NULL) {
    	printf("\nThe list is empty.\n");
		return;
	}

    Node* temp = tail->next;
    tail->next= tail->next->next;
    tail->next->prev = tail;
    free(temp);
}
//function to delete last node
void deleteLast(){

    //empty list
    if(tail == NULL) {
    	printf("\nThe list is empty.\n");
		return;
	}

    Node* temp = tail;

    tail->prev->next = tail->next;
    tail->next->prev = tail->prev;
    tail = tail->prev;
    free(temp);
}

//function to delete from a position

void deletePos(){
    int pos;
    printf("\nEnter the pos from where you want to delete: ");
    scanf("%d",&pos);

    if(pos == 1){
    Node* temp = tail->next;
    tail->next= tail->next->next;
    tail->next->prev = tail;
    free(temp);
    return;
    }

    Node* itr = tail->next;
    for(int i=1; i< pos-1 ;i++){
    itr = itr->next;
    }

    Node* temp = itr->next;
    itr->next = itr->next->next;
    temp->next->prev = itr;

    if(temp == tail){
    tail= itr;
    }

    free(temp);
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
    
    bool flag = true;
	int choice =1;
	while(flag){
		
		switch (choice){
			case 1:
				deleteFirst();
				break;
				
			case 2:
				deleteLast();
				break;
			case 3:
				deletePos();
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
			printf("\n1.deleteFirst\n2.deletetLast\n3.deletePos\n4.printList\n5 Exit\n");
			printf("Your choice : ");
			scanf("%d" , &choice);
		}
	}

return 0;
}
