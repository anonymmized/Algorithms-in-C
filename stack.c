#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Stack;

int stack_init(Stack *s, int capacity) {
    if (s == NULL || capacity <= 0) {
        return -1;
    }

    s->data = malloc(capacity * sizeof(int));
    if (s->data == NULL) {
        return -1;
    }

    s->size = 0;
    s->capacity = capacity;
    return 0;
}

int stack_push(Stack *s, int value) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        int *new_data = realloc(s->data, s->capacity * sizeof(int));
        if (new_data == NULL) {
            return -1;
        }
        s->data = new_data;
        return 0;
    }

    s->data[s->size] = value;
    s->size++;
}

int stack_pop(Stack *s) {
    if (s->size == 0) {
        return -1;
    }
    s->size--;
    return s->data[s->size];
}

int stack_top(Stack *s) {
    if (s->size == 0) {
        return -1;
    }
    return s->data[s->size - 1];
}

int stack_size(Stack *s) {
    if (s == NULL) return 0;
    return s->size;
}

void stack_free(Stack *s) {
    if (s == NULL) return;
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
}