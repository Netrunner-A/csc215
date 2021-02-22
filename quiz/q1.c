#include <stdio.h>
#include <ctype.h>

int main() {
char words[1000];
int counter = 0;

printf("Please enter a sentence: ");
fgets(words, 1000, stdin);

while(words[counter]!='\n'){
    if(isdigit(words[counter])){
      if(words[counter-1]==' ') {
        words[counter-1]='(';
      }
      if(words[counter+1]==' ')
        words[counter+1]=')';
    }
    counter++;
}

printf("The modified result: ");
printf("%s\n", words);




  return 0;
}
