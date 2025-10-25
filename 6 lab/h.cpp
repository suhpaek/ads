#include <cstdio>


const int N = 1e6;
char arr[N];
int n;
/*

abccef
d
m = 3->a[m] = c;
l = 

*/
int upper(char letter){
  int l = 0, r = n - 1;
  int res = -1;
  while(l <= r){
    int m = l + (r - l) / 2;
    if(arr[m] <= letter){
      res = m;
      l = m + 1;
    } else r = m - 1;
  }
  return res;
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf(" %c", arr + i);
  char letter;
  scanf(" %c", &letter);
  int index = upper(letter);
  if(index == n - 1 && arr[index] <= letter) index = 0;
  if(index == -1) index = 0;
  if(arr[index] == letter and index != 0) index++;
  printf("%c", arr[index]);
}