#include <catch.hpp>

/**
 * @brief 演習問題のテストコード
 * 
 */
// #include "XXXXX.hpp"
TEST_CASE("exercises", "")
{
    // 回答コードはここに記載する

    
    // これ以降は変更しないこと ======>
    
    // 3人の学生を作成し、5回分の成績を追加する。
    // 成績は被らない値とする
    auto student1 = Student("Alice");
    student1.addGrade(11);
    student1.addGrade(20);
    student1.addGrade(31);
    student1.addGrade(41);
    student1.addGrade(50);

    auto student2 = Student("Bob");
    student2.addGrade(23);
    student2.addGrade(33);
    student2.addGrade(43);
    student2.addGrade(53);
    student2.addGrade(63);

    auto student3 = Student("Charlie");
    student3.addGrade(37);
    student3.addGrade(42);
    student3.addGrade(53);
    student3.addGrade(64);
    student3.addGrade(75);

    // 成績表に学生を追加する
    auto gradeBook = GradeBook();
    gradeBook.addStudent(student1);
    gradeBook.addStudent(student2);
    gradeBook.addStudent(student3);

    // 成績表を出力する
    REQUIRE(gradeBook.outputRank() == "1,Charlie,54.2\n2,Bob,43.0\n3,Alice,30.6\n");

    // <====== ここまで
}
