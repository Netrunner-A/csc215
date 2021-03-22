#include <stdio.h>
#include <stdlib.h>
typedef struct Student {
  int id;
  char name[20];
  double GPA;
} Student;

int main(){

  int n=0, i, iMax=0;
  double max=0, tmp;

  do {
    printf("Enter the number of students: ");
    scanf("%d", &n);
    if(n<=0)
      printf("Wrong input (must be positive integer)\n");
  } while(n<=0);

  Student *stds = (Student*) malloc(n*sizeof(Student));

  for(i=0; i<n; i++){
    printf("Enter ID of student %d: ", i+1);
    scanf("%d", &(*(stds+i)).id);
    printf("Enter name of student %d: ", i+1);
    scanf("%s", (*(stds+i)).name);
    printf("Enter GPA of student %d: ", i+1);
    scanf("%lf", &tmp);
    if(max==0)
      max = tmp;
    (*(stds+i)).GPA=tmp;
    if(max < tmp){
      max = tmp;
      iMax = i;
    }
  }

  printf("%s\n", (*(stds+iMax)).name);
  for(i=0; i<n; i++){
    if(i!=iMax)
      printf("%s\n", (*(stds+i)).name);
  }
  
  free(stds);
  return 0;
}
