#include <stdio.h>
#define INF 10000

typedef struct {
    int data;
    Node *next;
} Node;

Node *head;

void addFront(Node *root, int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = root->next;
    root -> next = node;
}

int main(void) {

    head = (Node*)malloc(sizeof(Node));
    Node *node1 = (Node*)malloc(sizeof(Node));
    node1->data = 1;
    Node *node2 = (Node*)malloc(sizeof(Node));
    node2->data = 2;
    head -> next = node1;
    node1 -> next = node2;
    node2 -> next = NULL;
    Node *cur = head -> next;
    while(cur != NULL) {
        printf("%d", cur->data);
        cur = cur -> next;
    }
    
    
    return 0;
}