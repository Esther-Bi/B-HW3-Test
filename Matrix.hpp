#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#ifndef MY_HEADER
#define MY_HEADER

namespace zich{

    class Matrix{
        private:
            int rows;
            int columns;
            std::vector<double> mat;
        public:
            Matrix(vector<double> , int , int);
            Matrix(zich::Matrix const & other);

            int get_rows();
            int get_columns();
            vector<double> get_mat();
            Matrix operator + (Matrix &);
            Matrix operator - (Matrix &);
            friend Matrix operator * (double const & , Matrix); //  סקלר לפני הכפל
            Matrix operator * (double); // סקלר אחרי הכפל
            Matrix operator * (Matrix &); // כפל מטריצות
            Matrix& operator *= (Matrix &);
            Matrix& operator *= (double);
            Matrix& operator += (Matrix &);
            Matrix& operator -= (Matrix &);
            bool operator == (Matrix const &)const;
            bool operator != (Matrix const &)const;
            bool operator <= (Matrix const &)const;
            bool operator >= (Matrix const &)const;
            bool operator < (Matrix const &)const;
            bool operator > (Matrix const &)const;
            friend Matrix operator + (Matrix &); // unari
            friend Matrix operator - (Matrix &); // unari
            friend std::ostream& operator << (std::ostream& os , Matrix const &);
            friend std::istream& operator >> (std::istream& os , Matrix const &);
            Matrix& operator ++();
            Matrix& operator ++(int);
            Matrix& operator --(int);
            Matrix& operator --();
            ~Matrix();

    };

}

#endif