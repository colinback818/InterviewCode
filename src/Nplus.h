/*
 * Nplus.h
 *
 *  Created on: Jul 29, 2013
 *      Author: shimao
 */

namespace Interview {
template<int N>
struct Nplus {
	enum {
		Val = Nplus<N-1>::Val + N
	};
};

template<>
struct Nplus<1> {
	enum{
		Val = 1
	};
};
}


