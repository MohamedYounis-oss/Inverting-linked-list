#include <stdio.h>
#include <stdlib.h>



typedef struct node{

    int data;
    struct node* next;

}node_t;



node_t* list_createNode(int data)
{

    node_t* new_node  = (node_t*) malloc(sizeof(node_t));

    if(new_node == 0)
    {
        return 0;
    }

    new_node->data = data;
    new_node->next = 0;


    return new_node;


}


void list_addNode(node_t** phead, int data){


    node_t* newNode_address = list_createNode(data);
    node_t* current = *phead;

    if(*phead == 0)
    {
        *phead = newNode_address;
        return;
    }

    while(current->next != 0)
    {
        current = current->next;
    }

    current->next = newNode_address;


}


void list_reverse(node_t **phead){

    if (*phead == 0){
        return ;
    }

    node_t *previous, *current, *temp;
    previous = *phead; 
    current = previous->next; 
    previous->next = 0;

    while (current !=0){

        temp = current->next;
        current->next = previous;  
        previous = current;    
        current = temp; 
    }
    *phead = previous;

}


void list_print(node_t* head){

    node_t* current = head;

    while(current != 0)
    {

        printf("%d\n", current->data);
        current = current->next;
    }
    printf("==========\n");

}



int main()
{

    node_t *list1 = 0;

    list_addNode(&list1, 1);
    list_addNode(&list1, 3);
    list_addNode(&list1, 5);
    list_addNode(&list1, 7);
    list_addNode(&list1, 9);
    list_addNode(&list1, 11);

    list_print(list1);
    list_reverse(&list1);
    list_print(list1);



    return 0;
}
