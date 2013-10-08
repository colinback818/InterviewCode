/*
 * EqualSubSeq.h
 *
 *  Created on: 2013-8-4
 *      Author: colin
 */

#ifndef EQUALSUBSEQ_H_
#define EQUALSUBSEQ_H_

#include <stdio.h>

// 15 = 1+2+3+4+5 = 7+8
namespace Interview {

void EqualSubSeq(int n) {
	if (n < 0)
		return;

	int leftWin = 1, rightWin = 1;
	int sum = leftWin;
	for(int i =1; i<n/2+1; i++) {
		if (sum < n) {
			sum += ++rightWin;
		}

		if (sum > n) {
			sum -= leftWin++;
		}

		if (sum == n) {
			for(int j=leftWin; j<=rightWin; j++) {
				printf("%d ",j);
			}
			printf("\n");
			leftWin = ++rightWin;
			sum = leftWin;
		}
	}
}
}

#endif /* EQUALSUBSEQ_H_ */
