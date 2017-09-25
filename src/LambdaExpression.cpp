/****************************************************************************************************/
/*                                                                                                  */
/* @module        : Cpp 11 features examples                                                        */
/* @file          : LambdaExpressn.cpp                                                              */
/* @brief         : This is the sample code explaning lambda expressions                            */
/* @input         :                                                                                 */
/* @outpu         :                                                                                 */
/* @date       	  : 25-Aug-2017                                                                     */
/* @author        : Pratik Patil                                                                    */
/* License        :                                                                                  */
/*               Copyright (C) 2017  Pratik Patil                                                   */
/*                                                                                                  */
/*               This program is free software: you can redistribute it and/or modify               */
/*               it under the terms of the GNU General Public License Version 3 as published by     */
/*               the Free Software Foundation.                                                      */
/*                                                                                                  */
/*               This program is distributed in the hope that it will be useful,                    */
/*               but WITHOUT ANY WARRANTY; without even the implied warranty of                     */
/*               MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                      */
/*               GNU General Public License for more details.                                       */
/*                                                                                                  */
/*               You should have received a copy of the GNU General Public License                  */
/*               along with this program.  If not, see <http://www.gnu.org/licenses/>.              */
/****************************************************************************************************/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * Description :
 * In C++11, a lambda expression—often called a lambda—is a convenient way of defining an anonymous
 * function object right at the location where it is invoked or passed as an argument to a function.
 * Typically lambdas are used to encapsulate a few lines of code that are passed to algorithms or
 * asynchronous methods.
 *
 * A lambda expression has the form:
 *
 * 	[capture](parameters)->return-type {body}
 *
 *	captures 	- 	a comma-separated list of zero or more captures, optionally beginning with a capture-default.
 *	Capture list can be passed as follows (see below for the detailed description):
 *	 [a,&b] where a is captured by copy and b is captured by reference.
 *	 [this] captures the current object (*this) by reference
 *	 [&] captures all automatic variables used in the body of the lambda by reference and current object by reference if exists
 *	 [=] captures all automatic variables used in the body of the lambda by copy and current object by reference if exists
 *	 [] captures nothing
 *
 *	 A variable can be used without being captured if it does not have automatic storage duration
 *	 (i.e. it is not a local variable or it is static or thread local) or if it is not odr-used in the body of the lambda.
 *
 *	params 	- 	The list of parameters, as in named functions, except that default arguments are not allowed
 *
 *	ret 	- 	Return type. If not present it's implied by the function return statements (or void if it doesn't return any value)
 *
 *	body 	- 	Function body
 */

///
/// simple lambda expression using single char to convert it into upper case
/// note that this lambda returns nothing as well as captures nothing
///
void
toUppserCase (string& s)
{
  cout << " Converted to all uppercase: ";
  for_each (s.c_str (), s.c_str () + s.size (), [] (char c)
    {
      cout << (char)toupper(c);
    });
  cout << endl;
}

///
/// Lambda expression that captures single int value
///
void
countUpperCase (string& s)
{
  int Uppercase = 0; //modified by the lambda
  for_each (s.c_str (), s.c_str () + s.size (),
	    [/*capture*/&Uppercase] (/*parameters*/char c)
	      {
		/*body*/
		if (isupper(c))
		Uppercase++;
	      });
  cout << Uppercase << " uppercase letters in: " << s << endl;
}

///
/// Lambda expression that captures multiple values
///
void
findMinMax (int* arr, int size)
{
  int min (0);
  int max (0);
  cout << "Array : { ";
  for_each (arr, arr + size, [&min, &max] (int a)
    {
      cout << a << ", ";
      if(min > a)
      min = a;

      if(max < a)
      max = a;
    });
  cout << " }" << endl << "Min : " << min << "\nMax : " << max << endl;
}

///
/// Lambda expression that returns value
///
void
findFirst (vector<int> arr, int num)
{
  vector<int>::iterator p = find_if (arr.begin (), arr.end (), [num](int i)->int
    {
      return i > num;
    });
  cout << "First number greater than " << num << " is : " << *p << endl;
}

int
main (int argc, char* argv[])
{
  int retVal (0);
  string s = "Hello World!";
  countUpperCase (s);
  toUppserCase (s);

  int arr[] =
    { 1, 2, 4, 5, 7, 8 };
  findMinMax (arr, sizeof(arr) / sizeof(*arr));
  vector<int> vec (arr, arr + sizeof(arr) / sizeof(*arr));
  findFirst (vec, 3);

  ///
  /// Another way of executing lambda
  ///

  auto lambda = [](void) -> void
    { cout << "Code within a lambda expression" << endl;};
  lambda ();
  return retVal;
}
