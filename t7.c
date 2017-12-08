
#include "header.c"



/**
  TEST SUIT t7.

     FUNCTIONS:  
		filter_leq
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
  printf("TEST SUITE t7.c RESULTS FOR FUNCTIONS: \n\n");
  printf("         lst_filter_leq\n");
  printf("########################################\n\n");


  START("lst_filtr_leq", 20); 
  {
	int i;

	  PtsPer = 2.0;


	  lsts[0] = arr2list(a5[0], 5);
	  lsts[1] = lst_filter_leq(lsts[0], 0);
	  TEST_RET_MESSAGE(lst_is_empty(lsts[1]), 
			"test case with empty filtered list",
			1, PtsPer);

	  TEST_RET_MESSAGE(eq2array(lsts[0], a5[0], 5), 
			"empty filtered list: is given list intact?",
			1, PtsPer);


	 cleanup();
	  lsts[0] = arr2list(a5[0], 5);
	  lsts[1] = lst_filter_leq(lsts[0], 9);
	
	  TEST_RET_MESSAGE(lst_is_empty(lsts[0]), 
			"test case where everything is LEQ: given list empty?", 
			1, PtsPer);

	  TEST_RET_MESSAGE(eq2arrayP(lsts[1], a5[0], 5), 
			"test case where everything is LEQ: returned list correct?", 
			1, PtsPer);

	cleanup();

	{
	 int a[] = {2, 0, 2, 2, 0, 0, 2, 0};
	 int leq[] = {0, 0, 0, 0};
	 int gt[] = {2, 2, 2, 2};

	 lsts[0] = arr2list(a, 8);
	 lsts[1] = lst_filter_leq(lsts[0], 1);

	  TEST_RET_MESSAGE(eq2arrayP(lsts[1], leq, 4), 
			"test: 4 0's, 4 2's; cutoff=1 - is LEQ correct?",
			1, PtsPer);
	 
	  TEST_RET_MESSAGE(eq2arrayP(lsts[0], gt, 4), 
			"test: 4 0's, 4 2's; cutoff=1 - is right-side correct?",
			1, PtsPer);

	}
	cleanup();
	{
	 int a[] = {10, 8, 6, 4, 2, 0};
	 int leq[] = {4, 2, 0};
	 int gt[] = {10, 8, 6};

	 lsts[0] = arr2list(a, 6);
	 lsts[1] = lst_filter_leq(lsts[0], 5);

	 lsts[2] = arr2list(leq, 3); // leq list
	 lsts[3] = arr2list(gt, 3); // greater-than list

	  TEST_RET_MESSAGE(same_contents(lsts[1], lsts[2], 1),
			"test: [10 8 6 4 2 0]; cutoff=5 - is LEQ correct?",
			1, PtsPer);
	 
	  TEST_RET_MESSAGE(same_contents(lsts[0], lsts[3], 1),
			"test: [10 8 6 4 2 0]; cutoff=5 - is RHS correct?",
			1, PtsPer);
	}
	cleanup();
	{
	 int i;

	 lsts[0] = lst_create();
	 lsts[2] = lst_create();  // zeros
	 lsts[3] = lst_create();  // twos
	 for(i=0; i<1000; i++) {
		lst_push_front(lsts[0], 2);
		lst_push_front(lsts[0], 0);
		lst_push_front(lsts[2], 0);
		lst_push_front(lsts[3], 2);
	 }
	 lsts[1] = lst_filter_leq(lsts[0], 1);
	  TEST_RET_MESSAGE(are_equal_destructive(lsts[1], lsts[2]),
			"test: 1000 0's, 1000 2's; cutoff=1 - is LEQ correct?",
			1, PtsPer);

	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[3]),
			"test: 1000 0's, 1000 2's; cutoff=1 - is RHS correct?",
			1, PtsPer);
	
	 }	


  }
  END


  report();

}

  
