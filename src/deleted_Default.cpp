/****************************************************************************************************/
/*                                                                                                  */
/* @module        : Cpp 11 features examples                                                        */
/* @file          : deleted&default.cpp                                                             */
/* @brief         : This is the sample code explaning deleted and default functions                 */
/* @input         :                                                                                 */
/* @outpu         :                                                                                 */
/* @date       	  : 17-September-2017                                                               */
/* @author        : Pratik Patil                                                                    */
/* License        :                                                                                 */
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
/*
 * Description :
 * default -
 *   C++11 introduced "default" keyword to help instruct compiler to generate the default implementation
 *   for the function. Defaulted functions have two advantages: They are more efficient than manual
 *   implementations, and they rid the programmer from the chore of defining those functions manually.
 *
 * delete :
 *   The opposite of a defaulted function is a deleted function. Deleted functions are useful for
 *   preventing object copying, among the rest. Recall that C++ automatically declares a
 *   copy constructor and an assignment operator for classes. To disable copying, we can instruct
 *   compiler not generate these two special member functions, using delete keyword.
 */

struct defaultConstructorStruct
{
  defaultConstructorStruct () = default; //default constructor
  virtual
  ~defaultConstructorStruct () = default;
  //default distructor
  int intVal;
  float floatVal;
};

struct deletedCopyStructError
{
  //using delete here, is also deleteding default constructor.
  deletedCopyStructError &
  operator = (const deletedCopyStructError &) = delete;
  deletedCopyStructError (const deletedCopyStructError &) = delete;
};

struct deletedCopyStruct
{
  deletedCopyStruct () = default;
  deletedCopyStruct &
  operator = (const deletedCopyStruct &) = delete;
  deletedCopyStruct (const deletedCopyStruct &) = delete;
  virtual
  ~deletedCopyStruct () = default;
};

int
main (int argc, char* argv[])
{
  defaultConstructorStruct a; // This will call compiler generated default constructor
  deletedCopyStruct d;

  //  deletedCopyStruct error (d);   // This will be an error as copy constructor is deleted.
  //deletedCopyStructError e;     //This line will cause error as there is no default constructor provided

  return 0;
}
