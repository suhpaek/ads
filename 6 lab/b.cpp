#include <cmath>
#include <cstdint>
#include <cstdio>
#include <utility>

template<typename type>
class vector{
  private:
    size_t size;
    type* arr;
    size_t capacity;
  public:
    vector(size_t capacity) : size(capacity), capacity(capacity), arr(new type[capacity]{}) {}

    // void push_back(type val){
      // arr[size++] = val;
    // }
    type& operator[](int index){
      return arr[index];
    }
    size_t length(){
      return this->size; 
    }
};

template<typename type>
vector<type> merge(vector<type>& a, vector<type>& b){
  
  int ai = 0, bi = 0, i = 0;
  vector<type> c(a.length() + b.length());
  
  while(true){
    if(ai < a.length() && bi < b.length()){
      if(a[ai] > b[bi]) c[i++] = b[bi++];
      else c[i++] = a[ai++];
    }
    else if(ai < a.length() && bi >= b.length()){
      c[i++] = a[ai++];
    }
    else if(ai >= a.length() && bi < b.length()){
      c[i++] = b[bi++];
    }
    else break;
  }
  return c;
}
vector<int> mergesort(vector<int>& arr){
  if(arr.length() <= 1) return arr;
  
  vector<int> left(std::ceil(float(arr.length()) / 2.0));
  vector<int> right(std::floor(float(arr.length()) / 2.0));
  
  for(int i = 0; i < left.length(); i++) left[i] = arr[i];
  for(int i = left.length(), j = 0; i < arr.length(); i++, j++) right[j] = arr[i];
  
  left = mergesort(left);
  right = mergesort(right);
  
  return merge(left, right);
}
int main(){
  int m, n;
  scanf("%d %d", &m, &n);
  vector<int> a(m);
  vector<int> b(n);
  for(int i = 0; i < m; i++) scanf("%d", &a[i]);
  for(int i = 0; i < n; i++) scanf("%d", &b[i]);
  b = mergesort(b);
  a = mergesort(a);
  int i = 0, j = 0;
  while(i < a.length() && j < b.length()){
    while(j < b.length() && a[i] > b[j]) j++;
    while(i < a.length() && a[i] < b[j]) i++;
    if(a[i] == b[j]){
      printf("%d ", a[i]);
      i++;
      j++;
    }
  }
  
  
}