
#include "header.c"



/**
  TEST SUIT t8.

     FUNCTIONS:  
		merge_sorted
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
  printf("TEST SUITE t8.c RESULTS FOR FUNCTIONS: \n\n");
  printf("         lst_merge_sorted\n");
  printf("########################################\n\n");


  START("lst_merge_sorted", 20); 
  {
	int i;

	int a[] = {5, 7, 7, 10, 12};
	int b[] = {0, 1, 6, 11, 20};
	int ab[] = {0, 1, 5, 6, 7, 7, 10, 11, 12, 20, 99}; 

	int x[] = {1, 2, 3, 4, 5};
	int y[] = {6, 7, 8, 9, 10};
	int xy[] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	  PtsPer = 3.33333333333;


	  lsts[0] = arr2list(a, 5);
	  lsts[1] = arr2list(b, 5);
	  lsts[3] = arr2list(ab, 10);

	  lst_merge_sorted(lsts[0],lsts[1]);

	  TEST_RET_MESSAGE(lst_is_empty(lsts[1]), 
			"test case - 2nd list should be empty after merge",
			1, PtsPer);

	  TEST_RET_MESSAGE(eq2array(lsts[0], ab, 10), 
			"merge [5,7,7,10,12] & [0,1,6,11,20]?",
			1, PtsPer);

	cleanup();

	  lsts[0] = arr2list(a, 5);
	  lsts[1] = arr2list(b, 5);

	  lst_merge_sorted(lsts[0],lsts[1]);
	  lst_push_back(lsts[0], 99);
	  TEST_RET_MESSAGE(eq2array(lsts[0], ab, 11), 
			"Test push-back(99) after merge",
			1, PtsPer);


	 cleanup();
	  lsts[0] = arr2list(x, 5);
	  lsts[1] = arr2list(y, 5);
	  lst_merge_sorted(lsts[0], lsts[1]);
	
	  TEST_RET_MESSAGE(eq2array(lsts[0], xy, 10), 
			"merge [5,7,7,10,12] & [0,1,6,11,20]?",
			1, PtsPer);


	  cleanup();
	  lsts[0] = lst_create();   // empty
	  lsts[1] = arr2list(a, 5);
	  lst_merge_sorted(lsts[0], lsts[1]);
	  TEST_RET_MESSAGE(eq2array(lsts[0], a, 5), 
			"Test merge [] & [5 7 7 10 12]",
			1, PtsPer);

	  TEST_RET_MESSAGE(lst_is_empty(lsts[1]), 
			"test case - 2nd list should be empty after merge",
			1, PtsPer);


  }
  END


  report();

}

