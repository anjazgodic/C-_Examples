//  We will pass pointers to 4 arrays 
//         Cusum1: holds the cumulative sum score   
//         W1: holds the unit-level scores 
//         ind1: hold the indexes of the change over UCL 
//         UCL 

#include <R.h>
void function1( double * UCL, int * n1, double * Cusum1, double * W1, int*ind1 ) {

	double ucl  = UCL[0];
	int i_max = n1[0];
	int i, j; 

	j=0;                //  This is to augment the position in the ind1 vector 
	for (i=1; i<= i_max; i++) {      // i starts from position 1 -- not 0 

		if ( Cusum1[i-1] < ucl ) {
			//Cusum1[i] = max(0.0, Cusum1[i-1] + W1[i]);
			if (Cusum1[i-1] + W1[i] > 0.0) {
				Cusum1[i] =  (Cusum1[i-1] + W1[i]);
			} else {
				Cusum1[i] = 0.0; 
			}
		} 
		else {
			//Cusum1[i] = max(0.0, W1[i]);
			if ( W1[i] > 0.0) {
				Cusum1[i] = W1[i];	
			}
			else {
				Cusum1[i] = 0.0; 
			}  
			ind1[j] = i;      // we record the previous index, where the Cusum1 
			                  //went above UCL -- but +1 because R uses 1-based indexes
			j = j+1;
		}
	}
}
