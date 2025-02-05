#include <stdio.h>
#include <string.h>

#define SIZE 20

void check_word(char *min_word, char *current_word) {
  if (strlen(current_word) >= 2 &&
      (strcmp(current_word, min_word) < 0 || strlen(min_word) == 0)) {
    strcpy(min_word, current_word);
  }
}

int main() {
  int R, C;
  char grid[SIZE][SIZE + 1];
  char min_word[SIZE + 1] = "";
  scanf("%d %d", &R, &C);

  for (int i = 0; i < R; i++) {
    scanf("%s", grid[i]);
  }

  for (int i = 0; i < R; i++) {
    char curren_word[SIZE + 1] = "";
    for (int j = 0; j < C; j++) {
      if (grid[i][j] != '#') {
        int len = strlen(curren_word);
        curren_word[len] = grid[i][j];
        curren_word[len + 1] = '\0';
      } else {
        check_word(min_word, curren_word);
        curren_word[0] = '\0';
      }
    }
    check_word(min_word, curren_word);
  }

  for (int j = 0; j < C; j++) {
    char curren_word[SIZE + 1] = "";
    for (int i = 0; i < R; i++) {
      if (grid[i][j] != '#') {
        size_t len = strlen(curren_word);
        curren_word[len] = grid[i][j];
        curren_word[len + 1] = '\0';
      } else {
        check_word(min_word, curren_word);
        curren_word[0] = '\0';
      }
    }
    check_word(min_word, curren_word);
  }

  printf("%s\n", min_word);

  return 0;
}
