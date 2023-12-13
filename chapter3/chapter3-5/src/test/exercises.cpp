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
    
    Employee employee("Yamada");
    employee.addProject(Project("P001", "project1"));
    employee.addProject(Project("P002", "project2"));
    employee.addProject(Project("P003", "project3"));

    std::vector<Project> projects = employee.getProjects();
    REQUIRE(projects.size() == 3);
    REQUIRE(projects[0].getProjectID() == "P001");
    REQUIRE(projects[0].getProjectName() == "project1");
    REQUIRE(projects[1].getProjectID() == "P002");
    REQUIRE(projects[1].getProjectName() == "project2");
    REQUIRE(projects[2].getProjectID() == "P003");
    REQUIRE(projects[2].getProjectName() == "project3");

    // <====== ここまで
}
