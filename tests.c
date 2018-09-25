#include "glmc.h"

void glmc_test_inv(){
	mat3f src_a = {{13,6,4}, {3,7,8}, {14,9,10}};
	mat3f dest;
	glmc_mat3f_inv(dest, src_a);
	glmc_mat3f_print(dest);
}

int main()
{
	glmc_test_inv();
}

