
#include "header.c"



/**
  TEST SUIT t1.

     FUNCTIONS:  
		lst_are_equal
		lst_count
		lst_length
**/
		


int a5[][5] = {
		{ 1, 2, 3, 4, 5} ,
		{ 5, 4, 3, 2, 1},
		{ 0, 2, 3, 4, 5} ,
		{ 1, 2, 3, 4, 0} ,
		{ 0, 0, 0, 0, 0} ,   //IDX-4
		{ 1, 0, 0, 0, 0} ,   //IDX-5
		{ 0, 0, 0, 0, 1},    //IDX-6
		{ 0, 1, 0, 1, 0}     //IDX-7
	     };


int main(){

  printf("TEST SUITE t1.c RESULTS FOR FUNCTIONS: \n");
  printf("         lst_are_equal\n");
  printf("         lst_count\n");
  printf("         lst_length\n");
  printf("########################################\n\n");


  START("lst_are_equal", 10); 
  {
	  lsts[0] = arr2list(a5[0], 5);
	  lsts[1] = arr2list(a5[1], 5);
	  lsts[2] = arr2list(a5[0], 5);

	  lsts[3] = arr2list(a5[1], 4);
	  lsts[4] = arr2list(a5[2], 5);
	  lsts[5] = arr2list(a5[3], 5);

	  PtsPer = 2.0;
	  TEST_RET(lst_are_equal(lsts[0], lsts[1]), 0, PtsPer);
	  TEST_RET(lst_are_equal(lsts[0], lsts[2]), 1, PtsPer);
	  TEST_RET(lst_are_equal(lsts[0], lsts[3]), 0, PtsPer);
	  TEST_RET(lst_are_equal(lsts[0], lsts[4]), 0, PtsPer);
	  TEST_RET(lst_are_equal(lsts[0], lsts[5]), 0, PtsPer);

  }
  END



  START("lst_count", 10); 

	  lsts[0] = arr2list(a5[4], 5);
	  lsts[1] = arr2list(a5[5],5);
	  lsts[2] = arr2list(a5[6], 5);
	  lsts[3] = arr2list(a5[7], 5);

	  PtsPer = 2.5;
	  TEST_RET(lst_count(lsts[0], 0), 5, PtsPer);
	  TEST_RET(lst_count(lsts[1], 1), 1, PtsPer);
	  TEST_RET(lst_count(lsts[2], 1), 1, PtsPer);
	  TEST_RET(lst_count(lsts[3], 1), 2, PtsPer);
  END


  START("lst_length", 15.0);

	  PtsPer = 3.75;

	  time_t budget;

	  budget = calibrate_constant(TIME_TRIALS);

	  int len = 1000;
	  int i;

	  lsts[0] = one_to_n_lst(len);
	  TIME(lst_length(lsts[0]), len, budget, PtsPer);

	  for(i=0; i<len/2; i++) 
		  lst_pop_front(lsts[0]);
	  TIME(lst_length(lsts[0]), len - len/2, budget, PtsPer);
	  for(i=0; i<len/2; i++) 
		  lst_push_front(lsts[0], 0);
	  TIME(lst_length(lsts[0]), len, budget, PtsPer);
	  for(i=0; i<len/2; i++) 
		  lst_push_back(lsts[0], 0);
	  TIME(lst_length(lsts[0]), len+len/2, budget, PtsPer);

  END

  report();

}

  
