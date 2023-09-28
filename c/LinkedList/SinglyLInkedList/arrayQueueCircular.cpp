#include <stdio.h>
# define max 6 
int queue[max];
int front = -1;
int rear = -1;
void enqueue(int x){
	if(front == -1 && rear == -1){
		front = 0;
		rear = 0;
		queue[rear] = x;
	}
	else if((rear+1)%max == front){
		printf("Queue is Overflow.....");
	}else{
		rear = (rear+1) %max;
		queue[rear] = x;
	}
}

int dequeue(){
	if(front == -1 && rear == -1){
		printf("Queue is underflow...");
	}else if(front == rear){
		printf("\nThe deleted element is: %d",queue[front]);
		front = -1;
		rear = -1;
	}
    else{
		printf("\n The deleted element is: %d",queue[front]);
		front = (front + 1) %max;
	}
}

void display(){
	int i = front;
	if(front == -1 && rear == -1){
		printf("\n Queue is empty");
	}
    else{
		printf("\nElements in a Queue are: ");
		while(i<=rear){
			printf(" %d",queue[i]);
			i = (i+1)%max;
		}
	}
}
int main()  {  
    int choice=1,data;     
    while(choice<4 && choice!=0) {  
        printf("\n1.Insert an element");  
        printf("\n2.Delete an element");  
        printf("\n3.Display");  
        printf("\nEnter your choice: ");  
        scanf("%d", &choice);  
        switch(choice) {  
            case 1:  
                printf("\nEnter the element which is to be inserted: ");  
                scanf("%d", &data);  
                enqueue(data);  
                break;  
            case 2:  
                dequeue();  
                break;  
            case 3:  
                display();
                break;

        }
    }  
    return 0;  
} 
