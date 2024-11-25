#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRecursive
{
    TEST_CLASS(UnitTestRecursive)
    {
    public:

        TEST_METHOD(TestCountCriteriaElements) {
            int arr[5] = { 1, 2, 3, -4, 5 };
            Assert::AreEqual(3, CountCriteriaElements(arr, 5));
        }

        TEST_METHOD(TestSumCriteriaElements) {
            int arr[5] = { 1, 2, 3, -4, 5 };
            Assert::AreEqual(9, SumCriteriaElements(arr, 5));
        }

        TEST_METHOD(TestReplaceCriteriaElementsWithZero) {
            int arr[5] = { 1, 2, 3, -4, 5 };
            ReplaceCriteriaElementsWithZero(arr, 5);
            Assert::AreEqual(0, arr[0]);
            Assert::AreEqual(2, arr[1]);
            Assert::AreEqual(0, arr[2]);
            Assert::AreEqual(-4, arr[3]);
            Assert::AreEqual(0, arr[4]);
        }
    };
}