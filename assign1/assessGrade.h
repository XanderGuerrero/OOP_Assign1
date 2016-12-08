//FileName:		assessGrade.h
//Project:		assign1
//Author:		Alex Guerrero	
//Date:			january 24, 2014
//Description:	This program uses overloaded functions to assess individual student grades
//				inputted by the user.  The program then calculates a final average and displays it back to the user.
//				The input can be a single numerical grade as a floating point number, a string and an array of integers.



//Include files
#include<stdio.h>
#include<ctype.h>
#include<iostream>
#include<string>
using namespace std;



//disables a warning to allow the use of the getNum()
#pragma warning(disable: 4996)



//defined constants 
#define kThreshold  54.50
const int kGradesConditions = 13;
const char letterGrade[13][12] = {"A+", "A", "B+", "B", "C+", "C", "D", "F", "I", "Q", "AU", "DNA", "I/P"};



//Function prototypes
void processString(char *userInput, char* p, char* string );
int findDot(char* userInput);
void fillArray(char* userInput, int grades[], char* p);
double assessGrade(const char cities[][12],const int kGradesConditions, char *string);
double assessGrade(char* string);
double assessGrade(double finalGrade);
double assessGrade(int grades[]);
double testStringFunction(int test, const char testInput[][20], const char letterGrade[][12], char string[], double result, const int kGradesConditions, int count, char expectedResults[][40]);
double testStringFunction2(int test, const char testInput[][20], const char letterGrade[][12], char string[], double result, const int kGradesConditions, int count, char expectedResults[][40]);
double testArrayFunction3(int test, const char testInput[][20], double result, int count, int grades[], char expectedResults[][40]);
double testFunction4(int test, const char testInput[][20], double result, int count, char expectedResults[][40], double finalGrade);