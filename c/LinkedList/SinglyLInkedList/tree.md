# Introduction to Tree

A tree is a widely used data structure that represents a hierarchical structure. It is composed of nodes connected by edges, and it is often visualized as an upside-down tree with the root at the top.

## Basic Terminology

Here are some essential terms related to trees:

- **Node:** Each element in a tree is called a node. It can hold data and may have zero or more child nodes.
- **Edge:** A connection between two nodes. It represents a relationship or link between the nodes.
- **Root:** The topmost node of a tree. It is the starting point of the tree and has no incoming edges.
- **Parent and Child:** A node directly connected to another node is called its child, and the connected node is called its parent.
- **Leaf:** A node that has no children is called a leaf node or a terminal node.
- **Subtree:** A subtree is a portion of the tree that can be viewed as a complete tree itself. It consists of a node and its descendants.

## Properties of Trees

Trees possess some characteristics that distinguish them from other data structures:

1. **Hierarchical Structure:** A tree follows a hierarchical structure, where each node except the root has exactly one parent and zero or more child nodes.
2. **Acyclic Structure:** A tree is acyclic, meaning there are no loops or cycles in the connections between nodes.
3. **One Path between Any Two Nodes:** In a tree, there is exactly one unique path between any two nodes.
4. **Multiple Children:** Unlike linear data structures like lists or arrays, a node in a tree can have multiple children, leading to branching structures.

## Types of Trees

There are various types of trees, each with its own characteristics and applications. Here are a few common types:

1. **Binary Tree:** A binary tree is a tree in which each node can have at most two children, referred to as the left child and the right child.
2. **Binary Search Tree (BST):** A binary search tree is a binary tree in which the left child is smaller (or equal) in value compared to the parent node, and the right child is greater (or equal) in value.
3. **AVL Tree:** An AVL tree is a self-balancing binary search tree, where the heights of the left and right subtrees of any node differ by at most one.
4. **B-tree:** A B-tree is a self-balancing search tree that can have more than two children per node. It is commonly used in file systems and databases for efficient storage and retrieval.
5. **Heap:** A binary heap is a complete binary tree that satisfies the heap property. It is often used to implement priority queues.
6. **Trie:** A trie, also known as a prefix tree, is a tree-like data structure used for efficient retrieval of keys that are usually strings.

Trees are fundamental data structures with a hierarchical arrangement of nodes connected by edges. They find applications in various domains, such as computer science, databases, file systems, and more. Understanding the basic terminology and properties of trees lays the foundation for exploring more advanced concepts and algorithms related to trees.

# Binary Tree

A binary tree is a tree data structure in which each node can have at most two children, referred to as the left child and the right child.

## Properties:

- **Node Structure:** Each node in a binary tree contains three components:

  - Data: The value or information stored in the node.
  - Left Child: A reference to the left child node, or null if there is no left child.
  - Right Child: A reference to the right child node, or null if there is no right child.

- **Child Relationship:**

  - Left Child: The left child node is smaller (or equal) in value compared to the parent node.
  - Right Child: The right child node is greater (or equal) in value compared to the parent node.

- **Tree Structure:**

  - Each node in a binary tree can have zero, one, or two children.
  - The binary tree starts with a special node called the root node. It serves as the entry point to the tree structure.
  - Nodes other than the root node are called internal nodes.
  - Nodes that do not have any children are called leaf nodes or terminal nodes.

- **Operations:**
  - **Insertion:** Adding a new node to the tree. The new node is inserted as either the left child or the right child of an existing node based on the comparison of values.
  - **Traversal:** Visiting all nodes in a specific order. There are three common types of binary tree traversal:
    - Pre-order Traversal: Visit the current node, then recursively traverse the left subtree, followed by the right subtree.
    - In-order Traversal: Recursively traverse the left subtree, visit the current node, and then traverse the right subtree. In the case of a binary search tree, an in-order traversal produces the nodes in ascending order.
    - Post-order Traversal: Recursively traverse the left subtree, then the right subtree, and finally visit the current node.
  - **Search:** Finding a specific node in the tree by comparing its value with the nodes in the tree. Typically, the search operation starts at the root node and traverses the tree based on the comparison of values until the desired node is found or determined to be absent.

## Applications:

Binary trees find applications in various algorithms and data structures, including:

- Binary search trees (BST) provide efficient searching, insertion, and deletion operations, making them useful in data storage and retrieval scenarios.
- Expression trees are binary trees used to represent arithmetic expressions, where the operators are internal nodes and the operands are leaf nodes.
- Huffman coding, a compression algorithm, uses binary trees to construct optimal prefix codes for data compression.
- Binary heaps, a specialized binary tree structure, are used to implement priority queues efficiently.
- Game trees, such as minimax trees used in game-playing algorithms, employ binary tree structures to represent the possible moves and outcomes of a game.

## Binary Tree Node

```
struct node {
	int data;
	struct node* left;
	struct node* right;
};
```

```
//we can use the typedef for ease
typedef struct node* Node;
```

## Node\* createNode()

```
Node* createNode(){
	int data ;
	Node* newnode = (Node*) malloc(sizeof(Node));
	printf("Enter the data you want to insert : ");
	scanf("%d" , &data);
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}
```

## Traversals

As we learned there are mainly 3 types traversals , based on the positioning of the the root .

- preOrder : Means we operate the root before left and right (Root L R )
- inOrder : we operate the root between the two child nodes (L Root R)
- postOrder : we operate the root at the end (L R Root)

## void preOrder()

```
void preOrder(Node* root){
	if(root == NULL) return;

	printf("%d " , root->data);
	preOrder(root->left);
	preOrder(root->right);
}
```

We start at the top of the tree, which is called the "root." We check if the root exists (if it's not empty or null). If the root doesn't exist, it means the tree is empty, so we stop.

If the root does exist, we first print the value stored in that root node. It could be any number or some other type of information.

After printing the value of the root, we move to the left side of the tree and visit the left child of the root. We do the same steps again for this left child: print its value (if it exists), move to its left child (if it exists), and so on.

Once we reach the end of the left side, we come back to the root and move to the right side of the tree. We visit the right child of the root and do the same steps as we did for the left side: print its value (if it exists), move to its left child (if it exists), and so on.

Once this concept it is clear the other traversal's are just done by switching the order of operations.

## void inOrder()

```
void inOrder(Node* root){
	if(root == NULL) return;

	inOrder(root->left);
	printf("%d " , root->data);
	inOrder(root->right);
}
```

## void postOrder()

```
void postOrder(Node* root){
	if(root == NULL) return;

	postOrder(root->left);
	postOrder(root->right);
	printf("%d " , root->data);
}
```

# BST

A Binary Search Tree (BST) is a special type of binary tree that follows a specific ordering rule. In a BST, each node has a value, and the values in the left subtree are always smaller (or equal) than the value of the current node, while the values in the right subtree are always greater (or equal).

- **Node Structure:** Each node in a BST contains three components:

  - Data: The value or information stored in the node.
  - Left Child: A reference to the left child node, which has a smaller (or equal) value than the current node, or null if there is no left child.
  - Right Child: A reference to the right child node, which has a greater (or equal) value than the current node, or null if there is no right child.

- **Ordering Rule:**

  - For any node in the BST, all the values in its left subtree are smaller (or equal) than the value of the node.
  - For any node in the BST, all the values in its right subtree are greater (or equal) than the value of the node.

- **Search Operation:** The BST's ordering rule allows for efficient searching. Starting from the root, we compare the target value with the current node's value. If they are equal, we have found the node we are looking for. If the target value is smaller, we move to the left subtree. If the target value is greater, we move to the right subtree. We repeat this process until we find the target node or determine that it doesn't exist in the tree.

- **Insertion Operation:** To insert a new value into a BST, we compare the value with each node starting from the root and follow the ordering rule. If the value is smaller, we move to the left subtree. If the value is greater, we move to the right subtree. We continue this process until we find an empty spot (a null reference), where we can add the new node while maintaining the ordering rule.

- **Traversal Operations:** Just like in a regular binary tree, we can perform pre-order, in-order, and post-order traversals in a BST. However, due to the ordering rule, the in-order traversal of a BST visits the nodes in ascending order.

- **Deletion Operation:** Removing a node from a BST while maintaining its properties can be a bit more complex than insertion. It requires rearranging the tree to preserve the ordering rule. The specific approach depends on the node being deleted and its children. There are several cases to consider, such as deleting a leaf node, a node with one child, or a node with two children.

Binary Search Trees are commonly used in situations where efficient searching, insertion, and deletion operations are required. They can be used for various purposes, such as implementing dictionaries, database indexing, and sorting algorithms like the binary search.

## Basic Operations on BST

## void search(int data)

```c
void search (){
	int data;
	printf("Enter the data you want to search : ");
	scanf("%d" , &data);
	Node* temp = root;
	while(temp !=  NULL){
		if(temp-> data == data){
			printf("Data is Present!");
			return;
		}
		else if(temp->data < data){
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	printf("Data is not present");
}
```

If you are familiar will binary serch you will find a lot of similarities in this. This is a very important concept and helps in many BST operations. So pay close attention to this .

## void insertNode()

```c
void insertNode(Node** node, int data) {
    if (*node == NULL) {
        *node = createNode(data);
    }
	else if (data > (*node)->data) {
        insertNode(&((*node)->right), data);
    }
	else if (data < (*node)->data) {
        insertNode(&((*node)->left), data);
    }
	else {
        printf("\nData already present in the tree.");
    }
}

```

- The insertNode function takes a double pointer to a node (Node\*\* node) and the data to be inserted (int data).
- It first checks if the current node is NULL, which means we have reached a position in the tree where we can insert a new node.
- If the current node is NULL, it means we have found an empty spot in the tree, so we create a new node using the createNode function with the given data and assign it to the current node using \*node = createNode(data).
- If the current node is not NULL, we need to determine whether to move to the left or right subtree based on the value of the data we want to insert.
- If the data is greater than the current node's data, we recursively call insertNode with the right child of the current node (&((\*node)->right)) and the data.
- If the data is less than the current node's data, we recursively call insertNode with the left child of the current node (&((\*node)->left)) and the data.
- If the data is equal to the current node's data, it means the data is already present in the tree, and we display a message indicating that.
- By using the double pointer and passing the address of the node (&root) when calling insertNode, any modifications made to the node inside the function will be reflected outside, allowing us to correctly build the binary search tree.

## void Insert()

```c
void Insert() {
    int data;
    printf("\nEnter the data you want to add: ");
    scanf("%d", &data);
    insertNode(&root, data);
}

```

- Since the insertNode() is recursive , we cannot ask for user input in that function as it would ask for input everytime the function is called recursively, thus we use this wrapper function to prevent that , we just take the input from the user and pass to the insertNode function along with the root address.
- The reason for passing the address is so that the function can update the root after new values are added.

## InOder Predecessor

````
** The InOrder Predecessor of any node is the right most element of its left sub tree**.
It is the largest value in the tree smaller than the node .
```c
        9
      /   \
     6     12
    / \    / \
   3   8  10  15
````

Consider this tree , if we take node as **9** , then its left subtree will be.

```c
        6
       / \
      3   8
```

- And in this subtree, the right most value is **8**.
- Thus the inorder predecessor of 9 in this tree is 8.
- The formal defination is a bit confusing but it is rather simple.

## Node* inOrderPredecessor(Node* root)

```c
Node* inOrderPredecessor(Node* root){
    //going to the left subtree
    root = root->left;
    //keep on moving to the right while we reach the end (leafnode)
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
```

## Node* deleteNde(Node* root , int data)

```c
Node* deleteNode(Node* root ,int data ){
	Node* iPre;

	if(root == NULL){
		return NULL;
	}

	if(root->left == NULL && root->right == NULL){
		free(root);
		return NULL;
	}

	if(root->left == NULL || root->right == NULL){
		if(root->left == NULL){
			return root->right;
		}
		else {
			return root->left;
		}
	}

	if(data < root->data){
		root->left = deleteNode(root->left , data);
	}
	else if(data > root->data){
		root->right =deleteNode(root->right , data);
	}
	else{
		iPre = inOrderPredecessor(root);
		root->data = iPre->data;
		root->left = deleteNode(root->left , iPre->data);

	}
	return root;
}

```

- The deleteNode function takes a pointer to a node (Node\* node) and the data value (int data) of the node to be deleted from the binary search tree.
- It first checks if the node is NULL. If it is, it means we have reached the end of a branch, and we return NULL to indicate that there is nothing to delete.
- Next, it checks if the current node has no children (both the left and right children are NULL). In this case, it frees the memory occupied by the node using free(node) and returns NULL to indicate that the node has been deleted.
- Then, it checks if the current node has only one child (either the left or right child is NULL). If so, it bypasses the current node and returns its non-NULL child to connect it directly with the parent node. This effectively removes the node from the tree.
- If the current node has two children, it needs to find the in-order predecessor, which is the rightmost node in the left subtree of the node. It does this by calling the inOrderPredecessor function.
- The data value of the in-order predecessor is then copied to the current node, effectively replacing the value to be deleted.
- Finally, it recursively calls deleteNode to delete the in-order predecessor from the left subtree of the current node, ensuring the tree remains valid.
- The function returns the modified node (or its child) to correctly update the tree structure.

## void Delete()

```c
void Delete(){

	int data;
	printf("Enter the data you want to delete:");
	scanf("%d" , &data);
	root = deleteNode(root , data);

}
```

Similar to the `Insert()` we use a wrapper function for `Delete()` to avoid the recursive input of data.

## Menu Driven Program For BST

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node Node;
Node* root = NULL;

Node* createNode(int data){
	Node* n = (Node*) malloc(sizeof(Node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void insertNode(Node** node, int data) {
    if (*node == NULL) {
        *node = createNode(data);
    }
	else if (data > (*node)->data) {
        insertNode(&((*node)->right), data);
    }
	else if (data < (*node)->data) {
        insertNode(&((*node)->left), data);
    }
	else {
        printf("\nData already present in the tree.");
    }
}

void Insert() {
    int data;
    printf("\nEnter the data you want to add: ");
    scanf("%d", &data);
    insertNode(&root, data);
}

void search (){
	int data;
	printf("Enter the data you want to search : ");
	scanf("%d" , &data);
	Node* temp = root;

	while(temp !=  NULL){

		if(temp-> data == data){
			printf("Data is Present!");
			return ;
		}
		else if(temp->data < data){
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	printf("Data is not present");
}

Node* inOrderPredecessor(Node* root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

Node* deleteNode(Node* node, int data) {
    Node* iPre;

    if (node == NULL) {
        return NULL;
    }

    if (node->left == NULL && node->right == NULL) {
        free(node);
        return NULL;
    }

    if (node->left == NULL || node->right == NULL) {
        if (node->left == NULL) {
            return node->right;
        } else {
            return node->left;
        }
    }

    if (data < node->data) {
        node->left = deleteNode(node->left, data);
    } else if (data > node->data) {
        node->right = deleteNode(node->right, data);
    } else {
        iPre = inOrderPredecessor(node);
        node->data = iPre->data;
        node->left = deleteNode(node->left, iPre->data);
    }

    return node;
}

void Delete(){

	int data;
	printf("Enter the data you want to delete:");
	scanf("%d" , &data);
	root = deleteNode(root , data);
}

void inOrder(Node* root){
	if(root == NULL){
		return;
	}
	inOrder(root->left);
	printf("%d " , root->data);
	inOrder(root->right);
}

int main(){

	bool flag = true;
	int choice =1;
	while(flag){

		switch (choice){
			case 1:
				Insert();
				break;

			case 2:
				search();
				break;
			case 3:
				Delete();
				break;
			case 4:
				inOrder(root);
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
			printf("\n1.Insert\n2.Search\n3.Delete\n4.Print Tree\n5 Exit\n");
			printf("Your choice : ");
			scanf("%d" , &choice);
		}

	}
	return 0;
}

```

## AVL Tree Deletion

### Introduction

AVL trees are self-balancing binary search trees that maintain their height balance property to ensure efficient search, insertion, and deletion operations. When deleting a node from an AVL tree, the tree needs to be rebalanced to maintain its balanced state.

```c
#include <stdio.h>
# include <stdlib.h>


struct node {
	int data;

	struct node* left;
	struct node* right;
	int height;
};

typedef struct node Node;

Node* root = NULL;


int getHeight(Node* n){
	if(n ==NULL) return 0;
	return n->height;
}


Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data  =data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
}
int max(int a ,int b){
	return a> b ? a:b;
}

int getBalanceFactor(Node* n){
	if (n==NULL) return 0;
	return (getHeight(n->left) - getHeight(n->right));
}

Node* inOrderPredecessor(Node* root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

Node* rightRotate(Node* y){

	Node* x = y->left;
	Node* T2  = x->right;
	x->right = y;
	y->left = T2;

	x->height =max(getHeight(x->right) , getHeight(x->left)) + 1;

	y->height =max(getHeight(y->right) , getHeight(y->left)) +1;

	return x;
}

Node* leftRotate(Node* x){
	Node* y = x->right;
	Node* T2  = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(getHeight(x->right) , getHeight(x->left)) + 1;
	y->height = max(getHeight(y->right) , getHeight(y->left)) +1;

	return y;
}




Node* insertNode(Node** node, int data) {
    if (*node == NULL) {
        *node = createNode(data);
        return *node;
    }
    else if (data > (*node)->data) {
        insertNode(&((*node)->right), data);
    }
    else if (data < (*node)->data) {
        insertNode(&((*node)->left), data);
    }
    else {
        printf("\nData already present in the tree.");
       return *node;
    }

    (*node)->height = 1 + max(getHeight((*node)->right), getHeight((*node)->left));

    int balance = getBalanceFactor(*node);

    if (balance > 1 && data < (*node)->left->data)
        return rightRotate(*node);

    if (balance < -1 && data > (*node)->right->data)
        return leftRotate(*node);

    if (balance > 1 && data > (*node)->left->data) {
        (*node)->left = leftRotate((*node)->left);
        return rightRotate(*node);
    }

    if (balance < -1 && data < (*node)->right->data) {
        (*node)->right = rightRotate((*node)->right);
        return leftRotate(*node);
    }

    return *node;
}



void Insert() {
    int data;
    printf("\nEnter the data you want to add: ");
    scanf("%d", &data);
    root = insertNode(&root, data);
}


void search (){
	int data;
	printf("Enter the data you want to search : ");
	scanf("%d" , &data);
	Node* temp = root;

	while(temp !=  NULL){

		if(temp-> data == data){
			printf("Data is Present!");
			return ;
		}
		else if(temp->data < data){
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	printf("Data is not present");
}





Node* deleteNode(Node** node,int data) {
    if (*node == NULL) {
        return *node;
    }
    else if (data < (*node)->data) {
        (*node)->left = deleteNode(&((*node)->left), data);
    }
    else if (data > (*node)->data) {
        (*node)->right = deleteNode(&((*node)->right), data);
    }
    else {
        if ((*node)->left == NULL) {
            Node* temp = (*node)->right;
            free(*node);
            return temp;
        }
        else if ((*node)->right == NULL) {
            Node* temp = (*node)->left;
            free(*node);
            return temp;
        }
        Node* inOrderPred = inOrderPredecessor((*node)->left);
        (*node)->data = inOrderPred->data;
        (*node)->left = deleteNode(&((*node)->left), inOrderPred->data);
    }

    (*node)->height = 1 + max(getHeight((*node)->left), getHeight((*node)->right));
    int balance = getBalanceFactor(*node);

    if (balance > 1 && getBalanceFactor((*node)->left) >= 0)
        return rightRotate(*node);

    if (balance > 1 && getBalanceFactor((*node)->left) < 0) {
        (*node)->left = leftRotate((*node)->left);
        return rightRotate(*node);
    }

    if (balance < -1 && getBalanceFactor((*node)->right) <= 0)
        return leftRotate(*node);

    if (balance < -1 && getBalanceFactor((*node)->right) > 0) {
        (*node)->right = rightRotate((*node)->right);
        return leftRotate(*node);
    }

    return *node;
}


void Delete(){

	int data;
	printf("Enter the data you want to delete:");
	scanf("%d" , &data);
	root = deleteNode(&root,data);

}


void inOrder(Node* root){
	if(root == NULL){
		return;
	}
	inOrder(root->left);
	printf("%d " , root->data);
	inOrder(root->right);
}

int main(){

	bool flag = true;
	int choice =1;
	while(flag){

		switch (choice){
			case 1:
				Insert();
				break;

			case 2:
				search();
				break;
			case 3:
				Delete();
				break;
			case 4:
				inOrder(root);
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
			printf("\n1.Insert\n2.Search\n3.Delete\n4.Print Tree\n5 Exit\n");
			printf("Your choice : ");
			scanf("%d" , &choice);
		}

	}
	return 0;
}
```
