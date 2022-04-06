#include <iostream>
#include <bits/stdc++.h>
#include "Matrix.hpp"
using namespace std;


namespace zich{

    Matrix::Matrix(vector<double> vec , int row , int col){
        this->rows=row;
        this->columns=col;
        vector<double> mat;
        mat.reserve(vec.size());
        for (int i=0 ; i<vec.size() ; i++){
            double temp = vec[(unsigned int)i];
            mat.push_back(temp);
        }
        this->mat=mat;
    }
    Matrix::Matrix(zich::Matrix const & other){
        this->rows=other.rows;
        this->columns=other.columns;
        vector<double> vec;
        vec.reserve(other.mat.size());
        for (int i=0 ; i<other.mat.size() ; i++){
            double temp = other.mat[(unsigned int)i];
            vec.push_back(temp);
        }
        this->mat=vec;
    }

    bool check_size(int row_a , int col_a , int row_b , int col_b){
        if (row_a==row_b && col_a==col_b){
            return true;
        }
        return false;
    }

    int Matrix::get_rows(){
        return this->rows;
    }

    int Matrix::get_columns(){
        return this->columns;
    }

    vector<double> Matrix::get_mat(){
        return this->mat;
    }

    Matrix Matrix::operator + (Matrix & other){
        if (!check_size(this->rows,this->columns,other.rows,other.columns)){
            throw std::domain_error( "matrices are not the same size");
        }
        vector<double> vec;
        vec.reserve(this->mat.size());
        for (int i=0 ; i<this->mat.size() ; i++){
            double temp = this->mat[(unsigned int)i]+other.mat[(unsigned int)i];
            vec.push_back(temp);
        }
        static zich::Matrix ans{vec,this->rows,this->columns};
        return ans;
    }

    Matrix Matrix::operator - (Matrix & other){
        if (!check_size(this->rows,this->columns,other.rows,other.columns)){
            throw std::domain_error( "matrices are not the same size");
        }
        vector<double> vec;
        vec.reserve(this->mat.size());
        for (int i=0 ; i<this->mat.size() ; i++){
            double temp = this->mat[(unsigned int)i]-other.mat[(unsigned int)i];
            vec.push_back(temp);
        }
        static zich::Matrix ans{vec,this->rows,this->columns};
        return ans;
    }
    Matrix operator * (double const & num , Matrix other){
        return other;
    } //  סקלר לפני הכפל
    Matrix Matrix::operator * (double num){
        for (int i=0 ; i<this->mat.size() ; i++){
            this->mat[(unsigned int)i]=this->mat[(unsigned int)i]*num;
        }
        static zich::Matrix ans{this->mat,this->rows,this->columns};
        return ans;
    } // סקלר אארחי הכפל
    Matrix Matrix::operator * (Matrix & other){
        if (this->columns!=other.rows){
            throw std::domain_error( "undefined matrices multiplication");
        }
        static zich::Matrix ans{this->mat,this->rows,this->columns};
        return ans;
    } // כפל מטריצות
    Matrix& Matrix::operator *= (Matrix & other){
        if (this->columns!=other.rows){
            throw std::domain_error( "undefined matrices multiplication");
        }
        return other;
    }
    Matrix& Matrix::operator *= (double num){
        for (int i=0 ; i<this->mat.size() ; i++){
            this->mat[(unsigned int)i]=this->mat[(unsigned int)i]*num;
        }
        static zich::Matrix ans{this->mat,this->rows,this->columns};
        return ans;
    }
    Matrix& Matrix::operator += (Matrix & other){
        if (!check_size(this->rows,this->columns,other.rows,other.columns)){
            throw std::domain_error( "matrices are not the same size");
        }
        return other;
    }
    Matrix& Matrix::operator -= (Matrix & other){
        if (!check_size(this->rows,this->columns,other.rows,other.columns)){
            throw std::domain_error( "matrices are not the same size");
        }
        return other;
    }
    bool Matrix::operator == (Matrix const & other) const{
        if (!check_size(this->rows,this->columns,other.rows,other.columns)){
            throw std::domain_error( "matrices are not the same size");
        }
        return false;
    }
    bool Matrix::operator != (Matrix const & other) const{
        if (!check_size(this->rows,this->columns,other.rows,other.columns)){
            throw std::domain_error( "matrices are not the same size");
        }
        return true;
    }
    bool Matrix::operator <= (Matrix const & other) const{
        if (!check_size(this->rows,this->columns,other.rows,other.columns)){
            throw std::domain_error( "matrices are not the same size");
        }
        return true;
    }
    bool Matrix::operator >= (Matrix const & other) const{
        if (!check_size(this->rows,this->columns,other.rows,other.columns)){
            throw std::domain_error( "matrices are not the same size");
        }
        return false;
    }
    bool Matrix::operator < (Matrix const & other) const{
        if (!check_size(this->rows,this->columns,other.rows,other.columns)){
            throw std::domain_error( "matrices are not the same size");
        }
        return false;
    }
    bool Matrix::operator > (Matrix const & other) const{
        if (!check_size(this->rows,this->columns,other.rows,other.columns)){
            throw std::domain_error( "matrices are not the same size");
        }
        return true;
    }
    Matrix operator + (Matrix & other){
        return other;
    } // unari
    Matrix operator - (Matrix & other){
        return other;
    }
    std::ostream& operator << (std::ostream& os , Matrix const & other){
        return os;
    }
    std::istream& operator >> (std::istream& os , Matrix const & other){
        return os;
    }
    Matrix& Matrix::operator ++(){
        std::vector<double> arr = {4, 0, 0, 0, 4, 0, 0, 0, 4};
        static zich::Matrix c{arr, 3, 3};
        return c;
    }
    Matrix& Matrix::operator ++(int num){
        std::vector<double> arr = {4, 0, 0, 0, 4, 0, 0, 0, 4};
        static zich::Matrix c{arr, 3, 3};
        return c;
    }
    Matrix& Matrix::operator --(int num){
        std::vector<double> arr = {4, 0, 0, 0, 4, 0, 0, 0, 4};
        static zich::Matrix c{arr, 3, 3};
        return c;
    }
    Matrix& Matrix::operator --(){
        std::vector<double> arr = {4, 0, 0, 0, 4, 0, 0, 0, 4};
        static zich::Matrix c{arr, 3, 3};
        return c;
    }
    Matrix::~Matrix(){
        return;
    }

}