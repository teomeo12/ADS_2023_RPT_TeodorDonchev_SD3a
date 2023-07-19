#include "pch.h"
#include "CppUnitTest.h"
#include "../orderedArr.h"
#include "../myset.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ADS2023RPTTEST
{
	
	TEST_CLASS(OrderedArrayTest)
	{
	public:
		//test the default constructor
		TEST_METHOD(TestDefaultConstructor)
		{
			OrderedArray<int> arr;
			Assert::AreEqual(arr.length(), 0);
			Assert::AreEqual(arr.capacity(), 0);
			Assert::AreEqual(arr.getGrowSize(), 10);
			arr.push(2);
			arr.push(3);
			arr.push(4);
			arr.push(7);
			arr.push(4);
			arr.push(4);
			arr.push(8);
			arr.push(99);
			arr.push(40);
			arr.push(2);
			Assert::AreEqual(arr.length(), 10);
			Assert::AreEqual(arr.capacity(), 10);
			Assert::AreEqual(arr.getGrowSize(), 10);
			arr.push(23);
			arr.push(44);
			Assert::AreEqual(arr.length(), 12);
			Assert::AreEqual(arr.capacity(), 20);
			Assert::AreEqual(arr.getGrowSize(), 10);

		}
		//test the custom constructor
		TEST_METHOD(TestCustomConstructor)
		{
			OrderedArray<int> arr(5);
			Assert::AreEqual(arr.length(), 0);
			Assert::AreEqual(arr.capacity(), 0);
			Assert::AreEqual(arr.getGrowSize(), 5);
			arr.push(2);
			arr.push(3);
			Assert::AreNotEqual(arr.length(), 1);
			Assert::AreEqual(arr.length(), 2);
			Assert::AreEqual(arr.capacity(), 5);
			Assert::AreEqual(arr.getGrowSize(), 5);


		}

		//test the constructor exeptions with zero values
		TEST_METHOD(ConstructorExceptionTestZero)
		{

			void(*funct)() = [] {OrderedArray<int>arr(0); };
			Assert::ExpectException<invalid_argument>(funct);


		}

		//test the exeptions with negative values
		TEST_METHOD(ConstructorWithNegativeSize) {

			void(*funct)() = [] {OrderedArray<int>arr(-1); };
			Assert::ExpectException<invalid_argument>(funct);

		}

		//test push function with integers
		TEST_METHOD(TestPushInt)
		{

			OrderedArray<int> arr(1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			Assert::AreEqual(arr.length(), 5);
			arr.push(2);
			Assert::AreEqual(arr.length(), 6);
			Assert::AreEqual(arr.getGrowSize(), 1);
			Assert::AreEqual(arr.sumOfTwoElements(), 3);

		}

		//test push function with double
		TEST_METHOD(TestPushDouble)
		{
			OrderedArray<double> arr(2);
			arr.push(6.4);
			arr.push(2.3);
			arr.push(2.1);

			Assert::AreEqual(arr.length(), 3);
			Assert::AreEqual(arr.getGrowSize(), 2);
			Assert::AreEqual(arr.sumOfTwoElements(), 4.4, 0.001);
			Assert::AreNotEqual(arr.sumOfTwoElements(), 4.5, 0.001);

		}

		//test push function with float
		TEST_METHOD(TestPushFloat)
		{

			OrderedArray<float> arr2(10);
			arr2.push(3.4f);
			arr2.push(1.3f);
			arr2.push(23.1f);

			Assert::AreEqual(arr2.length(), 3);
			Assert::AreEqual(arr2.getGrowSize(), 10);
			Assert::AreEqual(arr2.sumOfTwoElements(), 4.7f);
			Assert::AreNotEqual(arr2.sumOfTwoElements(), 4.8f);
		}

		//test length function
		TEST_METHOD(TestLength)
		{

			OrderedArray<int> arr(1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			Assert::AreEqual(arr.length(), 5);
		}

		//test getGrowSize function
		TEST_METHOD(TestGetGrowSize)
		{

			OrderedArray<int> arr(2);
			Assert::AreEqual(arr.capacity(), 0);
			Assert::AreEqual(arr.getGrowSize(), 2);
			arr.push(1);
			arr.push(2);
			arr.push(3);
			arr.push(4);
			Assert::AreEqual(arr.capacity(), 4);
			Assert::AreEqual(arr.getGrowSize(), 2);

			OrderedArray<double> arr1(5);
			Assert::AreEqual(arr1.capacity(), 0);
			Assert::AreEqual(arr1.getGrowSize(), 5);
			arr1.push(1.2);
			arr1.push(2.3);
			arr1.push(3.4);
			arr1.push(5.6);
			arr1.push(7.8);
			arr1.push(9.0);
			Assert::AreEqual(arr1.capacity(), 10);
			Assert::AreEqual(arr1.getGrowSize(), 5);


			OrderedArray<float> arr2(10);
			Assert::AreEqual(arr2.capacity(), 0);
			Assert::AreEqual(arr2.getGrowSize(), 10);
			arr2.push(1.2f);
			arr2.push(2.3f);
			arr2.push(3.4f);
			arr2.push(5.6f);
			arr2.push(7.8f);
			arr2.push(9.0f);
			arr2.push(1.2f);
			arr2.push(2.3f);
			arr2.push(3.4f);
			arr2.push(5.6f);
			arr2.push(7.8f);
			Assert::AreEqual(arr2.capacity(), 20);
			Assert::AreEqual(arr2.getGrowSize(), 10);

		}

		//test getelement function
		TEST_METHOD(TestGetElement)
		{
			OrderedArray<int> arr(1);
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

		//test remove function

		TEST_METHOD(TestRemove)
		{

			OrderedArray<int> arr(1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			Assert::AreEqual(arr.length(), 5);
			arr.remove(2);
			Assert::AreEqual(arr.length(), 4);
			arr.push(7);
			arr.push(99);
			Assert::AreEqual(arr.length(), 6);

			OrderedArray<double> arr1(2);
			arr1.push(6.4);
			arr1.push(2.3);
			Assert::AreEqual(arr1.length(), 2);
			arr1.remove(0);
			arr.remove(0);
			Assert::AreEqual(arr1.length(), 1);
		}

		//test search 
		TEST_METHOD(TestSearch)
		{
			OrderedArray<int> arr(1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			Assert::AreEqual(arr.search(1), 0);
			Assert::AreEqual(arr.search(2), 2);
			Assert::AreEqual(arr.search(4), 3);
			Assert::AreEqual(arr.search(6), 4);
			Assert::AreNotEqual(arr.search(0), 0);
			Assert::AreEqual(arr.search(7), -1);
			Assert::AreEqual(arr.search(3), -1);
			
			

		}

		//test clear function
		TEST_METHOD(TestClear)
		{

			OrderedArray<int> arr(1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			Assert::AreEqual(arr.length(), 5);
			arr.clear();
			Assert::AreEqual(arr.length(), 0);

		}

		//test sumOfTwoElements function
		TEST_METHOD(TestSumOfTwoElements)
		{

			OrderedArray<int> arr(1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			Assert::AreEqual(arr.sumOfTwoElements(), 3);
			Assert::AreNotEqual(arr.sumOfTwoElements(), 4);
			Assert::AreNotEqual(arr.sumOfTwoElements(), 5);
			Assert::AreNotEqual(arr.sumOfTwoElements(), 6);

			OrderedArray<double> arr1(3);
			arr1.push(6.4);
			arr1.push(2.3);
			arr1.push(2.3);
			arr1.push(4.5);
			arr1.push(1.2);

			Assert::AreEqual(arr1.sumOfTwoElements(), 3.5);
			Assert::AreNotEqual(arr1.sumOfTwoElements(), 4.5);
			Assert::AreNotEqual(arr1.sumOfTwoElements(), 5.5);


		}

		//test operator == function
		TEST_METHOD(TestOperator)
		{
			//Same size Array of ints
			OrderedArray<int> arr(1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			OrderedArray<int> arr1(1);
			arr1.push(6);
			arr1.push(2);
			arr1.push(2);
			arr1.push(4);
			arr1.push(1);

			Assert::IsTrue(arr == arr1);

			//Different size Array of ints
			OrderedArray<int> arr2(1);
			arr2.push(6);
			arr2.push(2);
			arr2.push(2);
			arr2.push(4);
			arr2.push(1);
			arr2.push(1);

			Assert::IsFalse(arr == arr2);

			//Same size Array of doubles
			OrderedArray<double> arrDoubles(1);
			arrDoubles.push(6.4);
			arrDoubles.push(2.3);
			arrDoubles.push(2.3);
			arrDoubles.push(4.5);
			arrDoubles.push(1.2);

			OrderedArray<double> arrDoubles1(1);
			arrDoubles1.push(6.4);
			arrDoubles1.push(2.3);
			arrDoubles1.push(2.3);
			arrDoubles1.push(4.5);
			arrDoubles1.push(1.2);

			Assert::IsTrue(arrDoubles == arrDoubles1);

			//Different size Array of doubles
			OrderedArray<double> arrDoubles2(1);
			arrDoubles2.push(6.4);
			arrDoubles2.push(2.3);
			arrDoubles2.push(2.3);
			arrDoubles2.push(4.5);
			arrDoubles2.push(1.2);
			arrDoubles2.push(1.2);

			Assert::IsFalse(arrDoubles == arrDoubles2);
		}

		//test operator != function
		TEST_METHOD(TestOperatorNotEqual)
		{
			//Same size Array of ints
			OrderedArray<int> arr(1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			OrderedArray<int> arr1(1);
			arr1.push(6);
			arr1.push(2);
			arr1.push(2);
			arr1.push(4);
			arr1.push(1);

			Assert::IsFalse(arr != arr1);

			//Different size Array of ints
			OrderedArray<int> arr2(1);
			arr2.push(6);
			arr2.push(2);
			arr2.push(2);
			arr2.push(4);
			arr2.push(1);
			arr2.push(1);

			Assert::IsTrue(arr != arr2);

			//Same size array of doubles
			OrderedArray<double> arrDoubles(1);
			arrDoubles.push(6.4);
			arrDoubles.push(2.3);
			arrDoubles.push(2.3);
			arrDoubles.push(4.5);
			arrDoubles.push(1.2);

			OrderedArray<double> arrDoubles1(1);
			arrDoubles1.push(6.4);
			arrDoubles1.push(2.3);
			arrDoubles1.push(2.3);
			arrDoubles1.push(4.5);
			arrDoubles1.push(1.2);

			Assert::IsFalse(arrDoubles != arrDoubles1);

			//Different size array of doubles 
			OrderedArray<double> arrDoubles2(1);
			arrDoubles2.push(6.4);
			arrDoubles2.push(2.3);
			arrDoubles2.push(2.3);
			arrDoubles2.push(4.5);
			arrDoubles2.push(1.2);
			arrDoubles2.push(1.2);

			Assert::IsTrue(arrDoubles != arrDoubles2);
		}

		//test operator < function
		TEST_METHOD(TestOperatorLessThan)
		{
			//Same size Array of ints
			OrderedArray<int> arr(1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			OrderedArray<int> arr1(1);
			arr1.push(6);
			arr1.push(2);
			arr1.push(2);
			arr1.push(4);
			arr1.push(1);

			Assert::IsFalse(arr < arr1);

			//Different size Array of ints
			OrderedArray<int> arr2(1);
			arr2.push(6);
			arr2.push(2);
			arr2.push(2);
			arr2.push(4);
			arr2.push(1);
			arr2.push(1);

			Assert::IsTrue(arr < arr2);

			//Same size Array of doubles
			OrderedArray<double> arrDoubles(1);
			arrDoubles.push(6.4);
			arrDoubles.push(2.3);
			arrDoubles.push(2.3);
			arrDoubles.push(4.5);
			arrDoubles.push(1.2);

			OrderedArray<double> arrDoubles1(1);
			arrDoubles1.push(6.4);
			arrDoubles1.push(2.3);
			arrDoubles1.push(2.3);
			arrDoubles1.push(4.5);
			arrDoubles1.push(1.2);

			Assert::IsFalse(arrDoubles < arrDoubles1);

			//Different size Array of doubles
			OrderedArray<double> arrDoubles2(1);
			arrDoubles2.push(6.4);
			arrDoubles2.push(2.3);
			arrDoubles2.push(2.3);
			arrDoubles2.push(4.5);
			arrDoubles2.push(1.2);
			arrDoubles2.push(1.2);

			Assert::IsTrue(arrDoubles < arrDoubles2);
		}

		//test operator > function
		TEST_METHOD(TestOperatorGreaterThan)
		{
			//Same size Array of ints
			OrderedArray<int> arr(1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			OrderedArray<int> arr1(1);
			arr1.push(6);
			arr1.push(2);
			arr1.push(2);
			arr1.push(4);
			arr1.push(1);

			Assert::IsFalse(arr > arr1);

			//Different size Array of ints
			OrderedArray<int> arr2(1);
			arr2.push(6);
			arr2.push(2);
			arr2.push(2);
			arr2.push(4);
			arr2.push(1);
			arr2.push(1);

			Assert::IsFalse(arr > arr2);

			//Same size Array of doubles
			OrderedArray<double> arrDoubles(1);
			arrDoubles.push(6.4);
			arrDoubles.push(2.3);
			arrDoubles.push(2.3);
			arrDoubles.push(4.5);
			arrDoubles.push(1.2);

			OrderedArray<double> arrDoubles1(1);
			arrDoubles1.push(6.4);
			arrDoubles1.push(2.3);
			arrDoubles1.push(2.3);
			arrDoubles1.push(4.5);
			arrDoubles1.push(1.2);

			Assert::IsFalse(arrDoubles > arrDoubles1);

			//Different size Array of doubles
			OrderedArray<double> arrDoubles2(1);
			arrDoubles2.push(6.4);
			arrDoubles2.push(2.3);
			arrDoubles2.push(2.3);
			arrDoubles2.push(4.5);
			arrDoubles2.push(1.2);
			arrDoubles2.push(1.2);

			Assert::IsFalse(arrDoubles > arrDoubles2);
		}

		//test operator <= function
		TEST_METHOD(TestOperatorLessThanEqualTo)
		{
			//Same size Array of ints
			OrderedArray<int> arr(1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			OrderedArray<int> arr1(1);
			arr1.push(6);
			arr1.push(2);
			arr1.push(2);
			arr1.push(4);
			arr1.push(1);

			Assert::IsTrue(arr <= arr1);

			//Different size Array of ints
			OrderedArray<int> arr2(1);
			arr2.push(6);
			arr2.push(2);
			arr2.push(2);
			arr2.push(4);
			arr2.push(1);
			arr2.push(1);

			Assert::IsTrue(arr <= arr2);

			//Same size Array of doubles
			OrderedArray<double> arrDoubles(1);
			arrDoubles.push(6.4);
			arrDoubles.push(2.3);
			arrDoubles.push(2.3);
			arrDoubles.push(4.5);
			arrDoubles.push(1.2);

			OrderedArray<double> arrDoubles1(1);
			arrDoubles1.push(6.4);
			arrDoubles1.push(2.3);
			arrDoubles1.push(2.3);
			arrDoubles1.push(4.5);
			arrDoubles1.push(1.2);

			Assert::IsTrue(arrDoubles <= arrDoubles1);

			//Different size Array of doubles
			OrderedArray<double> arrDoubles2(1);
			arrDoubles2.push(6.4);
			arrDoubles2.push(2.3);
			arrDoubles2.push(2.3);
			arrDoubles2.push(4.5);
			arrDoubles2.push(1.2);
			arrDoubles2.push(1.2);

			Assert::IsTrue(arrDoubles <= arrDoubles2);
		}

		//test operator >= function
		TEST_METHOD(TestOperatorGreaterThanEqualTo)
		{
			//Same size Array of ints
			OrderedArray<int> arr(1);
			arr.push(6);
			arr.push(2);
			arr.push(2);
			arr.push(4);
			arr.push(1);

			OrderedArray<int> arr1(1);
			arr1.push(6);
			arr1.push(2);
			arr1.push(2);
			arr1.push(4);
			arr1.push(1);

			Assert::IsTrue(arr >= arr1);

			//Different size Array of ints
			OrderedArray<int> arr2(1);
			arr2.push(6);
			arr2.push(2);
			arr2.push(2);
			arr2.push(4);
			arr2.push(1);
			arr2.push(1);

			Assert::IsFalse(arr >= arr2);

			//Same size Array of doubles
			OrderedArray<double> arrDoubles(1);
			arrDoubles.push(6.4);
			arrDoubles.push(2.3);
			arrDoubles.push(2.3);
			arrDoubles.push(4.5);
			arrDoubles.push(1.2);

			OrderedArray<double> arrDoubles1(1);
			arrDoubles1.push(6.4);
			arrDoubles1.push(2.3);
			arrDoubles1.push(2.3);
			arrDoubles1.push(4.5);
			arrDoubles1.push(1.2);

			Assert::IsTrue(arrDoubles >= arrDoubles1);

			//Different size Array of doubles
			OrderedArray<double> arrDoubles2(1);
			arrDoubles2.push(6.4);
			arrDoubles2.push(2.3);
			arrDoubles2.push(2.3);
			arrDoubles2.push(4.5);
			arrDoubles2.push(1.2);
			arrDoubles2.push(1.2);

			Assert::IsFalse(arrDoubles >= arrDoubles2);
		}
	};

	TEST_CLASS(MySetTest)
	{
		//test MySet class

		//test push function for unique values
		TEST_METHOD(TestPushUnique)
		{
			MySet<int> set(1);
			set.push(1);
			set.push(2);
			set.push(3);
			set.push(4);
			set.push(5);

			Assert::AreEqual(set.length(), 5);
		}

		//test push function for non-unique values
		TEST_METHOD(TestPushNonUnique)
		{
			MySet<int> set(1);
			set.push(1);
			set.push(2);
			set.push(3);
			set.push(4);
			set.push(5);
			set.push(5);
			set.push(5);
			set.push(5);
			set.push(5);

			Assert::AreEqual(set.length(),5);
		}
	};
}