/*
 * IsPostOrder.h
 *
 *  Created on: 2013-8-3
 *      Author: colin
 */

#ifndef ISPOSTORDER_H_
#define ISPOSTORDER_H_

#include <stdio.h>

namespace Interview {
bool isPostOrderTree(const int array[], int left, int right) {
	if (left == right)
		return true;

	int mid = -1;
	for(int i = left; i < right; i++) {
		if (array[i] >= array[right]) {
			mid = i-1;
			break;
		}
	}

	if (mid == right)
		return true;

	return (isPostOrderTree(array, left, mid) && isPostOrderTree(array,mid+1,right-1));
}
}


#endif /* ISPOSTORDER_H_ */
