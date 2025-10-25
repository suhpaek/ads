#include <algorithm>
#include <cstdio>
#include <cstddef>

template<typename type>
class vector{
  private:
    size_t size;
    size_t capacity;
    type* arr;
  public:
    vector(size_t size) : size(size), capacity(size) {
      arr = new type[size];
    }
    vector() : size(0), capacity(2){
      arr = new type[capacity];
    }
    void push_back(type val){
      if(size == capacity){ // to prevent overflow
        type* newArr = new type[capacity * 2];
        for(int i = 0; i < capacity; i++) newArr[i] = arr[i];
        capacity *= 2;
        delete[] arr;
        arr = newArr;
      }

      this->arr[size++] = val;
    }

    type& operator[](size_t index){
      return arr[index];
    }
    size_t length() const {
      return this->size;
    }
    vector<type>& operator=(const vector<type>& v1){
      if(this != &v1){
        delete[] arr;
        size = v1.size;
        capacity = v1.capacity;
        arr = new type[capacity];
        std::copy(v1.arr, v1.arr + size, arr);
      }

      return *this;
      
      
    }
    void clear(){
      size = 0;
    }
    ~vector(){
      delete[] arr;
    }
    
};

template<typename type>
vector<type> merge(vector<type>& a, vector<type>& b){
  
  vector<type> c(a.length() + b.length());
  
  int ai = 0, bi = 0, i = 0;
  while(ai < a.length() or bi < b.length()){
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

template<typename type>
void mergesort(vector<type>& arr){
  if(arr.length() == 1) return;
  
  
  vector<type> left(arr.length() / 2);
  vector<type> right(arr.length() - (arr.length() / 2));
  for(int i = 0; i < left.length(); i++) left[i] = arr[i];
  for(int i = 0, j = left.length(); j < arr.length(); j++) right[i++] = arr[j];
  
  mergesort(left);
  mergesort(right);
  arr = merge(left, right);
  
  
}
template<typename type>
void mergesort(type* arr, size_t size){
  vector<type> v(size);
  for(int i = 0; i < size; i++) v[i] = arr[i];
  mergesort(v);
  for(int i = 0; i < size; i++) arr[i] = v[i];
}

int main(){
  
  char arr[int(1e6)];
  char letter;
  int i = 0;
  while(scanf("%c", &letter) == 1){
    if(letter == '\n') continue;
    arr[i++] = letter;
  }
  arr[i] = '\0';
  mergesort<char>(arr, i);
  printf("%s", arr);
  
}