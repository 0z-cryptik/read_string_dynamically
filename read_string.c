#include <stdio.h>
#include <stdlib.h>

char *read_string_dynamically() {
  int capacity = 10; // initial capacity
  int length = 0;    // keep track of where we are in the string
  char *buffer = malloc(capacity * sizeof(char));

  if (!buffer) {
    printf("buffer malloc failed\n");
    return NULL;
  }

  int ch;

  while ((ch = getchar()) != '\n' && ch != EOF) {
    // the +1 for \0
    if ((length + 1) >= capacity) {
      capacity *= 2;
      char *new_buffer = realloc(buffer, capacity);

      if (!new_buffer) {
        printf("realloc failed\n");
        free(buffer);
        return NULL;
      }

      buffer = new_buffer;
    }
    buffer[length++] = (char)ch;
  }
  buffer[length] = '\0';

  // shrink the buffer size to only what's needed (so as not to waste RAM), +1 because length is 0 indexed but realloc counts from 1, therefore we'll be off by 1 without the +1
  char *final_buffer = realloc(buffer, length + 1);
  return final_buffer ? final_buffer : buffer;
}