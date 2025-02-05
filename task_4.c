#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define MAXN 210

long long dp[MAXN][MAXN];
char s[MAXN];

int is_pair(char a, char b) {
  return (a == '(' && b == ')') || (a == '[' && b == ']') ||
         (a == '{' && b == '}');
}

long long solve(int i, int j) {
  if (i > j)
    return 1;
  if (dp[i][j] != -1)
    return dp[i][j];

  long long res = 0;

  for (int k = i + 1; k <= j; k += 2) {
    if (s[i] == '?' && s[k] == '?') {
      res = (res + 3 * solve(i + 1, k - 1) * solve(k + 1, j)) % MOD;
    } else if (s[i] == '?') {
      if (s[k] == ')' || s[k] == ']' || s[k] == '}') {
        res = (res + solve(i + 1, k - 1) * solve(k + 1, j)) % MOD;
      }
    } else if (s[k] == '?') {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        res = (res + solve(i + 1, k - 1) * solve(k + 1, j)) % MOD;
      }
    } else if (is_pair(s[i], s[k])) {
      res = (res + solve(i + 1, k - 1) * solve(k + 1, j)) % MOD;
    }
  }

  dp[i][j] = res;
  return res;
}

int main() {
  int N;
  scanf("%d", &N);
  scanf("%s", s);

  memset(dp, -1, sizeof(dp));

  long long result = solve(0, N - 1);

  printf("%lld\n", result);

  return 0;
}