/*
 * plalindrome.h
 *
 *  Created on: 2013-8-6
 *      Author: colin
 */

#ifndef PLALINDROME_H_
#define PLALINDROME_H_

#include <iostream>

namespace Interview {
int plalindrome(char str[], int n, int& start) {
// add #
	char nstr[2*n+1];
	for (int i=0; i<2*n+1; i++) {
		if (! (i & 1))
			nstr[i] = '#';
		else
			nstr[i] = str[i/2];
	}
	std::cout << nstr <<std::endl;

	// array p[] for radis
	int p[2*n+1];
	int id = 0;
	int mx = 0;
	for(int i=0; i<2*n+1; i++) {
		// ¹Ø¼üµã mx =id+p[id]
		//   j=2*id-i       id      i     mx
		//-(-----(*-------*-------*)------*)--
		if (mx > i)
			p[i] = p[2*id-i]<mx-i?p[2*id-i]:mx-i;
		else
			p[i] = 1;

		for(;i+p[i]<2*n+1 && i-p[i]>=0;) {
			if (nstr[i+p[i]]==nstr[i-p[i]])
				p[i]++;
			else
				break;
		}

		if (p[i] + i >mx) {
			mx = p[i] +i;
			id = i;
		}
	}

	int max = 0, len = -1;
	for(int i=0; i<2*n+1; i++) {
		if (p[i] > max) {
			max = p[i];
			len = p[i]-1;
			start = (i+1-p[i])/2;
		}
		std::cout<<p[i]<< " ";
	}
	std::cout<<std::endl;

	return len;
}
}

#endif /* PLALINDROME_H_ */
