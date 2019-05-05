#ifndef _DEQUEUE_H
#define _DEQUEUE_H

template<class T>
class Dequeue;

template< class T >
class Node{
	friend class Dequeue<T>;
 private:
	T _value;
  Node<T> * _prev;
	Node<T> * _next;
};

template< class T >
class Dequeue {

public:
  Dequeue() {
    _pHead = new Node<T>;
  	_pHead->_next = _pHead;
  	_pHead->_prev = _pHead;
  	_size = 0;
  }

  Dequeue(const Dequeue<T>& d) {
    _pHead = new Node<T>;
  	_pHead->_pNext = _pHead;
  	_pHead->_pPrev = _pHead;
  	_size = 0;
    auto sHead=d._pHead->_next;
    while (sHead!=d._pHead) {
      addFirs(sHead->_value);
      sHead=sHead->_next;
    }
  }

  ~Dequeue() {
    while(!isEmpty())
      removeFirst();
    delete _pHead;
  }

  void addFirst(const T& e) {
    Node<T>* t=new Node<T>;
    t->_value = e;
    t->_prev = _pHead;
    t->_next = _pHead->_next;
		_pHead->_next->_prev = t;
    _pHead->_next = t;
    _size++;
  }

  void removeFirst() {
    if (!isEmpty()) {
			Node<T>* p = _pHead->_next;
			p->_prev->_next = p->_next;
			p->_next->_prev = p->_prev;
			delete p;
      _size--;
    }
  }

  T getFirst() {
    if (!isEmpty())
      return _pHead->_next->_value;
  }

  void addLast(const T& e) {
    Node<T>* t=new Node<T>;
    t->_value = e;
    t->_next = _pHead;
    t->_prev = _pHead->_prev;
		_pHead->_prev->_next = t;
    _pHead->_prev = t;
    _size++;
  }

  void removeLast() {
    if (!isEmpty()) {
      Node<T>* p = _pHead->_prev;
			p->_prev->_next = p->_next;
			p->_next->_prev = p->_prev;
			delete p;
      _size--;
    }
  }

  T getLast() {
    if (!isEmpty())
      return _pHead->_prev->_value;
  }

  int size() const {
    return size;
  }

  void clear() {
    while(!isEmpty())
      removeFirst();
  }

  bool isEmpty() const {
    return (_pHead == _pHead->_next);
  }

private:
  Node<T> * _pHead;
  int _size;
};

#endif
