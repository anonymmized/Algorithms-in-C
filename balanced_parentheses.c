#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

typedef struct {
    char *data;
    int size;
    int capacity;
} Stack;

int stack_init(Stack *s, int capacity) {
    if (s == NULL || capacity <= 0) {
        return -1;
    }
    s->data = malloc(capacity * sizeof(char));
    if (s->data == NULL) return -1;
    s->size = 0;
    s->capacity = capacity;
    return 0;
}

int stack_push(Stack *s, char value) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        char *new_data = realloc(s->data, s->capacity * sizeof(char));
        if (new_data == NULL) {
            return 1;
        }
        s->data = new_data;
    }
    s->data[s->size] = value;
    s->size++;
    return 0;
}

char stack_pop(Stack *s) {
    if (s->size == 0) {
        return 0;
    }
    return s->data[--s->size];
}

int stack_empty(Stack *s) {
    return s->size == 0;
}

void stack_free(Stack *s) {
    if (s == NULL) return;
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
}

int is_opening(char c) {
    return (c == '(' || c == '[' || c == '{');
}

char get_opening(char closing) {
    switch (closing) {
        case ')' : return '(';
        case ']' : return '[';
        case '}' : return '{';
        default: return 0;
    }
}

int is_balanced(const char *line) {
    Stack s;
    if (stack_init(&s, 32) != 0) return 0;

    for (int i = 0; line[i] != '\0'; i++) {
        char c = line[i];
        if (is_opening(c)) {
            stack_push(&s, c);
        } else {
            char expected = get_opening(c);
            if (expected != 0) {
                if (stack_empty(&s)) {
                    stack_free(&s);
                    printf("No matching opening bracket for '%c'\n", c);
                    return 0;
                }
                char actual = stack_pop(&s);
                if (actual != expected) {
                    stack_free(&s);
                    printf("Mismatch: expected '%c', got '%c'\n", expected, actual);
                    return 0;
                    }
            }
        }
    }
    int result = stack_empty(&s);
    if (result == 0) {
        printf("No matching opening bracket for '%c'\n", stack_pop(&s));
    }
    stack_free(&s);
    return result;
}

int mgetline(char *line, int lim) {
    int c;
    int i = 0;
    while (--lim > 0 && (c = getchar()) != '\n' && c != EOF) {
        line[i++] = c;
    }
    if (c == '\n') {
        line[i++] = '\n';
    }
    line[i] = '\0';
    return i;
}