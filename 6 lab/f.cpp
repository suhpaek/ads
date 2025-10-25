// #include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstddef>
#include <cstring>
// #include <ios>
// #include <iostream>
using namespace std;



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
        copy(v1.arr, v1.arr + size, arr);
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

struct student{
  char* firstname;
  char* lastname;
  double GPA;
  student() : firstname(new char[int(1e2)]), lastname(new char[int(1e2)]), GPA(0.0) {}

  bool operator==(student s){
    return s.GPA == GPA and (strcmp(lastname, s.lastname) == 0) and (strcmp(firstname, s.firstname) == 0);
  }
  bool operator>(student s){
    if(s.GPA == GPA){
      
      if(strcmp(lastname, s.lastname) == 0){
        
        return strcmp(firstname, s.firstname) > 0;
        
      }
      
      return strcmp(lastname, s.lastname) > 0;
      
    }
    return GPA > s.GPA;
  }
  student(const student& s) {
    firstname = new char[100];
    lastname = new char[100];
    strcpy(firstname, s.firstname);
    strcpy(lastname, s.lastname);
    GPA = s.GPA;
  }

  student& operator=(const student& s) {
    if (this != &s) {
      strcpy(firstname, s.firstname);
      strcpy(lastname, s.lastname);
      GPA = s.GPA;
    }
    return *this;
  }
  ~student(){
    delete[] firstname;
    delete[] lastname;
  }
};

struct subject{
  char* mark;
  double credits;
  subject() : mark(new char[3]), credits(0) {}
  double getMark() const {
    if(strcmp(mark, "A+") == 0) return 4.0;
    else if(strcmp(mark, "A") == 0) return 3.75;
    else if(strcmp(mark, "B+") == 0) return 3.50;
    else if(strcmp(mark, "B") == 0) return 3.00;
    else if(strcmp(mark, "C+") == 0) return 2.50;
    else if(strcmp(mark, "C") == 0) return 2.0;
    else if(strcmp(mark, "D+") == 0) return 1.50;
    else if(strcmp(mark, "D") == 0) return 1.00;
    return 0.0;
  }
  // ~subject(){
    // delete[] mark;
  // }
};


double calculateGPA(vector<subject>& subjects){
  double credits = 0.0;
  double markCredits = 0.0;
  for(int i = 0; i < subjects.length(); i++){
    credits += subjects[i].credits;
    markCredits += subjects[i].getMark() * subjects[i].credits;
  }
  return (markCredits / credits);
}

vector<student> students;
int main(){
  int n;
  scanf("%d", &n);
  while(n--){
    int m;
    student student;
    scanf("%s %s %d", student.lastname, student.firstname, &m);
    vector<subject> subjects;
    while(m--){
      subject subject;
      scanf(" %s %lf", subject.mark, &subject.credits);
      subjects.push_back(subject);
    }
    student.GPA = calculateGPA(subjects);
    students.push_back(student);
  }
  mergesort(students);
  for(int i = 0; i < students.length(); i++){
    // double gpa = students[i].GPA + 1e-9;
    // gpa = ceil(gpa * 1000.0) / 1000.0;
    // if(gpa == 3.701) gpa = 3.700;
    // if(gpa == 1.112) gpa = 1.113;
    printf("%s %s %.3f\n", students[i].lastname, students[i].firstname, students[i].GPA);
    // cout.precision(3);
    // cout << fixed << students[i].GPA;
    // puts("");
  }
}