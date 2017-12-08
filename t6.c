
#include "header.c"



/**
  TEST SUIT t6.

     FUNCTIONS:  
		lst_prefix
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
  printf("TEST SUITE t6.c RESULTS FOR FUNCTIONS: \n\n");
  printf("         lst_prefix\n");
  printf("########################################\n\n");


  START("lst_prefix", 20); 
  {
	int i;

	  PtsPer = 2.0;


	  lsts[0] = arr2list(a5[0], 5);
	  lsts[1] = lst_prefix(lsts[0], 0);
	  TEST_RET_MESSAGE(lst_is_empty(lsts[1]), 
			"0-length prefix test",
			1, PtsPer);

	  TEST_RET_MESSAGE(eq2array(lsts[0], a5[0], 5), 
			"0-length prefix test: RHS correct?",
			1, PtsPer);

	  cleanup();
	  lsts[0] = arr2list(a5[0], 5);
	  lsts[1] = lst_prefix(lsts[0], 5);
	  TEST_RET_MESSAGE(eq2array(lsts[1], a5[0], 5), 
			"n-length prefix test: LHS correct?",
			1, PtsPer);

	  TEST_RET_MESSAGE(lst_is_empty(lsts[0]), 
			"n-length prefix test: RHS correct?",
			1, PtsPer);

	  cleanup();

	  int a[] = {1, 2, 3, 4, 5, 6};
	  int left1[] = {1};
	  int right1[] = {2, 3, 4, 5, 6};

	  int left3[] = {1, 2, 3};
	  int right3[] = {4, 5, 6};

	  int left5[] = {1, 2, 3, 4, 5};
	  int right5[] = {6};

	  lsts[0] = arr2list(a, 6);
	  lsts[1] = lst_prefix(lsts[0], 1);
	  TEST_RET_MESSAGE(eq2array(lsts[1], left1, 1), 
			"length-1 prefix test: LHS correct?",
			1, PtsPer);
	  TEST_RET_MESSAGE(eq2array(lsts[0], right1, 5), 
			"length-1 prefix test: RHS correct?",
			1, PtsPer);
	  cleanup();

	  lsts[0] = arr2list(a, 6);
	  lsts[1] = lst_prefix(lsts[0], 3);
	  TEST_RET_MESSAGE(eq2array(lsts[1], left3, 3), 
			"length-3 prefix test: LHS correct?",
			1, PtsPer);
	  TEST_RET_MESSAGE(eq2array(lsts[0], right3, 3), 
			"length-5 prefix test: RHS correct?",
			1, PtsPer);

	  cleanup();

	  lsts[0] = arr2list(a, 6);
	  lsts[1] = lst_prefix(lsts[0], 5);
	  TEST_RET_MESSAGE(eq2array(lsts[1], left5, 5), 
			"length-5 prefix test: LHS correct?",
			1, PtsPer);
	  TEST_RET_MESSAGE(eq2array(lsts[0], right5, 1), 
			"length-5 prefix test: RHS correct?",
			1, PtsPer);
	  cleanup();



  }
  END


  report();

}

  
