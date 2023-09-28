#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
 struct node *newnode;
 struct node*temp=NULL;
 struct node* start=NULL;

void create_list(){
        int choice=1;
        while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for the Node : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(start==NULL){
            start=newnode;
            temp=start;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        } 
        printf("Do you want to enter more nodes: 1/0");
        scanf("%d",&choice);
    }
}
void find_mid(){
	struct node *slow=start;
	struct node *fast=start;
	if(start!=NULL){
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
	    }
    }
    printf("Middle element of the linked list is %d",slow->data);
}
int main(){
	create_list();
	find_mid();
    return 0;
}
