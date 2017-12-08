
#include "header.c"



/**
  TEST SUIT t2.

     FUNCTIONS:  
		lst_print_rev
		lst_reverse
		lst_clone
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

  printf("TEST SUITE t2.c RESULTS FOR FUNCTIONS: \n");
  printf("         lst_print_rev\n");
  printf("         lst_reverse\n");
  printf("         lst_clone\n");
  printf("########################################\n\n");


  START("lst_print_rev", 15); 
  {
	  lsts[0] = arr2list(a5[0], 5);
	  lsts[1] = lst_create();  // empty list


	  PtsPer = 5.0;
	  MANUAL(lst_print_rev(lsts[0]), "5 4 3 2 1", PtsPer);
	  // make sure they didn't actually reverse the list!
	  MANUAL(lst_print_rev(lsts[0]), "5 4 3 2 1", PtsPer);

	  MANUAL(lst_print_rev(lsts[1]), "[] (empty)", PtsPer);

  }
  END_MANUAL



  START("lst_reverse", 20); 

	  PtsPer = 5;

	  lsts[0] = arr2list(a5[0], 5);
	  lst_reverse(lsts[0]);
	  TEST_RET_MESSAGE(eq2array(lsts[0], a5[1], 5), "rev([1,2,3,4,5]) test", 
		 1,  PtsPer);
	  lst_free(lsts[0]);

	  lsts[0] = arr2list(a5[0], 5);
	  lst_reverse(lsts[0]);
	  lst_reverse(lsts[0]);
	  TEST_RET_MESSAGE(eq2array(lsts[0], a5[0], 5), "double-reverse test", 
		 1,  PtsPer);
	  lst_free(lsts[0]);

	  lsts[0] = arr2list(a5[0], 5);
	  lsts[1] = arr2list(a5[1], 5);
	  lst_reverse(lsts[0]);
	  lst_push_back(lsts[0], 99);
	  lst_push_back(lsts[1], 99);

	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[1]), 
		"reverse+push_back test", 1,  PtsPer);

	  lst_free(lsts[0]);
	  lst_free(lsts[1]);

	  lsts[0] = lst_create();
	  lsts[1] = lst_create();

	  lst_reverse(lsts[0]);
	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[1]), 
		"reverse: empty-list test", 1,  PtsPer);

  END


  START("lst_clone", 15.0);

	  PtsPer = 3;


	  lsts[0] = lst_create();
	  lsts[1] = lst_clone(lsts[0]);
	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[1]), 
		"clone: empty-list test", 1,  PtsPer);

	  cleanup();
	  lsts[0] = one_to_n_lst(100);
	  lsts[1] = lst_clone(lsts[0]);
	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[1]), 
		"clone: [1, 2. ... 100]  test", 1,  PtsPer);

	  cleanup();
	  lsts[0] = one_to_n_lst(100);
	  lsts[1] = lst_clone(lsts[0]);

	  TEST_RET_MESSAGE(lst_length(lsts[1]), 
		"clone: length  test", 100,  PtsPer);


	  cleanup();
	  lsts[0] = one_to_n_lst(5);
	  lsts[1] = lst_clone(lsts[0]);
	  lst_push_back(lsts[1], 99);

	  TEST_RET_MESSAGE(lst_length(lsts[0]), 
		"clone+push_back length test 2", 5,  PtsPer);
	  TEST_RET_MESSAGE(lst_length(lsts[1]), 
		"clone+push_back length test 2", 6,  PtsPer);

	  MANUAL(lst_print(lsts[0]), "[1 2 3 4 5]", 2.5);

	  MANUAL(lst_print(lsts[1]), "[1 2 3 4 5 99]", 2.5);
	  

  END

  report();

}

  
