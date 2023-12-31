# cplusplus_exercises
C++の演習問題


## 演習環境
WSLのUbuntu2204で確認

コンパイラはgcc
プロジェクトのビルドにはcmakeを使用

### 演習問題の解き方

演習問題のディレクトリ構造
<pre>
chapter XX
│  CMakeLists.txt
│  main.cpp
│
└─src
    │  CMakeLists.txt
    │
    ├─reserve
    │  CMakeLists.txt
    │
    └─test
            CMakeLists.txt
            exercises.cpp
</pre>

* 回答者が変更するのはsrcディレクトリ以下のみ。
* 回答コードはsrc/test/exercises.cppに記述する。
* ソースファイル(.cpp)の追加、ディレクトリの追加を行う場合は、src/CMakeLists.txtを編集する。
* ディレクトリを追加する場合は、src/reserveディレクトリをコピーしてリネームする。その後、src/CMakeLists.txtにリネームしたディレクトリ名を記載する。
* ヘッダーファイルの明示的な記載は不要

#### ビルドのやり方
1. ターミナルでREADME.mdのあるディレクトリへcdする.
1. 以下のコマンドを実行してconfigする.
    ```
    cmake -S [ビルドしたいディレクトリ名] -B [ビルドディレクトリ名]
    ```
    例：chapter1-1

    cmake -S chapter1/chapter1-1 -B build/chapter1-1
1. ビルドする.
    ```
    cmake --build [ビルドディレクトリ名] --config release
    ```
    例：chapter1-1

    cmake --build build/chapter1-1
1. 実行する.
    ```
    ./[ビルドディレクトリ名]/output/testExecutor
    ```
    例：chapter1-1
    ./build/chapter1-1/output/testExecutor



## Cahpter. 1

### 1-1. Hello World
std::coutを用いて、"Hello, World!"を表示するプログラムを書いてください。

### 1-2. 変数と演算
二つの整数をユーザーに入力させ、その合計を表示するプログラムを書いてください。
入力はstd::cinを用いてください。

### 1-3. 条件分岐
ユーザーに整数を入力させ、その数が偶数か奇数かを判定して表示するプログラムを書いてください。
入力はstd::cinを用いてください。

### 1-4. ループ
1から10までの整数を順番に表示するプログラムをforループを使って書いてください。

### 1-5. 関数
二つの整数を引数として受け取り、それらの平均値を返す関数を作成してください。
また、その関数を呼び出して結果を表示してください。

### 1-6. 配列
5つの整数を要素とする配列を作成し、その合計を計算して表示するプログラムを書いてください。

### 1-7. 文字列処理:
ユーザーに文字列を入力させ、その文字列の長さを表示するプログラムを書いてください。

### 1-8. ポインタ
二つの変数を作成し、そのポインタを使って値を入れ替えるプログラムを書いてください。
クラスとオブジェクト:

学生の情報を格納するStudentクラスを作成し、それを使って学生の名前と年齢を表示するプログラムを書いてください。

### 1-9. ファイル入出力
テキストファイル(readfile.txt)を読み込んでその内容を表示するプログラムを書いてください。
注：readfile.txtは、ビルドした時にtestExecutorと同じディレクトリにコピーされます。

