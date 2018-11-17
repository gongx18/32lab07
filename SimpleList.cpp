#include <iostream>
#include "SimpleList.h"
#include <vector>


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
    if(index < 0 || index > numElements -1){
	//how to throw exceptions?
	InvalidIndexException i; 
	throw i; 
    }
    else{
	return elements[index]; 
    }
}

template<typename T>
T SimpleList<T>::first() const throw (EmptyListException){
     if(numElements == 0){
	EmptyListException excpt; 
	throw excpt;
     }
     else{
	return elements[0];
     }
} 



template<typename T>
bool SimpleList<T>::empty() const{
    return numElements == 0; 
} 

template<typename T>
T SimpleList<T>::last() const throw (EmptyListException){
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
void SimpleList<T>::insert(T item) throw (FullListException){
    if(numElements ==CAPACITY){
        FullListException full;
        throw full;
    }else{
        elements[numElements] = item;
        numElements++;
    }        
}

template<typename T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException){
    if(index >= numElements || index < 0){
	InvalidIndexException ii;
	throw ii; 
    }else if(numElements == 0){
	EmptyListException e;
	throw e; 
    }else{
	for(int i = index; i < numElements - 1; ++i){
	    elements[i] = elements[i + 1]; 
	}
	numElements --; 
	//elements->push_back();
        elements->erase(elements->end() - 1);
    }
}
