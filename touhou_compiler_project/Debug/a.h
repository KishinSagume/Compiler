typedef struct csy_que_node que_node;
struct csy_que_node{
    int type;
    void * value;
    que_node * next_node;
};

typedef struct csy_queue{
    que_node * head_node;//³ö 
    que_node * end_node;//½ø 
}queue;

/////////////////////////////////////

que_node * creat_node(void * value,int type){
    que_node * new_que_node = malloc(sizeof(que_node));
    switch(type){
    case 0:new_que_node->value = malloc(sizeof(int));
           *(int *)new_que_node->value = *(int *)value;
           new_que_node->type = 0;break;
    case 1:new_que_node->value = malloc(sizeof(double));
           *(double *)new_que_node->value = *(double *)value;
           new_que_node->type = 1;break;
    default:new_que_node->value = NULL;
    }
    return new_que_node;
}

queue * creat_queue(){
    queue * new_que = malloc(sizeof(queue));
    new_que->head_node = NULL;
    new_que->end_node = NULL;
    return new_que;
}


void insert(queue * myqueue,void * value,int type){
    que_node * new_node = creat_node(value,type);
    if(myqueue->head_node == NULL){
        myqueue->head_node = new_node;
        myqueue->end_node = new_node;
        return;
    }
    myqueue->end_node->next_node = new_node;
    myqueue->end_node = new_node;
    return;
}

void free_que_node(que_node * node){
    node->next_node = NULL;
    free(node->value);
    return;
}

void delete_que_node(queue * myqueue){
    if(myqueue->head_node == NULL) return;
    if(myqueue->head_node == myqueue->end_node){
        free_que_node(myqueue->head_node);
        myqueue->head_node = myqueue->end_node = NULL;
    }
    que_node * node_p = myqueue->head_node;
    myqueue->head_node = myqueue->head_node->next_node;
    free_que_node(node_p);
    return;
}
#include "C:/Users/Administrator/Desktop/touhou_compiler_project/Debug/b.h"
