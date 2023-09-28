#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int expo;
    struct node* next;
};

typedef struct node Node;

Node* createNode(int coeff, int expo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

Node* createPolynomial(Node* head) {
    int choice = 1, coeff, expo;
    Node* temp;
    
    while (choice == 1) {
        printf("\nEnter the coefficient & exponent :\n");
        scanf("%d", &coeff);
        scanf("%d", &expo);
        Node* newNode = createNode(coeff, expo);
        if (head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            temp->next = newNode;
            temp = temp->next;
        }
        printf("Do you want to add more elements (1/0):");
        scanf("%d", &choice);
    }
    return head;
}

Node* multiply(Node* l1, Node* l2) {
    Node* l3 = NULL;
    Node* temp;
    int expo, coeff;
    while (l1 != NULL && l2 != NULL) {
        if (l1->expo == l2->expo) {
            expo = l1->expo;
            coeff = l1->coeff * l2->coeff;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1->expo > l2->expo) {
            expo = l1->expo;
            coeff = l1->coeff;
            l1 = l1->next;
        }
        else {
            expo = l2->expo;
            coeff = l2->coeff;
            l2 = l2->next;
        }
        Node* newNode = createNode(coeff, expo);
        if (l3 == NULL) {
            l3 = newNode;
            temp = l3;
        }
        else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    // If any elements are remaining in l1 or l2, add them to the result
    while (l1 != NULL) {
        Node* newNode = createNode(l1->coeff, l1->expo);
        temp->next = newNode;
        temp = temp->next;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        Node* newNode = createNode(l2->coeff, l2->expo);
        temp->next = newNode;
        temp = temp->next;
        l2 = l2->next;
    }
    return l3;
}


void printPolynomial(Node* head) {
    while (head != NULL) {
        if(head->next == NULL){
            printf(" %d ", head->coeff);
        }
        else{
            printf("(%dx^%d) + ", head->coeff, head->expo);
        }
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* p1 = NULL;
    Node* p2 = NULL;
    Node* mul = NULL;
    printf("Enter the data for the polynomial 1:");
    p1 = createPolynomial(p1);
    printf("Enter the data for the polynomial 2:");
    p2 = createPolynomial(p2);
    mul = multiply(p1, p2);
    printf("\nPolynomial 1: ");
    printPolynomial(p1);
    printf("\nPolynomial 2: ");
    printPolynomial(p2);
    printf("\nMultiplication of the Polynomials: ");
    printPolynomial(mul);
    
    return 0;
}
