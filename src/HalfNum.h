/*
 * HalfNum.h
 *
 *  Created on: Oct 8, 2013
 *      Author: shimao
 */

#ifndef HALFNUM_H_
#define HALFNUM_H_

namespace Interview {
class HalfNum {
private:
	int *ptr;
	int N;
public:
	HalfNum(const int a[], const int n);
	~HalfNum();
	int findHalfNum();
};

HalfNum::HalfNum(const int a[], const int n) {
	N = n;
	ptr = new int[N];
	for(int i=0; i<N; i++) {
		ptr[i] = a[i];
	}
}

HalfNum::~HalfNum() {
	if (!ptr)
		delete [] ptr;
}

int HalfNum::findHalfNum() {
	int cur_num, cnt = 0;
	for(int i=0; i<N; i++) {
		if (cnt ==0) {
			cur_num = ptr[i];
			cnt++;
		} else if (ptr[i] == cur_num) {
			cnt++;
		} else {
			cnt--;
		}
	}
	return cur_num;
}

}


#endif /* HALFNUM_H_ */
