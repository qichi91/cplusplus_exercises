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

    // 口座を1つもつ顧客を作成
    Customer customer("John");
    BankAccount account;
    account.deposit(1000);
    account.withdraw(200);
    account.deposit(500);
    customer.addBankAccount(account);
    
    // 口座を2つもつ顧客を作成
    Customer customer2("Mike");
    BankAccount account2;
    account2.deposit(2350);
    account2.withdraw(200);
    account2.deposit(666);
    customer2.addBankAccount(account2);
    BankAccount account3;
    account3.deposit(325);
    account3.withdraw(200);
    account3.deposit(19954);
    customer2.addBankAccount(account3);
#if 0
    // 顧客の口座情報を出力
    std::cout << "customer1" << std::endl;
    for (const auto &transaction : customer.outputBankAccounts())
    {
        std::cout << transaction << std::endl;
    }
    std::cout << "customer2" << std::endl;
    for (const auto &transaction : customer2.outputBankAccounts())
    {
        std::cout << transaction << std::endl;
    }
#endif
    
    // 顧客の口座情報をテスト
    std::list<std::string> expected1 = {"John", "+1000", "-200", "+500", "1300"};
    std::list<std::string> expected2 = {"Mike", "+2350", "-200", "+666", "2816", "+325", "-200", "+19954", "20079"};
    REQUIRE(customer.outputBankAccounts() == expected1);
    REQUIRE(customer2.outputBankAccounts() == expected2);

    // <====== ここまで

}