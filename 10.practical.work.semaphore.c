#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
#define BUFFER_SIZE 10

typedef struct {
	char type; // 0=fried chicken, 1=French fries
	int amount; // pieces or weight
	char unit; // 0=piece, 1=gram
} item;

int pid = -1;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

int pthread_create(
	pthread_t *thread,
	const pthread_attr_t *attr,
	void *(*start_routine) (void *),
	void *arg
);


item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last){
		printf("Nothing to consume");
	}
	memcpy(i, &buffer[last], sizeof(item));
	i->amount -= 1;
	last = (last +1) % BUFFER_SIZE;
	printf("first = %d\t last = %d\n", first, last);
	return i;

}

void produ(item *i) {
	while ((first + 1) % BUFFER_SIZE == last){
		printf("No free buffer item\n");
	}
	memcpy(&buffer[first], i, sizeof(item));
	i->amount += 1;
	first = (first + 1) % BUFFER_SIZE;
	printf("first = %d\t last = %d\n", first, last);

}

item* createItem(char type, int amount, char unit){
	item* i = malloc(sizeof(item));
	i->type= type;
	i->amount = amount;
	i->unit = unit;
	return i;
}

void *consu_thread(void* param){
	
	printf("Consumer Thread is speak\nConsume bottles...\n");
	pthread_lock(&m);
	consume();
	consume();
	consume();
	pthead_unlock(&m);
	pthread_exit(NULL);

}

void *produ_thread(void* param){

	printf("Producer Thread is speak\nProduct bottles...\n");
	pthread_lock(&m);
	item* bottle = createItem('0', 3, '0');
	produ(bottle);
	produ(bottle);
	produ(bottle);
	pthead_unlock(&m);
	pthread_exit(NULL);

}



int main(){
	pthread_t tid1, tid2;
	int error;
	if(pthread_create(&tid1, NULL, produ_thread, NULL) !=0){
		pthead_err("pthread_create() fails");
	}
	if(pthread_create(&tid2, NULL, consu_thread, NULL) !-0){
		pthead_err("pthread_create() fails");
	}
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	ptherad_destroy(&m);
	return 0;

}
