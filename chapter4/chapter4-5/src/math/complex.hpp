#pragma once

#include <iostream>
#include "calculator.hpp"

// Complexクラスは、複素数を表すクラスである
// 以下の要件を満たすこと
// 1. Complexクラスは、double型のm_realとm_imaginaryをメンバ変数として持つ
// 2. Complexクラスは、m_realとm_imaginaryをコンストラクタで初期化する
// 3. displayメソッドを作成する
//    このメソッドは、"Complex: "の後にm_realとm_imaginaryの値を出力する

class Complex
{
private:
    double m_real;
    double m_imaginary;

public:
    // コンストラクタ
    Complex(double real, double imaginary);

    // m_realを取得する
    double getReal() const;

    // m_imaginaryを取得する
    double getImaginary() const;

    // m_realとm_imaginaryを出力する
    void display() const;
};
