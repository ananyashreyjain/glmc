/* 
 * Copyright 2018 Anish Bhobe, glmc Contributors
 * 
 * Permission is hereby granted, free of charge, 
 * to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the 
 * ollowing conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

//#include "glmc.h"
#include<stdio.h>
#include<math.h>

typedef float vec2f[2];
typedef float vec3f[3];
typedef float vec4f[4];
typedef float mat2f[2][2];
typedef float mat3f[3][3];
typedef float mat4f[4][4];

// vec3f

void glmc_vec3f_from_2f(vec3f dest, vec2f src_a, float src_b)
{
	int e3;
	for(e3=0; e3<2; e3++)
	{
		dest[e3] = src_a[0];
		printf("%f\n", dest[e3]);
	}
	dest[e3] = src_b;
	printf("%f\n", dest[e3]);
}

void glmc_vec3f_from_4f(vec3f dest, vec4f src)
{
	int e4;
	int e3 = 0;
	for(int e4=0; e4<4; e4++)
	{
		if(src[e4]!=0 && e3<3)
		{
			dest[e3++] = src[e4];
			printf("%f\n", dest[e3]);
		}
		else if(e3>2 && src[e4]!=0)
		{
			printf("Warning: Fourth value got dumped");
		}
	}
}

void glmc_vec3f_copy(vec3f dest, vec3f src)
{
	int e3 = 0;
	for(e3=0; e3<3; e3++)
	{
		dest[e3] = src[e3];
		printf("%f\n",dest[e3]);
	}
}

float glmc_vec3f_sqrlength(vec3f vec)
{
	int e3 = 0;
	float sum=0.0;
	for(e3=0; e3<3; e3++)
	{
		sum+=vec[e3]*vec[e3];
		printf("%f\n",vec[e3]);
	}
	return sum;

}

float glmc_vec3f_length(vec3f vec)
{
	return (powf(glmc_vec3f_sqrlength(vec),0.5));
}

int  glmc_vec3f_is_normalized(vec3f src)
{
	if(glmc_vec3f_length(src)==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void glmc_vec3f_normlize(vec3f dest, vec3f src)
{
	int e3;
	int length=glmc_vec3f_length(src);
	for(e3=0; e3<3; e3++)
	{
		dest[e3] = src[e3]/length;
	}
}

void glmc_vec3f_add(vec3f dest, vec3f src_a, vec3f src_b) // dest = src_a + src_b;
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		dest[e3] = src_a[e3] + src_b[e3];
		printf("%f\n",dest[e3]);
	}
}
	
void glmc_vec3f_add_dest(vec3f src_dest, vec3f src_b) // dest += src_a;
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		src_dest[e3] += src_b[e3];
		printf("%f\n",src_dest[e3]);
	}
}

void glmc_vec3f_sub(vec3f dest, vec3f src_a, vec3f src_b) // dest = src_a - src_b;
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		dest[e3] = src_a[e3] - src_b[e3];
		printf("%f\n",dest[e3]);
	}
}
	
void glmc_vec3f_sub_dest(vec3f src_dest, vec3f src_b) // dest -= src_a;
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		src_dest[e3] -= src_b[e3];
		printf("%f\n",src_dest[e3]);
	}
}

void glmc_vec3f_mul(vec3f dest, vec3f src_a, vec3f src_b) // dest = src_a * src_b;
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		dest[e3] = src_a[e3] * src_b[e3];
		printf("%f\n",dest[e3]);
	}
}
	
void glmc_vec3f_mul_dest(vec3f src_dest, vec3f src_b) // dest *= src_a;
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		src_dest[e3] *= src_b[e3];
		printf("%f\n",src_dest[e3]);
	}
}
void glmc_vec3f_mul_s(vec3f dest, vec3f src_a, float src_b) // dest = src_a * scalar
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		dest[e3] = src_a[e3] * src_b;
		printf("%f\n",dest[e3]);
	}
}

void glmc_vec3f_div(vec3f dest, vec3f src_a, vec3f src_b) // dest = src_a / src_b;
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		dest[e3] = src_a[e3] / src_b[e3];
		printf("%f\n",dest[e3]);
	}
}
void glmc_vec3f_div_dest(vec3f src_dest, vec3f src_b) // dest /= src_a;
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		src_dest[e3] /= src_b[e3];
		printf("%f\n",src_dest[e3]);
	}
}
void glmc_vec3f_div_s(vec3f dest, vec3f src_a, float src_b) // dest = src_a / scalar
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		dest[e3] = src_a[e3] / src_b;
		printf("%f\n",dest[e3]);
	}
}

void glmc_vec3f_addadd(vec3f dest, vec3f src_a, vec3f src_b) // dest += src_a + src_b;
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		dest[e3] += src_a[e3] + src_b[e3];
		printf("%f\n",dest[e3]);
	}
}
	
void glmc_vec3f_subadd(vec3f dest, vec3f src_a, vec3f src_b) // dest += src_a - src_b;
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		dest[e3] += src_a[e3] - src_b[e3];
		printf("%f\n",dest[e3]);
	}
}
	

void glmc_vec3f_madd(vec3f dest, vec3f src_a, vec3f src_b) // dest += src_a * src_b;
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		dest[e3] += src_a[e3] * src_b[e3];
		printf("%f\n",dest[e3]);
	}
}
	
void glmc_vec3f_msub(vec3f dest, vec3f src_a, vec3f src_b)// dest -= src_a * src_b;
{
	int e3;
	for(e3=0; e3<3; e3++)
	{
		dest[e3] -= src_a[e3] * src_b[e3];
		printf("%f\n",dest[e3]);
	}
}

float glmc_vec3f_dot(vec3f src_a, vec3f src_b)
{
	int e3;
	float dot_product = 0;
	for(e3=0; e3<3; e3++)
	{
		dot_product += src_a[e3] * src_b[e3];
	}
	return dot_product;
}

void  glmc_vec3f_cross(vec3f dest, vec3f src_a, vec3f src_b)
{
	dest[0] = (src_a[1]*src_b[2]-src_a[2]*src_b[1]);
	dest[1] =-1*(src_a[0]*src_b[2]-src_a[2]*src_b[0]);
	dest[2] = (src_a[0]*src_b[1]-src_a[1]*src_b[0]);
}

// vec4f

void glmc_vec4f_from_2f(vec4f dest, vec2f src_a, float src_b, float src_c)
{
	int e4;
	for(e4=0; e4<2; e4++)
	{
		dest[e4] = src_a[e4];
	}
		dest[e4++] = src_b;
		dest[e4++] = src_c;
}
		
void glmc_vec4f_from_3f(vec4f dest, vec3f src_a, float src_b)
{
	int e4;
	for(e4=0; e4<3; e4++)
	{
		dest[e4] = src_a[e4];
	}
		dest[e4++] = src_b;
}

void glmc_vec4f_copy(vec4f dest, vec4f src)
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		dest[e4] = src[e4];
	}
}

float glmc_vec4f_sqrlength(vec4f vec)
{
	int e4 = 0;
	float sum=0.0;
	for(e4=0; e4<4; e4++)
	{
		sum+=vec[e4]*vec[e4];
		printf("%f\n",vec[e4]);
	}
	return sum;

}

float glmc_vec4f_length(vec4f vec)
{
	return (powf(glmc_vec4f_sqrlength(vec),0.5));
}

int  glmc_vec4f_is_normalized(vec4f src)
{
	if(glmc_vec4f_length(src) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void glmc_vec4f_normlize(vec4f dest, vec4f src)
{
	int e4 = 0;
	float sum=0.0;
	for(e4=0; e4<4; e4++)
	{
		dest[e4] = src[e4] / (glmc_vec4f_length(src));
		printf("%f\n",dest[e4]);
	}
}

void glmc_vec4f_add(vec4f dest, vec4f src_a, vec4f src_b) // dest = src_a + src_b;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		dest[e4] = src_a[e4] + src_b[e4];
		printf("%f\n",dest[e4]);
	}
}
	
void glmc_vec4f_add_dest(vec4f src_dest, vec4f src_b) // dest += src_a;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		src_dest[e4] += src_b[e4];
		printf("%f\n",src_dest[e4]);
	}
}

void glmc_vec4f_sub(vec4f dest, vec4f src_a, vec4f src_b) // dest = src_a - src_b;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		dest[e4] = src_a[e4] - src_b[e4];
		printf("%f\n",dest[e4]);
	}
}

void glmc_vec4f_sub_dest(vec4f src_dest, vec4f src_b) // dest -= src_a;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		src_dest[e4] -= src_b[e4];
		printf("%f\n",src_dest[e4]);
	}
}

void glmc_vec4f_mul(vec4f dest, vec4f src_a, vec4f src_b) // dest = src_a * src_b;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		dest[e4] = src_a[e4] * src_b[e4];
		printf("%f\n",dest[e4]);
	}
}

void glmc_vec4f_mul_dest(vec4f src_dest, vec4f src_b) // dest *= src_a;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		src_dest[e4] *= src_b[e4];
		printf("%f\n",src_dest[e4]);
	}
}

void glmc_vec4f_mul_s(vec4f dest, vec4f src_a, float src_b) // dest = src_a * scalar;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		dest[e4] = src_a[e4] * src_b;
		printf("%f\n",dest[e4]);
	}
}

void glmc_vec4f_div(vec4f dest, vec4f src_a, vec4f src_b) // dest = src_a / src_b;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		dest[e4] = src_a[e4] / src_b[e4];
		printf("%f\n",dest[e4]);
	}
}
void glmc_vec4f_div_dest(vec4f src_dest, vec4f src_b) // dest /= src_a;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		src_dest[e4] /= src_b[e4];
		printf("%f\n",src_dest[e4]);
	}
}

void glmc_vec4f_div_s(vec4f dest, vec4f src_a, float src_b) // dest = src_a / scalar;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		dest[e4] = src_a[e4] / src_b;
		printf("%f\n",dest[e4]);
	}
}

void glmc_vec4f_addadd(vec4f dest, vec4f src_a, vec4f src_b) // dest += src_a + src_b;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		dest[e4] += src_a[e4] + src_b[e4];
		printf("%f\n",dest[e4]);
	}
}

void glmc_vec4f_subadd(vec4f dest, vec4f src_a, vec4f src_b) // dest += src_a - src_b;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		dest[e4] += src_a[e4] - src_b[e4];
		printf("%f\n",dest[e4]);
	}
}

void glmc_vec4f_madd(vec4f dest, vec4f src_a, vec4f src_b) // dest += src_a * src_b;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		dest[e4] += src_a[e4] * src_b[e4];
		printf("%f\n",dest[e4]);
	}
}

void glmc_vec4f_msub(vec4f dest, vec4f src_a, vec4f src_b) // dest -= src_a * src_b;
{
	int e4;
	for(e4=0; e4<4; e4++)
	{
		dest[e4] -= src_a[e4] * src_b[e4];
		printf("%f\n",dest[e4]);
	}
}

float glmc_vec4f_dot(vec4f src_a, vec4f src_b)
{
	int e4;
	float dot_product = 0;
	for(e4=0; e4<4; e4++)
	{
		dot_product += src_a[e4] * src_b[e4];
	}
	return dot_product;
}

// vec2f

void glmc_vec2f_from_3f(vec2f dest, vec3f src)
{
	int e3;
	int e2 = 0;
	for(int e3=0; e3<3; e3++)
	{
		if(src[e3]!=0 && e2<2)
		{
			dest[e2++] = src[e3];
			printf("%f\n", dest[e2]);
		}
		else if(e2>1 && src[e3]!=0)
		{
			printf("Warning: Third value got dumped");
		}
	}
}
void glmc_vec2f_from_4f(vec2f dest, vec2f src)
{
	int e3;
	int e2 = 0;
	for(int e4=0; e4<4; e4++)
	{
		if(src[e3]!=0 && e2<2)
		{
			dest[e2++] = src[e3];
			printf("%f\n", dest[e2]);
		}
		else if(e2>1 && src[e3]!=0)
		{
			printf("Warning: One value got dumped");
		}
	}
}
void glmc_vec2f_copy(vec2f dest, vec2f src)
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		dest[e2] = src[e2];
	}
}

float glmc_vec2f_sqrlength(vec2f vec)
{
	int e2 = 0;
	float sum=0.0;
	for(e2=0; e2<2; e2++)
	{
		sum+=vec[e2]*vec[e2];
		printf("%f\n",vec[e2]);
	}
	return sum;

}

float glmc_vec2f_length(vec2f vec)
{
	return (powf(glmc_vec2f_sqrlength(vec),0.5));
}

int  glmc_vec2f_is_normalized(vec2f src)
{
	if(glmc_vec2f_length(src) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void glmc_vec2f_normlize(vec2f dest, vec2f src)
{
	int e2 = 0;
	float sum=0.0;
	for(e2=0; e2<2; e2++)
	{
		dest[e2] = src[e2] / (glmc_vec2f_length(src));
		printf("%f\n",dest[e2]);
	}
}

void glmc_vec2f_add(vec2f dest, vec2f src_a, vec2f src_b) // dest = src_a + src_b;
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		dest[e2] = src_a[e2] + src_b[e2];
		printf("%f\n",dest[e2]);
	}
}

void glmc_vec2f_add_dest(vec2f src_dest, vec2f src_b) // dest += src_a;
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		src_dest[e2] += src_b[e2];
		printf("%f\n",src_dest[e2]);
	}
}

void glmc_vec2f_sub(vec2f dest, vec2f src_a, vec2f src_b) // dest = src_a - src_b;
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		dest[e2] = src_a[e2] - src_b[e2];
		printf("%f\n",dest[e2]);
	}
}

void glmc_vec2f_sub_dest(vec2f src_dest, vec2f src_b) // dest -= src_a;
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		src_dest[e2] -= src_b[e2];
		printf("%f\n",src_dest[e2]);
	}
}

void glmc_vec2f_mul(vec2f dest, vec2f src_a, vec2f src_b) // dest = src_a * src_b;
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		dest[e2] = src_a[e2] * src_b[e2];
		printf("%f\n",dest[e2]);
	}
}

void glmc_vec2f_mul_dest(vec2f src_dest, vec2f src_b) // dest *= src_a;
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		src_dest[e2] *= src_b[e2];
		printf("%f\n",src_dest[e2]);
	}
}

void glmc_vec2f_mul_s(vec2f dest, vec2f src_a, float src_b) // dest = src_a * scalar
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		dest[e2] = src_a[e2] * src_b;
		printf("%f\n",dest[e2]);
	}
}

void glmc_vec2f_div(vec2f dest, vec2f src_a, vec2f src_b) // dest = src_a / src_b;
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		dest[e2] = src_a[e2] / src_b[e2];
		printf("%f\n",dest[e2]);
	}
}
void glmc_vec2f_div_dest(vec2f src_dest, vec2f src_b) // dest /= src_a;
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		src_dest[e2] /= src_b[e2];
		printf("%f\n",src_dest[e2]);
	}
}

void glmc_vec2f_div_s(vec2f dest, vec2f src_a, float src_b) // dest = src_a / scalar
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		dest[e2] = src_a[e2] / src_b;
		printf("%f\n",dest[e2]);
	}
}
void glmc_vec2f_addadd(vec2f dest, vec2f src_a, vec2f src_b) // dest += src_a + src_b;
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		dest[e2] += src_a[e2] + src_b[e2];
		printf("%f\n",dest[e2]);
	}
}

void glmc_vec2f_subadd(vec2f dest, vec2f src_a, vec2f src_b) // dest += src_a - src_b;
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		dest[e2] += src_a[e2] - src_b[e2];
		printf("%f\n",dest[e2]);
	}
}

void glmc_vec2f_madd(vec2f dest, vec2f src_a, vec2f src_b) // dest += src_a * src_b;
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		dest[e2] += src_a[e2] * src_b[e2];
		printf("%f\n",dest[e2]);
	}
}
void glmc_vec2f_msub(vec2f dest, vec2f src_a, vec2f src_b) // dest -= src_a * src_b;
{
	int e2;
	for(e2=0; e2<2; e2++)
	{
		dest[e2] -= src_a[e2] * src_b[e2];
		printf("%f\n",dest[e2]);
	}
}
float glmc_vec2f_dot(vec2f src_a, vec2f src_b)
{
	int e2;
	float dot_product = 0;
	for(e2=0; e2<2; e2++)
	{
		dot_product += src_a[e2] * src_b[e2];
	}
	return dot_product;
}
