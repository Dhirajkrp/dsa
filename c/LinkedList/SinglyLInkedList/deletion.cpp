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


//function to delete First element
void deleteFirst(){
    if(start == NULL) return;

    //only one node in the list
    if(start->next ==NULL){
        end = NULL;
    }
    Node* temp = start;
    start= start->next;
    free(temp);
}

//function to delete last node
void deleteLast(){

    if(start==NULL) return;

    //only one element
    if(start->next == NULL){
        Node* temp = start;
        start = NULL;
        free(temp);
        end = start;
        return;
    }

    Node* itr = start;
    while(itr->next->next !=NULL){
        itr = itr->next;
    }

    Node* temp = itr->next;
    end = itr;
    free(temp);
    end->next = NULL;
}

//function to delete from a position

void deletePos(){
    int pos;
    printf("\nEnter the pos from where you want to delete: ");
    scanf("%d",&pos);

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
