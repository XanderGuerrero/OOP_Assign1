//FileName:		fileUtilities.c
//Project:		cA5
//Author:		Alex Guerrero	
//Date:			December 2, 2013
//Description:	This function works properly for files that are less than 2 billion bytes in size.  
//				The function retrieves the size of the file through the use of the WIN32_FIND_DATA structure and returns
//				the nfilesizelow field otherwise the function returns -1 if unsuccessful



//include files
#include"assessGrade.h"



//FunctionName: processString(char* userInput, char* p, char* string )
//Description:  This function scans the user input to determine if the
//				user has entered an exit program condition 'x' or 'X'.
//				If the user has entered an exit condition, a pointer to 
//				the variable exit is changed to 'a' for use in a switch 
//				statement for program exit purposes.  If the user has 
//				not entered an exit condition, no values are changed.
//Parameters:	char* userInput, char* p, char* string
//Return Values: values changed through reference
void processString(char* userInput, char* p, char* string )
{

	if(sscanf(userInput, "%s", string) == 1)
	{
		if((strcmp(string, "x") == 0) || (strcmp(string, "X") == 0))
		{
			*p = 'a';
		}
	}
	
}



//FunctionName: fillArray(char* userInput, int grades[], char* p)
//Description:  This function scans the string entered by the user for integer
//				numbers to extract and place inside of an array of ints called
//				grades[].
//Parameters:	char* userInput, int grades[], char* p
//Return Values:Enters values into grade array and exit variable in main by 
//				pass by reference method
void fillArray(char* userInput, int grades[], char* p)
{
	//Scan integer data into the array, if sscanf returns -1, no integers were detected
	//and the value of exit is changed to 'd' in main.  If Numbers were extracted, they
	//are placed into the array parameter and the value of exit is changed to 'b' in main
	if(sscanf(userInput, "%d%d%d%d%d", &grades[0], &grades[1], &grades[2], &grades[3], &grades[4]) == -1)
	{
		*p = 'd';
	}
	else
	{
		*p = 'b';
	}
}



//FunctionName:  findDot(char* userInput)
//Description:  This function searches an array for a '.'.  If found, a flag is set to 
//				zero.  If not found, flag is set to 2. flag is for use in an 'if' statement
//Parameters: userInput 
//Return Values: flag
int findDot(char* userInput)
{
	//variables initialized
	int textCount = 0;
	int i = 0;
	int flag = 1;

	//loop that will iterate through the users input element by element to 
	//detect a '.'. If it is detected, flag is set to zero and breaks out of the loop.
	//Then, if the first character is an alphabetic character, flag will be reset to 
	//2.  The function returns the flag value
	for(textCount = 0; textCount < (i = strlen(userInput)); ++textCount)
	{
		if(userInput[textCount] == '.')
		{				
			flag = 0;
			break;
		}
	}
	if(isalpha(userInput[0]) != 0)
	{
		flag = 2;
	}
	return flag;
}



//FunctionName: assessGrade(double finalGrade)
//Description:  assigns parameter value to score variable and returns that value
//Parameters: void
//Return Values: number
double assessGrade(double finalGrade)
{
	double score = 0.0;

	score = finalGrade;
	if(score > 100.0 || score < 0.0)
	{
		score = 0.0;
	}

	return score;
}



//FunctionName: double assessGrade(int grades[])
//Description:  This function uses a running total to add all of the numbers in the array
//				and divdes them by 5 to determine an average.  The total is then stored in
//				a double to convert the value to floating point.
//Parameters: int grades[]
//Return Values: total
double assessGrade(int grades[])
{
	double total = 0.0;
	//total all values stored in array and place into total.
	total = (grades[0]) + (grades[1]) + (grades[2]) + (grades[3]) + (grades[4]);
	//divide total by 5 to determine average
	total = total/5;
	//if average is greater than 100 or less than 0, set total to 0
	if(total > 100 || total < 0)
	{
		total = 0;
	}
	return total;
}



//FunctionName: double assessGrade( const char letterGrade[][12], const int kGradesConditions, char *string )
//Description:  This function compares string data entered by a user and data stored in letterGrade[] array
//				to determine a match.  When a match is determined, the numeric average is retrieved from an
//				array that corresponds to the data entered.
//Parameters:  const char letterGrade[][12], const int kGradesConditions, char *string 
//Return Values: double finalMark
double assessGrade(const char letterGrade[][12], const int kGradesConditions, char *string)
{
	//variables used in function intialized
	int count = 0;
	int numberGrade[8] = {95, 85, 77, 72, 67, 62, 57, 50};
	char specialSituation[5][40] = {"Incomplete", "Withdrawl after drop/refund date", "Audit", "Did not attend", "In process"};
	double finalMark = 0.0;
	int noMatch = 0;

	//This section of code will loop through the string array letterGrade[]
	//to detect a match between the user input string and the strings stored
	//in the letterGrade[] array.  if a match is detected, the count number 
	//is entered into the numberGrade array or specialsituation array 
	//to retrieve the numeric grade or the special condition which is assined 
	//to finalMark.  If a special condition is detected, finalMark is assigned
	//-3.0 for use in determining the exit strategy and the user is prompted
	//with futher information on their status.
	//If there is no match between the users input and the stored data, finalMark 
	//is  assigned -2.0.  finalMark is then returned.
	for( count = 0; count < kGradesConditions; ++count)
	{
		if(strcmp(letterGrade[count], string) == 0)
		{
			if(count <= 7)
			{
				finalMark = numberGrade[count];
				break;
			}
			else
			{
				int newCount = 0;

				newCount = count - 8;
				cout << "Student has a special situation: " << specialSituation[newCount] << "\n" << endl;
				finalMark = -3.0;
				break;
			}
		}
		//increments, keeping track of how many 'non' matches have occurred
		++noMatch;
	}
	if(noMatch == 13)
	{
		finalMark = -2.0;
	}
	return finalMark;
}



//FunctionName: double testStringFunction(int test, const char testInput[][20], const char letterGrade[][12], char string[], double result, 
//				const int kGradesConditions, int count, char expectedResults[][40])
//Description:  This function displays expected results of the function assessGrade(const char letterGrade[][12], const int kGradesConditions, 
//				char *string)'s behaviour vs. the actual returned result.  If there is a match and assessGrade() returns an average, the test 
//				passed, otherwise the test failed.
//Parameters:	double testStringFunction(int test, const char testInput[][20], const char letterGrade[][12], char string[], double result, 
//				const int kGradesConditions, int count, char expectedResults[][40]
//Return Values: testValue
double testStringFunction(int test, const char testInput[][20], const char letterGrade[][12], char string[], double result, const int kGradesConditions, int count, char expectedResults[][40])
{
	//variables
	double testValue = 0.00;

	while(testValue == 0.00)
	{
		//Display test information
		printf("TEST %d - normal test of assessGrade(char *string)\n", test);
		printf("submitting %s as the student's mark\n", testInput[count]);
		//display expected results
		printf("Expect result: student achieved  %s, which is a special condition\nActual result: ", expectedResults[count]);
		//perform test
		result = assessGrade( letterGrade, kGradesConditions, string );
		//If a special situation was detected, test passed, otherwise,
		//test failed
		if(result == -3.0)
		{
			if(result < kThreshold)
			{
				printf("which is a special condition\n\n");
				printf("**TEST PASSED**\n\n");
				break;
			}
			else
			{
				printf("which is a fail condition\n\n", result);
				printf("**TEST FAILED**\n\n");
				break;
			}
		}    
		//displays student average and whether it is a pass or fail condition 
		//The test result is also displayed to ther user
		printf("student achieved %.2f, ", result);
		if(result > kThreshold)
		{
			printf("which is a pass condition\n\n", result);
			printf("**TEST PASSED**\n\n");
			break;
		}
		else
		{
			printf("which is a fail condition\n\n", result);
			printf("**TEST FAILED**\n\n");
			break;
		}
	}
	//assign result to testValue to break out of loop
	testValue = result;

	return testValue;
}



//FunctionName: (double testStringFunction2(int test, const char testInput[][20], const char letterGrade[][12], char string[], double result, 
//				const int kGradesConditions, int count, char expectedResults[][40])
//Description:  This function displays expected results of the function assessGrade(const char letterGrade[][12], const int kGradesConditions, char *string)'s
//				behaviour vs. the actual returned result.  If assessGrade cannot find a string that matches the stored data and returns -2.0, the test 
//				passed, otherwise the test failed.
//Parameters:	double testStringFunction2(int test, const char testInput[][20], const char letterGrade[][12], char string[], double result, 
//				const int kGradesConditions, int count, char expectedResults[][40]
//Return Values: testValue
double testStringFunction2(int test, const char testInput[][20], const char letterGrade[][12], char string[], double result, const int kGradesConditions, int count, char expectedResults[][40])
{
	double testValue = 0.0;

	while(testValue == 0.0)
	{
		//Display test information
		printf("TEST %d - exception test of assessGrade(char *string)\n", test);
		printf("submitting -A as the student's mark\n", testInput[count]);
		//display expected results
		printf("Expect result: student achieved  %s, which is an invalid entry condition\n", expectedResults[count]);
		//perform test
		result = assessGrade( letterGrade, kGradesConditions, string );
		//display actual results
		printf("Actual result: student has achieved %.2f, student has ", result);
		printf("entered invalid input \n\n");
		//If a special situation was detected by assessGrade, test passed, otherwise,
		//test failed
		if(result == -2.0)
		{
			if(result < kThreshold)
			{
				printf("which is a pass condition\n\n");
				printf("**TEST PASSED**\n\n");
				break;
			}
			else
			{
				printf("which is a fail condition\n\n", result);
				printf("**TEST FAILED**\n\n");
				break;
			}
		}
	}
	//assign result to testValue to break out of loop
		testValue = result;

		return testValue;
}



//FunctionName: testArrayFunction3(int test, const char testInput[][20], double result, int count, int grades[], char expectedResults[][40])
//Description:  This function displays expected results of the function assessGrade(int grades[])'s behaviour vs. the actual returned result. 
//Parameters:	int test, const char testInput[][20], double result, int count, int grades[], char expectedResults[][40]
//Return Values: double testValue
double testArrayFunction3(int test, const char testInput[][20], double result, int count, int grades[], char expectedResults[][40])
{
	double testValue = 0.0;
	double value = 0.0;

	while(testValue == 0.0)
	{
		while(testValue == 0.00)
		{
			//for the tests 10, 11, 12, display this message. 
			//After that display the default message
			switch(test)
			{
				case 10:
				case 11:
				case 12:
						{
							printf("TEST %d - exception test of assessGrade(int grades)\n", test);
							break;
						}
				default:
						{
							printf("TEST %d - normal test of assessGrade(int grades)\n", test);
							break;
						}
			}
			break;
		}
		
		//diplay test information
		printf("submitting %s as the student's mark\n", testInput[count]);
		//display expected results
		printf("Expect result: student achieved %s ", expectedResults[count]);
		//check if expected result is a pass or fail condition
		value = atof(expectedResults[count]);
		if(value > kThreshold)
		{
			printf("which is a pass condition\n");
		}
		if(value < kThreshold)
		{
			printf("which is a fail condition\n");
		}
		//perform test
		result = assessGrade(grades);
		//display actual results	
		printf("Actual results: student achieved %.2f, ", result);
		//if result is greater than or equal to 54.50, it is a pass condition
		if(result >= kThreshold)
		{
			printf("which is a pass condition\n\n");
		}
		else
		{
			printf("which is a fail condition\n\n", result);
		}
		//if value extracted is the same as the return value from assessGrade(),
		//test passed, otherwise failed
		if(value == result)
		{
			printf("**TEST PASSED**\n\n");
			break;
		}
		else
		{
			printf("**TEST FAILED**\n\n");
			break;
		}
	}
	//assign result to testValue to break out of loop
	testValue = result;

	return testValue;
}



//FunctionName: double testFunction4(int test, const char testInput[][20], double result, int count, char expectedResults[][40], double finalGrade)
//Description:  This function displays expected results of the function assessGrade(int grades[])'s behaviour vs. the actual returned result. 
//Parameters:	int test, const char testInput[][20], double result, int count, char expectedResults[][40], double finalGrade
//Return Values:double testValue
double testFunction4(int test, const char testInput[][20], double result, int count, char expectedResults[][40], double finalGrade)
{
	double value = 0.00;
	double testValue = -1.00;

	while(testValue == -1.00)
	{
		//for the tests 13, 14, 15, display this message, for case 16, 17, 18, display this message.
		//Otherwise, display this message. After that display the default message
		switch(test)
		{
			case 13:
			case 14:
			case 15:
					{
						printf("TEST %d - normal test of assessGrade(double finalGrade)\n", test);
						break;
					}
			case 16:
			case 17:
			case 18:
					{
						printf("TEST %d - exception test of assessGrade(double finalGrade)\n", test);
						break;
					}
			default:
					{
						printf("TEST %d - boundary test of assessGrade(double finalGrade)\n", test);
						break;
					}
		}
		//diplay test information
		printf("submitting %s as the student's mark\n", testInput[count]);
		//display expected results
		printf("Expect result: student achieved %s, ", expectedResults[count]);
		//check if expected result is a pass or fail condition
		value = atof(expectedResults[count]);
		if(value >= kThreshold)
		{
			printf("which is a pass condition\n");
		}
		if(value < kThreshold)
		{
			printf("which is a fail condition\n");
		}
		//perform test
		result = assessGrade(finalGrade);
		//display actual results
		printf("Actual results: student achieved %.2f, ", result);
		//if result is greater than or equal to 54.50, it is a pass condition
		if(result >= kThreshold)
		{
			printf("which is a pass condition\n\n");
		}
		if(result < kThreshold)
		{
			printf("which is a fail condition\n\n");
		}
		//if result equals value in expected results, test passed,
		//otherwise, test failed
		if(result == atof(expectedResults[count]))
		{
			printf("**TEST PASSED**\n\n");
			break;
		}
		else
		{
			printf("**TEST FAILED**\n\n");
			break;
		}
	}
	//assign result to testValue to break out of loop
	testValue = result;
	
	return testValue;
}