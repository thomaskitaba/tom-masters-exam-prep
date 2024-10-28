#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct node{
    struct node* next;
    int m;
} node;

node *InsertNode(node * temp);
node *FreeNode(node* temp);
node * PrintNode(node* temp);

int main(void) {
    
    node *head = NULL;
    node *temp = head;
    node * current = NULL;

    head = InsertNode(head);
    temp = head;
    PrintNode(temp);
    temp = head;
    printf("test Print--temp head: %d\n", temp->m);
    

    while(temp) {
        current = temp;
        free(temp);
        temp = current->next;
    }
    /* or possibley 
     while(temp) {
        current = temp->next;
        free(temp);
        temp = current;
    }
    
    */
    return(0);
}

node * InsertNode(node * temp) {
    node* h = NULL;
    int i;

    node* newNode = NULL;
    for(i = 1; i <= 10; i++) {
        newNode = (node *)malloc(sizeof(node));
        if (newNode == NULL) {
            printf("Malloc ERROR");
            return(NULL);
        }
        newNode->m = i;
        newNode->next = NULL;

        if (temp == NULL) {
            temp = newNode;
            h = temp;
        } else {

        temp->next = newNode;
        temp = temp->next;
        }
    }
    return(h);
}

node * PrintNode(node* temp) {
    node * h = temp;
    int count = 0;

    printf("Print Using While Loop--------------\n");
    while(temp) {
        count ++;
        printf("node-%d: %d\n", count, temp->m);
        temp = temp->next;
    }

    printf("print Using For loop--------------\n");
    
    count = 0;
    for (temp = h; temp != NULL; temp = temp->next) {
        count ++;
        printf("node-%d: %d\n", count, temp->m);
    }
    return(h);

}

node * FreeNode(node* temp) {
    node * h;
    node * current = temp;
    h = temp;
    while(temp) {
        current = temp;
        free(temp);
        current = current->next;
    }
    return(h);
}