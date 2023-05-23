#include "./include/List.h"

template<typename TYPE>
List<TYPE>::List(){

}

template<typename TYPE>
List<TYPE>::~List(){

}

template<typename TYPE>
bool List<TYPE>::add(TYPE value){
    try{
        List<TYPE>::Node<TYPE> * temp = new List<TYPE>::Node<TYPE>;

        temp->nextNode = nullptr;
        temp->content = value;

        lastNode->nextNode = temp;
        lastNode = temp;
    }
    catch(exception ex){
        return false;
    }
}

template<typename TYPE>
bool List<TYPE>::remove(TYPE valse){

}

template<typename TYPE>
bool List<TYPE>::find(TYPE valse){

}