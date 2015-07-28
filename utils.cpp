/**
 * Utils for C++
 *
 * @author: Lu Sun
 * 
 * Version: 0
 */

#include "utils.h"

#include <cstdlib>
#include <ctime>

using namespace std;

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

template void rSampling<int>(const vector<int>& src, vector<int>& dst, size_t S);
