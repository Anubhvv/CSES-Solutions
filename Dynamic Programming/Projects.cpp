#include <bits/stdc++.h>

#include <array>

#define loop(i, a, n) for (long long i = a; i < n; ++i)

  long long max_reward_upto[200001];
int n;
using namespace std;

long long max(long long a, long long b) {
  if (a > b)
    return a;
  return b;
}

int binary_search(long long target, array < long long, 3 > schedule_adp[], int i) {
  int st = i;
  int end = n - 1;
  while (st <= end) {
    int mid = (st + end) / 2;
    if (schedule_adp[mid][0] <= target) {
      st = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return st;
}

long long rec(int ind, array < long long, 3 > schedule_adp[]) {
  if (max_reward_upto[ind] == -1) {
    long long ans = 0;
    if (ind < n) {
      int i = binary_search(schedule_adp[ind][1], schedule_adp, ind + 1);
      ans = max(ans, schedule_adp[ind][2] + rec(i, schedule_adp));
      ans = max(ans, rec(ind + 1, schedule_adp));
    }
    max_reward_upto[ind] = ans;
  }
  return max_reward_upto[ind];
}
int main() {
  memset(max_reward_upto, -1, sizeof max_reward_upto);
  scanf("%d", & n);
  long long a, b, p;
  array < long long, 3 > schedule_adp[n];
  loop(i, 0, n) {
    scanf("%lld %lld %lld", & a, & b, & p);
    schedule_adp[i][0] = a;
    schedule_adp[i][1] = b;
    schedule_adp[i][2] = p;
  }
  sort(schedule_adp, schedule_adp + n);
  printf("%lld", rec(0, schedule_adp));
  return 0;
}
