#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next; 
};

typedef struct node Node;


//declaring the start and end globally so that all the functions can access it.
Node *start = NULL , *end = NULL;


void insertLast(int val){
	
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	
	temp->data = val;
	temp->next =NULL;
	
	if(start == NULL){
		start = temp;
		end = temp;
	}
	
	else{
		end->next = temp;
		end = temp;
	}
	
		
}

void insertFirst(int val){
	
	Node *temp = NULL;
	temp = (Node*)malloc(sizeof(Node));
	
	temp->data =val;
	temp->next = NULL;
	
	if(start == NULL){
		start = temp;
	}
	else{
		
	temp->next = start;
	start = temp;
	
	}
	
	 
}

void printList(Node *start){
	
	Node *itr = start;
	printf("The Linked List is : \n");
	while(itr != NULL){
		printf("%d ->" , itr->data);
		itr = itr->next;
	}
	printf("NULL");
}

int main(){
	
	
	insertFirst(10);
	insertFirst(7);
	insertFirst(5);

	
//	insertLast(13);
//	insertLast(17);

	
	printList(start);
		 
	return 0;
}
