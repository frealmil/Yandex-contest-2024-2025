#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define MAX_WORDS 30000
#define MAX_WORD_LENGTH 31

typedef struct TrieNode {
  struct TrieNode *children[ALPHABET_SIZE];
  int is_end_of_word;
} TrieNode;

TrieNode *create_node() {
  TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
  node->is_end_of_word = 0;
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    node->children[i] = NULL;
  }
  return node;
}

void insert(TrieNode *root, const char *word) {
  TrieNode *current = root;
  for (int i = 0; word[i]; i++) {
    int index = word[i] - 'a';
    if (!current->children[index]) {
      current->children[index] = create_node();
    }
    current = current->children[index];
  }
  current->is_end_of_word = 1;
}

int longest_common_prefix(TrieNode *root, const char *word) {
  TrieNode *current = root;
  int prefix_length = 0;
  for (int i = 0; word[i]; i++) {
    int index = word[i] - 'a';
    if (!current->children[index]) {
      break;
    }
    current = current->children[index];
    prefix_length++;
  }
  return prefix_length;
}

int main() {
  int N, Q;
  char database[MAX_WORDS][MAX_WORD_LENGTH];
  char query[MAX_WORD_LENGTH];

  TrieNode *root = create_node();

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", database[i]);
    insert(root, database[i]);
  }

  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    scanf("%s", query);

    int total_operations = 0;
    for (int j = 0; j < N; j++) {
      int lcp = longest_common_prefix(root, query);
      total_operations += 1 + lcp;
      if (strcmp(database[j], query) == 0) {
        break;
      }
    }
    printf("%d\n", total_operations);
  }

  return 0;
}