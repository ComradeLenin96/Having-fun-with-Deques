#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
}Node;

typedef struct cdeque {
    Node* front;
    Node* rear;
}Cdeque;

Node* createNode(int);
Cdeque* emptyDeque();
int peek_front(Cdeque*);
int peek_rear(Cdeque*);
void push_front(Cdeque*, int);
void pop_front(Cdeque*);
void push_back(Cdeque*, int);
void pop_back(Cdeque*);
void display(Cdeque*);
int countElem(Cdeque*);

int main() {
    Cdeque* c_deque = emptyDeque();
    int count = countElem(c_deque);
    printf("COUNT:%d\n", count);
    push_back(c_deque, 5);
    push_front(c_deque, 6);
    push_front(c_deque, 7);
    push_front(c_deque, 8);
    count = countElem(c_deque);
    int peekVal = peek_front(c_deque);
    printf("peekVal:%d\n", peekVal);
    push_back(c_deque, 99);
    display(c_deque);
    pop_front(c_deque);
    pop_back(c_deque);
    display(c_deque);
    pop_back(c_deque);
    pop_back(c_deque);
    pop_front(c_deque);
    count = countElem(c_deque);
    printf("COUNT:%d\n", count);
    return 0;
}

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Allocation failed\n");
        return NULL;
    }else {
        newNode->next = newNode->prev = NULL;
        newNode->data = data;
    }
    return newNode;
}

Cdeque* emptyDeque() {
    Cdeque* cDeque = malloc(sizeof(Cdeque));
    if (cDeque == NULL) {
        printf("Allocation failed\n");
        return NULL;
    }else cDeque->front = cDeque->rear = NULL;
    return cDeque;
}

int peek_front(Cdeque* cDeque) {
    if (cDeque->front == NULL) printf("ERROR\n");
    else return cDeque->front->data; 
}

int peek_rear(Cdeque* cDeque) {
  if (cDeque->rear == NULL) printf("ERROR\n");
    else return cDeque->rear->data;
}

void push_front(Cdeque* cDeque, int data) {
    Node* newNode = createNode(data);
    //if cDeque is empty
    if (cDeque->front == NULL) {
        cDeque->front = cDeque->rear = newNode;
        newNode->next = cDeque->front;
    }else {
        Node* temp = cDeque->front;
        newNode->next = temp;
        temp->prev = newNode;
        cDeque->front = newNode;
        cDeque->rear->next = cDeque->front;
    }
    printf("<push_front>\n");
}

void pop_front(Cdeque* cDeque) {
    //if list is empty
    if (cDeque->front == NULL) printf("List is empty\n");
    else {
        Node* temp = cDeque->front;
        if (cDeque->front == cDeque->rear) {
            cDeque->front = cDeque->rear = NULL;
            temp->next = NULL;
            free(temp);
        }else{
            cDeque->front = temp->next;
            temp->next = NULL;
            cDeque->front->prev = NULL;
            cDeque->rear->next = cDeque->front;
            free(temp);
        }
    }
    printf("<pop_front>\n");
    printf("\n");
}

void push_back(Cdeque* cDeque, int data) {
    Node* newNode = createNode(data);
    //if list is empty
    if (cDeque->rear == NULL) {
        cDeque->front = cDeque->rear = newNode;
        newNode->next = cDeque->front;
    }else {
        Node* temp = cDeque->rear;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = cDeque->front;
        cDeque->rear = newNode;
    }
    printf("<push_back>\n");
}

void pop_back(Cdeque* cDeque) {
    if (cDeque->rear == NULL) printf("empty\n");
    else {
        //if we have one element in deque
        Node* temp = cDeque->rear;
        if (cDeque->rear == cDeque->front) {
           cDeque->rear = cDeque->front = NULL;
           temp->next = NULL;
           free(temp);
        }else {
            cDeque->rear = temp->prev;
            temp->next = temp->prev = NULL;
            cDeque->rear->next = cDeque->front;
            free(temp);
        }
    }
    printf("<pop_back>\n");
}

void display(Cdeque* cDeque) {
    if (cDeque->front == NULL) printf("Cdeque is empty\n");
    Node* curr = cDeque->front;
    while (curr->next != cDeque->front) {
        printf("cdeque->{%d}\t", curr->data);
        curr = curr->next;
    }
    printf("cdeque->{%d}\t", curr->data);
}

int countElem(Cdeque* cDeque) {
    int count = 0; 
    if (cDeque->front == 0) return count;
    else {
        Node* curr = cDeque->front;
        while (curr->next != cDeque->front) {
            ++count;
            curr = curr->next;
        }
        ++count;
    }
    return count;
}





