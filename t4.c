
#include "header.c"



/**
  TEST SUIT t4.

     FUNCTIONS:  
		lst_pop_back
		lst_insert_sorted
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
  printf("TEST SUITE t4.c RESULTS FOR FUNCTIONS: \n");
  printf("         lst_pop_back\n");
  printf("         lst_insert_soted\n");
  printf("########################################\n\n");


  START("lst_pop_back", 15); 
  {
	  PtsPer = 15/4.0;
	  lsts[0] = arr2list(a5[0], 5);

	  TEST_RET(lst_pop_back(lsts[0]), 5, PtsPer);
	  cleanup();
	
	  lsts[0] = arr2list(a5[0], 5);
	  lst_pop_back(lsts[0]);

	  TEST_RET_MESSAGE(eq2array(lsts[0], a5[0], 4), 
			"test list after pop_back([1 2 3 4 5])", 
			1, PtsPer);

	  lsts[0] = arr2list(a5[0], 5);
	  lst_pop_back(lsts[0]);
	  TEST_RET_MESSAGE(lst_length(lsts[0]), 
			"length after pop-back test", 
			4, PtsPer);

	  cleanup();
	  
	  lsts[0] = arr2list(a5[0], 5);
	  lsts[1] = arr2list(a5[0], 4);
	
	  lst_push_back(lsts[1], 99);
	  lst_pop_back(lsts[0]);
	  lst_push_back(lsts[0], 99);


	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[1]), 
		"pop_back followed by push_back test", 
		1, PtsPer);

  }
  END



  START("lst_insert_sorted", 15); 
  {
	  int a0[]        = {5, 5, 6, 9, 12};
	  int a1[]        = {0, 5, 5, 6, 9, 12};  // insert front
	  int a2[]        = {5, 5, 6, 9, 12, 13}; // insert end
	  int a3[]        = {5, 5, 6, 7, 9, 12};  // insert middle (7)

	  int b[]        = {9, 11, 22, 9, 0, 0, 22, 0};
	  int b_sorted[] = {0, 0, 0, 9, 9, 11, 22, 22};

	  int i;

	  PtsPer = 3;


	  lsts[0] = arr2list(a0, 5);
	  lsts[1] = arr2list(a1, 6);
	  lst_insert_sorted(lsts[0], 0);
	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[1]), 
			"insert_sorted: new min case",
			1, PtsPer);
	  cleanup();

	  lsts[0] = arr2list(a0, 5);
	  lsts[1] = arr2list(a2, 6);
	  lst_insert_sorted(lsts[0], 13);
	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[1]), 
			"insert_sorted: new max case",
			1, PtsPer);
	  cleanup();

	  lsts[0] = arr2list(a0, 5);
	  lsts[1] = arr2list(a3, 6);
	  lst_insert_sorted(lsts[0], 7);
	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[1]), 
			"insert_sorted: middle insertion case",
			1, PtsPer);
	  cleanup();

	  lsts[0] = lst_create();
	  for(i=0; i<8; i++) {
		lst_insert_sorted(lsts[0], b[i]);
	  }

	  TEST_RET_MESSAGE(eq2array(lsts[0], b_sorted,  8), 
		"test inserting [9, 11, 22, 9, 0, 0, 22, 0] 1-by-1",
		 1,  PtsPer);

	  cleanup();
	  lsts[0] = arr2list(a0, 5);
	  lst_insert_sorted(lsts[0], 13);
	  lst_push_back(lsts[0], 99);
	  lsts[1] = arr2list(a2, 6);
	  lst_push_back(lsts[1], 99);
	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[1]), 
			"test:  push_back after insert_sorted",
			1, PtsPer);
	  cleanup();
	  
  }
  END


  report();

}

  
