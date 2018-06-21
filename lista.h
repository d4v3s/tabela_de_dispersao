#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <iomanip> 
template <typename T>
struct node {
	T content;
	int repetido;
	struct node * next;
};

// List with head
template <typename T>
class LinkedList {
	struct node<T> * head;
	struct node<T> * tail;
	int length;

public:
	LinkedList();
	~LinkedList();

	void PushBack(T content);
	void PushFront(T content);
	bool  Search(T content);
	T    GetElement(int index);
	void Remove(int index);
	void Erase();
	int  Length();
	bool IsEmpty();
	void Print();
	void PrintRepetidos();
};

template <typename T>
LinkedList<T>::LinkedList() {
	head = new struct node<T>;
	head->next = nullptr;

	tail = new struct node<T>;
	tail->next = nullptr;

	length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {

}

template <typename T>
bool LinkedList<T>::IsEmpty() {
	return length == 0;
}

template <typename T>
void LinkedList<T>::PushFront(T content) {
	struct node<T> * newNode = new struct node<T>;
	newNode->content = content;
	newNode->next = head->next;
	head->next = newNode;

	if(IsEmpty())
		tail->next = newNode;

	length++;
}


template <typename T>
void LinkedList<T>::PushBack(T content) {

		//busca pelo elemento (false nao exite | true existe)
		if(!Search(content)){	//so adiciona se nao existir
			//inserir elemento
			struct node<T> * newNode = new struct node<T>; //novo no
			newNode->content = content; // adiciona conteudo ao no
			newNode->next = nullptr; //ultimo aponta pra null
			newNode->repetido++; //atribui 1

			if(!IsEmpty()) 
				tail->next->next = newNode;	
			
			tail->next = newNode;

			if(IsEmpty())
				head->next = newNode;

			length++;
		}
}
//caso encontrar elemento repedito ja efetua o incremento.
template <typename T>
bool LinkedList<T>::Search(T content){
	int position = 0;
	bool found = false;
	struct node<T> * newNode = new struct node<T>;
	newNode = head;	

	while(!found && position < length){
		newNode = newNode->next;	
		if(newNode->content == content){						
			found = true;
			newNode->repetido++;
		}
		position++;
		
	}
	//retorno do indice
	return found;
}

template <typename T>
T LinkedList<T>::GetElement(int index){	
	struct node<T> * newNode = new struct node<T>;
	int position = 0;
	newNode = head;

	while(position-1 < index){
		newNode = newNode->next;
		position++;
	}

	return newNode->content;
}

template <typename T>
void LinkedList<T>::Remove(int index){
	struct node<T> * newNode = new struct node<T>;
	newNode = head;

	for(int i = 0; i <= index-1; i++){
		newNode = newNode->next;
		if(i == index-1){			
			newNode->next = newNode->next->next;			
		}
	}

	if(length > 0){
		length--;
	}
}

template <typename T>
void LinkedList<T>::Erase(){		
	head->next = nullptr;	
	length = 0;
}

template <typename T>	
int LinkedList<T>::Length(){
	return this->length;
}

template <typename T>
void LinkedList<T>::Print() {
	struct node<T> * aux = head->next;

	while(aux != nullptr) {
		std::cout << aux->content << "\t  ";
		aux = aux->next;

	}

	std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::PrintRepetidos() {
	struct node<T> * aux = head->next;
	aux = aux->next;

	while(aux != nullptr) {
			if(aux->repetido != 1 )
			std::cout << std::setfill('-') << aux->content << std::setw(10) << "\t  " << "repetiu: " << aux->repetido << " vezes" << std::endl;
			aux = aux->next;

	}
}

#endif