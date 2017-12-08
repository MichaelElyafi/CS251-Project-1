
#include "header.c"



/**
  TEST SUIT t9.

     FUNCTIONS:  
		remove_all_fast
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

  printf("\n########################################\n\n");
  printf("TEST SUITE t9.c RESULTS FOR FUNCTIONS: \n\n");
  printf("         lst_remove_all_fast\n");
  printf("########################################\n\n");


  START("lst_remove_all_fast", 20); 
  {
	int i;


	  PtsPer = 1.5;


	  lsts[0] = rem_all_hard_caseA(10);
	  TEST_RET_MESSAGE(lst_remove_all_fast(lsts[0], 0), 
			"Ten 1's followed by 10 0's (return val test)",
			10, PtsPer);

	  TEST_RET_MESSAGE(n_ones(lsts[0], 10), 
			"after deleting 0's, list should be exactly 10 1's",
			1, PtsPer);

	cleanup();
	  lsts[0] = rem_all_hard_caseB(10);
	  TEST_RET_MESSAGE(lst_remove_all_fast(lsts[0], 0), 
			"(5 1's) (5 0's) (5 1's) (5 0's) test (return val test)",
			10, PtsPer);

	  TEST_RET_MESSAGE(n_ones(lsts[0], 10), 
			"after deleting 0's, list should be exactly 10 1's",
			1, PtsPer);


	cleanup();

	 lsts[0] = rem_all_hard_caseA(5000);

	 clock_t budget = calibrate_linear(10000, 1);
	
	 TIME_ONCE(lst_remove_all_fast(lsts[0], 0), 
		"5k 1's followed by 5k 0's test", 5000, budget, 5.5);

	  TEST_RET_MESSAGE(n_ones(lsts[0], 5000), 
			"after deleting 0's, list should be exactly 5k 1's",
			1, PtsPer);

	cleanup();
	 lsts[0] = rem_all_hard_caseB(5000);
	
	 TIME_ONCE(lst_remove_all_fast(lsts[0], 0), 
		"(2.5k 1's)(2.5k 0's)(2.5k 1's)(2.5k 0's) case", 5000, budget, 5.5);

	  TEST_RET_MESSAGE(n_ones(lsts[0], 5000), 
			"after deleting 0's, list should be exactly 5k 1's",
			1, PtsPer);


  }
  END


  report();


}

