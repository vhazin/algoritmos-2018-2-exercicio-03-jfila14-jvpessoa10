#include <stdio.h>
#include <stdlib.h>


typedef struct List_Item{
    struct List_Item * next;
    int value;
}ListItem;

typedef struct  {
    ListItem * start;
    ListItem * top;
    int total;  
}List;


void appendList(List * lista, int value){
    
    ListItem  * new = (ListItem *)malloc(sizeof(ListItem));
    new->value = value;
    new -> next = NULL;
    

    if(lista->start == NULL){
        lista -> start = new;
        lista -> top = new;
        return;
    }

    lista->top->next = new;
    lista->top = new;

        
}

void removePerson(List * list,int value){
    
    ListItem * index = list->start, *tmp;

    if(list->start != NULL && index->value == value){
        list->start = index->next;
        free(index);
        return;
    }
    
    

    while(index->value != value && index != NULL){
        
        tmp = index;
        index = index->next;
    }
    if(index->next == NULL){
        list->top = tmp;
        tmp->next = NULL;
        free(index);
        return;
    }
    tmp->next = index->next;
    
        

}

int main(){    
    List * listOfPeople = (List *)malloc(sizeof(List));
    int i;
    scanf("%d",&i);
    
    while(i--){
        int peoplevalue; 
        scanf("%d",&peoplevalue);
        appendList(listOfPeople,peoplevalue);
        
    }
    
    int numberOfItensToRemove;
    scanf("%d",&numberOfItensToRemove);
    
    
    while(numberOfItensToRemove--){
        int Removevalue;
        scanf("%d",&Removevalue);
        removePerson(listOfPeople,Removevalue);
    }
    
    ListItem * printItem = listOfPeople->start;

    while(printItem != NULL){
        printf("%d ",printItem->value);
        printItem = printItem->next;
    }
    printf("\n");
        free(listOfPeople);
     return 0;
    
}
