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

template<typename type1, typename type2, typename type3>
struct triplet{
  type1 first;
  type2 second;
  type3 third;
  triplet() : first(type1{}), second(type2{}), third(type3{}) {}
  bool operator>(triplet<type1, type2, type3> t) const {
    if(t.third == third){
      if(t.second == second){
        return first > t.first;
      }
      return second > t.second;
    }
    return third > t.third;
  }
  bool operator==(triplet<type1, type2, type3> t) const {
    return first == t.first and second == t.second and third == t.third;
  }
  bool operator<(triplet<type1, type2, type3> t){
    if(t.third == third){
      if(t.second == second){
        return first < t.first;
      }
      return second < t.second; 
    }
    return third < t.third;
  }
  char* toDateFormat(){
    char* date = new char[11];
    date[10] = '\0';
    
    if(first < 10) date[0] = '0';
    else date[0] = char(first / 10 + '0');
    date[1] = char(first % 10 + '0');
    
    date[2] = '-';
    if(second < 10) date[3] = '0';
    else date[3] = char(second / 10 + '0');
    date[4] = char(second % 10 + '0');
    
    date[5] = '-';

    for(int i = 9; i >= 6; i--){
      date[i] = char(third % 10 + '0');
      third /= 10;
    } 
    
    return date;
  }
};



vector<triplet<int, int, int>> dates;



int main(){
  int n;
  scanf("%d", &n);
  while(n--){
    triplet<int, int, int> t;
    
    scanf("%d-%d-%d", &t.first, &t.second, &t.third);
    dates.push_back(t);
  }
  mergesort(dates);
  for(int i = 0; i < dates.length(); i++){
    // char date[10];
    printf("%s\n", dates[i].toDateFormat());
  }
}