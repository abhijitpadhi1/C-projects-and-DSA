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
void insertionAtAnypoint(Node** start, int ele);
void deleteFirst(Node** start);
void deleteLast(Node** start);
void deleteAnyNode(Node** start);
void search(Node* start);
void merge(Node** start);
void sort(Node* start);
void reverse(Node** start);
void freeList(Node* start);

void main() {
    Node* start = NULL;
    int ch = 0;
    while(ch != 13) {
        int ele;
        printf("Choose your choice\n");
        printf("1:Creation\t2:insert at beginning\t3:insert at end\t4:insert at any point\t5:traverse\t6:delete first\t");
        printf("7:delete last\t8:delete at any point\t9:search\t10:merge\t11:sort\t12:reverse\t13:exit\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("Ent ele : ");
                scanf("%d",&ele);
                start = createNode(ele);
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
                insertionAtAnypoint(&start,ele);
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
                deleteAnyNode(&start);
                break;
            case 9:
                search(start);
                break;
            case 10:
                merge(&start);
                break;
            case 11:
                sort(start);
                break;
            case 12:
                reverse(&start);
                break;
            case 13:
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

void insertAtEnd(Node** start, int ele) {
    Node* newNode = createNode(ele);
    if(*start == NULL) {
        *start = newNode;
    } else {
        Node* curr = *start;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void insertAtBeginning(Node** start, int ele) {
    Node* newNode = createNode(ele);
    if(*start == NULL) {
        *start = newNode;
    } else {
        newNode->next = *start;
        *start = newNode;
    }
}

void insertionAtAnypoint(Node** start, int ele) {
    Node* newNode = createNode(ele);
    if(*start == NULL) {
        *start = newNode;
    } else {
        int pos;
        printf("Ent pos to insert : ");
        scanf("%d", &pos);
        if(pos < 1) {
            printf("Invlid position...");
            return;
        } else if(pos == 1) {
            insertAtBeginning(start,ele);
            return;
        } else {
            Node* temp = *start;
            int i=1;
            while(temp!=NULL && i<pos-1) {
                temp = temp->next;
                i++;
            }
            if(temp == NULL) {
                printf("Invlid position...");
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteFirst(Node** start) {
    if(*start == NULL) {
        printf("LL is already empty\n");
        return;
    } else {
        Node* temp = *start;
        *start = temp->next;
        free(temp);
    }
}

void deleteLast(Node** start) {
    if(*start == NULL) {
        printf("LL is already empty\n");
        return;
    } else {
        Node* temp = *start;
        Node* prev = NULL;
        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

void deleteAnyNode(Node** start) {
    if(*start == NULL) {
        printf("LL is already empty\n");
        return;
    } else {
        int pos;
        printf("Ent pos : ");
        scanf("%d", &pos);
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
            while(temp!=NULL && i<pos){
                prev = temp;
                temp = temp->next;
                i++;
            }
            if(temp == NULL) {
                printf("Invlid Position...");
                return;
            }
            prev->next = temp->next;
            free(temp);
        }
    }
}

void traverse(Node* start) {
    Node* temp = start;
    printf("LL is : ");
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(Node* start) {
    Node* curr = start;
    int count=0,sele;
    printf("Ent ele to search : ");
    scanf("%d", &sele);
    while(curr != NULL) {
        if(curr->data == sele) {
            printf("The req ele found at Node%d\n", count+1);
            return;
        } else {
            curr = curr->next;
            count++;
        }
    }
}

void merge(Node** start) {
    Node* head = NULL;
    int n;
    printf("Creat another LL to merge with it.\n");
    printf("Ent no of Node for second LL : ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int ele;
        printf("Ent the ele to store at Node%d : ", i+1);
        scanf("%d", &ele);
        printf("1:insert at beginning\t2:insert at end\t3:insertionAtAnypoint\n");
        int ch;
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                insertAtBeginning(&head,ele);    break;
            case 2:
                insertAtEnd(&head,ele);          break;
            case 3:
                insertionAtAnypoint(&head,ele);  break;
            default:
                printf("Wrong chcoice\n");       break;
        }
    }
    printf("The sec ");
    traverse(head);       // Now merge both
    Node* temp = *start;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    printf("The merged ");
    traverse(*start);
}

void sort(Node* start) {
    Node* temp;
    Node* ptr = NULL;
    int swap;
    if(start == NULL) {
        printf("Nothing to sort");
        return;
    } else {
        do {
            swap = 0;
            temp = start;
            while(temp->next != ptr) {
                if(temp->data > temp->next->data) {
                    int tempdata = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = tempdata;
                    swap = 1;
                }
                temp = temp->next;
            }
            ptr = temp;
        } while(swap);
    }
}

void reverse(Node** start) {
    Node* prev = NULL;
    Node* current = *start;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *start = prev;
    printf("Reversed ");
    traverse(*start);
}

void freeList(Node* start) {
    Node* current = start;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

