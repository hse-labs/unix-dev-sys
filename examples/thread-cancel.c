#include <pthread.h>
#include <stdio.h>
struct thr_params {
	char c;
	int count;
};
void* thr_func(void* arg) {
	struct thr_params *p = (struct thr_params*)arg;
	for (int i=0; i < p->count; ++i)
		fputc(p->c,stdout);
	printf("Before cancel\n");
	pthread_testcancel();
	printf("After cancel");
	return NULL;
}
int main() {
	pthread_t thr1_id, thr2_id;
	struct thr_params thr1_params;
	thr1_params.count = 1000;
	thr1_params.c = 'a';
	pthread_create(&thr1_id, NULL, &thr_func, &thr1_params);
	pthread_cancel(thr1_id);
	struct thr_params thr2_params;
	thr2_params.count = 1500;
	thr2_params.c = 'b';
	pthread_create(&thr2_id, NULL, &thr_func, &thr2_params);
	pthread_cancel(thr2_id);
	return 0;
}
