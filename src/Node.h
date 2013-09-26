/*
 * Node.h
 *
 *  Created on: Jul 19, 2013
 *      Author: shimao
 */

#ifndef NODE_H_
#define NODE_H_
#include <stddef.h>

namespace Interview {
template<typename T>
class Node {
	//friend class Bag<T>;
public:
	Node<T>() {next = NULL;}

	Node<T>(const Node<T>& N) {
		item = N.item;
		next = N.next;
	}

	Node<T>& operator=(const Node<T>& N) {
		item = N.item;
		next = N.next;
		return *this;
	}

	T item;
	Node<T>* next;
};
}


#endif /* NODE_H_ */
