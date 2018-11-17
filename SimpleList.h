// SimpleList.h

// Written for CS32 S18, Lab07

#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include "EmptyListException.h"
#include "FullListException.h"
#include "InvalidIndexException.h"

template <class T>
class SimpleList {
	public:
		SimpleList();
		~SimpleList();
		T at(int index) const throw (InvalidIndexException);
		bool empty() const;
		T first() const throw (EmptyListException);
		T last() const throw (EmptyListException);
		int getNumElements() const;
		void insert(T item) throw (FullListException);
		void remove(int index) throw (InvalidIndexException, EmptyListException);
		static const int CAPACITY = 10;
	private:
		int numElements;
		T* elements;
};

template<typename T>
SimpleList<T>::SimpleList(){
    elements = new T[CAPACITY]; 
    numElements = 0;
}

template<typename T>
SimpleList<T>::~SimpleList(){
    delete[] elements; //memorize this!!! 
}

template<typename T>
T SimpleList<T>::at(int index) const throw (InvalidIndexException){
    if(index < 0 || index > numsElements -1){
	//how to throw exceptions?
	InvalidIndexException inv; 
	throw iv; 
    }
    else{
	return elements[index]; 
    }
}

template<typename T>
T SimpleList<T>::T first() const throw (EmptyListException){
     if(numElements == 0){
	EmptyListException excpt; 
	throw excpt;
     }
     else{
	return elements[0];
     }
} 



template<typename T>
bool SimpleList<T>::empty(){
    return numElements = 0; 
} 

template<typename T>
T SimpleList<T>:: T last() const throw (EmptyListException){
    if(numElements == 0){
	EmptyListException excpt;
	throw excpt;
    }
    else{
	return elements[numElements - 1];
    }
}

template<typename T>
int SimpleList<T>::getNumElements() const{
    return numElements;
}

template<typename T>
void SimpleList<T> insert(T item) throw (FullListException){
    if(numElements ==CAPACITY){
        FullListException full;
        throw full;
    }else{
        elements[numElements] = item;
        numElements++;
    }        
}

template<typename T>
void SimpleList<T> remove(int index) throw (InvalidIndexException, EmptyListException){
    if(index >= numElements || index < 0){
	InvalidIndexException ii;
	throw ii; 
    }else if(numElements == 0){
	EmptyListException e;
	throw e; 
    }else{
	for(int i = index; i < index; i++){
	    elements[i] = elements[i + 1]; 
	}
    }
}




























#endif
