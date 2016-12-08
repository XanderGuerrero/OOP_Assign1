//FileName:		assign1.cpp
//Project:		assign1
//Author:		Alex Guerrero	
//Date:			jan 24, 2014
//Description:	This program uses overloaded functions to assess individual student grades
//				inputted by the user.  The program then calculates a final average and displays it back to the user.
//				The input can be a single numerical grade as a floating point number, a string and an array of integers.



//Include files
#include"assessGrade.h"




//variables for use in program, initialized
int main()
{
	int grades[5] = {0};
	char userInput[80] = {0};
	double finalMark = 0.0;
	double finalOverallGrade = 0.0;
	char string[80];
	char exit = 0;
	int flag = 0;
	int noDataFlag = 0;
	int i = 0;
	
	//while loops set to help control flow of program
	while(1)
	{
		while(1)
		{
			while(1)
			{
				//This portion of code displays to the user the instructions for valid input and how 
				//to exit the porgram if desired.  Input is accepted by using cin.getline; the data is then 
				//stored in userInput[80].
				cout << "\n" << endl;
				cout << "Please enter your grades as either:\n\n" << endl;
				cout << "1) A number ranging from 0.0 to 100.0\n" << endl;
				cout << "2) A letter grade\n" << endl;
				cout << "3) One number grade for every assignment completed (5 total)\n" << endl;
				cout << "Press 'X' to exit the program\n" << endl;
				cin.getline(userInput, 80);

				//if the array is empty display invalid input and restart program
				if(userInput[0] == NULL)
				{
					cout << "Invalid input\n" << endl;
					break;
				}

				cout << "\n";
				//if the array is not empty,  determine if a '.' is detected inside
				//and set flag for use in a series of if statements.  The input is 
				//then passed to another function processString() to determine if 
				//the user has entered an exit condition.  If so, the loop is exited
				//and the code jumps to a switch statement to determine the proper 
				//exit path.
				flag = findDot(userInput);
				processString(userInput, &exit, string);
				if(exit == 'a')
				{
					break;
				}
				//If the decimal '.' is detected, the floating point number is extracted
				//using atof() and passed to assessGrade() to determine the students 
				//final average.....................
				//If the final average is less than 0 or greater than 100, the final overall
				//average is changed to 0.00 and the exit value is set to 'a'.  Otherwise, exit
				//is set to 'b' and breaks out of the loop.
				if(flag == 0)
				{
					finalMark = atof(userInput);
					finalOverallGrade = assessGrade(finalMark);
					if(finalOverallGrade < 0.00 || finalOverallGrade > 100.0)
					{
						finalOverallGrade = 0.00;
						exit = 'd';
					}
					else 
					{
						exit = 'b';
					}
					break;
				}

				//If the flag returned from findDout() is set to 1, the input is assumed
				//to be interger data because no alpha characters were detected and no '.' 
				//was detected.  The user input is then passed to the fill array to fill
				//a integer array with the values entered by the user.
				if(flag == 1)
				{
					fillArray(userInput, grades, &exit);
					//If exit equals 'd', no input was extracted and the program breaks 
					//out of the loop and restarts, reprompting the user.
					if(exit == 'd')
					{
						cout << "no input detected\n" << endl;
						break;
					}
					//If integers were extracted into the array, the array is passed to
					// assessGrade to determine the final overall average.  When the value 
					//is returned, the program breaks and flows to the switch statement
					finalOverallGrade = assessGrade(grades);
					break;
				}
				//If the flag returned from findDout() is set to 2, the input is assumed
				//to be string data because alpha characters were detected and no '.' 
				//was detected.  The user string input is then passed to assessGrade() to determine 
				//the final average or special situation the student is in.
				if(flag == 2)
				{
					finalOverallGrade = assessGrade(letterGrade, kGradesConditions, userInput);
					//If a special situation was detected, assign 'd' to exit
					//and break out of the loop
					if(finalOverallGrade == -3.0)
					{
						exit = 'd';
						break;
					}
					/*if(finalOverallGrade == -1.0)
					{
						exit = 'a';
						break;
					}*/
					//If no match was found, set exit to 'c' and break out of the loop
					else if(finalOverallGrade == -2.0)
					{
						exit = 'c';
						break;
					}
					//if a match was detected and an average determined, assign 'b' to exit
					//and break out of the loop
					exit = 'b';
					break;
				}
			}
			break;
		}
		//The following code uses a switch statement to determine the exit path of the program.
		//Based on the user input exit has been set to follow through one of these paths.  If exit 
		//equals 'a', the user entered 'x' or 'X' to exit the program. if 'b' was set, an average
		//was determined an either a pass pr fail statement will be displayed.  If 'c' was assigned,
		//Invalid input was detected and the program will loop to reprompt the user. If 'd' was 
		//assigned, a special situation was detected and the program will loop again.
		switch(exit)
		{
			case 'a': 
					break;
			case 'b':
					if(finalOverallGrade >= kThreshold)
					{
						printf("Student achieved %.2f%% which is a pass condition\n\n", finalOverallGrade);
					}
					if(finalOverallGrade < kThreshold)
					{
						printf("Student achieved %.2f%% which is a fail condition\n\n", finalOverallGrade);
					}
				
					break;
			case 'c':
					cout << "Invalid Input\n" << endl;
					break;
			case 'd':
					break;
		}
		//if exit was chosen break out of outer most loop, exit program
		if(exit == 'a')
		{
			break;
		}
	}

	cout << "\n";
	
	return 0;
}



