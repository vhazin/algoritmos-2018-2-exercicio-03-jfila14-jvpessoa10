#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int * next;
    int value;
}ListItem;

typedef struct  {
    struct ListItem * list_item;
    int amount;  
}List;


void appendList(List * lista, int * value){
    ListItem *anterior,*novo;
    anterior = lista->list_item; 
    while(anterior->next != NULL){
        anterior  = anterior->next; 
    }
    novo->value = value;
    novo ->next = NULL;
    anterior->next =  novo;
    lista->amount +=1;
}


int main(){    
    int totalOfPeople;
    List * lista = malloc(sizeof(List));
    scanf("%d",&totalOfPeople);
    while(totalOfPeople--){
        int peopleId;
        scanf("%d",&peopleId);
        appendList(lista,peopleId);
    }
    
}