## Chapter. 4

### 4-1. テンプレート関数
2つの数値を加算する関数addを作成してください。
関数addはテンプレートを用いて実装してください。


<details>
<summary>回答例</summary>

```
#include <iostream>

template <typename T>
T add(T v1, T v2)
{
    return v1 + v2;
}

int main() {
    int iValue_1 = 1;
    int iValue_2 = 5;
    int iValueAdd = add(iValue_1, iValue_2);
    std::cout << "iValueAdd : " << iValueAdd  << std::endl;

    double dValue_1 = 1.40;
    double dValue_2 = 4.560;
    double dValueAdd = add(dValue_1, dValue_2);
    std::cout << "dValueAdd : " << dValueAdd  << std::endl;

    return 0;
}
```

</details>



### 4-2. クラステンプレート
クラステンプレートを使用して、ジェネリックなStackクラスを実装してください。このStackクラスは異なる型のデータを格納できるように設計されます。

<details>
<summary>回答例</summary>

```
#include <iostream>
#include <vector>

template <typename T>
class Stack {
public:
    void push(const T& item) {
        data.push_back(item);
    }

    T pop() {
        if (!isEmpty()) {
            T item = data.back();
            data.pop_back();
            return item;
        } else {
            throw std::out_of_range("Stack is empty");
        }
    }

    bool isEmpty() const {
        return data.empty();
    }

private:
    std::vector<T> data;
};

int main() {
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    while (!intStack.isEmpty()) {
        std::cout << intStack.pop() << " ";
    }

    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");

    while (!stringStack.isEmpty()) {
        std::cout << stringStack.pop() << " ";
    }

    return 0;
}
```

</details>




### 4-3. テンプレートクラスと特殊化
ジェネリックなPairクラスを作成し、2つの要素を格納できるようにしてください。また、このPairクラスの特殊化を作成して、1つの要素だけを格納できるようにしてください。

<details>
<summary>回答例</summary>

```
#include <iostream>

// Generic Pair class
template <typename T, typename U>
class Pair {
public:
    Pair(const T& first, const U& second) : first(first), second(second) {}

    void display() const {
        std::cout << "Pair: (" << first << ", " << second << ")" << std::endl;
    }

private:
    T first;
    U second;
};

// Specialization for a Pair with a single element
template <typename T>
class Pair<T, void> {
public:
    Pair(const T& singleElement) : singleElement(singleElement) {}

    void display() const {
        std::cout << "Single Element Pair: (" << singleElement << ")" << std::endl;
    }

private:
    T singleElement;
};

int main() {
    Pair<int, std::string> pair1(42, "Hello");
    pair1.display();

    Pair<double, char> pair2(3.14, 'A');
    pair2.display();

    Pair<std::string, void> singleElementPair("World");
    singleElementPair.display();

    return 0;
}
```

</details>





### 4-4. オペレータオーバーロード
2次元ベクトルを表すVector2Dクラスを作成し、加算演算子（+）をオーバーロードして、2つのベクトルの和を計算するプログラムを書いてください。


<details>
<summary>回答例</summary>

```
#include <iostream>

class Vector2D {
public:
    Vector2D(double x, double y) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    void display() const {
        std::cout << "(" << x << ", " << y << ")";
    }

private:
    double x;
    double y;
};

int main() {
    Vector2D v1(1.0, 2.5);
    Vector2D v2(2.5, 3.0);

    Vector2D sum = v1 + v2;

    std::cout << "Sum of ";
    v1.display();
    std::cout << " and ";
    v2.display();
    std::cout << " is ";
    sum.display();
    std::cout << std::endl;

    return 0;
}
```

</details>


### 4-5. 友達関数
2つのクラスComplexとCalculatorを作成し、CalculatorクラスをComplexクラスの友達関数として、複素数の掛け算を計算するプログラムを書いてください。

<details>
<summary>回答例</summary>

```
#include <iostream>

class Complex;

class Calculator {
public:
    static Complex multiply(const Complex& a, const Complex& b);
};

class Complex {
public:
    Complex(double real, double imag) : real(real), imag(imag) {}

    void display() const {
        std::cout << real << " + " << imag << "i";
    }

    friend Complex Calculator::multiply(const Complex& a, const Complex& b);

private:
    double real;
    double imag;
};

Complex Calculator::multiply(const Complex& a, const Complex& b) {
    return Complex((a.real * b.real) - (a.imag * b.imag), (a.real * b.imag) + (a.imag * b.real));
}

int main() {
    Complex c1(2.0, 3.0);
    Complex c2(4.0, 5.0);

    Complex result = Calculator::multiply(c1, c2);

    std::cout << "Product of ";
    c1.display();
    std::cout << " and ";
    c2.display();
    std::cout << " is ";
    result.display();
    std::cout << std::endl;

    return 0;
}
```

</details>


### 4-6. コピーコンストラクタ
文字列を表すStringクラスを作成し、コピーコンストラクタを使用して新しいオブジェクトが既存のオブジェクトのコピーとして作成されるプログラムを書いてください。


<details>
<summary>回答例</summary>

```
#include <iostream>
#include <cstring>

class String {
public:
    String(const char* str) {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Copy constructor
    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    ~String() {
        delete[] data;
    }

    void display() const {
        std::cout << "String: " << data << ", Length: " << length << std::endl;
    }

private:
    char* data;
    std::size_t length;
};

int main() {
    String original("Hello");
    String copy = original;

    std::cout << "Original string:" << std::endl;
    original.display();

    std::cout << "Copied string:" << std::endl;
    copy.display();

    return 0;
}
```

</details>


### 4-7. コピーアサインメント演算子
文字列を表すStringクラスを作成し、コピーアサインメント演算子を使用して既存のオブジェクトに別のオブジェクトを代入するプログラムを書いてください。


<details>
<summary>回答例</summary>

```
#include <iostream>
#include <cstring>

class String {
public:
    String(const char* str) {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Copy assignment operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }

    ~String() {
        delete[] data;
    }

    void display() const {
        std::cout << "String: " << data << ", Length: " << length << std::endl;
    }

private:
    char* data;
    std::size_t length;
};

int main() {
    String original("Hello");
    String copy("World");

    std::cout << "Original string:" << std::endl;
    original.display();

    std::cout << "Copied string before assignment:" << std::endl;
    copy.display();

    // Copy assignment
    copy = original;

    std::cout << "Copied string after assignment:" << std::endl;
    copy.display();

    return 0;
}
```

</details>


### 4-8. ムーブコンストラクタとムーブ演算子
動的に確保されたメモリを持つStringクラスを作成し、ムーブコンストラクタとムーブ演算子を使用して、オブジェクトの所有権を移動するプログラムを書いてください。


<details>
<summary>回答例</summary>

```
#include <iostream>
#include <cstring>

class String {
public:
    String(const char* str) {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Move constructor
    String(String&& other) noexcept {
        length = other.length;
        data = other.data;
        other.length = 0;
        other.data = nullptr;
    }

    // Move assignment operator
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = other.data;
            other.length = 0;
            other.data = nullptr;
        }
        return *this;
    }

    ~String() {
        delete[] data;
    }

    void display() const {
        std::cout << "String: " << data << ", Length: " << length << std::endl;
    }

private:
    char* data;
    std::size_t length;
};

int main() {
    String original("Hello");

    std::cout << "Original string:" << std::endl;
    original.display();

    // Move constructor
    String moved = std::move(original);

    std::cout << "Original string after move:" << std::endl;
    original.display();

    std::cout << "Moved string:" << std::endl;
    moved.display();

    // Move assignment
    String another("World");
    another = std::move(moved);

    std::cout << "Moved string after assignment:" << std::endl;
    moved.display();

    std::cout << "Another string after assignment:" << std::endl;
    another.display();

    return 0;
}
```

</details>


