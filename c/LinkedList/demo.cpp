#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next; 
};

typedef struct node Node;

int main(){
	
	Node *temp = NULL;
	
	temp = (Node*)malloc(sizeof(Node));
	int val;
	
	printf("Enter the value for node:");
	scanf("%d" ,&temp->data);
	
	
	printf("%d" , temp->data);
	
	return 0;
}
