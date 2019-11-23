#include <stdio.h>

long long fib(long long);

int main(){
  long long a;
  while(scanf("%lld", &a) != EOF){
    printf("%lld\n", fib(a));
  }

  return 0;
}

long long fib(long long n){
  return (n == 0) ? n : (n == 1) ? n : fib(n - 1) + fib(n - 2);
}
