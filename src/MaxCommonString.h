/*
 * MaxCommomString.h
 *
 *  Created on: 2013-8-4
 *      Author: colin
 */

#ifndef MAXCOMMONSTRING_H_
#define MAXCOMMONSTRING_H_

#include <string>

namespace Interview {
void maxCommonString(std::string a, std::string b) {
	int aLen = a.length();
	int bLen = b.length();
	int lcs[aLen+1][bLen+1];

	for(int i=0; i<=aLen; i++)
		lcs[i][0] = 0;
	for(int j=1; j<=bLen; j++)
		lcs[0][j] = 0;


	for(int i=1; i<=aLen; i++)
		for (int j=1; j<=bLen; j++) {
			if (a[i-1] == b[j-1]) {
					lcs[i][j] = lcs[i-1][j-1]+1;
			}
			else {
				lcs[i][j] = lcs[i-1][j]>lcs[i][j-1]?lcs[i-1][j]:lcs[i][j-1];
			}
		}

	 //print maxtrix lcs[i][j]
	for(int i =0; i<=aLen; i++) {
		for (int j=0; j<=bLen; j++)
			printf("%d ", lcs[i][j]);
		printf("\n");
	}


	int i=aLen, j=bLen;
	int commonLen = lcs[i][j];
	char result[commonLen];
	while(i>0 && j>0) {
		if (a[i-1] == b[j-1]) {
			result[--commonLen] = a[i-1];
			i--; j--;
		}
		else if(lcs[i][j-1] > lcs[i-1][j]) {
			j--;
		}
		else i--;
	}

	for(int k=0; k<lcs[aLen][bLen]; k++)
		printf("%c",result[k]);
}
}
#endif /* MAXCOMMOMSTRING_H_ */
