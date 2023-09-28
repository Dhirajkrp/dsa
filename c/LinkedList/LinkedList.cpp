#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next; 
};

typedef struct node Node;

int main(){
	
	Node *start =NULL , *end =NULL;
	
	int choice = 1;
	
	while(choice==1){
		
		Node *temp;
		temp = (Node*)malloc(sizeof(Node));
		printf("Enter the value for the node:");
		scanf("%d" ,&temp ->data);
		temp->next =NULL;
		
		if(start == NULL){
			start = temp;
			end = temp;
		}
		else{
			end->next = temp;
			end = temp;
		}
		
		printf("Do you want to add more node ? \n");
		scanf("%d",&choice);
	}
	
	Node *itr = start;
	
	printf("The Linked List is : \n");
	while(itr != NULL){
		printf("%d ->" , itr->data);
		itr = itr->next;
	}
	printf("NULL\n");
	return 0;
}
