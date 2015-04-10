#include<stdio.h>
#include<stdlib.h>
#include"list"
void append(list *node)
{
    list*node=malloc(sizeof(node*));
    node=node->next;
    node->next=NULL;
}
