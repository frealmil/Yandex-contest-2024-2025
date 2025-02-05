#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int n;
int A[MAX_N], B[MAX_N], C[MAX_N];
bool removed[MAX_N];

int countA[MAX_N + 1] = {0}, countB[MAX_N + 1] = {0}, countC[MAX_N + 1] = {0};
int queue[MAX_N], q_size = 0;
bool inQueue[MAX_N + 1] = {0};

int invA[MAX_N + 1][100], invB[MAX_N + 1][100], invC[MAX_N + 1][100];
int invA_size[MAX_N + 1] = {0}, invB_size[MAX_N + 1] = {0},
                      invC_size[MAX_N + 1] = {0};

void pushQueue(int num) {
  if (!inQueue[num]) {
    queue[q_size++] = num;
    inQueue[num] = true;
  }
}

void removeColumn(int idx) {
  countA[A[idx]]--;
  countB[B[idx]]--;
  countC[C[idx]]--;
  removed[idx] = true;
  if (countA[A[idx]] == 0)
    pushQueue(A[idx]);
  if (countB[B[idx]] == 0)
    pushQueue(B[idx]);
  if (countC[C[idx]] == 0)
    pushQueue(C[idx]);
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    countA[A[i]]++;
    invA[A[i]][invA_size[A[i]]++] = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &B[i]);
    countB[B[i]]++;
    invB[B[i]][invB_size[B[i]]++] = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &C[i]);
    countC[C[i]]++;
    invC[C[i]][invC_size[C[i]]++] = i;
  }

  memset(removed, 0, sizeof(removed));
  int toRemove = 0;

  for (int i = 1; i <= n; i++) {
    if (countA[i] == 0 || countB[i] == 0 || countC[i] == 0) {
      pushQueue(i);
    }
  }

  while (q_size > 0) {
    int cur = queue[--q_size];

    for (int i = 0; i < invA_size[cur]; i++) {
      int idx = invA[cur][i];
      if (!removed[idx]) {
        removeColumn(idx);
        toRemove++;
      }
    }
    for (int i = 0; i < invB_size[cur]; i++) {
      int idx = invB[cur][i];
      if (!removed[idx]) {
        removeColumn(idx);
        toRemove++;
      }
    }
    for (int i = 0; i < invC_size[cur]; i++) {
      int idx = invC[cur][i];
      if (!removed[idx]) {
        removeColumn(idx);
        toRemove++;
      }
    }
  }

  printf("%d\n", toRemove);
  return 0;
}