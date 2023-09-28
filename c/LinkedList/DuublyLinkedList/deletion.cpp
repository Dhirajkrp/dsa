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

//function to delete First element
void deleteFirst(){
    if(start == NULL) return;
    Node* temp = start;
    start= start->next;
    free(temp);
}


//function to delete last node
void deleteLast(){

    if(start==NULL) return;

    //only one element
    if(end == start){
        Node* temp = start;
        start = NULL;
        end = NULL;
        free(temp);
        return;
    }

    Node* temp = end;
    end  = end->prev;
    end->next = NULL;
    free(temp);
}

//function to delete from a position

void deletePos(){
    int pos;
    printf("\nEnter the pos from where you want to delete: ");
    scanf("%d",&pos);

    //implementing deleteFirst()
    if(pos == 1){
    Node* temp = start;
    start= start->next;
    free(temp);
    return;
    }

    Node* itr = start;
    for(int i=1; i< pos-1 ;i++){
    itr = itr->next;
    }

    Node* temp = itr->next;
    //i.e last element
    //implement deleteLast

    if(temp == end){
    end  = end->prev;
    end->next = NULL;
    free(temp);
    }

    itr->next = temp->next;
    temp->next->prev = itr;
    free(temp);
}


int main(){
	
	createList();
    
    bool flag = true;
	int choice =10;
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
			printf("\nChoose between 1-5:\n");
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
