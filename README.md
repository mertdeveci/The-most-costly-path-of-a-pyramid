# The-most-costly-path-of-a-pyramid
Calculation of the most costly path of a pyramid from first line to end line


# Description
###### @author: Mert Deveci
###### @contact: mertdeveci0@gmail.com
###### @contact: https://www.linkedin.com/in/mert-deveci-49361a135/
###### @company: Sakarya University - Department of Computer Engineering (cs.sakarya.edu.tr)
###### @date: 22/8/2020

###### @description: The program creates a pyramid of random numbers and finds the most costly path.



	 	  4		
   	     	 3 7	-> row-2 (Total nodes:3)
  		7 6 7	-> row-3 (Total nodes:6)
 	       9 2 5 0  -> row-4 (Total nodes:10)
 		  ...	-> row-n 

> The table below can be made for the n-line pyramid

     -line: The number of the pyramid line.
     -total_nodes: Total nodes
     -Branching: Number of branches from the first line to the finish line
     -counter_bites: The number of branches can be represented in how many bytes.

    line | total_nodes | Branching | counter_bites				
       2	3	     2  	1 [0-1]					
       3	6 	     4 		2 [00-01-10-11]				
       4 	10	     8 	        3 [000-001-010-011-100-101-110-111]
       ...												
       n 	... 	 2^(n-1)	(n-1)					


> According to the table above, the following equations are obtained.
  -For the n-row pyramid, the total number of paths (branches) = 2 ^ (n-1)
  -For the n-row pyramid, the number of counter bits = n-1


 	
		
# Solution		  	

          4
         / \
	3   7
       / \ / \
      7   6   7
     / \ / \ / \
    9   2   5   0

> All steps
  -step-1:: Create a 2D array and its size will be given by the user.
  -step-2:: Each position of the pyramid will be filled with random numbers and the pyramid will be printed on the screen.
  -step-3:: Create a dynamic array called counter, its size will be the same as the variable 'counter_bites'.
  -step-4:: All numbers starting from i = 0 up to the branching variable will be converted to binary and assigned to the 'counter' array.
 			
 				Example:
				For row-3: counter[2]={ 00, 01, 10, 11}

  -step-5:: You will forward on the pyramid according to the values of the counter array.
  
  			 counter[0]==0 forward left-cross
  			 counter[1]==1 forward right-cross
  			 
  				Example:
  					For row-3 and counter[2]= 00-01-10-11 

  						4
	  				       / \
	  				     [0] [1] 	->> counter[0]
	  				     / 	   \
	  				    3	    7
					   / \ 	   / \
					 [0] [1] [0] [1]	->> counter[1]
					 /     \ /     \
					7	    6 	    7       

 				>> counter[0]==0 and counter[1]==0 ->> 4-3-7
				>> counter[0]==0 and counter[1]==1 ->> 4-3-6
 				>> counter[0]==1 and counter[1]==0 ->> 4-7-6
				>> counter[0]==1 and counter[1]==1 ->> 4-7-7 [BIGGEST]

  step-6:: Compare the sum value with biggest variable.
  step-7:: Continue until step-4 is over
  step-8:: Print the result on screen and deallocate the memory

