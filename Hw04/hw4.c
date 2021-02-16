#include <stdio.h>
/* Question 1 */

int isPrime(int x);
int sLen(char s[]);
void reverse();
int sumDig(int a);

/*
int main() {

  printf("%d\n", isPrime(18));
  printf("%d\n", sLen("Eight Letters") );
  reverse();
  printf("%d\n", sumDig(628105));
  return 0;
}
*/

int isPrime(int x) {
  int i, prime=1;

  for(i=2; i<x && prime==1; i++)
    if(x%i==0)
      prime=0;

  return prime;
}

int sLen(char a[]){
  int length=0;
  while(a[length]!='\0')
    length++;
  return length;
}

void reverse() {
  int i=0, a[100];

  while(a[i-1]!=-1){
    scanf("%d", &a[i] );
    i++;
  }

  i=i-2;
  for(i; i>=0; i--){
    printf("%d  ", a[i]);
  }
}

int sumDig(int a) {
int sum=0;

while(a){
  sum+=a%10;
  a/=10;
}

  return sum;
}
/* ================= */
/* Question 2 */
/* Problem 1 */
/*  main function has no "return 0;", but fixing that
will print:0  5  */

/* Problem 2 */
/*
20
A 40
20
50 1.2340
50
*/
