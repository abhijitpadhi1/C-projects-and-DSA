/* Implementation of Circular Linked List */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void traverse(Node* start);
Node* createNode(int ele);
void insertAtEnd(Node** start, int ele);
void insertAtBeginning(Node** start, int ele);
void insertionAtAnypoint(Node** start, int ele, int pos);
void deleteFirst(Node** start);
void deleteLast(Node** start);
void deleteAnyNode(Node** start, int pos);
void freeList(Node* start);

void main() {
    Node* start = NULL;
    int ch = 0;
    while(ch != 9) {
        int ele,pos;
        printf("Choose your choice\n");
        printf("1:creation\t2:insert at beginning\t3:insert at end\t4:insert at any point\t5:traverse\t");
        printf("6:delete first\t7:delete last\t8:delete at any point\t9:exit\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("Ent ele : ");
                scanf("%d",&ele);
                start = createNode(ele);
                start->next = start;
                break;
            case 2:
                printf("Ent ele : ");
                scanf("%d",&ele);
                insertAtBeginning(&start,ele);
                break;
            case 3:
                printf("Ent ele : ");
                scanf("%d",&ele);
                insertAtEnd(&start,ele);
                break;
            case 4:
                printf("Ent ele : ");
                scanf("%d",&ele);
                printf("Ent pos to insert : ");
                scanf("%d", &pos);
                insertionAtAnypoint(&start,ele,pos);
                break;
            case 5:
                printf("Created ");
                traverse(start);
                break;
            case 6:
                deleteFirst(&start);
                break;
            case 7:
                deleteLast(&start);
                break;
            case 8:
                printf("Ent pos : ");
                scanf("%d", &pos);
                deleteAnyNode(&start,pos);
                break;
            case 9:
                freeList(start);
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
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** start, int ele) {
    Node* newNode = createNode(ele);
    Node* last = *start;
    if (*start == NULL) {
        newNode->next = newNode;
        *start = newNode;
    } else {
        while (last->next != *start) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *start;
    }
    *start = newNode;
}

void insertAtEnd(Node** start, int ele) {
    Node* newNode = createNode(ele);
    if(*start == NULL) {
        newNode->next = newNode;
        *start = newNode;
    } else {
        Node* curr = *start;
        while(curr->next != *start) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = *start;
    }
}

void insertionAtAnypoint(Node** start, int ele, int pos) {
    Node* newNode = createNode(ele);
    if(*start == NULL) {
        *start = newNode;
    } else {
        if(pos < 1) {
            printf("Invlid position...");
            return;
        } else if(pos == 1) {
            insertAtBeginning(start,ele);
            return;
        } else {
            Node* temp = *start;
            int i=1;
            while(i<pos-1) {
                temp = temp->next;
                i++;
                if(temp == *start) {
                    printf("Invlid position...");
                    return;
                }
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void traverse(Node* start) {
    Node* temp = start;
    printf("LL is : HEAD->");
    do {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("HEAD\n");
}

void deleteFirst(Node** start) {
    if(*start == NULL) {
        printf("LL is already empty\n");
        return;
    } else {
        Node* temp = *start;
        Node* last = *start;
        while(last->next != *start) {
            last = last->next;
        }
        if(*start == last) {
            *start = NULL;
            free(temp);
        } else {
            *start = (*start)->next;
            last->next = *start;
            free(temp);
        }
    }
}

void deleteLast(Node** start) {
    if(*start == NULL) {
        printf("LL is already empty\n");
        return;
    } else {
        Node* temp = *start;
        Node* prev = NULL;
        while(temp->next != *start) {
            prev = temp;
            temp = temp->next;
        }
        if(prev == NULL) {
            *start = NULL;
            free(temp);
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }
}

void deleteAnyNode(Node** start, int pos) {
    if(*start == NULL) {
        printf("LL is already empty\n");
        return;
    } else {
        if(pos < 1) {
            printf("Invlid Position...");
            return;
        } else if(pos == 1) {
            deleteFirst(start);
            return;
        } else {
            Node* temp = *start;
            Node* prev = NULL;
            int i=1;
            do {
                prev = temp;
                temp = temp->next;
                i++;
                if(temp == *start) {
                    printf("Invlid position...");
                    return;
                }
            } while(i<pos);
            prev->next = temp->next;
            free(temp);
        }
    }
}

void freeList(Node* start) {
    Node* current = start->next;
    while (current != start) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    start = NULL;
    free(start);
}
