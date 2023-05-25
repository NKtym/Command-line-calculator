#include <stdlib.h>

#include <lib/Error.h>

#include <ctest.h>

CTEST(correctness_of_input_data, check_data){
	char* good = "1 + 2";
	char* bad = "1a + 2";
	int resultgood = correctness_of_input_data(good);
    	int resultbad = correctness_of_input_data(bad);
    	ASSERT_EQUAL(1, resultbad);
    	ASSERT_EQUAL(0, resultgood);
}

CTEST(check_for_expression_signs, check_signs){
	char* good = "1 + 2";
	char* bad = "1 ++ 2";
	char* bad2 = "1+6 + 2";
	int resultgood = check_for_expression_signs(good);
    	int resultbad = check_for_expression_signs(bad);
	int resultbad2 = check_for_expression_signs(bad2);
    	ASSERT_EQUAL(1, resultbad);
	ASSERT_EQUAL(1, resultbad2);
    	ASSERT_EQUAL(0, resultgood);
}

CTEST(check_for_expression_signs2, check_signs2){
	char* bad = "1 2 + 3";
	char* good = "1 + 2 + 3";
	int resultgood = check_for_expression_signs2(good);
    	int resultbad = check_for_expression_signs2(bad);
    	ASSERT_EQUAL(1, resultbad);
    	ASSERT_EQUAL(0, resultgood);
}
