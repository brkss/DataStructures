#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

struct Node *HEAD = NULL;

void add(int data){

    if(HEAD == NULL){
        HEAD = (struct Node*)malloc(sizeof(struct Node*));
        if(!HEAD) return;
        HEAD->data = data;
        HEAD->next = NULL;
        return;
    }else{
        struct Node *tmp = HEAD;
        struct Node *n = NULL;
        while(tmp->next){
            tmp = tmp->next;
        }    
        n = (struct Node*)malloc(sizeof(struct Node*));
        if(!n) return;
        n->data = data;
        n->next = NULL;
        tmp->next = n;
        return;
    }
}

void show(){
    struct Node *tmp = HEAD;
    if(!tmp) return;    
    while(tmp->next){
        printf("[%d]->", tmp->data);
        tmp = tmp->next;
    }
    printf("[%d]\n", tmp->data);
}

int main(){

    add(5);
    add(13);
    add(99);
    add(100);
    add(-2);
    add(4);
    add(2);
    show(); 
    return 0;

}