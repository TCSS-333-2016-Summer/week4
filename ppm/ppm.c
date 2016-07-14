#include "ppm.h"

static ppm* init_ppm(){
	ppm *p=malloc(sizeof(ppm));
	if(!p)exit(1);
	p->image=0;
	return p;
}	
ppm* init_ppm_read(char filename, FILE *fp){
 ppm *p=init_ppm();
	read_ppm(p,filename,fp);
	return p;
}
	
void destroy_ppm(ppm *p){
	if(p && p->image)free(p->image);
	free(p);
	p=0;
}	
void read_ppm(ppm *p,char filename, FILE *fp){
	if(filename){
		fp=fopen(filename,"r");
		if(!fp)exit(1);
	}
	fseek(fp,0,SEEK_END);
	p->imageSize=ftell(fp);	
	p->image=malloc(p->imageSize);
	if(p->image)exit(1);
	
	fseek(fp,0,SEEK_SET); //rewind the file - set point to start of file
	if(!fread(p->image,p->imageSize,1,fp)) exit(1);
	//look for 4 \n s;
	int nLines=0;
	for (int i=0;i<p->imageSize;i++){
		if(p->image[i] == '\n'){
			nLines++;
			if(nLines == 4){
			 p->pixels=(rgb*) (p->image+i+1);
			 p->nPixels=(p->imageSize-i-1)/3;
			}
		}	
	}	
	if(filename){
	 fclose(fp);	
	}		
}	
void write_ppm(ppm *p,char filename, FILE *fp){
if(filename){
		fp=fopen(filename,"w");
		if(!fp)exit(1);
	}
 if(!fwrite(p->image,p->imageSize,1,fp))exit(1);
	if(filename){
	 fclose(fp);	
	}		
}	
void dered_ppm(ppm *p){
	for(int i=0;i<nPixels;i++)
	 p->pixels[i].red=0;
}	
#endif
