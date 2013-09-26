/*
 * MaxSubArray.h
 *
 *  Created on: Jul 29, 2013
 *      Author: shimao
 */

#ifndef MAXSUBARRAY_H_
#define MAXSUBARRAY_H_

#include <assert.h>
#include <string>
#include <iostream>

namespace Interview {
class FindMaxSub {
public:
	FindMaxSub(int*, int n);
	~FindMaxSub();
	int find();
	int find2(int start, int end,int& left, int& right);
private:
	int *array;
	int n;
};

FindMaxSub::FindMaxSub(int *in, int n): n(n) {
	assert(n > 0);
	array = new int[n];
	for (int i=0; i<n; i++)
		array[i] = in[i];
}

FindMaxSub::~FindMaxSub() {
	delete [] array;
}

int FindMaxSub::find2(int start, int end, int& left, int& right) {
	if(start == end) {
		left = right = start;
		return array[start];
	}
	if(end - start == 1) {
		if (array[start] > 0) {
			if (array[end] >= 0) {
				left = start; right = end;
				return array[start] + array[end];
			}
			else {
				left = start; right = start;
				return array[start];
			}
		}
		else {
			if (array[start] > array[end]) {
				left = start; right = start;
				return array[start];
			}
			else {
				left = end; right = end;
				return array[end];
			}
		}
	}

	int mid = (start + end)/2;
	// left part
	int ls =0, le = 0, rs=0, re=0;
	int max;

	int lvalue = find2(start,mid,ls,le);
	int rvalue = find2(mid+1,end,rs,re);

	if (lvalue > rvalue) {
		max = lvalue;
		left = ls; right = le;
	}
	else {
		max = rvalue;
		left = rs; right = re;
	}

	int sum =0;
	for (int i=ls; i<=re; i++) {
		sum += array[i];
	}

	if (sum > max) {
			left = ls; right = re;
			max = sum;
	}

	return max;
}

int FindMaxSub::find() {
	assert(n>0);

	int maxendinghere = array[0], maxsofar = array[0];
	int startsofar = 0, endsofar = 0;
	int starthere =0,  endhere = 0;
	for(int move=1; move <n; move++) {
		if (maxendinghere + array[move] < 0) {
			starthere = endhere = move;
			maxendinghere = array[move];
		}
		else {
			if (maxendinghere < 0) {
				maxendinghere = array[move];
				starthere = move;
			}
			else
				maxendinghere += array[move];
			endhere = move;
		}

		if ( maxendinghere > maxsofar) {
			maxsofar = maxendinghere;
			startsofar = starthere;
			endsofar = endhere;
		}
	}
	std::cout << startsofar << " "<<endsofar<<std::endl;
	return maxsofar;
}
}

#endif /* MAXSUBARRAY_H_ */
