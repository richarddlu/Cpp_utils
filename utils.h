/**
 * Utils for C++
 *
 * @author: Lu Sun
 * 
 * Version: 0.01
 */

#ifndef __CPP_UTILS__
#define __CPP_UTILS__

#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * reservoir sampling
 * samples S distinct elements from src randomly
 *
 * The definition is put in the header file because of a C++ template problem
 *
 * refreence: http://stackoverflow.com/questions/54059/efficiently-selecting-a-set-of-random-elements-from-a-linked-list
 *
 * @param const vector<T>& src input vector
 * @param vector<T>& dst output vector
 * @param size_t S number of selected elements
 */
template <typename T>
void rSampling(const vector<T>& src, vector<T>& dst, size_t S) {
	// parameter validation
	if(!(S > 0))
		return;
	if(src.size() < S)
		return;

	// clear dst
	dst.clear();

	for(size_t i = 0; i < S; i++) {
		dst.push_back(src[i]);
	}

	size_t n = src.size();	// performance consideration, avoid calling function
	size_t num_seen = S;
	srand(time(NULL));
	while(num_seen < n) {
		num_seen++;
		int rn = rand() % num_seen;
		if(rn < S)
			dst[rn] = src[num_seen-1];
	}
}

#endif
