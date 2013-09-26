/*
 * ArrayList.h
 *
 *  Created on: Aug 26, 2013
 *      Author: shimao
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <assert.h>

namespace Interview {

void swap(int *a, int start, int n, int len) {
	int temp;
	for(int i=0; i<len; i++) {
		temp = a[start];
		a[start] = a[start+n-len];
		a[start+n-len] = temp;
		start++;
	}
}

// n is half of real array lenth
int arrayList(int *a, int n) {
	assert(a!=0);

	if (n==1)
		return 0;

	int i=1, k=1;
	while(i<n) {
		swap(a,i,n,k);
		i = i+k;
		k *= 2;
	}
	return 0;
}
}


#endif /* ARRAYLIST_H_ */
