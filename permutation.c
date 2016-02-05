#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

#define string char*

string input(string query) {
    string reply = malloc(200);

    printf("%s: ", query);
    fgets(reply, 200, stdin);

    // apparently, fgets also gets the \n at the end.
    reply[strlen(reply)-1] = '\0';

    return reply;
}

void permute(Stack* stack, string s, int j, int length) {
    for (int i = j; i < length; i++) {
        push(stack, s[i]);
        print(stack);
        printf("\n");
        permute(stack, s, i + 1, length);
        pop(stack);
    }
}

int main() {
    char* s = input("Input your string");

    int length = strlen(s);

    Stack* stack = create_stack();

    print(stack);
    printf("\n");
    permute(stack, s, 0, length);

    return 0;
}

