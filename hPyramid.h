
/* * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
*    @author: Mert Deveci
*    @contact: mertdeveci0@gmail.com
*    @contact: https://www.linkedin.com/in/mert-deveci-49361a135/
*    @company: Sakarya University - Department of Computer Engineering (cs.sakarya.edu.tr)
*    @date: 22/8/2020
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



	void space(int i){	// space characters(' ') at the beginning of each line
		while(i>0){
			printf(" ");
			i--;
		}
	}

	
	
	void binary(int *counter,int number, int limit){	// convert value of the 'number' variable to binary and write it in the array of 'counter'
		int i=0;
        for(;i<limit;i++){
            counter[i]=number%2;
            number=number/2;
        }
	}

    void error(){       // Error
        printf("%s\n","Wrong parameters usage");
        printf("%s\n","./pyramid [number]");
        exit(EXIT_FAILURE);
    }
      
  
    void change(int *path,int *way,int line){   // Write inside of 'way' to 'path'
        int i=0;
        for(;i<line;i++){
            path[i]=way[i];
        }
    }

