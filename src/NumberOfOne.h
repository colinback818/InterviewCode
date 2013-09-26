/*
 * NumberOfOne.h
 *
 *  Created on: Jul 30, 2013
 *      Author: shimao
 */

#ifndef NUMBEROFONE_H_
#define NUMBEROFONE_H_

#include <stdio.h>
#include <math.h>
#include <string>

namespace Interview {
#define LEN 12

int getLength(int n) {
	char buf[LEN];
	sprintf(buf, "%d", n);
	return strlen(buf);
}

//方法一，分别1-999和1000-1245；递归

int NumberOfOne(int n) {
	int len = getLength(n);
	if(len == 1) {
		if (n >= 1)
			return 1;
		else return 0;
	}

	int first = n/pow(10,len-1);
	int rest = n - first*pow(10,len-1);

	int sum = 0;
	if (first == 1)
		sum = (rest +1) + NumberOfOne(rest) + NumberOfOne(pow(10,len-1)-1);
	else
		sum = pow(10,len-1) + first*NumberOfOne(rest) + NumberOfOne(pow(10,len-1)-1);
	return sum;
}

// 方法二，按位计算1个个数

int countOnes(int n) {
	int iCount = 0;
	int iFactor = 1;

	int iLowerNum = 0;
	int iCurrNum = 0;
	int iHigherNum = 0;

	while(n/iFactor != 0) {
		iLowerNum = n - (n/iFactor) * iFactor;
		iCurrNum = (n / iFactor) % 10;
		iHigherNum = n / (iFactor * 10);

		switch(iCurrNum) {
		case 0:
			iCount += iHigherNum * iFactor;
			break;
		case 1:
			iCount += iHigherNum * iFactor + iLowerNum + 1;
			break;
		default:
			iCount += (iHigherNum + 1) * iFactor;
			break;
		}
		iFactor *= 10;
	}
	return iCount;
}
}


#endif /* NUMBEROFONE_H_ */
