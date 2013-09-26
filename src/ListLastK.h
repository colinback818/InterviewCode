/*
 * ListLastK.h
 *
 *  Created on: Jul 29, 2013
 *      Author: shimao
 */

#ifndef LISTLASTK_H_
#define LISTLASTK_H_

#include "Node.h"

namespace Interview {
template<typename T>
class ListLastK {
public:
	ListLastK(int n, T item[]);
	~ListLastK();
	int getLastK(int k, T& item);
	void toString();
private:
	int n;
	Node<T> *first;
};

template<typename T>
ListLastK<T>::ListLastK(int n, T item[]): n(n), first(new Node<T>) {
	Node<T> *old = first, *cur;
	for (int i=0; i<n; i++){
		cur = new Node<T>;
		cur->item = item[i];
		old->next = cur;
		old = cur;
	}
}


template<typename T>
ListLastK<T>::~ListLastK() {
	Node<T> *cur = first, *next;
	for(int i=0; i<n+1; i++) {
		next = cur->next;
		delete cur;
		cur = next;
	}
}

template<typename T>
void ListLastK<T>::toString() {
	Node<T> *cur = first->next;
	for(int i=0; i<n; i++) {
		std::cout<<cur->item<<"\t";
		cur = cur->next;
	}
	std::cout<<std::endl;
}

template<typename T>
int ListLastK<T>::getLastK(int k, T& item) {
	if (n < k) return -1;

	Node<T> *cur = first->next;
	Node<T> *pre = NULL;
	int i=0;
	while (cur != NULL) {
		if(i == k-1)
			pre = first->next;
		else if (i > k-1)
			pre = pre->next;
		cur = cur->next;
		i++;
	}
	item = pre->item;
	return 0;
}
}



#endif /* LISTLASTK_H_ */
