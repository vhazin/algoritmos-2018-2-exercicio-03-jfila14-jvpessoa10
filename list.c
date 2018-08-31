#include <stdio.h>
#include <stdlib.h>


typedef struct List_Item{
    struct List_Item * next;
    struct List_Item * before;
    int value;
}ListItem;

typedef struct  {
    ListItem * start;
    ListItem * top;
    int total;  
}List;


void appendList(List * lista, int value){
    
    ListItem  * new = malloc(sizeof(new));
    new->value = value;
    new -> next = NULL;
    new -> before = lista->top;

    if(lista->start == NULL){
        lista -> start = new;
        lista -> top = new;
        return;
    }

    lista->top->next = new;
    lista->top = new;

        
}

void removePerson(List * list,int index){
    
    ListItem * tmp = list->start;

    if(list->start != NULL && tmp->value == index){
        list->start = tmp->next;
        list->top->before = NULL;
        free(tmp);
        return;
    }
    
    
    while(tmp->value != index && tmp != NULL){
        if(list->top != NULL && tmp->next == NULL){
            list->top = tmp->before;
            list->top->next = NULL;
            free(tmp);
            return;
        }

        tmp = tmp->next;
    }
    tmp->before->next= tmp->next;
    free(tmp);
    

}
int main(){    
    List listOfPeople = (List){.total = 0,.start = NULL,.top=NULL};
    
    int i;
    scanf("%d",&i);
    
    while(i--){
        int peopleIndex; 
        scanf("%d",&peopleIndex);
        appendList(&listOfPeople,peopleIndex);
        
    }
    
    int numberOfItensToRemove;
    scanf("%d",&numberOfItensToRemove);
    
    
    while(numberOfItensToRemove--){
        int RemoveIndex;
        scanf("%d",&RemoveIndex);
        removePerson(&listOfPeople,RemoveIndex);
    }
    
    ListItem * printItem = listOfPeople.start;

    while(printItem != NULL){
        printf("%d ",printItem->value);
        printItem = printItem->next;
    }
    printf("\n");

     return 0;
    
}
