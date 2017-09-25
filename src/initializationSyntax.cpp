/****************************************************************************************************/
/*                                                                                                  */
/* @module        : Cpp 11 features examples                                                        */
/* @file          : initializationSyntax.cpp                                                        */
/* @brief         : This is the sample code explaning new initialization syntax                     */
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
#include <vector>
#include <map>
#include <algorithm>

/*
 * Description :
 * In C++ prior to 11,
 * 1) C++ has at least four different initialization notations, some of which overlap.
 * 2) C++03 you can’t initialize POD array members and POD arrays allocated using new[]
 *
 * C++11 cleans up initialization syntax with a uniform brace notation
 */

class C
{
  int a;
  int b;
  int c = 7; // In class initialization of members
public:
  C (int i, int j) :
      a (i), b (j)
  {
  }
  ;
};

///
/// C++11 allows class member array to be initialized in initializer list
///
class X
{
  int a[4];
public:
  X () :
      a
	{ 1, 2, 3, 4 }
  {
  } //member array initializer
};

///
/// Initializing stl containers with ease. No need to have lots of push_back.
///
void
stlContainersInitialization ()
{
  std::vector<std::string> vs=
    { "first", "second", "third"};
  std::for_each(vs.begin(),vs.end(),[](std::string s)
	{
	  std::cout << s << "\t" <<std::endl;
	});

  std::map<std::string,std::string> singers =
    {
	{ "Lady Gaga", "+1 (212) 555-7890"},
	{ "Beyonce Knowles", "+1 (212) 555-0987"}};
  std::for_each(singers.begin(),singers.end(),[]( std::pair<std::string, std::string> s)
	{
	  std::cout << s.first << "\t" << s.second << std::endl;
	});
}
int
main (int argc, char* argv[])
{
  C c
    { 0, 0 }; //Equivalent to: C c(0,0);

  int* a = new int[3]
    { 1, 2, 0 };

  X x;
  stlContainersInitialization ();
  return 0;
}
