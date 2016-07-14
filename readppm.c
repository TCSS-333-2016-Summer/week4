#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//readprint -i inputfile -o outputfile
//readprint < inputfile > outputfile
int main(int argc, char *argv[]){
	FILE *inputfp=stdin;
	FILE *outputfp=stdout;
	char *files[2]={0,0};
	if(argc > 5){
		fprintf(stderr,"line 12 readprint -i inputfile -o outputfile\n");
		exit(0);
	}
	int i=1;
	while(i < argc){
		if( strcmp(argv[i],"-i") == 0){
			files[0]=argv[i+1];
			i+=2;
		}	
		else if(strcmp(argv[i],"-o")==0){
			files[1]=argv[i+1];
			i+=2;
		}
		else{
			fprintf(stderr,"line 26 readprint -i inputfile -o outputfile\n");
		 exit(0);
		}		
	}	
 if(files[0])fprintf(stderr,"reading in from %s\n",files[0]);
 else fprintf(stderr,"reading from stdin\n");
 if(files[1])fprintf(stderr,"writing to %s\n",files[1]);
 else fprintf(stderr,"writing to stdout\n");
 
 char line[4096];
 if(files[0]){
		inputfp=fopen(files[0],"r");
		if(!inputfp)exit(0);
	}
	if(files[1]){
		outputfp=fopen(files[1],"w");
		if(!outputfp)exit(0);
	}
	for (int i=0;i<4;i++){
	 fgets(line,sizeof(line),inputfp);
		fprintf(outputfp,"%s",line);
	}
	char buffer[3];
	while(fread(buffer,3,1,inputfp)){
		buffer[0]=0;
		fwrite(buffer,3,1,outputfp);
	}				
 if(inputfp!=stdin)fclose(inputfp);
 if(outputfp!=stdout)fclose(outputfp);
 return 0;
}
