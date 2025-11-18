#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, soma=0;
    scanf("%d",&n);
    int *v=malloc(n*sizeof(int));
    for (int i=0;i<n;i++) {
        scanf("%d",&v[i]);
        soma+=v[i];
    }
    float media = (float)soma/(float)n;
    printf("Media: %.2f", media);
    free(v);
}