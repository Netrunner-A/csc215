#include <stdio.h>
#include <stdlib.h>
int main(){

  int a=0, i=0, c=0, flag=0, tmp=0;
  double avgSum=0, avg=0;
  printf("Enter the number of integers to process: ");
  scanf("%d", &a);
  int *v = (int *) malloc(a*sizeof(int));
  
  for(i = 0; i < a; i++) {
    printf("Enter value #%d: ", i+1);
    scanf("%d", &(tmp));
    for(c = 0; c < i; c++)
      if(*(v+c)==tmp) {
        printf("You have entered %d already\n", tmp);
        flag = 1;
        i--;
        break;
      } else flag = 0;
    if(!flag){
      *(v+i)=tmp;
      avgSum += (double)*(v+i);
    }
  }

  free(v);
  avg=avgSum/a;
  printf("The average of array elements: %.2f\n", avg);

  return 0;
}
