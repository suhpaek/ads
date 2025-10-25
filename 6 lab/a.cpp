#include <cstdio>
#include <utility>
using namespace std;

template<typename type>
int partition(type* arr, int start, int end){
  int i = start - 1, j = start;
  type pivot = arr[end];
  while(j < end){
    if(arr[j] < pivot)
      swap(arr[++i], arr[j]);
    j++;
  }
  swap(arr[++i], arr[end]);
  return i;
}


template<typename type>
void quickSort(type* arr, int start, int end){
  if(start >= end) return;
  int pivot = partition<type>(arr, start, end);
  quickSort(arr, start, pivot - 1);
  quickSort(arr, pivot + 1, end);
}

const int N = 1e5 + 10;
int n;

char s[N];
char vowels[N];
char consonants[N];
int vowels_size, consonants_size;

bool isVowel(char letter){
  return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
}

int main(){
  scanf("%d %s", &n, s);
  for(int i = 0; i < n; i++){
    char letter = s[i];
    if(isVowel(letter)) vowels[vowels_size++] = letter;
    else consonants[consonants_size++] = letter;
  }
  consonants[consonants_size] = '\0';
  vowels[vowels_size] = '\0';
  quickSort(vowels, 0, vowels_size - 1);
  quickSort(consonants, 0, consonants_size - 1);
  printf("%s%s", vowels, consonants);
}