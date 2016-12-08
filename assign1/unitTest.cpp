//FileName:		unitTest.cpp
//Project:		assign1
//Author:		Alex Guerrero	
//Date:			jan 24, 2014
//Description:	This program tests the overloaded functions used to assess individual student grades
//				in the program assign1.cpp.  The program runs through test data to test expected results
//				with actual results to determine if the functions are functioning properly.  This is done 
//				with 4 functions that test and display submitted, expected and actual results.



//Include files
#include"assessGrade.h"



int main()
{
	//Variables used to store test data
	char string[80] = "";
	int grades[5] = {1,2,3,4,5};
	const char testInput[22][20] = {"A+", "DNA", "I", "-A", "Hello", "-I", "1,2,3,4,5", "80,20,0,0,0", "75,90,80,70,60", "75,-90,80,70,60", "-1,0,0,0,0", "-10,20,80,90,0", "42.37", "80.00", "76.20", "-23.50", "-234.10", "-0.01", "54.50", "0.00", "100.0"};
	char expectedResults[22][40] = {"95.00", "Did not attend", "Incomplete","-2.00", "-2.00", "-2.00","3.00", "20.00", "75.00", "39.00", "0.00", "36.00", "42.37", "80.00", "76.20", "0.00", "0.00", "0.00", "54.50", "0.00", "100.00"};
	double result = 0.00;
	double finalGrade = 42.37;
	int count = 0;
	int test = 1;
	double testValue = 0.00;
	int i = 0;


	//The following code prepares the functions test data for input into the different functions.  
	//The functions are then called with the test data and a return value is stored into testValue.


	//Normal Test for string version of assessGrade(string)
	//test 1.....................................................
	//input data
	strcpy(string, "A+");
	//This function test tests 
	testValue = testStringFunction( test, testInput,  letterGrade,  string, result,  kGradesConditions, count, expectedResults);

	//test 2.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	strcpy(string, "DNA");
	testValue = testStringFunction( test, testInput,  letterGrade,  string, result,  kGradesConditions, count, expectedResults);

	//test 3.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	strcpy(string, "I");
	testValue = testStringFunction( test, testInput,  letterGrade,  string, result,  kGradesConditions, count, expectedResults);
	
		
	//Exception Test for string version of assessGrade(string)
	//test 4.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	strcpy(string, "-A");
	testValue = testStringFunction2( test, testInput,  letterGrade,  string, result,  kGradesConditions, count, expectedResults);

	//test 5.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	strcpy(string, "Hello");
	testValue = testStringFunction2( test, testInput,  letterGrade,  string, result,  kGradesConditions, count, expectedResults);

	//test 6.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	strcpy(string, "-I");
	testValue = testStringFunction2( test, testInput,  letterGrade,  string, result,  kGradesConditions, count, expectedResults);
	
	//Normal Test for assignment version of assessGrade(int grades)
	//test 7.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	testValue = testArrayFunction3(test, testInput, result, count, grades, expectedResults);

	//test 8.....................................................
	//input data
	grades[0] = 80;
	grades[1] = 20;
	grades[2] = 0;
	grades[3] = 0;
	grades[4] = 0;
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	testValue = testArrayFunction3(test, testInput, result, count, grades, expectedResults);

	//test 9.....................................................
	//input data
	grades[0] = 75;
	grades[1] = 90;
	grades[2] = 80;
	grades[3] = 70;
	grades[4] = 60;
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	testValue = testArrayFunction3(test, testInput, result, count, grades, expectedResults);

	//Exception Test for assignment version of assessGrade(int grades)
	//test 10.....................................................
	//input data
	grades[0] = 75;
	grades[1] = -90;
	grades[2] = 80;
	grades[3] = 70;
	grades[4] = 60;
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	testValue = testArrayFunction3(test, testInput, result, count, grades, expectedResults);

	//test 11.....................................................
	//input data
	grades[0] = -1;
	grades[1] = 0;
	grades[2] = 0;
	grades[3] = 0;
	grades[4] = 0;
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	testValue = testArrayFunction3(test, testInput, result, count, grades, expectedResults);

	//test 12.....................................................
	//input data
	grades[0] = -10;
	grades[1] = 20;
	grades[2] = 80;
	grades[3] = 90;
	grades[4] = 0;
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	testValue = testArrayFunction3(test, testInput, result, count, grades, expectedResults);
	
	//Normal Test for double version of assessGrade(double finalGrade)
	//test 13.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	finalGrade = 42.37;
	testValue = testFunction4(test, testInput, result, count, expectedResults, finalGrade);

	//test 14.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	finalGrade = 80.00; 
	testValue = testFunction4(test, testInput, result, count, expectedResults, finalGrade);

	//test 15.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	finalGrade = 76.20;
	testValue = testFunction4(test, testInput, result, count, expectedResults, finalGrade);

	//exception Test for double version of assessGrade(double finalGrade)
	//test 16.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	finalGrade = -23.5;
	testValue = testFunction4(test, testInput, result, count, expectedResults, finalGrade);

	//test 17.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	finalGrade = -234.1;
	testValue = testFunction4(test, testInput, result, count, expectedResults, finalGrade);

	//test 18.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	finalGrade = -0.01;
	testValue = testFunction4(test, testInput, result, count, expectedResults, finalGrade);

	////boundary Test for double version of assessGrade(double finalGrade)
	//test 19.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	finalGrade = 54.50;
	testValue = testFunction4(test, testInput, result, count, expectedResults, finalGrade);

	//test 20.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	finalGrade = 0.00;
	testValue = testFunction4(test, testInput, result, count, expectedResults, finalGrade);

	//test 21.....................................................
	//increment arrays containing test data
	testInput[++i];
	++count;
	expectedResults[++i];
	++test;
	//input data
	finalGrade = 100.00;
	testValue = testFunction4(test, testInput, result, count, expectedResults, finalGrade);

return 0;
}