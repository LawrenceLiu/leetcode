#include<iostream>

using namespace std;

typedef int uint32_t;


int main(int argc, char ** argv)
{
	uint32_t n = 43261596;

	unsigned int MASK_LEFT = 0x80000000;
	unsigned int MASK_RIGHT = 0x00000001;
	uint32_t ret = 0;

	for (size_t i = 0; i < 32/2; ++i) {
		unsigned short times = 31 - 2*i;
		//printf("%u\t%u\n", MASK_LEFT, MASK_RIGHT);

		ret |= ((n & MASK_LEFT) >> times) | ((n & MASK_RIGHT) << times);
		
		MASK_LEFT >>= 1;
		MASK_RIGHT <<= 1;
	}
	
	printf("output: %u\n", ret);
}

