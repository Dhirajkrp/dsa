# Introduction to Linked List

## Linked Lists

A linked list is a data structure that consists of a sequence of nodes, where each node contains a value and a pointer to the next node in the sequence. The first node in the sequence is called the head node, and the last node is called the tail node. Linked lists are often used to implement dynamic data structures that can grow or shrink in size during program execution.

### Advantages of Linked Lists

- Linked lists can be used to implement various data structures, such as stacks, queues, and hash tables.
- They can also be used to implement graph algorithms and to represent sparse matrices.
- One advantage of linked lists is that they can be modified efficiently, since adding or removing an element from a linked list typically requires only changing a few pointers, rather than moving a large block of memory as with arrays.

### Differences Between Arrays and Linked Lists

| Arrays                                           | Linked Lists                                              |
| ------------------------------------------------ | --------------------------------------------------------- |
| Allocated in contiguous memory locations         | Allocated in a non-contiguous fashion                     |
| Size is fixed at the time of creation            | Size can be dynamically adjusted during program execution |
| Access time is fast                              | Access time is slower                                     |
| Insertion and deletion require shifting elements | Insertion and deletion require updating pointers          |
| Can be less memory-efficient                     | Can be more memory-efficient                              |

In general, arrays are a good choice when the size of the data is known in advance and random access to elements is important. Linked lists are a good choice when the size of the data is not known in advance and when insertion or deletion of elements is frequent.

## Types of Linked Lists

There are several different types of linked lists, each with its own characteristics and use cases. The main types of linked lists are:

### 1. Singly Linked List

A singly linked list is the simplest type of linked list. Each node in a singly linked list contains a value and a pointer to the next node in the sequence. The last node in the sequence points to `null`. Singly linked lists are used in many applications where traversal of the list only needs to be in one direction.

### 2. Doubly Linked List

A doubly linked list is a type of linked list where each node has two pointers: one to the next node in the sequence, and one to the previous node in the sequence. This allows for bidirectional traversal of the list. Doubly linked lists are commonly used in applications where it is necessary to traverse the list in both directions.

### 3. Circular Linked List

A circular linked list is a type of linked list where the last node in the sequence points back to the first node in the sequence, creating a loop. Circular linked lists can be either singly or doubly linked. They are used in many applications where a list needs to be processed repeatedly in a loop.

#### 3.1 Singly Circular Linked List

In a singly circular linked list, the last node in the sequence points to the first node, creating a loop. This type of linked list is useful for applications where traversal of the list needs to start again from the beginning after reaching the end.

#### 3.2 Doubly Circular Linked List

A doubly circular linked list is similar to a singly circular linked list, but each node has two pointers: one to the next node in the sequence and one to the previous node in the sequence. This allows for bidirectional traversal of the list in a loop.

## Libraries and common functions used in a linkedlist

### 1. stdlib.h

The `stdlib.h` library in C provides functions for dynamic memory allocation, which can be used to create and manipulate linked lists.

#### Functions:

- `malloc(size_t size)`: Allocates a block of memory of the specified size and returns a pointer to the first byte of the block. This function is commonly used to create a new node in a linked list.
- `free(void *ptr)`: Deallocates the memory previously allocated by `malloc()`. This function is commonly used to remove a node from a linked list.

### 2. stdio.h

The `stdio.h` library in C provides functions for input and output operations.

#### Functions:

- `printf()`: Prints formatted output to the standard output stream (usually the console). This function is commonly used to display the contents of a linked list to the user.
- `scanf()`: Reads formatted input from the standard input stream (usually the keyboard). This function is commonly used to read user input and add nodes to a linked list.

## Few Useful changes

Writing **struct node \*var_name** ,everytime to declare a varible can get time consuming thus to shorten our work
we can use the **typedef** to give a shorthand to our newly created datatype

```
typedef struct node Node;
Node *start;
```

One more thing ,instead of declaring the (start ,end) or (head,tail) pointers inside the main function we can define them globally outside the main so that they are easily accessible to all the functions we create later.

# Singly Linked List

In a singly linked list, each element in the list is called a node. Each node contains two fields: a data field and a pointer field.

The data field is used to store the actual value of the node (for example, an integer, string, or any other type of data). The pointer field, on the other hand, is used to store the memory address of the next node in the list.

eg:

```
struct node{
int data;
struct node\* next;
};

```

## An Example code of Singly Linked list

```
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
    printList();

return 0;
}

```

In the above code ,we used 4 functions , lets see them one by one

## 1. Node\* CreateNode()

```
Node* createNode(){
    Node* newNode = (Node*) malloc(sizeof(Node));
    printf("Enter the data for the node: ");
    scanf("%d" ,&newNode->data);
    newNode->next = NULL;
    return newNode;
}

```

This function is used to create a node and return the pointer to the newly created node ,which we can the store as.

```
Node* newNode = createNode();
```

### 2. void insertLast()

```
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

```

This function inserts a new node at the end of the list .
If the start is null ,i.e when list is empty the new node will become the start and end both.
Else if the list has some node , the end is updated to the new node as that will become the new end of our list.

### 3. void createList()

```
void createList(){
    int choice =1;
    while(choice ==1){
        insertLast();
        printf("Do you want to add more node? 1/0 : ");
        scanf("%d" ,&choice);
    }
}
```

This function simply calls the insertLast() function until the user desires ,or wants to add more nodes to the list.

### 4. void printList()

```
void printList(){
    Node *itr = start;
    printf("\nThe list is : ");
    while(itr != NULL){
        printf("%d ->" ,itr->data);
        itr = itr->next;
    }
    printf("Null");
}
```

This is simply a helper function which prints the data of the list.
we first declare an Node `itr` or `temp` whichever you prefer, which traverse through the list and prints the data.
The output will be in the format:

```
The list is : 10->20->30->40->NULL
```

## Advatages of using functionl approach

There are multiple advantages of using this approach such as .

- Reusability : The printList function can be used in all the four types of linked list.
- Easy to debug: It becomes easy to find out which part of the code is not working properly.
- Makes the code a lot more readable .

After defing the functions the only things we need to do in the main() is

```
int main(){
    createList();
    printList();
    return 0;
}
```

It craetes a list ,prints it and simply returns, as simple as that. :)

# Some Useful Functions

## void insertFirst()

```
void insertFirst(){
Node* newNode = createNode();
    if(start == NULL){
    	start = newNode;
    	end = newNode;
    }
    else{
    	newNode->next = start;
    	start = newNode;
    }
}
```

This function adds newly created node at the begining of the list .
we use the createNode() funciton here as well to reduce our work.

It creates a new node ,checks if the start is null ,if yes the newnode will be the start else the new node
will replace the start.

## void insertPos()

```
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
        return;
    }
    Node *itr = start;
    for(int i =1 ; i< pos-1 ;i++){
    	itr = itr->next;
    }
    newNode->next = itr->next;
    itr->next = newNode;

}
```

There are few edge cases in this functions,like firstly if the list is empty , it wont matter what position the user
wants the add the newnode in , so we simply make the newnode the start and return.

Secondly , if the user wants to add at first position , we need to update our start , so we implement the logic of insertFirst.

apart from that , we traverse to one node behind the position and insert the node in between. `itr` and `itr->next`.
If `itr` is confusing you can just use `temp`.

## void createListFromStart()

```
void createListFormStart(){
    int choice =1;
    while(choice ==1){
        insertFirst(); //just changing here
        printf("Do you want to add more node? 1/0 : ");
        scanf("%d" ,&choice);
    }
}

```

This is similar to crateList() the only difference being it implements insertFirst() instead of insertLast().
Again , we ca clearly see the advantage of using functional approach , the createList() can just become a generic fucntion and we just need the chage the insert() function , for example if we are working on the double linked list
all we need to change is the createNode() and insertLast()

```
Node* createNode(){
    Node* newNode = (Node*) malloc(sizeof(Node));
    printf("Enter the data for the node: ");
    scanf("%d" ,&newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL; //just adding a prev here
    return newNode;

}
```

```
void insertLast(){
    Node* newNode = createNode();
    if(start == NULL){
        start = newNode;
        end= newNode;
    }
    else{
        end->next = newNode;
        newMNode->prev = end; //attaching the previous node back
        end = newNode;
    }
}
```

And now we can simply pass this insertLast() int the createList() and our doublyLinked list is ready to go.
No chnages in the printList() or the createList().

## void length()

```
int lengtht(){
    Node *itr = start;
    int count =0;
    while(itr != NULL){
        itr = itr->next;
        count++;
    }
    return count;
}
```

## void contains()

```
//function to check if the list contains a value
bool contains(int val){
    Node *itr = start;
    while(itr != NULL){
        if(itr->data == val) return true;
        itr = itr->next;
    }
    return false;
}
```

## void sort()

```
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
```

## void deleteFirst()

```
//function to delete First element
void deleteFirst(){
    if(start == NULL) return;
    Node\* temp = start;
    start= start->next;
    free(temp);
}
```

## void deleteLast()

```
//function to delete last node
void deletelast(){

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
```

To Delete the last element , we have to traverse to the second last element so that we can delete the last ,and then make the second last the new last.
For this we get two edge cases , first is the common one i.e this list being empty and the second being when the list has one node.
In this case we cannot access the next->next as its next is already Null.

It will be treated as Null->next which will give and error , thus when the list has one node, we simple delete that and make the start as NUll.

## void deletePos()

```
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
```

For this function there will be 2 edge cases

1. when the user wants to delete the start (i.e pos = 1)
   For this we implement deleteFirst .
2. After traversal , if we find out that the node which we want to delete is the last node (end) ,
   We have to update the end to its prevvious node.

# Doubly Linked List

For this we can greatly use the functions which me defined for the Singly Linked List

## Functions which we can use form Singly Linked List

- printList()
- length()
- sort()
- contains()
- createList() : replace the insertLast() with insertLast() of doubly.
- createListFromStart() : replace the insertFirst() with insert of doubly.

## Node

```
struct node{
***
    int data;
    struct node* prev;
    struct node* next;
};

```

## createNode()

```
Node* createNode(){
    Node* newNode = (Node*) malloc(sizeof(Node));
    printf("Enter the data for the node: ");
    scanf("%d" ,&newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
```

## void insertlast()

```
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

```

## void insertFirst()

```
void insertFirst(){
Node* newNode = createNode();
    if(start == NULL){
        start = newNode;
        end = newNode;
    }
    else{
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
}

```

## void insertPos()

```
void insertPos(){
int pos = 1;
printf("Enter the position you want to insert the node");
scanf("%d" ,&pos);
Node* newNode = createNode();

    if(start == NULL){
        start = newNode;
        end = newNode;
        return;
    }
    if(pos ==1){
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
        return;
    }
    Node *itr = start;
    for(int i =1 ; i< pos-1 ;i++){
        itr = itr->next;
    }
    newNode->next = itr->next;
    itr->next->prev = newNode;
    itr->next = newNode;
    newNode->prev = itr;

}

```

The edge cases are the same , just instead of changing one pointer i.e next , we now have to change two pointers ,next and prev.

## void deleteFirst()

```
//function to delete First element
void deleteFirst(){
    if(start == NULL) return;
    Node\* temp = start;
    start= start->next;
    free(temp);
}

```

## void deleteLast()

```
//function to delete last node
void deletelast(){

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
```

For this we have 2 edge cases

1. If the list is Null simply return;
2. If the list has one element delete that and make start and end `NULL`.

In other cases store the end in temp, as we need to delete that, move the end one step back and make its next as `NULL` finally free the temp.

## void deletePos()

```
void deletePos(){
    int pos;
    printf("\nEnter the pos from where you want to delete: ");
    scanf("%d",&pos);

    //implementing deleteFirst()
    if(pos == 1){
    Node* temp = start;
    start = NULL;
    end = NULL;
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
    Node* temp = end;
    end  = end->prev;
    end->next = NULL;
    free(temp);
    }

    itr->next = temp->next;
    temp->next->prev = itr;
    free(temp);
}
```

# Singly Circular

For this we use as single pointer as tail ,since the end always points to the start , we can use this logic to replace the use of start and head with tail.
In short we use `tail->next` instead of `start`. , and `tail` as `end`.

## Functions which we can use from Singly Linked List.

- createNode()
- createList()

## Funcions For Singly Circular

## void insertLast()

```
void insertLast(){
    Node* newNode = createNode();
    if(tail->next == NULL){
        tail->next = newNode;
        tail = newNode;
    }
    else{
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

```

## void insertFirst()

```
void insertFirst(){
    Node* newNode = createNode();
    if(tail->next == NULL){
        tail->next = newNode;
        tail = newNode;
    }
    else{
        newNode->next = tail->next;
        tail->next = newNode;
    }
}
```

The only difference in insertFirst() and insertLast() is that in insertLaast() we update the tail to the newNode as it is the last node in the list now.

## void insertPos()

```
void insertPos(){
int pos = 1;
printf("Enter the position you want to insert the node");
scanf("%d" ,&pos);
Node\* newNode = createNode();

    //empty list
    if(tail->next == NULL){
    	tail->next = newNode;
    	tail = newNode;
    	return;
    }

    //insertFirst Logic
    if(pos ==1){
        newNode->next = tail->next;
        tail->next = newNode;
        return;
    }

    Node *itr = tail->next;
    for(int i =1 ; i< pos-1 ;i++){
    	itr = itr->next;
    }
    newNode->next = itr->next;
    itr->next = newNode;

}
```

## void printList()

```
void printList(){
    Node *itr = tail->next;
    printf("\nThe list is : ");
    while(itr != NULL){
        printf("%d ->" ,itr->data);
        itr = itr->next;
    }
    printf("Null");
}
```

## void deleteFirst()

```
void deleteFirst(){
    if(tail->next == NULL) return;

    Node* temp = tail->next;
    tail->next= tail->next->next;
    free(temp);
}
```

## void deleteLast()

```
void deleteLast(){

    //empty list
    if (tail->next ==NULL return;

    Node* temp = tail->next;
    Node* prev = temp;
    while(tail->next != temp->next){
        prev = temp;
        temp = temp->next;
    }
    prev->next = tail->next;
    tail =  prev;
    free(temp);
}
```

```
void deletePos(){
    int pos;
    printf("\nEnter the pos from where you want to delete: ");
    scanf("%d",&pos);

    if(pos == 1){
    Node* temp = tail->next;
    tail->next= tail->next->next;
    free(temp);
    return;
    }

    Node* itr = start;
    for(int i=1; i< pos-1 ;i++){
    itr = itr->next;
    }

    Node* temp = itr->next;
    itr->next = itr->next->next;

    if(temp == tail){
    tail= itr;
    }
    free(temp);
}
```

# Doubly Circular

Same Logic as Singly Circular , instead of using two pointers `start` and `end` we using a single pointer as `tail`.

## Functions which we can use from Doubly Linked List.

- createNode()
- createList()
- printList(): can be used from Singly Circular.

## Funcions For Doubly Circular

## void insertLast()

```
void insertLast(){
    Node* newNode = createNode();
    if(tail->next == NULL){
        tail->next = newNode;
        tail = newNode;
    }
    else{
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next->prev = newNode;
        tail->next = newNode;
        tail = newNode;
    }
}

```

## void insertFirst()

```
void insertFirst(){
    Node* newNode = createNode();
    if(tail->next == NULL){
        tail->next = newNode;
        tail = newNode;
    }

    else{
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next->prev = newNode;
        tail->next = newNode;
    }
}
```

The only difference in insertFirst() and insertLast() is that in insertLaast() we update the tail to the newNode as it is the last node in the list now.

## void insertPos()

```
void insertPos(){
int pos = 1;
printf("Enter the position you want to insert the node");
scanf("%d" ,&pos);
Node* newNode = createNode();

    //empty list
    if(tail->next == NULL){
    	tail->next = newNode;
    	tail = newNode;
    	return;
    }

    //insertFirst Logic
    if(pos ==1){
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next->prev = newNode;
        tail->next = newNode;
        return;
    }

    Node *itr = tail->next;
    for(int i =1 ; i< pos-1 ;i++){
    	itr = itr->next;
    }
    newNode->next = itr->next;
    newNode->prev = itr;
    itr->next->prev = newNode;
    itr->next = newNode;
}
```

## void printList()

```
void printList(){
    Node *itr = tail->next;
    printf("\nThe list is : ");
    while(itr != NULL){
        printf("%d ->" ,itr->data);
        itr = itr->next;
    }
    printf("Null");
}
```

## void deleteFirst()

```
void deleteFirst(){
    if(tail->next == NULL) return;

    Node* temp = tail->next;
    tail->next= tail->next->next;
    tail->next-prev = tail;
    free(temp);
}
```

## void deleteLast()

```
void deleteLast(){

    //empty list
    if (tail->next ==NULL return;

    Node* temp =tail;

    tail->prev->next = tail->next;
    tail->next->prev = tail->prev;
    tail = tail->prev;
    free(temp);
}
```

```
void deletePos(){
    int pos;
    printf("\nEnter the pos from where you want to delete: ");
    scanf("%d",&pos);

    if(pos == 1){
    Node* temp = tail->next;
    tail->next= tail->next->next;
    tail->next-prev = tail;
    free(temp);
    return;
    }

    Node* itr = start;
    for(int i=1; i< pos-1 ;i++){
    itr = itr->next;
    }

    Node* temp = itr->next;
    itr->next = itr->next->next;
    temp->next->prev = itr;

    if(temp == tail){
    tail= itr;
    }

    free(temp);
}
```

## Summary

We saw how using functions help us to

- write code more efficiently
- debug debug code easily and
- reuse code well.

But there is still scope of simplification in the code above.
Lets take an exmple:

**Here Are Two printList function**

1. For Singly LinkedList

```
void printList(){
    Node *itr = start;
    printf("\nThe list is : ");
    while(itr != NULL){
        printf("%d ->" ,itr->data);
        itr = itr->next;
    }
    printf("Null");
}
```

2. For Singly Circular

```
void printList(){
    Node *itr = tail->next;
    printf("\nThe list is : ");
    while(itr != NULL){
        printf("%d ->" ,itr->data);
        itr = itr->next;
    }
    printf("Null");
}
```

Noticed Something ?
Its the same function , we are just using `start` we use `tail->next` . so why not just pass it as an argument and reuse the function. Say we use a generic name as ptr so the function will be.

```
void printList(Node* ptr){
    Node *itr = ptr;
    printf("\nThe list is : ");
    while(itr != NULL){
        printf("%d ->" ,itr->data);
        itr = itr->next;
    }
    printf("Null");
}

```

when calling the funciton we can do it as

```
//for singly and doubly
printList(start);

//for Singly Circular and Doubly Circular.
printList(tail->next);
```

Task: Find other functions which you can convert into generic functions.

# Questions on Linked List

## 1. Find the milldle element of the list.

### Approach 1 :

traverse the list ,
find the length
divide by 2
traverse the list to length /2  
we reach the middle element.

```
int middleNode(){

    //empty list
    if(start == NULL) return NULL;

    Node * temp = start;
    int count = 1;
    while(temp->next != NULL){
        temp= temp->next;
        count++;
    }
    //again starting from the begining
    temp = start;

    for(int i =0 ;i< count/2 ;i++){
        temp= temp->next;
    }
    return temp->data;
}
```

This works only for non circular , we can make some updates to make in genric , firstly pass the start as a parameter like we did in the print .
secondly to find the length of a circular linked list instead of check `while (temp != NULL)` we can use `while(temp ->next != start)` temp->next will only point to start if its the tail.
and when we combine both the cases , it will be
`while(temp->next != NULL || temp->next != start)`

so the generic function for all types of linked list will be

```
int middleNode(Node* ptr){
    Node* temp = ptr;
    int count = 1;
    while(temp->next != NULL || temp ->next != ptr){
        temp = temp->next ;
        count++;
    }

    temp = ptr;
    for (int i = 0 ; i< count/2 ;i++){
        temp = temp->next;
    }

    return temp->data;
}
```

### Approach 2:

Slow Fast pointer
works for non-circular LinkedList.

```
int middleNode(Node* ptr){
    Node* slow , Node* fast;
    int mid = ptr->data;
    slow = ptr;
    fast = ptr;
    while(fast->next !=NULL  && fast->next->next != NULL){
        mid = slow->data;
        slow = slow->next;
        fast = fast->next-next;
    }
    if(fast->next == NULL){
        return mid;
    }
    else{
        return slow->data;
    }
}
```

# Some Practice Questions:

## To check if a string is palindrome using stack.

### Approach

This is a simple program as the property of the stack perfectly suits the condition of a palindrome .As when we fetch the data from the stack we get in the reverse order , so all we have to do now is compare the original and the reverse.
we first push each character of the string in a stack.
After that pop each character and compare that with the original string.

### Code
