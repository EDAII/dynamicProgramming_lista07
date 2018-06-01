#include <stdio.h>
#include <stdlib.h>
 
typedef struct node {
	int val, len;
	struct node *next;
}no;
 
void sub(int *v, int len){
	no *p;
    no *n = (no *)calloc(len, sizeof(no));
	int i;

	for (i = 0; i < len; i++){
		n[i].val = v[i];
    }
 
	for (i = len; i >= 0; i--) {
		for (p = (n + i); p < (n + len); p++) {
			if (p->val > n[i].val && p->len >= n[i].len) {
				n[i].next = p;
				n[i].len = p->len + 1;
			}
		}
	}
 
	for (i = 0, p = n; i < len; i++){
		if (n[i].len > p->len){
            p = n + i;
        }
    }
    
    puts("\n======");
    puts("Maior subsequencia crescente:");
	for(;p != NULL; p = p->next){
        printf("%d ", p->val);
    }
	puts("");
	free(n);
}
 
int main(){
	int x[] = {2, 3, 14, 5, 9, 8, 4};
    int tam = sizeof(x) / sizeof(int);
    int i;

    puts("Sequencia inicial:");
    for(i=0; i < tam; i++){
        printf("%d ", x[i]);
    }
	sub(x, tam);
	return 0;
}