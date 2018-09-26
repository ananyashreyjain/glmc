//file underdevlopment

#include "glmc.h"
#include <stdio.h>

void glmc_test_inv(){
	mat3f src_a = {{1, 2, 3}, {2, 5, 3}, {1, 0, 8}};
	mat3f dest;
	mat3f soln = {{-40, 16, 9}, {13, -5, -3}, {5, -2, -1}};
	glmc_mat3f_inv(dest, src_a);
	int test=glmc_mat3f_isequal(dest,soln);
	//printf("%d",test);
}

void glmc_test_rotation()
{
	mat3f dest;
	vec3f vec;
	vec3f v = {1, 0 ,0};
	glmc_mat3f_rotation(dest, 2, 0, 0);
	glmc_mat3f_vecmul(vec, dest, v);
	glmc_mat3f_print(dest);
	printf("%f",vec[1]);
}
int main()
{
	glmc_test_inv();
	glmc_test_rotation();
}

