#include <stdio.h>
#include <stdlib.h>
#include "prog.h"
int is_letter(char c);
FileStats* process_file(char*);
char** get_lines(char*);
void write_rev(char* fn, char** strs, int nstr);
int main() {
  FileStats* fsp; char** lines;
  fsp = process_file("wcs.txt");
  /*printf the returned stats */
  lines = get_lines("wcs.txt");
  write_rev("wcs-rev.txt", lines, fsp->lines_count);
  return 0;
}
/* define the functions
you can write function stubs
during development */

/* returns 1 if param is a letter
and 0 otherwise */
int is_letter(char c) {
  if(c >= 'a' && c <= 'z' || c >= 'A' && c<= 'Z')
    return 1;
  return 0;
}
/* takes a filename as a string param
and returns a pointer to a FileStats
structure, or NULL on failure */
FileStats* process_file(char* c) {
  FileStats* p;
  p = (FileStats*)calloc(sizeof(FileStats), 1);
  char t;
  FILE* fp;
  int max = 0;
  if(fp = fopen(c, "r")) {
    int in = 0;
    do {
      t = getc(fp);
      max++;
      if(is_letter(t)) {
        p->letters_count++;
        if(!in) {
          p->words_count++;
          in = 1;
        }
      } else in = 0;
      if(t == '\n' || t == EOF)
        p->lines_count++;
      if(t == '\n') {
        if(p->max_line_length < max)
          p->max_line_length = max;
        max = 0;
      }
    } while(c != EOF);
    p->total_chars = ftell(fp);
    fclose(fp);
    return p;
  }
  perror("Cannt Open the file");
  return NULL;
}

char** get_lines(char* fn) {
  char** result = NULL;
  FileStats* fs = process_file(fn);
  if (fs) {
    result = (char**)calloc(fs->lines_count, sizeof(char*));
    FILE* f = fopen(fn, "r");
    if (f) {
      int i;
      for(i=0; i< fs-> lines_count; i++) {
        result[i] = (char*)calloc(fs->max_line_length, 1);
        fgets(result[i], fs->max_line_length, f);
      }

    }
    fclose(f);
  }
  return result;
}

void write_rev(char* fn, char** strs, int nstr) {
  int i;
  FILE* f = fopen(fn, "w");
  if(f) {
    for(i=nstr-1; i>=0; i--)
      while(fputs(strs[i], f) == 0)
        putc('\n', f);
  } else
    perror("Can't open the file");
}
