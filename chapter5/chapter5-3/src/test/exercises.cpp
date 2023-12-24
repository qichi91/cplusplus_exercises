#include <catch.hpp>
#include "catchhelper.hpp"

// スレッドセーフなキュークラスBoundedQueueを実装する
// 以下の要件を満たすこと
// - コンストラクタでキューのサイズを指定できる
// - キューにデータを追加するにはpushメソッドを使う
// - キューからデータを取り出すにはpopメソッドを使う
// - キューが空のときにpopメソッドを呼び出すとキューにデータが追加されるまで待機する
// - キューが満杯のときにpushメソッドを呼び出すとキューからデータが取り出されるまで待機する
// - キューにデータが追加されたら、popメソッドを呼び出しているスレッドに通知する
// - キューからデータが取り出されたら、pushメソッドを呼び出しているスレッドに通知する

/**
 * @brief 演習問題のテストコード
 * 
 */
#include <thread>
TEST_CASE("exercises", "")
{
    // 変更しないこと ======>

    // メインスレッドとワーカースレッド間でデータをやり取りするキューを作成する
    // キューは送信用キューと受信用キューを作成する
    // ワーカースレッドは送信用キューのデータを読み出して、受信用キューにデータを追加する
    // 受信用キューに追加する時に、接頭辞として”Recv: ”を付け加える
    // 10回読みだしたらスレッドを終了する
    // メインスレッドは受信用キューからデータを読み出して、コンソールに出力する

    BoundedQueue<std::string> send_queue(10);
    BoundedQueue<std::string> recv_queue(10);

    std::thread worker([&send_queue, &recv_queue]() {
        for (int i = 0; i < 10; ++i) {
            std::string value = send_queue.pop();
            recv_queue.push("Recv: " + value);
        }
    });

    for (int i = 0; i < 10; ++i) {
        auto value = std::to_string(i);
        std::cout << "Send: " << value << std::endl;
        send_queue.push(value);
    }

    worker.join();

    for (int i = 0; i < 10; ++i) {
        std::string value = recv_queue.pop();
        std::cout << value << std::endl;
        REQUIRE(value == "Recv: " + std::to_string(i));
    }

    REQUIRE(send_queue.empty());
    REQUIRE(recv_queue.empty());
    // <====== ここまで
}
