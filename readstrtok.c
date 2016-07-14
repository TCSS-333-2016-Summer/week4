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
	char *pch;
	char delim[]=" \n";
	while(fgets(line,sizeof(line),inputfp)){
  //parse a line for name rank and serialnumber
  char name[4096],rank[4096];
  int serialNumber;
	 pch=strtok(line,delim);
	 // Kirk Captain   1234
	 int nRecords=0;
 	while(pch){
	  if(nRecords %3 ==2){
	   fprintf(outputfp,"serial number is %d\n",atoi(pch));
			}
	  pch=strtok(0,delim);
	  nRecords++;
 	}
	}			
 if(inputfp!=stdin)fclose(inputfp);
 if(outputfp!=stdout)fclose(outputfp);
 return 0;
}
