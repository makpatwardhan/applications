#include "gtest/gtest.h"
#include <iostream>

namespace
{
class myTestFixture1: public testing::Test
{ 

public: 
   myTestFixture1() 
	{
 
       // initialization code here
   	} 

   

   ~myTestFixture1( )  { 
       // cleanup any pending stuff, but no exceptions allowed
   }

   // put in any custom data members that you need 
};

TEST_F (myTestFixture1, UnitTest1) 
{
}
} 
   



