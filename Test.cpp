#include "doctest.h"
#include "Matrix.hpp"
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

std::vector<double> build_random_vec(int row,int col){
	std::srand(unsigned(std::time(nullptr)));
	int num = row*col;
	std::vector<double> vec((unsigned long) num);
	std::generate(vec.begin(), vec.end(), std::rand);
    return vec;
}

std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};

TEST_CASE("Good input") {
	/***
	matrices are the same size, everything should run
	***/
	for (int i=1 ; i<5 ; i++){
		for (int j=1 ; j<5 ; j++){
			zich::Matrix a{build_random_vec(i,j) ,i ,j};
			zich::Matrix b{build_random_vec(i,j) ,i ,j};
			if (i==j){
				CHECK_NOTHROW(a*b);
				CHECK_NOTHROW(a*=b);
			}
			CHECK_NOTHROW(a+b);
			CHECK_NOTHROW(a-b);
			CHECK_NOTHROW(a*3);
			CHECK_NOTHROW(3*a);
			CHECK_NOTHROW(++a);
			CHECK_NOTHROW(a++);
			CHECK_NOTHROW(--a);
			CHECK_NOTHROW(a--);
			CHECK_NOTHROW(a*=3);
			CHECK_NOTHROW(a+=b);
			CHECK_NOTHROW(a-=b);
			CHECK_NOTHROW(bool ans=a==b);
			CHECK_NOTHROW(bool ans=a!=b);
			CHECK_NOTHROW(bool ans=a<=b);
			CHECK_NOTHROW(bool ans=a>=b);
			CHECK_NOTHROW(bool ans=a<b);
			CHECK_NOTHROW(bool ans=a>b);
			CHECK_NOTHROW(+a);
			CHECK_NOTHROW(-a);
		}
	}
}

TEST_CASE("Different size for + -") {
	/***
	matrices are not the same size for plus and minus operations
	***/
	for (int i=1 ; i<10 ; i++){
		for (int j=11 ; j<20 ; j++){
			zich::Matrix a{build_random_vec(i,j) ,i ,j};
			zich::Matrix b{build_random_vec(j,i) ,j ,i};
			CHECK_THROWS(a+b);
			CHECK_THROWS(a-b);
			CHECK_THROWS(a+=b);
			CHECK_THROWS(a-=b);
		}
	}
}

TEST_CASE("Different size for comparison operators") {
	/***
	matrices are not the same size for comparison operators
	***/
	for (int i=1 ; i<10 ; i++){
		for (int j=11 ; j<20 ; j++){
			zich::Matrix a{build_random_vec(i,j) ,i ,j};
			zich::Matrix b{build_random_vec(j,i) ,j ,i};
			CHECK_THROWS(bool ans= (a==b));
			CHECK_THROWS(bool ans= (a!=b));
			CHECK_THROWS(bool ans= (a<=b));
			CHECK_THROWS(bool ans= (a>=b));
			CHECK_THROWS(bool ans= (a<b));
			CHECK_THROWS(bool ans= (a>b));
		}
	}
}

TEST_CASE("Different size for matrices multiplication") {
	/***
	matrices are not the same size for matrices multiplication
	***/
	for (int i=1 ; i<10 ; i++){
		for (int j=1 ; j<10 ; j++){
			for (int k=11 ; k<20 ; k++){
			zich::Matrix a{build_random_vec(i,j) ,i ,j};
			zich::Matrix b{build_random_vec(k,j) ,k ,j};
				CHECK_THROWS(a*b);
				CHECK_THROWS(a*=b);
			}
		}
	}
}

TEST_CASE("Same size for matrices multiplication") {
	/***
	matrices are with good sizes for matrices multiplication
	***/
	for (int i=1 ; i<10 ; i++){
		for (int j=1 ; j<10 ; j++){
			for (int k=2 ; k<5 ; k++){
			zich::Matrix a{build_random_vec(i,j) ,i ,j};
			zich::Matrix b{build_random_vec(j,k) ,j ,k};
			CHECK_NOTHROW(a*b);
			CHECK_NOTHROW(a*=b);
			}
		}
	}
}

TEST_CASE("Actual good outputs comparison operators") {
	/***
	good outputs
	***/
	zich::Matrix a{identity, 3, 3};
	zich::Matrix b{arr, 3, 3};
	zich::Matrix c{arr, 3, 3};
	zich::Matrix d{identity, 3, 3};
	CHECK_EQ((a*b) == c, true);
	CHECK_EQ((a*b) != d, true);
	CHECK(a <= b);
	CHECK_FALSE(a >= b);
	CHECK(a<b);
	CHECK_FALSE(a>b);
	CHECK(b<=c);
	CHECK_FALSE(b>=c);
	CHECK(b == c);
	CHECK_FALSE(b != c);
}

TEST_CASE("Actual good outputs + -") {
	/***
	good outputs
	***/
	std::vector<double> arr4 = {4, 0, 0, 0, 4, 0, 0, 0, 4};
	std::vector<double> arr4M = {-4, 0, 0, 0, -4, 0, 0, 0, -4};
	std::vector<double> arr0 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	zich::Matrix a{identity, 3, 3};
	zich::Matrix b{arr, 3, 3};
	zich::Matrix c{arr4, 3, 3};
	zich::Matrix d{arr4M, 3, 3};
	zich::Matrix e{arr0, 3, 3};
	CHECK_EQ((a+b) == c, true);
	CHECK_EQ((c+a) == b, true);
	CHECK_EQ((a+=b) == c, true);
	CHECK_EQ((c-=b) == a, true);
	CHECK_EQ((d+e) == d, true);
	CHECK_EQ((d-e) == d, true);
	CHECK_EQ((d+=c) == e, true);
}

TEST_CASE("Actual good outputs *") {
	/***
	good outputs
	***/
	std::vector<double> arr15 = {15, 0, 0, 0, 15, 0, 0, 0, 15};
	std::vector<double> arr7 = {7, 0, 0, 0, 7, 0, 0, 0, 7};
	zich::Matrix a{identity, 3, 3};
	zich::Matrix b{arr, 3, 3};
	zich::Matrix c{arr15, 3, 3};
	zich::Matrix d{arr7, 3, 3};
	CHECK_EQ((a*7) == d, true);
	CHECK_EQ((7*a) == d, true);
	CHECK_EQ((a*b) == b, true);
	CHECK_EQ((a*=b) == b, true);
	CHECK_EQ((b*=5) == c, true);
}

TEST_CASE("Actual good outputs Unary") {
	/***
	good outputs
	***/
	std::vector<double> arrP = {-3, 4, 5, 0, 8, -9, 11, 7};
	std::vector<double> arrM = {3, -4, -5, 0, -8, 9, -11, -7};
	zich::Matrix a{arrP, 2, 4};
	zich::Matrix b{arrP, 2, 4};
	zich::Matrix c{arrM, 2, 4};
	CHECK_EQ((+a) == b, true);
	CHECK_EQ((-a) == c, true);
}