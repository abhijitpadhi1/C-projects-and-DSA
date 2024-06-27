#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int coff;
    int exp;
    struct Node* next;
}Node;

Node* createNode(int coff, int exp);
void insertNode(Node** start, int coff, int exp);
void traverse(Node* start);
void sort(Node* start);
void creatPoly(Node** start);

void main() {
    Node* start = NULL;
    creatPoly(&start);
    printf("The created polynomial is : ");
    traverse(start);
}

Node* createNode(int coff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("No mem allocated\n");
        exit(1);
    }
    newNode->coff = coff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** start, int coff, int exp) {
    Node* newNode = createNode(coff,exp);
    if(*start == NULL) {
        *start = newNode;
    } else {
        newNode->next = *start;
        *start = newNode;
    }
}

void traverse(Node* start) {
    Node* temp = start;
    while(temp != NULL) {
        if(temp->coff != 0) {
            if(temp->exp == 0) {
                printf("%d ", temp->coff);
            } else if(temp->exp == 1) {
                printf("%dx ", temp->coff);
            } else {
                printf("%dx^%d ", temp->coff, temp->exp);
            }
        }
        if(temp->next != NULL) {
                printf("+ ");
        }
        temp = temp->next;
    }
    printf("= 0\n");
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
                if(temp->exp < temp->next->exp) {
                    int tempdata = temp->exp;         // swapping of exp val
                    temp->exp = temp->next->exp;
                    temp->next->exp = tempdata;
                    tempdata = temp->coff;            // swapping of coff val
                    temp->coff = temp->next->coff;
                    temp->next->coff = tempdata;
                    swap = 1;
                }
                temp = temp->next;
            }
            ptr = temp;
        } while(swap);
    }
}

void creatPoly(Node** start) {
    int ch = 1;
    printf("Ent 1 to insert term OR 0 to exit\n");
    while(ch != 0) {
        printf("1 OR 0 : ");
        scanf("%d", &ch);
        int coff, exp;
        switch (ch){
            case 1:
                printf("Ent term with coff and exp\n");
                scanf("%d", &coff);
                scanf("%d",&exp);
                insertNode(start, coff, exp);
                break;
            case 0:
                break;
            default:
                printf("Ent 1 OR 0\n");
                break;
        }
    }
    sort(*start);
}
