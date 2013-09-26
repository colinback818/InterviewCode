/*
 * DeleteChars.h
 *
 *  Created on: Jul 30, 2013
 *      Author: shimao
 */

#ifndef DELETECHARS_H_
#define DELETECHARS_H_

#include <string.h>

namespace Interview {
void setupMap(int *map, const char* pattern) {
	//init map[256]
	for(int i=0; i<256; i++)
		map[i] = 0;

	int n = strlen(pattern);
	for (int i=0; i<n; i++) {
		map[(int)pattern[i]] = 1;
	}
}

char* DeleteChars(char* target, const char* pattern) {
	int map[256];
	setupMap(map, pattern);
	int n = strlen(target);
	int lowpos = 0;
	for(int fastpos=0; fastpos<n; fastpos++) {
		if (map[(int)target[fastpos]] != 1 ) {
			if (fastpos != lowpos)
				target[lowpos] = target[fastpos];
			lowpos++;
		}
	}
	target[lowpos] = '\0';
	return target;
}
}

#endif /* DELETECHARS_H_ */
