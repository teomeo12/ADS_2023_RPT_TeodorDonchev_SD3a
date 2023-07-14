#include "pch.h"
#include "CppUnitTest.h"
#include "../orderedArr.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ADS2023RPTTEST
{
	
	TEST_CLASS(OrderedArrayTest)
	{
	public:
		//test push function with int
		TEST_METHOD(TestPushInt)
		{

			OrderedArray<int> arr(5, 1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			Assert::AreEqual(arr.length(), 5);
			arr.push(2);
			Assert::AreEqual(arr.length(), 6);
			Assert::AreEqual(arr.sumOfTwoElements(), 8);

		}
		//test push function with double
		TEST_METHOD(TestPushDouble)
		{
			OrderedArray<double> arr(5, 1);
			arr.push(6.4);
			arr.push(2.3);
			arr.push(2.1);

			Assert::AreEqual(arr.length(), 3);
			Assert::AreEqual(arr.sumOfTwoElements(), 4.4,0.01);
			Assert::AreNotEqual(arr.sumOfTwoElements(), 4.5,0.01);
			
		}
		//test push function with float
		TEST_METHOD(TestPushFloat)
		{

			OrderedArray<float> arr2(5, 1);
			arr2.push(3.4f);
			arr2.push(1.3f);
			arr2.push(23.1f);

			Assert::AreEqual(arr2.length(), 3);
			Assert::AreEqual(arr2.sumOfTwoElements(), 4.7f);
			Assert::AreNotEqual(arr2.sumOfTwoElements(), 4.8f);
		}
		//test clear function
		TEST_METHOD(TestClear)
		{

			OrderedArray<int> arr(5, 1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			Assert::AreEqual(arr.length(), 5);
			arr.clear();
			Assert::AreEqual(arr.length(), 0);
			
		}
		//test length function
		TEST_METHOD(TestLength)
		{
			
			OrderedArray<int> arr(5, 1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			Assert::AreEqual(arr.length(), 5);
		}

		//test getGrowSize function
		/*TEST_METHOD(TestGetGrowSize)
		{
			OrderedArray<int> arr(5, 1);
			Assert::AreEqual(arr.capacity(), 5);
			Assert::AreEqual(arr.getGrowSize(), 1);
			
			OrderedArray<int> arr2(5, 2);
			Assert::AreEqual(arr2.getGrowSize(), 1);

		}*/

		//test getelement function
		TEST_METHOD(TestGetElement)
		{
			OrderedArray<int> arr(5, 1);
			arr.push(42);
			arr.push(32);
			arr.push(26);
			arr.push(69);
			arr.push(1);
			
			Assert::AreEqual(arr.getElement(0), 1);
			Assert::AreEqual(arr.getElement(1), 26);
			Assert::AreEqual(arr.getElement(2), 32);
			Assert::AreEqual(arr.getElement(3), 42);
			Assert::AreEqual(arr.getElement(4), 69);

		}

		// exception test with a lambda function	
		/*TEST_METHOD(TestExeptions)
		{
			OrderedArray<int> arr(5, 0);
			void(*funct)() = [] {OrderedArray<int>arr(5, 0); };
			Assert::ExpectException<invalid_argument>(funct);
		}*/
		//test the default constructor
		TEST_METHOD(TestDefaultConstructor)
		{
			OrderedArray<int> arr;
			Assert::AreEqual(arr.length(), 0);
			Assert::AreEqual(arr.capacity(), 0);
			Assert::AreEqual(arr.getGrowSize(), 1);

		}
		//test the custom constructor
		TEST_METHOD(TestCustomConstructor)
		{
			OrderedArray<int> arr(5, 1);
			Assert::AreEqual(arr.length(), 0);
			Assert::AreEqual(arr.capacity(), 5);
			Assert::AreEqual(arr.getGrowSize(), 1);
			arr.push(2);
			arr.push(3);
			Assert::AreNotEqual(arr.length(), 1);
			Assert::AreEqual(arr.length(), 2);
			Assert::AreEqual(arr.capacity(), 5);
			Assert::AreEqual(arr.getGrowSize(), 1);

			
		}
		//test the constructor exeptions with zero values
		TEST_METHOD(ConstructorExceptionTestZero)
		{

			void(*funct)() = [] {OrderedArray<int>arr(0, 5); };
			Assert::ExpectException<invalid_argument>(funct);

			void(*funct1)() = [] {OrderedArray<int>arr(5, 0); };
			Assert::ExpectException<invalid_argument>(funct1);
			
		}
		//test the exeptions with negative values
		TEST_METHOD(ConstructorWithNegativeSize) {
			
		void(*funct)() = [] {OrderedArray<int>arr(-1,5); };
		Assert::ExpectException<invalid_argument>(funct);

		void(*funct1)() = [] {OrderedArray<int>arr(5, -1); };
		Assert::ExpectException<invalid_argument>(funct1);
			
		}
		

	};
}