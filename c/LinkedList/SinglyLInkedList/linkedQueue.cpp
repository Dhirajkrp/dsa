#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct node *front = NULL,*rear = NULL;
void enqueue(int x){
	struct node *newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	newnode ->next = NULL;
	newnode->data =x;
	if (front == 0 && rear == 0){
		front = rear = newnode;
	}else{
		rear ->next = newnode;
		rear = newnode;
	}	
}
void display(){
	struct node *temp;
	if (front == 0 && rear == 0){
		printf("Empty");
	}else{
		temp = front;
		while(temp != NULL){
			printf("\nData is %d",temp->data);
			temp = temp->next;
		}
	}
}

void dequeue(){
	struct node *newnode;
	struct node *temp;
	temp = front;
	if (front == 0 && rear == 0){
		front = rear = newnode;
	}else{
		printf("\nDeleted item is: %d",front ->data);
		front = front->next;
		free(temp);
	}
}

void peek(){
	struct node *newnode;
	if (front == 0 && rear == 0){
		front = rear = newnode;
	}else{
		printf("\nTop most element is %d",front->data);
	}
}

int main(){
	
	int queue[10];
	int size ;
	int choice = 1;
	int data;
	
	printf("The operations you can perform are: ");
	printf("\n1. Insert an element\n2.Delete \n3.Top most element\n4.Display the list");
	
	
	while(choice){
		printf("\nEnter the choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("\nEnter data: ");
				scanf("%d",&data);
				enqueue(data);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			default:
				printf("Invalid choice: ");
				break;
		}
		printf("\nDo you want to perform more operations: ");
		scanf("%d",&choice);
	}
	
	
	return 0;
}
