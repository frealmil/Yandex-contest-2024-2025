#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 200005

typedef struct {
  int first;
  int second;
} Pair;

int makeOpposite(int num) { return (num == 0) ? 0 : -num; }

int main() {
  int n, target;
  int ans = 0;
  scanf("%d %d", &n, &target);

  int *inp = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &inp[i]);
  }

  Pair *left_T = (Pair *)calloc(MAX_N, sizeof(Pair));

  int idx_target = -1;
  int left_count = 0, right_count = 0;

  for (int i = 0; i < n; i++) {
    if (inp[i] == target) {
      idx_target = i;
      break;
    }
  }

  left_T[MAX_N / 2].first++;
  left_T[MAX_N / 2].second = (idx_target % 2 == 0) ? 2 : 1;

  for (int i = idx_target - 1; i >= 0; i--) {
    left_count += (inp[i] > target) ? 1 : -1;
    int index = left_count + MAX_N / 2;
    left_T[index].first++;
    left_T[index].second = (i % 2 == 0) ? 2 : 1;
  }

  ans += left_T[MAX_N / 2].first;

  for (int i = idx_target + 1; i < n; i++) {
    right_count += (inp[i] > target) ? 1 : -1;
    if (right_count == 0) {
      if ((i % 2 == 0 && left_T[MAX_N / 2].second == 2) ||
          (i % 2 == 1 && left_T[MAX_N / 2].second == 1)) {
        ans += left_T[MAX_N / 2].first;
      }
    } else {
      int num = makeOpposite(right_count);
      int index = num + MAX_N / 2;
      if (left_T[index].first > 0) {
        if ((i % 2 == 0 && left_T[index].second == 2) ||
            (i % 2 == 1 && left_T[index].second == 1)) {
          ans += left_T[index].first;
        }
      }
    }
  }

  printf("%d\n", ans);

  free(inp);
  free(left_T);
  return 0;
}
