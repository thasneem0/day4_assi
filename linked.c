#include <stdio.h>
#include <stdlib.h>

typedef float T;

struct Node_t {
    T element;
    struct Node_t *next;
    struct Node_t *prev;
};

typedef struct Node_t node;

typedef struct {
    node *head;
    node *tail;
    int size; 
} list;

void listinit(list *list);
void listpushfront(list *list, T element);
void listpushback(list *list, T element);
void listpopfront(list *list);
void listpopback(list *list);
int listempty(list *list);
T listfront(list *list);
T listback(list *list);
node* createNode(T element); 


int main() {
    float salaries[] = {50000, 40000, 48000, 23000, 29000};
    list mylist; 

    listinit(&mylist);

    for (int i = 0; i < 5; i++) {
        listpushback(&mylist, salaries[i]);
    }

    printf("The salaries are:\n");
    for (node *current = mylist.head; current != NULL; current = current->next) {
        printf("%f\n", current->element);
    }

    return 0;
}

void listinit(list *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

node* createNode(T element) {  
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) { 
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    newNode->element = element;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void listpushfront(list *list, T element) {
    node *newNode = createNode(element);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->size++;
}

void listpushback(list *list, T element) {
    node *newNode = createNode(element);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    list->size++;
}

int listempty(list *list) {
    return list->size == 0;
}

T listfront(list *list) {
    if (listempty(list)) {
      fprintf(stderr, "List is empty, cannot get front element.\n");
      exit(EXIT_FAILURE); 
    }
    return list->head->element;
}

T listback(list *list) {
    if (listempty(list)) {
      fprintf(stderr, "List is empty, cannot get back element.\n");
      exit(EXIT_FAILURE); 
    }
    return list->tail->element;
}

void listpopfront(list *list) {
    if (listempty(list)) return;

    node *temp = list->head;
    list->head = list->head->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL; 
    }
    free(temp);
    list->size--;
}

void listpopback(list *list) {
    if (listempty(list)) return;

    node *temp = list->tail;
    list->tail = list->tail->prev;
    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL; 
    }
    free(temp);
    list->size--;
}
