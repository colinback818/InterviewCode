//============================================================================
// Name        : Interview.cpp
// Author      : Colin
// Version     :
// Copyright   : IBM
// Description : Hello World in C++, Ansi-style
//============================================================================

// 1+2..+N 不用乘除，for, while, if, case

#include "Nplus.h"
#include "FindMaxSub.h"
#include "ListLastK.h"
#include "StrToInt.h"
#include "DeleteChars.h"
#include "NumberOfOne.h"
#include "IsPostOrderTree.h"
#include "EqualSubSeq.h"
#include "MaxIncrementSubseq.h"
#include "MaxCommonString.h"
#include "StringCatNum.h"
#include "Plalindrome.h"
#include "Permutation.h"
#include "ArrayList.h"
#include "HalfNum.h"
#include <iostream>
#include <stdio.h>

using namespace Interview;

int main() {

/*	std::cout<<Nplus<10>::Val<<std::endl;

	int in[] = {1, -2, 5, -2, 8};
	FindMaxSub fms(in, sizeof(in)/sizeof(int));
	std::cout<<fms.find()<<std::endl;
	int left, right;
	std::cout<<fms.find2(0,4,left,right)<<std::endl;

	int item[] = {1, 2, 3, 4, 5, 6};
	int k = -1;
	ListLastK<int> llk(sizeof(item)/sizeof(int), item);
	llk.toString();
	llk.getLastK(3, k);
	std::cout<<"the last 3th of array is "<<k<<std::endl;

	int i = 0;
	StrToInt::toInt("5345", i);
	std::cout<<"string 5345 is: "<<i<<std::endl;

	char in[] = "i am a good boy";
	const char p[] = "ao";
	std::cout<<DeleteChars(in,p)<<std::endl;

	std::cout<<NumberOfOne(100000000)<<std::endl;
	std::cout<<countOnes(100000000)<<std::endl;

	int in[] = {5,7,6,9,11,10,8};
	int n = sizeof(in)/sizeof(int);
	std::cout << isPostOrderTree(in, 0, n-1);

	EqualSubSeq(15);

	int item[] = {1, -1, 2, -3, 4, -5, 6, -7 };
	int n = sizeof(item)/sizeof(int);
	maxIncrementSubseq(item, n);

	std::string a = "abcbdab";
	std::string b = "bdcaba";
	maxCommonString(a,b);

	std::string s[3];
	s[0] = "123";
	s[1] = "12";
	s[2] = "215";
 	int n = sizeof(s)/sizeof(std::string);
	maxCatNum(s,n);

	char str[] = "waabwswfd";
	int start,  len;
	len  = plalindrome(str,sizeof(str),start);
	std::cout<<start << " "<<len;

	int a[] = {1, 2, 3, 4, 5, 6, 7, 8 , 11, 12, 13, 14, 15, 16, 17, 18};
	arrayList(a,8);

	for(int i =0; i<sizeof(a)/sizeof(int); i++)
		printf("%d ",a[i]);

	std::string a = "abcbdab";
	std::string b = "bdcaba";
	maxCommonString(a,b);
*/
	int a[] = {4, 5, 4, 2, 5, 5, 5, 5, 1, 3};
	int n  = sizeof(a)/sizeof(int);
	HalfNum hf(a,n);
	std::cout<<hf.findHalfNum();
	return 0;
}
