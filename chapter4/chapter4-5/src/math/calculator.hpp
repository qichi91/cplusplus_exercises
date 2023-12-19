#pragma once
class Complex;

// 1. Calculatorクラスは、Complexクラスをfriendとして持つ
// 2. Calculatorクラスは、2つのComplexクラスを引数に持つmultiplyメソッドを作成する
//    このメソッドは、2つのComplexを受け取り、それらを乗算したComplexを返す
//     このメソッドはComplexクラスのフレンドメンバ関数として実装する
class Calculator
{
public:
    Calculator() = default;
    ~Calculator() = default;

    // 2つのComplexを受け取り、それらを乗算したComplexを返す
    Complex multiply(const Complex &c1, const Complex &c2) const;
};