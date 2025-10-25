#include <algorithm>
#include <cstdio>
#include <cstddef>
#include <cstring>

template<typename type>
class vector{
  private:
    size_t size;
    size_t capacity;
    type* arr;
  public:
    vector(size_t capacity) : size(capacity), capacity(capacity) {
      arr = new type[capacity];
    }
    vector(size_t size, size_t capacity) : size(size), capacity(capacity){
      arr = new type[capacity];
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
    vector(vector& v){
      arr = new type[v.capacity];
      size = v.size;
      capacity = v.capacity;
      for(int i = 0; i < size; i++) arr[i] = v[i];
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

struct changelog{
  char* first;
  char* second;
  changelog() : first(new char[int(1e2)]), second(new char[int(1e2)]) {}
  
  changelog(changelog& c) : first(new char[int(1e2)]), second(new char[int(1e2)]) {
    std::strcpy(first, c.first);
    std::strcpy(second, c.second);
  }
  changelog& operator=(changelog& c){
    if(this != &c){
      std::strcpy(first, c.first);
      std::strcpy(second, c.second);
    }
    return *this;
  }
  bool operator==(changelog& c){
    return std::strcmp(c.first, first) == 0 && std::strcmp(c.second, second) == 0;
  }
  bool operator<(changelog& c){
    return std::strcmp(first, c.first) < 0;
  }
  bool operator>(changelog& c){
    return std::strcmp(first, c.first) > 0;
  }
  ~changelog(){
    delete[] first;
    delete[] second;
  }
};

bool search(vector<changelog>& logs, changelog log){
  for(int i = 0; i < logs.length(); i++){
    if(std::strcmp(log.first, logs[i].second) == 0){
      std::strcpy(logs[i].second, log.second);
      return true;
    }
  }
  return false;
}

int main(){
  int n;
  scanf("%d", &n);
  vector<changelog> logs;
  for(int i = 0; i < n; i++){
    changelog log;
    scanf(" %s %s", log.first, log.second);
    if(!search(logs, log))
      logs.push_back(log);
  }
  mergesort(logs);
  printf("%ld\n", logs.length());
  for(int i = 0; i < logs.length(); i++) printf("%s %s\n", logs[i].first, logs[i].second);
  
}