// Implemention of Binary Search Tree

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* RC;
    struct Node* LC;
}Node;

Node* createNode(int ele);
Node* insertNode(Node* root, int ele);
void inorderTraverse(Node* root);
void preorderTraverse(Node* root);
void postorderTraverse(Node* root);
Node* deleteNode(Node* root, int ele);
Node* findMin(Node* root);
Node* findMax(Node* root);
Node* search(Node* root, int ele);

void main() {
    Node* root = NULL;
    Node* temp = NULL;
    int ch = 0;

    printf("1:Creation\t2:insert Node\t3:inorder traverse\t4:preorder traverse\t5:postorder traverse\t");
    printf("6:delete Node\t7:Find Max\t8:Find Min\t9:Search\t10:exit\n");
    while(ch != 10) {
        int ele;
        printf("Choose your choice\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("Ent ele : ");
                scanf("%d", &ele);
                root = createNode(ele);
                break;
            case 2:
                printf("Ent ele : ");
                scanf("%d", &ele);
                insertNode(root, ele);
                break;
            case 3:
                printf("Created BST : ");
                inorderTraverse(root);
                printf("NULL\n");
                break;
            case 4:
                printf("Created BST : ");
                preorderTraverse(root);
                printf("NULL\n");
                break;
            case 5:
                printf("Created BST : ");
                postorderTraverse(root);
                printf("NULL\n");
                break;
            case 6:
                printf("Ent val to delete : ");
                scanf("%d", &ele);
                deleteNode(root, ele);
                break;
            case 7:
                temp = findMax(root);
                printf("Tha max : %d\n", temp->data);
                break;
            case 8:
                temp = findMin(root);
                printf("Tha min : %d\n", temp->data);
                break;
            case 9:
                printf("Ent ele to search : ");
                scanf("%d", &ele);
                search(root, ele);
                break;
            case 10:
                printf("Exiting...");
                break;
            default:
                printf("Wrong chcoice\n");
                break;
        }
    }
}

Node* createNode(int ele) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("No mem allocated\n");
        exit(1);
    }
    newNode->data = ele;
    newNode->RC = NULL;
    newNode->LC = NULL;
    return newNode;
}

Node* insertNode(Node* root, int ele) {
    if(root == NULL) {
        root = createNode(ele);
        return root;
    } else {
        if(ele < root->data) {
            root->LC = insertNode(root->LC, ele);
        } else if(ele > root->data) {
            root->RC = insertNode(root->RC, ele);
        } else {
            printf("Duplicates not allowed\n");
        }
        return root;
    }
}

void inorderTraverse(Node* root) {
    if(root != NULL) {
        inorderTraverse(root->LC);
        printf("%d, ", root->data);
        inorderTraverse(root->RC);
    }
}

void preorderTraverse(Node* root) {
    if(root != NULL) {
        printf("%d, ", root->data);
        inorderTraverse(root->LC);
        inorderTraverse(root->RC);
    }
}

void postorderTraverse(Node* root) {
    if(root != NULL) {
        inorderTraverse(root->LC);
        inorderTraverse(root->RC);
        printf("%d, ", root->data);
    }
}

Node* deleteNode(Node* root, int ele) {
    // If Node is leaf Node then just return root       
    if(root == NULL) {
        return root;
    }
    // Travel to the node to delete 
    if(ele < root->data) {
        root->LC = deleteNode(root->LC, ele);
    } else if(ele > root->data) {
        root->RC = deleteNode(root->RC, ele);
    } else {
        // If node has either of the child then just replace by deleteing
        if(root->LC == NULL) {
            Node* temp = root->RC;
            free(root);
            return temp;
        } else if(root->RC == NULL) {
            Node* temp = root->LC;
            free(root);
            return temp;
        }
        // If Node has both children then 
        // find inorder successor
        Node* temp = findMin(root->RC);
        // Copy the inorder successor's data to this Node
        root->data = temp->data;
        // Delete the inorder successor
        root->RC = deleteNode(root->RC, temp->data);
    }
    return root;
}

Node* findMax(Node* root) {
    if(root->RC == NULL) {
        return root;
    } else {
        return findMax(root->RC);
    }
}

Node* findMin(Node* root) {
    if(root->LC == NULL) {
        return root;
    } else {
        return findMin(root->LC);
    }
}

Node* search(Node* root, int ele) {
    if(root == NULL) {
        printf("Ele not found\n");
        return root;
    }
    if(ele < root->data) {
        root->LC = search(root->LC, ele);
    } else if(ele > root->data) {
        root->RC = search(root->RC, ele);
    } else {
        printf("Ele is present\n");
    }
    return root;
}
