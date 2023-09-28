#include <stdio.h>
#include <stdlib.h>

## Linked List Introduction

A linked list is a data structure that consists of a sequence of nodes, where each node contains a value and a pointer to the next node in the sequence. The first node in the sequence is called the head node, and the last node is called the tail node. Linked lists are often used to implement dynamic data structures that can grow or shrink in size during program execution.

Linked lists can be used to implement various data structures, such as stacks, queues, and hash tables. One advantage of linked lists is that they can be modified efficiently, since adding or removing an element from a linked list typically requires only changing a few pointers, rather than moving a large block of memory as with arrays.

## Difference Between LinkedList And Arrays

**Memory allocation:** Arrays are allocated in contiguous memory locations, meaning that all the elements of an array are stored together in memory. In contrast, linked lists are allocated in a non-contiguous fashion, with each element (or node) pointing to the next element in the list.

**Size:** The size of an array is fixed at the time of its creation, whereas the size of a linked list can be dynamically adjusted during program execution.

**Access time:** Accessing an element in an array is fast, because the position of each element can be computed directly using its index. In contrast, accessing an element in a linked list requires traversing the list from the head node until the desired element is reached. This makes access time slower in linked lists than in arrays.

**Insertion and deletion:** Inserting or deleting an element in an array requires shifting all the elements after it to make room or fill the gap. This can be slow for large arrays. In contrast, insertion or deletion in a linked list requires only updating a few pointers, which can be faster and more efficient.

**Memory usage:** Arrays use contiguous memory, which can be less memory-efficient than linked lists, especially when the array needs to be resized. Linked lists, on the other hand, use dynamic memory allocation and can be more memory-efficient.

In general, arrays are a good choice when the size of the data is known in advance and random access to elements is important. Linked lists are a good choice when the size of the data is not known in advance and when insertion or deletion of elements is frequen

struct node{
int data;
struct node \*next;
};

typedef struct node Node;

Node *start = NULL , *end = NULL;

Node* createNode(){
Node* newNode = (Node\*) malloc(sizeof(Node));
printf("Enter the data for the node: ");
scanf("%d" ,&newNode->data);
newNode->next = NULL;
return newNode;
}

//function to add node at the start
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

//function to add node at the begining of the list.
void insertFirst(){
Node\* newNode = createNode();

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
Node\* newNode = createNode();

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

//function to create a list using insertFirst
//i.e inserts newNode at the begining.
void createListFormStart(){
int choice =1;
while(choice ==1){
insertFirst();
printf("Do you want to add more node? 1/0 : ");
scanf("%d" ,&choice);
}
}

//funciton to print list
void printList(){
Node \*itr = start;
printf("\nThe list is : ");
while(itr != NULL){
printf("%d ->" ,itr->data);
itr = itr->next;
}
printf("Null");
}

//function to find the length of the list
int lengtht(){
Node \*itr = start;
int count =0;
while(itr != NULL){
itr = itr->next;
count++;
}
return count;
}

//function to check if the list contains a value
bool contains(int val){
Node \*itr = start;
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
Node\* temp = start;
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
Node\* temp = itr->next;
end = itr;
free(temp);
end->next = NULL;
}

//function to delete at position

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
Node\* temp = itr->next;
itr->next = itr->next->next;
if(temp == end){
end= itr;
}
free(temp);
}

int main(){

    createList();
    printList();

return 0;
}
