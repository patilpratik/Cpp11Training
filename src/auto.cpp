/****************************************************************************************************/
/*                                                                                                  */
/* @module        : Cpp 11 features examples                                                        */
/* @file          : auto.cpp                                                                        */
/* @brief         : This is the sample code explaning auto and decltype                             */
/* @input         :                                                                                 */
/* @outpu         :                                                                                 */
/* @date       	  : 16-September-2017                                                               */
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
#include <initializer_list>
#include <vector>
#include <algorithm>
/*
 * Description :
 * In C++11, compiler can detect type of objects automatically. The new auto and decltype facilities
 * detect the type of an object automatically, thereby paving the way for cleaner and more intuitive
 * function declaration syntax. This helps in simplify the design of generic code,
 * improve code readability, and reduce maintenance overhead.
 */

void
func (void)
{
  std::cout << "Func is called" << std::endl;
}
void
func2 (void)
{
  std::cout << "Func2 is called" << std::endl;
}

/*
 *  auto
 */

///
/// This function demonstrates use of auto. Although its fairly simple, there are few things to remember
/// Read them inline in the function below
///
void
simpleAuto (void)
{
  ///
  /// Following are some simple usage of auto
  ///
  auto x = 0;   // with integers
  std::cout << x << std::endl;

  const auto PI = 3.14;   // with real numbers
  std::cout << PI << std::endl;

  // while defining case of class objects such as std::string, we need to include the name of the class
  // in the initializer to disambiguate the code. Otherwise, the quoted literal string “hello universe”
  // would be construed as const char[15]
  auto msg = std::string ("hello universe");
  std::cout << msg << std::endl;

  auto dirty = true;    // with boolean
  if (dirty)
    std::cout << "It's dirty" << std::endl;

  auto p = new char[1024]; // with pointers
  std::cout << p << std::endl;

  auto distance = 10000000000LL; // with huge numbers
  std::cout << distance << std::endl;

  auto pf = func;
  pf ();

}
///
/// If you want to declare cv-qualified objects, you have to provide the const and volatile qualifiers
/// in the auto declaration itself. That’s because the compiler can’t tell whether the initializer 3.14
/// is plain double, const double, volatile double, or const volatile double
///
void
qualifiedAuto (void)
{
  volatile auto i = 5; //volatile int
  std::cout << i << std::endl;

  auto volatile const flag = true; //const volatile bool
  if (flag)
    std::cout << "flag is true" << std::endl;

  auto const y = 'a'; //const char
  std::cout << y << std::endl;
}

///
/// To declare an auto array, enclose the initializers in braces. The compiler counts the number of
/// initializers enclosed and uses that information to determine the size (and dimensions) of the array
///
void
arrayAuto (void)
{
  auto iarr =
    { 0, 1, 2, 3 }; //int [4]

  std::cout << std::endl << "printing iarr" << std::endl;
  for (const int& a : iarr)
    {
      std::cout << a << "\t";
    }
}

/*
 * The new operator decltype captures the type of an expression. You can use decltype to store the type of
 * an object, expression, or literal value. In this sense, decltype is the complementary operation of auto
 * – whereas auto instructs the compiler to fill-in the omitted type, decltype “uncovers” the type of an object:
 */

/*
 *  decltype
 */
void
simpleDecltype (void)
{
  auto x = 0;  //int

  decltype (x) z = x; //same as auto z=x;

  typedef decltype (x) XTYPE; //XTYPE is a synonym for int

  XTYPE y = 5;
  std::cout << std::endl << "Printing y in simpleDecltyp : " << y << std::endl;
}
///
/// decltype with vector
///

void
realUseDecltyp (void)
{
  std::vector<int> vf;

  vf.push_back (0);
  vf.push_back (1);
  vf.push_back (2);
  typedef decltype(vf.begin()) ITER;

  std::cout << "Printing vf : " << std::endl;
  for (ITER it = vf.begin (); it < vf.end (); it++)

    std::cout << *it << std::endl;
}

///
/// function declaration
/// In the new function declaration notation, the return type appears after the closing parenthesis
/// of the parameter list and is preceded by a -> sign. For example:
/// This style is useful in template functions where the return type depends on the
/// template-id (the actual template instance). Thus, template functions can define a generic
/// return type using the new notation and decltype.
///
auto
newfunc (bool b)->decltype(b) //C++11 style function declaration

{
  return b;
}

template<class T>
  auto
  get_end (std::vector<T>& v) ->decltype(v.end())

  {
    return v.end ();
  }

int
main (int argc, char* argv[])
{
  simpleAuto ();
  qualifiedAuto ();
  arrayAuto ();
  simpleDecltype ();
  realUseDecltyp ();
  if (newfunc (true))
    {
      std::cout << "newfunc returned true" << std::endl;
    }

  std::vector<int> vi;
  vi.push_back (0);
  vi.push_back (1);

  std::cout << "Using template with decltype to loop in vector" << std::endl;
  std::for_each (vi.begin (), get_end (vi), [](int a)
    {
      std::cout << a << std::endl;
    });
  return 0;
}
