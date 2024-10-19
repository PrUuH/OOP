#include <iostream>
#include <stdexcept>
#include <cstring>

typedef char value_type;

class CircularBuffer {
  value_type * buffer;
  int head;
  int tail;
  int cap;
  int count;

public: 
//constructor
  CircularBuffer(): buffer(nullptr), head(0), tail(0), cap(0), count(0){}
//destructor
  ~CircularBuffer(){
    delete[] buffer;
  }

  //coping
  CircularBuffer(const CircularBuffer & cb): head(cb.head), tail(cb.tail), cap(cb.cap), count(cb.count){
    buffer = new value_type[cap];
    std::memcpy(buffer, cb.buffer, cap * sizeof(value_type));
  }

  //constructor with defined capacity
  explicit CircularBuffer(int capacity): head(0), tail(0), cap(capacity), count(0){
    if (capacity < 0) {
        throw std::invalid_argument("Capacity must be gt then 0");
    }
    buffer = new value_type[capacity];
  }

  //constructor with defined capacity. Filled
  CircularBuffer(int capacity, const value_type & elem): CircularBuffer(capacity){
    for (int i = 0; i < capacity; i++) {
        buffer[i] = elem;
    }
    count = capacity;
  }

  //index access without verifying
  value_type & operator[](int i) {
    return buffer[(tail + i) % cap];
  }
  const value_type & operator[](int i) const{
    return buffer[(tail + i) % cap];
  }
  
  //index access with veryfying
  value_type & at(int i){
    if (i < 0 || i >= count){
        throw std::out_of_range("Index out of range");
    }
    return (*this)[i];
  }

  const value_type & at(int i) const {
    return const_cast < const value_type&>((*this)[i]);
  }
//the link to the first element
  value_type & front(){
    if (empty()) throw std::out_of_range("Buffer is empty");
    return buffer[tail];
  } 
  //a link to the last element
  value_type & back() {
    if (empty()) throw std::out_of_range("Buffer is empty");
    return buffer[(head - 1 + cap) % cap];
  }

  const value_type & front() const{
    return const_cast<const value_type&>(const_cast<CircularBuffer*>(this)->front());
  }
  const value_type & back() const {
    return const_cast <const value_type&>(const_cast<CircularBuffer*>(this)->back());
  }

  //linearization
  value_type * linearize() {
    if (is_linearized()) return buffer;
    if (count == 0) return nullptr;

    value_type* new_buffer = new value_type[count];
    for (int i = 0; i < count; ++i) {
        new_buffer[i] = (*this)[i];
    }

    delete[] buffer;
    buffer = new_buffer;
    head = count;
    tail = 0;
    cap = count;
    return buffer;
  }


  //checks whether the buffer is linearized
  bool is_linearized() const {
    return tail == 0 && head == count;
  }

  //shifts the buffer so that an element with the new_begin index appears at the zero index
  void rotate(int new_begin) {
    if (new_begin < 0 || new_begin >= count) throw std::out_of_range("Invalid index for rotation");

    head = (tail + new_begin) % cap;
    tail = new_begin;
  }

  //the number of items stored in the buffer
  int size() const{
    return count;
  }

  bool empty() const{
    return count == 0;
  }

  //true, if size() == capacity()
  bool full() const{
    return count == cap;
  }
  //The number of free cells in the buffer
  int reserve() const{
    return cap - count;
  }
  //Buffer capacity
  int capacity() const{
    return cap;
  }

  void set_capacity(int new_capacity) {
    if (new_capacity <= 0 ) throw std::invalid_argument("Capacity must be greater then 0");

    if (new_capacity < count) {
      throw std::length_error("New capacity cannot be less than curerent size");
    }

    value_type* new_buffer = new value_type[new_capacity];

    for (int i = 0; i < count; ++i){
      new_buffer[i] = (*this)[i];
    }

    delete[] buffer;
    buffer = new_buffer;
    head = count;
    tail = 0;
    cap = new_capacity;
  }
  //changes the size of the buffer.In case of expansion, the new elements are filled with the item element
  void resize(int new_size, const value_type & item = value_type()){
    if (new_size < 0) throw std::invalid_argument("Size must be nonnegative");

    if (new_size > cap){
      set_capacity(new_size);
      for (int i =0; i < new_size; ++i) {
        buffer[i] = item;
      }
      count = new_size;
    }
    else if (new_size < count) {
      count = new_size;
    }
  }


  //assignment operator
  CircularBuffer & operator=(const CircularBuffer & cb){
    if (this != &cb){
      delete[] buffer;

      head = cb.head;
      tail = cb.tail;
      cap = cb.tail;
      count = cb.count;

      buffer = new value_type[cap];
      std::memcpy(buffer, cb.buffer, cap * sizeof(value_type));
    }
    return *this;
  }

  //xchanges the contents of the buffer with the cb buffer
  void swap(CircularBuffer & cb){
    std::swap(buffer, cb.buffer);
    std::swap(head, cb.head);
    std::swap(tail, cb.tail);
    std::swap(cap, cb.cap);
    std::swap(count, cb.count);
  }

  //adds an element to the end of the buffer.If the current buffer size is equal to its capacity, then the first element of the buffer is overwritten (i.e., the buffer is looped)
  void push_back(const value_type & item = value_type()){
    if(full()){
      tail = (tail + 1) % cap; //rewriting of the first element
    }
    else {
      ++count; //upping the size, if non-rewriting
    }
    buffer[head] = item;
    head = (head + 1) % cap; //up the index for next writing
  }
  //adds a new element before the first element of the buffer. Similarly, push_back can overwrite the last element of the buffer
  void push_front(const value_type & item = value_type()){
    if(full()){
      head = (head - 1 + cap) % cap;//rewriting of the last element
      tail= (tail - 1 + cap) % cap;//Pushing of the tail back 
    }
    else{
      --tail;//up the size if non-rewriting
      if (tail < 0) tail += cap;//circular buffer processing
      ++count;
    }
    buffer[tail] = item;//writing an element to the beginning
  }
  //deletes the last element of the buffer
  void pop_back(){
    if (empty()) throw std::out_of_range("Buffer is empty");

    head = (head - 1 + cap) % cap;//pushing head back
    --count;
  }
  //deletes the first element of the buffer
  void pop_front(){
    if (empty()) throw std::out_of_range("Buffer is empty");

    tail = (tail + 1) % cap;//pushing tail forward
  }

  //inserts the item element by the pos index. The buffer capacity remains unchanged
  void insert(int pos, const value_type & item = value_type()){
    if (pos < 0 || pos > count) throw std::out_of_range("Invalid position for insertion");

    push_back(item);//upe the size

    for(int i = count - 1; i > pos; --i){
      buffer[(tail + i) % cap] = buffer[(tail + i - 1) % cap];//moving the elements to the right
    }

    buffer[(tail + pos) % cap] = item;
  }
  //deletes items from the buffer in the interval [first, last).
  void erase(int first, int last){
    if (first < 0 || last > count || first >= last) throw std::out_of_range("Invalid range for erasure");

    for (int i = last; i < count; ++i){
      buffer[(tail + i - (last - first)) % cap] = buffer[(tail + i) % cap]; // moving the elements to the left
    }

    count -= (last - first); // reducing the size
  }


  //cleans the buffer
  void clear(){
    head = tail = count = 0; // reset all indexes and size
  }
};

bool operator==(const CircularBuffer & a, const CircularBuffer & b){
  if(a.size() != b.size()) return false;

  for (int i = 0; i < a.size(); ++i) {
    if(a[i] != b[i]) return false;
  }
  return true;
}
bool operator!=(const CircularBuffer & a, const CircularBuffer & b){ 
  return!(a == b);
}

