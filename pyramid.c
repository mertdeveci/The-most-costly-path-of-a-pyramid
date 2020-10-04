
/* * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
*	@author: Mert Deveci
*	@contact: mertdeveci0@gmail.com
*   @contact: https://www.linkedin.com/in/mert-deveci-49361a135/
*	@company: Sakarya University - Department of Computer Engineering (cs.sakarya.edu.tr)
*	@date: 22/8/2020
*
*
*	@description: The program creates a pyramid of random numbers and finds the most costly path. Details about the problem and
*				solution way can be found in the details file.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include"hPyramid.h"

int main(int argc, char **argv){
	srand(time(NULL)); 
	int **matrix;		// pyramid
	int *counter;		// count of bites of counter
    int *path,*road;    // 'path' is the biggest 'road'
	int i, j;
	int sum=0;		// cost of road
	int way=0; 		// count of branching
	int biggest=0;	// cost of the biggest road
    
    
    if(argc!=2){	
    	error();	
    }	

    const int line=strtol(argv[1],NULL,10);
    
    if(line<2){	
    	error();
    }
    
    
    // Details of processes of the below has been explained in algorithm file.
    way=pow(2,(line-1));    // way= 2^(line-1)
    counter=(int *)malloc((line-1) *sizeof(int));    // counter[line-1]
    path=(int *)malloc((line) *sizeof(int));		 // result of the road (biggest road)
    road=(int *)malloc((line) *sizeof(int));		 // each road
    

        
	

	// >>> Generate 2d array and fill it up randomly.
	matrix = (int **)malloc( line * sizeof(int*) );	
	if( matrix == NULL ){
		printf( "More memory required!" );
	}
		

	for( i = 0; i < line; i++ ) {			
		matrix[i] = malloc( line * sizeof(int) );
		if( matrix[i] == NULL ){
			printf( "More memory required!" );
		}
	}	
	
	
	
	for( i = 0; i < line; i++ ) {	
		space(line-i);
		for( j = 0; j <=i; j++ ){
			matrix[i][j]=rand()%10;	
			printf( "%d ", matrix[i][j] );
		}
		printf( "\n" );
	}


	
    
    

    //>>> Find the most cost way.
	int x,y;	
	for(i=0;i<way;i++){	 
		x=0;
		y=0;
		sum=0;
		binary(counter, i, (line-1));	
		for(j=0;j<line;j++){
			if(counter[j]==0){
				sum+=matrix[x][y];
                road[j]=matrix[x][y];
				x++;
			}else{
				sum+=matrix[x][y];
                road[j]=matrix[x][y];
				x++;
				y++;
			}
		}
		if(sum>biggest){
			biggest=sum;
            change(path,road,line);
		}
	}




	//>>> Result
    
    
    printf("\n%s","The most costly path: ");
    for(i=0;i<line;i++){
        printf(" %d ",path[i]);
        if(i!=line-1){
            printf("->");
        }
    }
	printf("\n%s%d\n\n","Total value of the most costly path:",biggest);
    

    // >>> Deallocation
	for( i = 0; i < line; i++ ) {
		free( matrix[i] );
	}
	free(matrix);
    free(counter);
    free(path);
    free(road);

	return 0;
}


