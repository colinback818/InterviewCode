/*
 * MaxIncrementSubseq.h
 *
 *  Created on: 2013-7-31
 *      Author: colin
 */

#ifndef MAXINCREMENTSUBSEQ_H_
#define MAXINCREMENTSUBSEQ_H_

#include <assert.h>
// 求数组中最长递增子序列

namespace Interview {
int maxIncrementSubseq(int array[], int n) {
	assert(array != 0);

	int seq[n];

	int curMaxPos = 0, preMaxPos = 0;
	int len = 0;
	seq[len] = array[curMaxPos];

	for (int i=1; i<n; i++) {
		if(array[i] > array[curMaxPos]) {
			preMaxPos = curMaxPos;
			curMaxPos = i;
			seq[++len] = array[i];
		}
		else if(array[i] > array[preMaxPos]) {
			curMaxPos = i;
			seq[len] = array[i];
		}
	}
	for(int i=0; i<len+1; i++)
		printf ("%d ", seq[i]);

	return len;
}
}

#endif /* MAXINCREMENTSUBSEQ_H_ */
