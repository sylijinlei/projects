pthread_create:pthread_create.c
	gcc -o $@ $^ -lpthread
mutex:mutex.c
	gcc -o $@ $^ -lpthread
sem:sem.c
	gcc -o $@ $^ -lpthread
cond:cond.c
	gcc -o $@ $^ -lpthread
clean:
	rm pthread_create
	rm mutex
	rm sem
	rm cond

