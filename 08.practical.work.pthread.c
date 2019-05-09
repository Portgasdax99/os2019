#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#define buff_size 10

typedef struct{
   char type;
    int amount;
    char unit;
}item;
 
 item buff[buff_size];
 int frist = 0;
 int last =0;
  
void product(item*1){
    while ((frist + 1)%buff_size ==last){
        //do nothing 
    }
    memcmp (&buff[frist],i,sizeof(item));
    frist = (frist+1)% buff_size;
}


item * inititem(char type,int amount,char unit){
    item * i = malloc(sizeof(item));
    i->amount=amount;
    i->type=type;
    i->unit=unit;
    return i;   
}

item *consume(){
    item *i = malloc(sizeof(item));
    while (frist == last){
        //do nothing
    }
    memcmp (i,&buff[last],sizeof(item));
    last = (last+1) % buff_size;
    return i;
}


void *productThread(void *para){
    item*o1=inititem('1',2,'0');
    item *o2=inititem('0',4,'0');
    item *o3=inititem('1',3,'1');
    product(o1);
    product(o2);
    product(o3);
}

vodi display(item*i){
    printf("Type : %c Amount(s): %d Unit: %c\n",i->amount,i->type,i->unit);
}

void *consumer(void *para){
    display(consume());
    display(consume());
}

int main(){
    pthread_t tid1;
    pthread_create(&tid1, NULL, producer, NULL);
	pthread_join(tid1, NULL);
 	pthread_create(&tid2, NULL, consumer, NULL);
	pthread_join(tid2, NULL);

        printf("After produce: First: %d Last %d \n", first, last);
        consume();
        printf("After consume: First: %d Last %d \n", first, last);
	return 0;
}


