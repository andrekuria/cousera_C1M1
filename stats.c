/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief The following code involes functions that do calculate various statistical features ie mean mode the maximum and minimum values.
 *
 * important to note all the printf statements used for debugging hence are commented out. <Add Extended Description Here>
 *
 * @author  WEREHIRE ANDRE
 * @date 24th Jan 2022 
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90 };

  /* Other Variable Declarations Go Here */
    float mean = find_mean(test, SIZE);
    float median = find_median(test, SIZE);
    unsigned char minimum = find_minimum(test, SIZE);
    unsigned char maximum = find_maximum(test, SIZE);
    
  /* Statistics and Printing Functions Go Here */
      print_statistics(mean, median, minimum , maximum);
     
      printf("\nArray before sorting : \n");
      print_array(test, SIZE);

      printf("\nArray after sorting in descending order : \n");
      sort_array(test, SIZE);  
      print_array(test, SIZE);
        
    
}

/* Add other Implementation File Code Here */
	
	void print_statistics(float mean , float median , unsigned char minimum , unsigned char maximum  ) {
	/* this prints the statistics of an array including minimum, maximum, mean, and median. */
	
	printf("The minimum value is: %u\n" , minimum );
	printf("The maximum value is: %u\n" ,maximum );
	printf("The mean value is: %f\n" , mean);
	printf("The median value is: %f\n" ,median);
	}

    void print_array(unsigned char * array , unsigned int length ){
	/*  prints the array to the screen */ 
	    for ( int a = 0 ; a < length ; a++){
	
		printf("%d\t " , array[a]);
		
		}
	}


unsigned char find_maximum(unsigned char * array , unsigned int length ){
 
    /* Here we will store the largest number in the last element by looping through and comparing the elements */ 
    for (int i=0 ; i < length ; i++){
        
        if(  array[i] > array[length -1 ]){
            
            array[length - 1] = array [i];
        }
    }   
    
     
    unsigned char maximum= array[length -1 ];
    
    //printf("largest is %d\n" ,maximum );
    
    return maximum;
}

unsigned char find_minimum(unsigned char * array , unsigned int length ){
 
    /* Here we will store the smallest number in the first element by looping through and comparing the elements */ 
    for (int i=0 ; i < length ; i++){
        
        if(  array[i] < array[0]){
            
            array[0] = array [i];
        }
    }   
    
    unsigned char minimum= array[0];
    
    //printf("smallest is %d\n" , minimum); 
    
    return minimum;
    
    
}

void sort_array(unsigned char * array , unsigned int length ){
    
    int i , j , k ;
	
	for (i=0 ; i < length ; i++ ){
	
		for( j=0 ; j < length - 1 ; j++){
		
			if (array[j] < array[j+1])
			{
				k = array[j] ; 
				array[j] = array[j+1] ; 
				array[j+1] = k ; 
				
				}
				}
				}
	
}


float  find_median(unsigned char * array , unsigned int length ) {
	/* returns the median value */ 
	
	/* First we do have to sort */ 
	
	int i , j , k ;
	
	for (i=0 ; i < length ; i++ ){
	
		for( j=0 ; j < length - 1 ; j++){
		
			if (array[j] > array[j+1])
			{
				k = array[j] ; 
				array[j] = array[j+1] ; 
				array[j+1] = k ; 
				
				}
				}
				}
	
	
	float median ; 
	
	// if number of elements are even
    if(length %2 == 0)
        median = (float)(array[(length -1)/2] + array[length/2])/2 ;
    // if number of elements are odd
    else
        median = (float)(array[length/2]);
	 
    return median ;
    
}



float find_mean(unsigned char * array , unsigned int length ){
    /*Given an array of data and a length, returns the mean */
    /* Loop through the array adding the elements together then type casting length variable to find the mean in a float ie more accurate way*/
   
    int kush = 0 ; 
    
    for (int i = 0; i < length ; i++ ){
        kush += array[i] ; 
        
    }
    
    float mean = kush / (float)length ; 
    
  
     
    return mean ; 


}





		
		
	




