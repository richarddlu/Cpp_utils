/**
 * Utils for C++
 *
 * @author: Lu Sun
 * 
 * Version: 0.02
 */

#include "utils.h"

#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void rSamplingInt(vector<int>& samples, int a, int b, size_t S) {
	// parameter validation
	if(!(S > 0))
		return;
	if(b - a < S)
		return;

	// clear dst
	samples.clear();

	for(size_t i = 0; i < S; i++) {
		samples.push_back(a + i);
	}

	size_t n = b - a;
	size_t num_seen = S;
	srand(time(NULL));
	while(num_seen < n) {
		num_seen++;
		int rn = rand() % num_seen;
		if(rn < S)
			samples[rn] = a + num_seen - 1;
	}
}
