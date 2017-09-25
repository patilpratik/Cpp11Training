/****************************************************************************************************/
/*                                                                                                  */
/* @module        : Cpp 11 features examples                                                        */
/* @file          : deleted&default.cpp                                                             */
/* @brief         : This is the sample code explaning rvalue references                             */
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
#include <cstring>
/*
 * Description:
 *   Reference types in C++03 can only bind to lvalues. C++11 introduces a new category of
 *   reference types called rvalue references. Rvalue references can bind to rvalues,
 *   e.g. temporary objects and literals.
 *
 *   The primary reason for adding rvalue references is move semantics. Unlike traditional copying,
 *   moving means that a target object pilfer the resources of the source object, leaving the
 *   source in an “empty” state. In certain cases where making a copy of an object is both expensive
 *   and unnecessary, a move operation can be used instead.
 */

/// Lets see how this move semantics can improve performance of string swapping
class myString
{

public:
  char* m_data;
  size_t m_size;
  myString ()
  {
    m_size = 0;
    m_data = nullptr;
  }
  myString (const char* ptr)
  {
    std::cout << "Using char* to \"" << ptr << "\"" << std::endl;
    m_size = strlen (ptr) + 1;
    m_data = new char[m_size];
    memcpy (m_data, ptr, m_size);
  }
  ~myString ()
  {
    delete[] m_data;
  }
  // Simple copy constructor
  myString (const myString& str)
  {
    std::cout << "Using copy constructor" << std::endl;
    m_size = str.m_size;
    m_data = new char[m_size];
    memcpy (m_data, str.m_data, m_size);
  }

  // rvalue ref
  myString (myString&& str)
  {
    std::cout << "Using rvalue reference" << std::endl;
    m_data = str.m_data;
    m_size = str.m_size;
    str.m_data = nullptr;
  }

//
// This operator will do necessary memory allocations to add two strings
//
  myString
  operator + (const myString& str)
  {
    std::cout << "Adding two strings" << std::endl;
    myString temp;
    temp.m_size = this->m_size + str.m_size - 1;
    temp.m_data = new char[temp.m_size];
    memcpy (temp.m_data, this->m_data, this->m_size);
    // temp.m_data + this->m_size - 1 is the location of the '\0'.
    memcpy (temp.m_data + this->m_size - 1, str.m_data, str.m_size);

    return temp;
  }
};
int
main (int argc, char* argv[])
{
  char arr[] = "This is data";
  char arr2[] = ".. And this is appended later";
  myString data (arr);
  myString appended (arr2);

  myString empty (std::move (myString
    { }));
  // This will invoke rvalue ref constructor hence reducing memory allocation operation
  myString stringFromRvalue (std::move (data + appended));

  for (int i = 0; i < 10; ++i)
    {
      std::cout << ".";
    }
  std::cout << std::endl;
  std::cout << stringFromRvalue.m_data << std::endl;

  return 0;
}
