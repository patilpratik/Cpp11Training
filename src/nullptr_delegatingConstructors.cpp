/****************************************************************************************************/
/*                                                                                                  */
/* @module        : Cpp 11 features examples                                                        */
/* @file          : deleted&default.cpp                                                             */
/* @brief         : This is the sample code explaning nullptr and delegated constructors            */
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
 * nullptr -
 *   Prior to this, a mactro NULL and literal 0 where used as null pointer. These hacks for null were
 *   not strongly-typed. Hence were bug-prone. Cpp11 has introduced "nullptr" keyword and it is
 *   strongly-typed. Hence it reduces bugs to great extent.
 *
 *   See these two function overloads for funct(). If I need to pass NULL to funct() then which
 *   overload should get invoked? Compiler cannot decide as both are valid. Hence it will throw a
 *   compilation error. Where as if I pass nullptr, it can very well invoke correct overload, that is
 *   funct(char* a).
 *
 */

void
funct (int a)
{
  std::cout << "Integer value is Passed :" << std::endl;
}

void
funct (char* a)
{
  std::cout << "Char pointer is Passed :" << std::endl;
}

/*
 * Delegating Constructors -
 *   In C++11 a constructor may call another constructor of the same class through initializer list
 *   In C++03, we had to call constructor in body, which means all the initializer list has to
 *   finish before we call other constructor. In short, object constructor has to be handled by
 *   the first constructor only. In C++ 11, we can delegate this with complete ownership of the
 *   construction process.
 */

class delegatingConstructor
{
public:
  delegatingConstructor () :
      delegatingConstructor (0)
  {
    //      delegatingConstructor(0);      // If we were using older c++, this is how we do it.
    std::cout << "delegatingConstructor()" << std::endl;
  }
  delegatingConstructor (int v)
  {
    std::cout << "delegatingConstructor(int)" << std::endl;
  }
};

int
main (int argc, char* argv[])
{
  funct (0);     // calls funct(int)
  //funct (NULL);  // compilation error
  funct (nullptr); // compiles

  // Here we are invoking default constructor, but as we have delegated construction to parameterized
  // constructor, object construction is completed by delegated constructor and then body of default
  // constructor gets executed. we can see this by the order in which constructors are called.
  delegatingConstructor dc;
  return 0;
}
