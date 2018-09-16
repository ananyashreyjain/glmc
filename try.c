#include<stdio.h>
typedef float vec4f[4];
typedef float vec3f[3];
typedef float vec2f[2];

int main(){

typedef vec4f mat4f[4];
typedef vec3f mat3f[3];
typedef vec2f mat2f[2];

vec2f v1={3,4};
vec2f v2={3,5};
mat2f m;
*m=(void*)v1;
printf("%f",**m);
}
