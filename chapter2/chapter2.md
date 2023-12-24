## Chapter. 2

### 2-1. コンストラクタとデストラクタ
クラスTimeを作成し、時間を表すための時・分・秒のメンバ変数を持ち、コンストラクタとデストラクタを実装してください。

時分秒はint型で作成して下さい。

<details>
<summary>回答例</summary>

```
#include <iostream>

class Time {
public:
    Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {
        std::cout << "Time object created." << std::endl;
    }

    ~Time() {
        std::cout << "Time object destroyed." << std::endl;
    }

private:
    int hours;
    int minutes;
    int seconds;
};

int main() {
    Time currentTime(12, 30, 45);
    // Do something with the Time object

    return 0;
}
```

</details>


### 2-2. メンバイニシャライザリスト
3Dベクトルを表すVector3Dクラスを作成し、コンストラクタでメンバイニシャライザリストを使用してx、y、zを初期化してください。


<details>
<summary>回答例</summary>

```
#include <iostream>

class Vector3D {
public:
    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    void display() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")";
    }

private:
    double x;
    double y;
    double z;
};

int main() {
    Vector3D v(1.0, 2.0, 3.0);

    std::cout << "Vector: ";
    v.display();
    std::cout << std::endl;

    return 0;
}
```

</details>


### 2-3. デフォルト引数
クラスRectangleを作成してください。
コンストラクタで幅と高さを引数として受け取る際、デフォルト引数を使用して高さが指定されない場合は50になるようにしてください。

<details>
<summary>回答例</summary>

```
#include <iostream>

class Rectangle {
public:
    Rectangle(double width, double height = 50.0) : width(width), height(height) {}

    void display() const {
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }

private:
    double width;
    double height;
};

int main() {
    Rectangle rect1(5.0, 10.0);
    Rectangle rect2(3.0);

    std::cout << "Rectangle 1: ";
    rect1.display();

    std::cout << "Rectangle 2: ";
    rect2.display();

    return 0;
}
```

</details>


### 2-4. スタティックメンバ変数
クラスStudentを作成し、学生の数を表す静的メンバ変数を使用して、各学生が登録されるたびに学生の番号を自動的に割り当てるプログラムを書いてください。


<details>
<summary>回答例</summary>

```
#include <iostream>

class Student {
public:
    Student(const std::string& name) : name(name) {
        studentNumber = ++nextStudentNumber;
    }

    void display() const {
        std::cout << "Student: " << name << ", Student Number: " << studentNumber << std::endl;
    }

private:
    std::string name;
    int studentNumber;

    static int nextStudentNumber; // Static member variable
};

// Initialize the static member variable
int Student::nextStudentNumber = 0;

int main() {
    Student student1("Alice");
    Student student2("Bob");

    std::cout << "Information for students:" << std::endl;
    student1.display();
    student2.display();

    return 0;
}
```

</details>


### 2-5. 静的メンバ関数
静的メンバ関数を使用して、数学関数（例: 素数判定）を提供するクラスを作成してください。

<details>
<summary>回答例</summary>

```
#include <iostream>

class MathFunctions {
public:
    static bool isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << "Is 17 prime? " << (MathFunctions::isPrime(17) ? "Yes" : "No") << std::endl;
    std::cout << "Is 25 prime? " << (MathFunctions::isPrime(25) ? "Yes" : "No") << std::endl;

    return 0;
}
```

</details>



### 2-6. データメンバの可視性
クラスPersonを作成し、名前と年齢を格納するprivateなメンバ変数を持ち、これにアクセスするためのpublicなメソッドを実装してください。

<details>
<summary>回答例</summary>

```
#include <iostream>
#include <string>

class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    void display() const {
        std::cout << "Name: " << getName() << ", Age: " << getAge() << std::endl;
    }

private:
    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    std::string name;
    int age;
};

int main() {
    Person person("John", 28);
    person.display();

    // Attempting to access private members directly would result in a compilation error
    // Uncommenting the following lines would cause an error:
    // std::cout << "Name: " << person.name << ", Age: " << person.age << std::endl;

    return 0;
}
```

</details>



### 2-7. 抽象クラス
動物を表す抽象クラスAnimalを作成し、そのクラスを継承した派生クラスBirdとMammalを実装してください。


<details>
<summary>回答例</summary>

```
#include <iostream>

class Animal {
public:
    virtual void makeSound() const = 0; // Pure virtual function

    virtual void eat() const {
        std::cout << "Animal is eating." << std::endl;
    }
};

class Bird : public Animal {
public:
    void makeSound() const override {
        std::cout << "Tweet tweet" << std::endl;
    }
};

class Mammal : public Animal {
public:
    void makeSound() const override {
        std::cout << "Roar" << std::endl;
    }

    void giveBirth() const {
        std::cout << "Mammal is giving birth." << std::endl;
    }
};

int main() {
    Bird myBird;
    Mammal myMammal;

    myBird.makeSound();
    myBird.eat();

    myMammal.makeSound();
    myMammal.eat();
    myMammal.giveBirth();

    return 0;
}
```

</details>


### 2-8. 継承とポリモーフィズム
基底クラスShapeとその派生クラスCircleとRectangleを作成し、それぞれのクラスで面積を計算するプログラムを書いてください。


<details>
<summary>回答例</summary>

```
#include <iostream>

class Shape {
public:
    virtual double calculateArea() const {
        return 0.0;
    }
};

class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}

    double calculateArea() const override {
        return 3.14 * radius * radius;
    }

private:
    double radius;
};

class Rectangle : public Shape {
public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double calculateArea() const override {
        return length * width;
    }

private:
    double length;
    double width;
};

int main() {
    Circle myCircle(5.0);
    Rectangle myRectangle(4.0, 6.0);

    std::cout << "Circle Area: " << myCircle.calculateArea() << std::endl;
    std::cout << "Rectangle Area: " << myRectangle.calculateArea() << std::endl;

    return 0;
}
```

</details>


### 2-9. 例外処理
クラスDivisionを作成し、整数の除算を行うメソッドdivideを実装してください。このメソッドではゼロでの除算が発生した場合に例外をスローし、メイン関数でその例外をキャッチしてエラーメッセージを表示するプログラムを書いてください。

<details>
<summary>回答例</summary>

```
#include <iostream>
#include <stdexcept>

class Division {
public:
    static double divide(int numerator, int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        return static_cast<double>(numerator) / denominator;
    }
};

int main() {
    try {
        // Attempt to divide by zero
        double result = Division::divide(10, 0);
        std::cout << "Result of division: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
```

</details>



### 2-10. ファイル入出力
ファイルからデータを読み込んでオブジェクトに格納し、そのオブジェクトの内容をファイルに書き込むプログラムを作成してください。例として、Personクラスを考え、名前と年齢をファイルから読み込んで表示し、新しいPersonオブジェクトをファイルに書き込んでください。

<details>
<summary>回答例</summary>

```
#include <iostream>
#include <fstream>
#include <string>

class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    // Serialize person data to a file
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << name << std::endl;
            file << age << std::endl;
            file.close();
        } else {
            std::cerr << "Error opening file for writing." << std::endl;
        }
    }

    // Deserialize person data from a file
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::getline(file, name);
            file >> age;
            file.close();
        } else {
            std::cerr << "Error opening file for reading." << std::endl;
        }
    }

private:
    std::string name;
    int age;
};

int main() {
    const Person person1("Alice", 25);
    
    // Save person data to file
    person1.saveToFile("person_data.txt");

    // Load person data from file
    Person person2("Bob", 30);
    person2.loadFromFile("person_data.txt");

    std::cout << "Loaded Person Data:" << std::endl;
    person2.display();

    return 0;
}
```

</details>
