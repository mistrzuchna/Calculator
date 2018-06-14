#include "stackHandle.h"

struct stack {
    char *data;
    struct stack *next;
};

struct stack *push(struct stack *top, char *data) {
    struct stack *new_node = (struct stack *)
            malloc(sizeof(struct stack));

    if (NULL != new_node) {
        new_node->data = calloc(1000, sizeof(char));
        strcpy(new_node->data, data);
        new_node->next = top;
        top = new_node;
    }
    return top;
}

struct stack *pop(struct stack *top, char *result) {
    strcpy(result, top->data);
    struct stack *tmp = top->next;
    free(top);
    return tmp;
}

char *peek(struct stack *top) {
    if (NULL != top)
        return top->data;
    return NULL;
}

void stackViev(struct stack *top){
    if(top==NULL)
        printf("Brak elementow\n");
    else
        do{
            printf("%s ", top->data);
            top=top->next;
        }while (top!=NULL);
    puts("\n");
}
