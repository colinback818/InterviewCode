/*
 * StrToInt.h
 *
 *  Created on: Jul 29, 2013
 *      Author: shimao
 */

#ifndef STRTOINT_H_
#define STRTOINT_H_

#include<string.h>
#include<stddef.h>

namespace Interview {
class StrToInt {
public:
	static int toInt(const char *str, int& ret) {
		if (str == NULL)
			return -1;
		int n = strlen(str);
		if (n < 1)
			return -1;

		/* need to deal with +/- here*/

		int sum = 0;
		for(int i=0; i<n; i++) {
			if (str[i] < '0' || str[i] > '9')
				return -1;
			sum = sum * 10 + (str[i]-'0');
		}
		ret = sum;
		return 0;
	}
};
}

#endif /* STRTOINT_H_ */
