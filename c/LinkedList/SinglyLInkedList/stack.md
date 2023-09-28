# Stacks

A stack is a simple data structure that follows the Last In First Out (LIFO) or First In Last Out(FILO) principle. In a stack, elements are added and removed from the same end, called the top. The last element added to the stack is the first one to be removed.

A real-world example of a stack is a pile of dishes. When you wash dishes, you add them to the top of the pile. When you need to use a dish, you take it from the top of the pile. Similarly, when you dry a dish, you add it to the top of the pile. This way, the dishes are always used in the reverse order of when they were washed.

In computer science, stacks are used in a variety of applications, such as implementing function calls in programming languages, evaluating arithmetic expressions, and parsing languages.

The two most common operations on a stack are:

- `push()`: adds an element to the top of the stack
- `pop()`: removes the element at the top of the stack

Other operations that are sometimes used with stacks include:

- `peek()`: returns the element at the top of the stack without removing it
- `isEmpty()`: returns `true` if the stack is empty, and `false` otherwise

Stacks can be implemented using an array or a linked list. The choice of implementation depends on the particular use case and the programming language being used.

## Advantages of using a stack data structure

1. **Efficiency**: Stacks have a constant time complexity O(1) for both push and pop operations, making them highly efficient for storing and retrieving elements.

2. **Memory management**: Stacks use a fixed amount of memory, making them ideal for managing memory in applications with limited memory.

3. **Recursion**: Stacks are useful in recursive algorithms where each recursive call adds a new frame to the stack and when the function returns, the most recent frame is removed from the stack.

4. **Undo operations**: Stacks are commonly used to implement undo operations in applications, where each action that modifies the state of the application is pushed onto the stack and when the user requests to undo an operation, the most recent action is popped from the stack and its inverse is applied to the application state.

5. **Constant Time Operation** : Since insertion and deletion is only done from one end these operations only take a constant time , thus in situations where insertion and deletion operations are frequent ,stack can be a useful data structure.

## Disadvantages of using a stack data structure

1. **Limited functionality**: Stacks only allow elements to be added or removed from one end, which can be limiting for some applications that require more complex operations.

2. **No random access**: Unlike arrays or linked lists, stacks do not allow for random access of elements. This means that you cannot access elements in the middle of the stack without first removing all the elements above it.

3. **Stack overflow**: Stacks have a fixed size, which means that they can overflow if too many elements are added. This can lead to data loss or crashes in the program.

4. **Recursive depth limitations**: Recursion, which is a common use case for stacks, can cause issues if the recursion depth becomes too deep. This can cause the stack to overflow, leading to program crashes or other errors.

## Ways of implementing stack

## Using Array

One way to implement a stack is to use an array. In this implementation, the stack is represented as a fixed-size array, and a variable called top keeps track of the top element in the stack. When an element is pushed onto the stack, it is added to the array at the index top, and top is incremented. When an element is popped from the stack, the element at index top-1 is removed, and top is decremented.

This is useful when the size of the stack is known at the runtime.

## Menu Driven program for stack using array

```
#include <stdio.h>
#include <stdlib.h>

int stack[10] = {0};
int N = 10;
int top = -1;


void push(){
	if(top == N-1){
		printf("Stack is full\n");
		return;
	}
	int val;
	printf("Enter the value you want add in the stack: ");
	scanf("%d" ,&val);
	top ++;
	stack[top] = val;

}

void pop(){
	if(top ==-1){
		printf("Stack is empty:\n");
		return;
	}
	printf("The value deleted is : %d" ,stack[top]);
	top--;

}

void peek(){
	if(top == -1){
	printf("The stack is empty :\n");
	}
	else{
	printf("\nThe element at the top is : %d" , stack[top]);
	}
}

void printStack(){
	printf("The stack is : ");
	for(int i = top ; i>= 0 ;i--){
		printf("%d ->" , stack[i]);
	}
	printf("Null");
}

int main(){
	printf("You have a stack of size 10 :\n");

	bool flag = true;
	int choice =1;
	while(flag){

		switch (choice){
			case 1:
				push();
				break;

			case 2:
				peek();
				break;
			case 3:
				pop();
				break;
			case 4:
				printStack();
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
			printf("\n1.Push\n2.Peek\n3.Pop\n4.Print Stack\n5 Exit\n");
			printf("Your choice : ");
			scanf("%d" , &choice);
		}

	}
	return 0;
}
```

## Using LinkedList

Another way to implement a stack is to use a linked list. In this implementation, the stack is represented as a linked list, where each node in the list contains an element and a pointer to the next node in the list. A variable called top points to the top element in the stack.

When an element is pushed onto the stack, a new node is created with the element, and the next pointer of the new node is set to the current top node. Then, top is updated to point to the new node.

When an element is popped from the stack, the node at the top of the stack is removed, and top is updated to point to the next node in the list.

As we have discussed the functions of the linked list lets see how can we use them .

For stack the push and pop will and peek are performed on the top , if we compare to linkedlist it is similar to insertFirst and deleteFirst.

## Comparison with linked list

- push() : insertFirst()
- pop() : deleteFirst()
- printStack() : printlist()

we just have to implement the peek() which is a one liner

```
void peek(){
    printf("The top of the stack is %d :" , top->data);
}
```

we can use two more helper functions as isEmpty() and length()

```
bool isEmpty(){
    return top == NULL;
    //same as saying if top == NULL return true ,else false.
}
```

As the size of the list can grow , there is no need to check if the stack is full.

```
int length(){
    return length;
}
```

For this we use a variable `length` which is initially 0.
As we perform push() and pop() we update the length to keep track of the size.

The `struct node` and `createNode()` will be the same as singly Linkedist.

## Menu Driven program for stack using linkedlist

```
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node Node;
Node *top = NULL;
int len = 0;

Node* createNode(){
	Node *newNode;
	newNode = (Node*)malloc(sizeof(Node));
	printf("Enter the value you want to add :");
	scanf("%d" , &newNode->data);
	newNode->next = NULL;

	return newNode;
}

bool isEmpty(){
	return top==NULL;
}

int length(){
	return len;
}

void push(){
	Node *newNode = createNode();
	if(top == NULL){
		top = newNode;
	}
	else{
		newNode->next = top;
		top = newNode;
	}
	len++;
}

void peek(){
	printf("The value at the top is :%d " , top->data);
}


void pop(){

	if(isEmpty()) {
		printf("The stack is Empty \n");
		return;
	}
	Node *temp = top;
	top = top->next;
	printf("The value deleted was :%d" , temp->data);
	free(temp);
	len--;

}

void printStack(){
	Node *itr = top;
	printf("The stack is :");
	while(itr != NULL){
		printf("%d ->", itr->data);
		itr = itr->next;
	}
	printf("NULL");
}

int main(){

	bool flag = true;
	int choice =1;
	while(flag){

		switch (choice){
			case 1:
				push();
				break;

			case 2:
				peek();
				break;
			case 3:
				pop();
				break;
			case 4:
				printStack();
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
			printf("\n1.Push\n2.Peek\n3.Pop\n4.Print Stack\n5 Exit\n");
			printf("Your choice : ");
			scanf("%d" , &choice);
		}

	}
	return 0;
}
```
