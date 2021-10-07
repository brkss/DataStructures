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

void delete(int data){
    
    if(!HEAD) return;
    struct Node *tmp = HEAD;
    struct Node *prv = NULL;
    // check if the head have the target value !
    if(tmp->data == data){
        HEAD = tmp->next;
        free(tmp);
        return;        
    }
    // check if next node doesnt exist !
    if(!tmp->next) return;
    prv = tmp;
    tmp = tmp->next;
    while(tmp->next){
        if(tmp->data == data){
            prv->next = tmp->next;
            free(tmp);
            return;
        }
        prv = tmp;
        tmp = tmp->next;
    }
    // check if last node have the target value;
    if(tmp->data == data){
        prv->next = NULL;
        free(tmp);
    }
    return;
}

struct Node *find(int data){

    if(!HEAD) return NULL;
    if(HEAD->data == data) return HEAD;
    struct Node *tmp = HEAD->next;
    while(tmp->next){
        if(tmp->data == data) return tmp;
        tmp = tmp->next;
    }
    if(tmp->data == data) return tmp;
    return NULL;

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
    delete(2);
    show();
    printf("find 99 : %d \n", find(99)->data); 
    return 0;

}