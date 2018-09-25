#include "glmc.h"
#include <math.h>
#include <stdio.h>

void glmc_mat3f_print(mat3f src_b)
{
	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			printf("%-6.2f ", src_b[x][y]);
		}
		printf("\n");
	}
}

int glmc_mat3f_isequal(mat3f src_a, mat3f src_b)
{
	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			if(src_a[x][y] != src_b[x][y])
			{
				return 0;
			}
		}
	}
	return 1;
}	

void glmc_mat3f_copy(mat3f dest, mat3f src_b)
{
	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			dest[x][y]=src_b[x][y];
		}
	}
}

void glmc_mat3f_add(mat3f dest, mat3f src_a, mat3f src_b)
{
	int x=0;
	for(x=0; x<3; x++)
	{ 
		glmc_vec3f_add(dest[x], src_a[x], src_b[x]);
	}
}

void glmc_mat3f_sub(mat3f dest, mat3f src_a, mat3f src_b)
{
	int x=0;
	for(x=0; x<3; x++)
	{ 
		glmc_vec3f_sub(dest[x], src_a[x], src_b[x]);
	}
}

void glmc_mat3f_transp(mat3f dest, mat3f src_b)
{
	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			dest[y][x]=src_b[x][y];
		}
	}
}

void glmc_mat3f_mul(mat3f dest, mat3f src_a, mat3f src_b)
{
	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			for(int z=0; z<3; z++)
			{
				dest[x][y]=src_a[x][z]*src_b[z][y];
			}
		}
	}
	
}

float glmc_mat3f_abs(mat3f src_b)
{
	float dest=0;
	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			dest+=src_b[x][y];
		}
	}
	return dest;
}

void glmc_mat3f_inv(mat3f dest, mat3f src_a)// Inverse of a matrix by Gauss-Jordan elimination
{
	mat3f temp_mat;
	glmc_mat3f_copy(temp_mat,src_a);
	mat3f identity = {{1,0,0}, {0,1,0}, {0,0,1}};
	glmc_mat3f_copy(dest,identity);
	glmc_vec3f_div_s(dest[0], dest[0], src_a[0][0]);
	glmc_vec3f_div_s(src_a[0], src_a[0], src_a[0][0]);
	float pivot1[]={src_a[1][0],src_a[2][0]};
	for(int x=1; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			src_a[x][y]=src_a[x][y]-(pivot1[x-1]*src_a[0][y]);
			dest[x][y]=dest[x][y]-(pivot1[x-1]*dest[0][y]);
		}
	}
	glmc_vec3f_div_s(dest[1], dest[1], src_a[1][1]);
	glmc_vec3f_div_s(src_a[1], src_a[1], src_a[1][1]);
	float pivot2=src_a[2][1];
	for(int y=0; y<3; y++)
	{
		src_a[2][y]=src_a[2][y]-pivot2*src_a[1][y];
		dest[2][y]=dest[2][y]-pivot2*dest[1][y];
	}
	glmc_vec3f_div_s(dest[2], dest[2], src_a[2][2]);
	glmc_vec3f_div_s(src_a[2], src_a[2], src_a[2][2]);
	float temp=src_a[0][1];
	for(int y=0; y<3; y++)
	{
		src_a[0][y]-=temp*src_a[1][y];
		dest[0][y]-=temp*dest[1][y];
	}
	for(int y=0; y<3; y++)
	{
		dest[0][y]-=src_a[0][2]*dest[2][y];
		dest[1][y]-=src_a[1][2]*dest[2][y];
	}
	src_a[0][2]=0;
	src_a[1][2]=0;
	if(glmc_mat3f_isequal(src_a, identity) == 0)
	{
		 printf("Warning:Matrix is not inversible");
	}
	glmc_mat3f_copy(src_a,temp_mat);
}

void glmc_mat3f_rotation(mat3f dest, float angleX, float angleY, float angleZ)
{
	mat3f rotation = {{cos(angleY)*cos(angleZ), cos(angleX)*cos(angleY)*cos(angleZ)-cos(angleX)*sin(angleZ),cos(angleX)*cos(angleZ)*sin(angleY)+sin(angleX)*sin(angleZ)},{cos(angleY)*sin(angleZ), cos(angleX)*cos(angleZ)+sin(angleX)*sin(angleY)*sin(angleZ),cos(angleX)*sin(angleY)*sin(angleZ)-cos(angleZ)*sin(angleX)}, {-1*sin(angleY), cos(angleY)*sin(angleX), cos(angleY)*cos(angleX)}};
	glmc_mat3f_copy(dest, rotation);
}
