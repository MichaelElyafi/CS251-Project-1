
#include "header.c"



/**
  TEST SUIT t5.

     FUNCTIONS:  
		lst_concat
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

int one_concat(LIST *a, int x) {
LIST *b;

  b = lst_create();
  lst_push_front(b, x);
  lst_concat(a, b);
  lst_free(b);
  return 1;
}

int main(){

  printf("\n########################################\n\n");
  printf("TEST SUITE t5.c RESULTS FOR FUNCTIONS: \n\n");
  printf("         lst_concat\n");
  printf("########################################\n\n");


  START("lst_concat", 15); 
  {
	int i;

	  PtsPer = 1.0;

	  int a[] = {1, 2, 3};
	  int b[] = {6, 7, 8};
	  int ab[] = {1, 2, 3, 6, 7, 8};

	  lsts[0] = arr2list(a, 3);
	  lsts[1] = arr2list(b, 3);
	  lsts[2] = arr2list(ab, 6);

	  lst_concat(lsts[0], lsts[1]);
	  TEST_RET_MESSAGE(lst_is_empty(lsts[1]), 
			"test: 2nd lst empty? ", 
			1, PtsPer);

	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[2]),
			"test concat([1,2,3],[6,7,8]) ", 
			1, PtsPer);

	  cleanup();
	  
	  lsts[0] = arr2list(a, 3);
	  lsts[1] = lst_create();
	  lsts[2] = arr2list(a, 3);
	  lst_concat(lsts[0], lsts[1]);
	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[2]),
			"empty 2nd list test: concat([1,2,3], []) ", 
			1, PtsPer);
	  
	  cleanup();
	  lsts[0] = arr2list(a, 3);
	  lsts[1] = lst_create();
	  lsts[2] = arr2list(a, 3);
	  lst_concat(lsts[0], lsts[1]);
	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[2]),
			"test with 2nd list given as empty ", 
			1, PtsPer);



	  cleanup();
	  lsts[0] = lst_create();
	  lsts[1] = arr2list(a, 3);
	  lsts[2] = arr2list(a, 3);
	  lst_concat(lsts[0], lsts[1]);
	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[2]),
			"test with 2nd list given as empty ", 
			1, PtsPer);

	  cleanup();
	  lsts[0] = arr2list(a, 3);
	  lsts[1] = lst_create();
	  lsts[2] = arr2list(a, 3);
	  lst_concat(lsts[0], lsts[1]);
	  lst_push_back(lsts[0], 99);
	  lst_push_back(lsts[2], 99);
	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[2]),
			"concat w/ empty list + push_back",
			1, PtsPer);

	  cleanup();
	  lsts[0] = arr2list(a, 3);
	  lst_concat(lsts[0], lsts[0]);
	  TEST_RET_MESSAGE(eq2array(lsts[0], a, 3),
			"test concatination with self (no-op)",
			1, PtsPer);

	  cleanup();
	  lsts[0] = lst_create();
	  lsts[1] = lst_create();
	  for(i=0; i<TIME_TRIALS; i++) {
	    lst_push_front(lsts[0], i);
	    lst_push_front(lsts[1], i);
	  }
	  for(i=0; i<TIME_TRIALS; i++) {
		lst_push_back(lsts[1], -1);
	  }

	  clock_t budget;
	  budget = 4 * calibrate_constant(TIME_TRIALS);

	  TIME(one_concat(lsts[0], -1), 1, budget, 7.0);

	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[1]), 
			"test correctness after many concats",
			1, PtsPer);
			


  }
  END


  report();

}

  
