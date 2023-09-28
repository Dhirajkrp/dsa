#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next; 
};

typedef  struct node Node;

Node *start = NULL , *end = NULL;

//function to add node at the start
void insertLast(){
    Node* newNode = (Node*) malloc(sizeof(Node));
    printf("Enter the data for the node: ");
    scanf("%d" ,&newNode->data);
    newNode->next = NULL;

    if(start == NULL){
        start = newNode;
        end= newNode;
    }
    else{
        end->next = newNode;
        end = newNode;
    }

}

//function to add node at the begining of the list.
void insertFirst(){
	Node* newNode = (Node*) malloc(sizeof(Node));
    printf("Enter the data for the node:");
    scanf("%d" ,&newNode->data);
    newNode->next = NULL;
    
    if(start == NULL){
    	start = newNode;
    	end = newNode;
	}
	else{
		newNode->next = start;
		start = newNode;
	}
	
}

//funcction to insert at a given pos
void insertPos(){
	
	int pos = 1;
	printf("Enter the position you want to insert the node");
	scanf("%d" ,&pos);
	Node* newNode = (Node*) malloc(sizeof(Node));
    printf("Enter the data for the node:");
    scanf("%d" ,&newNode->data);
    newNode->next = NULL;
    
    if(start == NULL){
    	start = newNode;
    	end = newNode;
    	return;
	}
	if(pos ==1){
		newNode->next = start;
		start = newNode;
	}
	Node *itr = start;
	for(int i =1 ; i< pos-1 ;i++){
		itr = itr->next;
	}
	
	newNode->next = itr->next;
	itr->next = newNode;	
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

//function to find the length of the list
int lengtht(){
	Node *itr = start;
	int count =0;
	while(itr != NULL){
		itr = itr->next;
		count++;
	}
	
	return count;
}

//function to check if the list contains a value
bool contains(int val){
	Node *itr = start;
	
	while(itr != NULL){
		if(itr->data == val) return true;
		itr = itr->next;
	}
	return false;
	
}

//function to sort the list using bubble sort.
void sort(){
	
	Node* prev = start;
	Node* cur;
	while(prev->next !=NULL){
		cur = prev->next;
		while(cur != NULL){
		
			if(prev->next > cur->next){
				int temp = prev->data;
				prev->data = cur->data;
				cur->data = temp;
			}
			cur = cur->next;
		}
	prev = prev->next;
	}
}

//function to delete First element
void deleteFirst(){
	if(start == NULL) return;
	
	Node* temp = start; 
	start= start->next;
	free(temp);
}

//function to delete last node
void deletelast(){
	Node* itr = start;
	if(start==NULL) return;
	
	if(start->next == NULL){
		Node* temp = start; 
		start = NULL;
		free(temp);
		end = start;
		return;
	}
	
	while(itr->next->next !=NULL){
		itr = itr->next;
		
	}
	Node* temp =  itr->next;
	end = itr;
	free(temp);
	end->next = NULL;
}

//function to delete at position 

void deletePos(){
	int pos;
	printf("\nEnter the pos from where you want to delete: ");
	scanf("%d" , &pos);
	
	if(pos == 1){
		Node* temp = start; 
		start = NULL;
		free(temp);
		end = start;
		return;
		
	}
	Node* itr = start;
	for(int i=1; i< pos-1 ;i++){
		itr = itr->next;
	}
	
	Node* temp = itr->next;
	itr->next = itr->next->next;
	
	if(temp == end){
		end= itr;
	}
	free(temp);	
}


int main(){

createList();
//insertFirst();
//insertPos();



printList();

//printf("The length of the list is :%d" , lengtht());
//
//printf("\nAfter sorting:\n");
//sort();
//printList();

//deletePos();
deleteFirst();

printList();

return 0;
}












