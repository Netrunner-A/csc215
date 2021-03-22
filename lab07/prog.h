

typedef struct {
  int total_chars;
  int letters_count;
  int words_count;
  int lines_count;
  int max_line_length;
} FileStats;
/* returns 1 if param is a letter
and 0 otherwise */
int is_letter(char);
/* takes a filename as a string param
and returns a pointer to a FileStats
structure, or NULL on failure */
FileStats* process_file(char*);
/* takes a filename as a string param
and returns an array contains all the
lines of the file, or NULL on failure
*/
char** get_lines(char*);
