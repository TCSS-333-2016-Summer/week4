#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __ppm_h
#define __ppm_h
typedef struct{
	char red;
	char green;
	char blue;
}rgb;

typedef struct{
	char *image;
	rgb *pixels;
	int nPixels;
	int imageSize;
} ppm;

static ppm* init_ppm();
ppm* init_ppm_read(char filename, FILE *fp);
void destroy_ppm(ppm *p);
void read_ppm(ppm *p,char filename, FILE *fp);
void write_ppm(ppm *p,char filename, FILE *fp);
void dered_ppm(ppm *p);
#endif
