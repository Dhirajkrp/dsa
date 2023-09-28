#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct CircularQueue {
    Node* front;
    Node* rear;
};

typedef struct CircularQueue CircularQueue;

CircularQueue* createCircularQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(CircularQueue* queue) {
    return (queue->front == NULL);
}

void enqueue(CircularQueue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
        newNode->next = queue->front;
    }
    else {
        newNode->next = queue->front;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued: %d\n", data);
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty.\n");
        return -1;
    }
    int data;
    if (queue->front == queue->rear) {
        data = queue->front->data;
        free(queue->front);
        queue->front = NULL;
        queue->rear = NULL;
    }
    else {
        Node* temp = queue->front;
        data = temp->data;
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
        free(temp);
    }
    printf("Dequeued: %d\n", data);
    return data;
}

void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty.\n");
        return;
    }
    Node* current = queue->front;
    printf("Circular Queue: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

int peek(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Circular Queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

int main() {
    CircularQueue* queue = createCircularQueue();
    int choice = 1, data;
    
    printf("The operations you can perform are: ");
    printf("\n1. Insert an element\n2. Delete an element\n3. Topmost element\n4. Display the queue");
    
    while (choice != 0) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                if (!isEmpty(queue))
                    printf("The element in the front is: %d\n", peek(queue));
                break;
            case 4:
                display(queue);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}
