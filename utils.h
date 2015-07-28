/**
 * Utils for C++
 *
 * @author: Lu Sun
 * 
 * Version: 0
 */

#ifndef __CPP_UTILS__
#define __CPP_UTILS__

#include <vector>

using namespace std;

/**
 * reservoir sampling
 * samples S distinct elements from src randomly
 *
 * refreence: http://stackoverflow.com/questions/54059/efficiently-selecting-a-set-of-random-elements-from-a-linked-list
 *
 * @param const vector<T>& src input vector
 * @param vector<T>& dst output vector
 * @param size_t S number of selected elements
 */
template <typename T>
void rSampling(const vector<T>& src, vector<T>& dst, size_t S);

#endif
