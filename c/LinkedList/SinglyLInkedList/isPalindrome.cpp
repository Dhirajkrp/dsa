#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *newnode;
struct node*temp=NULL;
struct node* start=NULL;
int create_list(){
	int count=0;
	int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(start==NULL){
        start=newnode;
        temp=start;
        count++;
      }
      else{
          temp->next=newnode;
          temp=newnode;
          count++;
      } 
        printf("Do you want to enter more nodes: 1/0");
        scanf("%d",&choice);
    }
    return count;
}
int palin_check()
{
    int i = 0, j;
    int count=create_list();
    struct node *one, *two;
     while (i!=count/2){
         one=two=start;
        for (j=0;j<i;j++){
            one=one->next;
        }
        for (j=0;j<count-(i + 1);j++){
            two=two->next;
        }
        if (one->data!=two->data){
            return 0;
        }
        else{
            i++;
        }
    }
    return 1;
}
int main(){
    int result = palin_check();
    if (result == 1){
        printf("List is a palindrome.\n");
    }
    else{
        printf("List is not a palindrome.\n");
    }
    return 0;
}


