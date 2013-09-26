/*
 * Permutation.h
 *
 *  Created on: Aug 9, 2013
 *      Author: shimao
 */

#ifndef PERMUTATION_H_
#define PERMUTATION_H_

namespace Interview {
void swap(char& a, char &b) {
	char tmp = a;
	a = b;
	b = tmp;
}

void permutation(char *array, int start, int end) {
	if (start == end) {
		for (int i=0; i<end; i++)
			std::cout<<array[i];
		std::cout<<std::endl;
	}

	for (int i=start; i<end; i++) {
		if (i != start)
			swap(array[start], array[i] );
		permutation(array, start+1, end);
	}
}

void permutation(char *array, int n) {
	permutation(array, 0, n);
}
}


#endif /* PERMUTATION_H_ */
