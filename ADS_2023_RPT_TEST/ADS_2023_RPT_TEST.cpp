#include "pch.h"
#include "CppUnitTest.h"
#include "../orderedArr.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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

		}
		//test push function with double
		TEST_METHOD(TestPushDouble)
		{
			OrderedArray<double> arr1(5, 1);
			arr1.push(6.4);
			arr1.push(2.3);
			arr1.push(2.1);

			Assert::AreEqual(arr1.length(), 3);
		}
		//test push function with float
		TEST_METHOD(TestPushFloat)
		{

			OrderedArray<float> arr2(5, 1);
			arr2.push(3.4f);
			arr2.push(1.3f);
			arr2.push(23.1f);

			Assert::AreEqual(arr2.length(), 3);
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
			//test length function
			OrderedArray<int> arr(5, 1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			Assert::AreEqual(arr.length(), 5);
		}

		// exception test with a lambda function	
		TEST_METHOD(TestExeptions)
		{
			OrderedArray<int> arr(0, 0);
			void(*funct)() = [] {OrderedArray<int>arr(); };
			Assert::ExpectException<invalid_argument>(funct);
		}



	};
}