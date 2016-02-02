#include <string.h>
#include <stdlib.h>
#define string char*

typedef struct Stack Stack;
typedef struct Node Node;

struct Stack {
    Node* top;
};

struct Node {
    Node* next;
    char value;
};

Stack* create_stack() {
    Stack* stack = malloc(sizeof(Stack));
    
    stack->top = NULL;

    return stack;
}

Node* create_node(Node* next, char value) {
    Node* node = (Node*) malloc(sizeof(Node));

    node->next = next;
    node->value = value;

    return node;
}

void push(Stack* stack, char value) {
    stack->top = create_node(stack->top, value);
}

char pop(Stack* stack) {
    Node* top = stack->top;
    char value = top->value;

    stack->top = top->next;

    free(top);

    return value;
}

int is_empty(Stack* stack) {
    return stack->top == NULL;
}

void print(Stack* stack) {
    if ( ! is_empty(stack)) {
        char c = pop(stack);
        print(stack);
        printf("%c", c);
        push(stack, c);
    }
}

