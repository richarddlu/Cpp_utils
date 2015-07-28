/**
 * Utils for C++
 *
 * @author: Lu Sun
 * 
 * Version: 0.02
 */

#ifndef __CPP_UTILS__
#define __CPP_UTILS__

#include <vector>

using namespace std;

/**
 * reservoir sampling
 * generate S distinct integers in [a, b)
 *
 * refreence: http://stackoverflow.com/questions/54059/efficiently-selecting-a-set-of-random-elements-from-a-linked-list
 *
 * @param const vector<int>& samples output vector
 * @param int a
 * @param int b
 * @param size_t S number of samples
 */
void rSamplingInt(vector<int>& samples, int a, int b, size_t S);

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

	vector<int> indices;
	rSamplingInt(indices, 0, src.size(), S);

	// clear dst
	dst.clear();

	for(size_t i = 0; i < S; i++)
		dst.push_back(src[indices[i]]);
}

#endif
