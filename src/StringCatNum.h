/*
 * StringCatNum.h
 *
 *  Created on: 2013-8-6
 *      Author: colin
 */

#ifndef STRINGCATNUM_H_
#define STRINGCATNUM_H_

#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

bool compareFunc(std::string l, std::string r) {
	char str1[l.length() + r.length() +1];
	char str2[l.length() + r.length() +1];
	strcpy(str1, l.c_str());
	strcat(str1, r.c_str());
	strcpy(str2, r.c_str());
	strcat(str2, l.c_str());
	if(strcmp(str1, str2) > 0)
		return false;
	else return true;
}

namespace Interview {
void maxCatNum(std::string str[], int n) {
	std::vector<std::string> myvector;
	for(int i=0; i<n; i++)
		myvector.push_back(str[i]);

	std::sort(myvector.begin(), myvector.end(),compareFunc);

	for (std::vector<std::string>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
	    std::cout << *it;

}
}


#endif /* STRINGCATNUM_H_ */
