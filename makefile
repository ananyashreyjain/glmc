glmc.o: mat3.c vec4.c vec3.c vec2.c 
	ar rcs glmc.a  mat3.c vec4.c vec3.c vec2.c
clean:
	rm glmc.a
	rm tests.a
testing:
	ar rcs tests.a mat3.c vec4.c vec3.c vec2.c
	gcc tests.a tests.c -o a
