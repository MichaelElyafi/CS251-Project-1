
#include "header.c"



/**
  TEST SUIT t3.

     FUNCTIONS:  
		lst_from_array
		lst_to_array
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

  printf("TEST SUITE t3.c RESULTS FOR FUNCTIONS: \n");
  printf("         lst_from_array\n");
  printf("         lst_to_array\n");
  printf("########################################\n\n");


  START("lst_from_array", 15); 
  {
	  PtsPer = 5.0;
	  lsts[0] = lst_from_array(a5[0], 5);

	  TEST_RET_MESSAGE(eq2array(lsts[0], a5[0], 5), "from_array([1 2 3 4 5])",
		1, PtsPer);

	  cleanup();

	  lsts[0] = lst_from_array(a5[0], 5);
	  TEST_RET_MESSAGE(lst_length(lsts[0]), "from_array - length test",
		5, PtsPer);

	  lsts[1] = arr2list(a5[0], 5);
	  lst_push_back(lsts[0], 99);
	  lst_push_back(lsts[1], 99);
	  TEST_RET_MESSAGE(are_equal_destructive(lsts[0], lsts[1]), 
		"from_array+push_back test", 1, PtsPer);

	  

  }
  END



  START("lst_to_array", 15); 

	  PtsPer = 15;

	  int *a;

	  lsts[0] = arr2list(a5[0], 5);
	  a = lst_to_array(lsts[0]);

	  TEST_RET_MESSAGE(arrays_eq(a5[0], a,  5), "lst_to_array([1,2,3,4,5]) test", 
		 1,  PtsPer);
	  TA_MESSAGE(" freeing array returned by lst_to_array\n \
                 If seg-fault results, apply 50% penalty to auto-graded score\n");

	  free(a);

  END


  report();

}

  
