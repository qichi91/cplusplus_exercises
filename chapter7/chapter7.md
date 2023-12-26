## Chapter. 7

### 7-1. Factory Method
オブジェクトの生成をサブクラスに委譲することで、クラスのインスタンス化を抽象化します.

#### 利点
コードの柔軟性
: Factory Methodパターンを使用すると、具体的なクラス名をハードコーディングすることなくオブジェクトを作成できます.これにより、新しいクラスを追加したり既存のクラスを変更したりする際の影響を最小限に抑えることができます.

コードの再利用
: Factory Methodパターンを使用すると、オブジェクトの作成ロジックを一箇所に集約できます.これにより、同じオブジェクトの作成ロジックを何度も書く必要がなくなり、コードの再利用性が向上します.

テスト容易性
: Factory Methodパターンを使用すると、テスト時に実際のオブジェクトの代わりにモックオブジェクトを簡単に注入できます.これにより、ユニットテストを容易に行うことができます.

依存関係の管理
: Factory Methodパターンを使用すると、クラス間の依存関係をよりうまく管理できます.具体的なクラスに依存するのではなく、抽象的なインターフェースや基本クラスに依存することで、コードの結合度を低く保つことができます.


#### 欠点
コードの複雑性
: Factory Methodパターンを使用すると、コードが複雑になる可能性があります.新しいインターフェースとクラスを導入することで、コードの全体的な複雑性が増加します.

リファクタリングの困難さ
: 既存のコードをFactory Methodパターンにリファクタリングするのは困難な場合があります.特に、既存のクラスがこのパターンを使用して設計されていない場合、大規模な変更が必要になることがあります.

オーバーヘッド
: Factory Methodパターンは、オブジェクトの作成に関するオーバーヘッドを導入する可能性があります.これは、パフォーマンスに影響を与える可能性があります.

開発者の理解
: Factory Methodパターンは、初めて見る開発者にとっては理解しにくいかもしれません.これは、新しい開発者がコードベースに迅速に適応するのを難しくする可能性があります.

#### 演習
以下では、ClientクラスはProductクラスの具体的なインスタンスを直接作成しています.
これは、ClientクラスがProductクラスに強く依存していることを意味します.

```c
class Product {
public:
    Product() {
        // Product initialization logic
    }
};

class Client {
public:
    void someOperation() {
        std::shared_ptr<Product> product = std::make_shared<Product>();
        // Use the product
    }
};
```

上記の例に対してFactory Methodパターンを適用してください.
* Productクラスを作成するCreatorクラスを作成します.
* ClientクラスはCreatorクラスのcreateProductメソッドを通じて、Productクラスのインスタンスを作成します.
* 作成したProductのインスタンスを用いて処理を実行します.

<details>
<summary>実装ヒント</summary>

1. Productインターフェースの作成:
まず、すべての具体的な製品が実装するべき共通のインターフェースまたは抽象クラスを定義します.
    ```
    class Product {
    public:
        virtual ~Product() {}
        virtual void use() = 0;
    };
    ```

1. ConcreteProductクラスの作成:
次に、具体的な製品クラスを作成します.これらのクラスはProductインターフェースを実装します.
    ```
    class ConcreteProduct : public Product {
    public:
        void use() override {
            // Implementation of use
        }
    };
    ```
1. Creatorインターフェースの作成:
Creatorインターフェースまたは抽象クラスを定義します.このクラスはFactory Methodを定義します.
    ```
    class Creator {
    public:
        virtual ~Creator() {}
        virtual std::shared_ptr<Product> createProduct() = 0;
    };
    ```
1. ConcreteCreatorクラスの作成:
具体的なCreatorクラスを作成します.これらのクラスはCreatorインターフェースを実装し、具体的なProductインスタンスを作成します.
    ```
    class ConcreteCreator : public Creator {
    public:
        std::shared_ptr<Product> createProduct() override {
            return std::make_shared<ConcreteProduct>();
        }
    };
    ```
1. Clientコードの作成:
最後に、Clientコードを作成します.ClientはCreatorのFactory Methodを通じてProductインスタンスを作成し、そのインスタンスを使用します.
    ```
    int main() {
        std::shared_ptr<Creator> creator = std::make_shared<ConcreteCreator>();
        std::shared_ptr<Product> product = creator->createProduct();
        product->use();
        return 0;
    }
    ```
</details>

<details>
<summary>回答例</summary>

```
class Product {
public:
    virtual ~Product() {}
    virtual void use() = 0;
};

class ConcreteProduct : public Product {
public:
    void use() override {
        // ConcreteProduct specific logic
    }
};

class Creator {
public:
    virtual ~Creator() {}
    virtual std::shared_ptr<Product> createProduct() = 0;
};

class ConcreteCreator : public Creator {
public:
    std::shared_ptr<Product> createProduct() override {
        return new ConcreteProduct();
    }
};

class Client {
public:
    void someOperation(Creator* creator) {
        std::shared_ptr<Product> product = creator->createProduct();
        // Use the product
        product->use();
    }
};
```

</details>


### 7-2. Singleton
クラスのインスタンスが1つしか存在しないことを保証します.

#### 利点
インスタンスの制御
: Singletonパターンを使用すると、特定のクラスのインスタンスが1つしか存在しないことを保証できます.これは、データベース接続やログファイルなど、一度に1つのインスタンスしか必要としないリソースを管理する際に便利です.

グローバルアクセスポイント
: Singletonパターンは、そのインスタンスへのグローバルなアクセスポイントを提供します.これにより、アプリケーションのどこからでもそのインスタンスにアクセスできます.

共有リソース
: Singletonパターンは、状態を共有する必要がある場合に有用です.すべてのクライアントが同じインスタンスを共有するため、状態の共有と管理が容易になります.

オブジェクトの再利用
: Singletonパターンは、高コストのリソースに対するアクセスを提供します.一度インスタンスが作成されると、それは再利用され、そのためリソースの効率的な使用が可能になります.

#### 欠点
グローバル変数の問題
: Singletonパターンは、グローバル変数のように振る舞います.これは、任意の場所からアクセス可能なオブジェクトを作成するため、コードの予測可能性と可読性を低下させる可能性があります.

テストの難易度
: Singletonパターンは、テストを難しくする可能性があります.特に、テスト間で状態を共有すると、テストの結果が他のテストに依存する可能性があります.

マルチスレッド環境
: Singletonパターンはマルチスレッド環境で問題を引き起こす可能性があります.特に、複数のスレッドが同時にSingletonインスタンスを初期化しようとすると、予期しない結果を引き起こす可能性があります.

拡張性の制限
: Singletonクラスは通常、サブクラス化が困難です.また、Singletonパターンは、システムが1つのインスタンスしか必要としないという強い仮定を置いていますが、これは将来的に制限となる可能性があります.

#### 演習
以下の例では、ApplicationクラスはLoggerクラスの新しいインスタンスを直接作成しています.
これは、Loggerクラスのインスタンスが1つしか存在しないことを保証できないことを意味します.

```c
class Logger {
public:
    void log(const std::string& message) {
        // Log the message
    }
};

class Application {
public:
    void doSomething() {
        Logger logger;
        logger.log("Doing something");
    }
};
```

上記の例に対してSingletonパターンを適用してください.
* LoggerクラスをSingletonにする.


<details>
<summary>回答例</summary>

```
class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message) {
        // Log the message
    }

private:
    Logger() {} // Private constructor
    Logger(const Logger&) = delete; // Prevent copy
    void operator=(const Logger&) = delete; // Prevent assignment
};

class Application {
public:
    void doSomething() {
        Logger::getInstance().log("Doing something");
    }
};
```

</details>


### 7-3. Observer
オブジェクト間に1対多の依存関係を定義し、あるオブジェクトの状態が変更されると、その依存オブジェクトに通知されます.

#### 利点
オープン/クローズド原則
: Observerパターンは、新しいObserverを追加することが容易で、Subjectを変更する必要がないため、オープン/クローズド原則に従います.

低結合性
: SubjectとObserverは独立しているため、それらを個別に変更または再利用することができます.

ブロードキャスト通信
: Subjectは状態の変更をすべてのObserverにブロードキャストします.これにより、Observer間で情報を簡単に共有できます.

#### 欠点
オーバーヘッド
: 大量のObserverが登録されている場合、Subjectの状態が変更されるたびに、すべてのObserverに通知するためのオーバーヘッドが発生します.

更新の順序
: Observerは通知を受け取る順序が保証されないため、これが問題となる場合があります.

メモリリーク
: Observerが適切に登録解除されない場合、メモリリークを引き起こす可能性があります.これは、特に言語が自動ガベージコレクションを提供しない場合に問題となります.

#### 演習
WeatherDisplayクラスはWeatherDataクラスの新しいインスタンスを直接作成しています.
これは、WeatherDataクラスの状態が変更されたときにWeatherDisplayクラスに自動的に通知されないことを意味します.

```c
class WeatherData {
public:
    float getTemperature() {
        // return the current temperature
    }
};

class WeatherDisplay {
public:
    void update() {
        WeatherData weatherData;
        float temperature = weatherData.getTemperature();
        // display the temperature
    }
};
```

上記の例に対してObserverパターンを適用してください.
* WeatherDataクラスにObserverパターンを適用する.
* WeatherDataクラスの状態が変更されたときに、登録されたすべてのObserverインスタンスに通知するように変更してください.
* Observerインスタンスの登録は、registerObserverメソッドを通じて行って下さい.

<details>
<summary>実装ヒント</summary>

1. Observerパターンを使用する際のオブザーバーの登録と通知の手順は以下の通りです.

1. オブザーバーインターフェースを定義します.
このインターフェースは、サブジェクトから通知を受け取るためのメソッドを定義します.
    ```
    class Observer {
    public:
        virtual void update() = 0;
    };
    ```
1. サブジェクトクラスを定義します.
このクラスは、オブザーバーを登録し、状態の変更をオブザーバーに通知するメソッドを持ちます.
    ```
    class Subject {
    public:
        void registerObserver(std::shared_ptr<Observer> o) {
            observers.push_back(o);
        }

        void notifyObservers() {
            for (std::shared_ptr<Observer> o : observers) {
                o->update();
            }
        }

    private:
        std::list<std::shared_ptr<Observer>> observers;
    };
    ```
1. オブザーバークラスを定義します.
このクラスはオブザーバーインターフェースを実装し、サブジェクトからの通知を受け取るためのメソッドを提供します.
    ```
    class DisplayObserver : public Observer {
    public:
        void update() override {
            // update
        }
    };
    ```
1. サブジェクトのインスタンスを作成し、オブザーバーを登録します.
    ```
    Subject subject;
    subject.registerObserver(std::make_shared<DisplayObserver>());
    ```
1. サブジェクトの状態が変更されたとき、サブジェクトは登録されたすべてのオブザーバーに通知します.
    ```
    subject.notifyObservers();
    ```
</details>


<details>
<summary>回答例</summary>

```
class Observer {
public:
    virtual void update(float temperature) = 0;
};

class WeatherData {
public:
    void registerObserver(std::shared_ptr<Observer> o) {
        m_observers.push_back(o);
    }

    void notifyObservers() {
        for (std::shared_ptr<Observer> o : m_observers) {
            o->update(temperature);
        }
    }

    void setTemperature(float temperature) {
        this->temperature = temperature;
        notifyObservers();
    }

private:
    std::list<std::shared_ptr<Observer>> m_observers;
    float temperature;
};

class WeatherDisplay : public Observer {
public:
    void update(float temperature) override {
        // display the temperature
    }
};
```

</details>


### 7-4. Strategy
アルゴリズムを定義し、それぞれをカプセル化して、それらを互換性を持つように交換可能にします.

#### 利点
オープン/クローズド原則
: 新しい戦略を追加するときに、既存のコードを変更する必要がないため、オープン/クローズド原則に従います.

高い柔軟性
: Strategyパターンは、アルゴリズムの選択と実装をクライアントから分離するため、アルゴリズムの振る舞いを簡単に変更できます.

テストの容易さ
: Strategyパターンを使用すると、各戦略を独立してテストすることが容易になります.

#### 欠点
クライアントの複雑さ
: Strategyパターンを使用すると、クライアントがStrategyオブジェクトを作成し、適切なStrategyを選択する責任がクライアントに移されます.

クラスの増加
: それぞれの戦略が独自のクラスを必要とするため、クラスの数が増える可能性があります.

コンテキストと戦略の間の通信
: コンテキストと戦略の間でデータを共有する必要がある場合、それらの間で適切な通信を確立するのは難しい場合があります.

#### 演習

Sorterクラスはバブルソートが実装されているとします.
これは、Sorterクラスが特定のソートアルゴリズムに強く依存していることを意味します.

```c
class Sorter {
public:
    void sort(std::vector<int>& data) {
        // Implement bubble sort
    }
};

class Client {
public:
    void doSomething() {
        std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6};
        Sorter sorter;
        sorter.sort(data);
        // Do something with the sorted data
    }
};
```

上記の例に対してStrategyパターンを適用してください.
* 以下のクラスを作成してStrategyパターンを適用する.
    * ソートアルゴリズムを抽象化するため、sortインターフェースを作成する.
    * ソートアルゴリズムを実装したクラスを作成し、sortインタフェースを継承する.
    * Sorterクラスを実装し、コンストラクタでsortインタフェースを注入してください.


<details>
<summary>実装ヒント</summary>
1. Strategyインターフェースの作成:
まず、共通のインターフェースを定義します.このインターフェースは、すべての具体的な戦略が実装する必要があります.
    ```
    class SortStrategy {
    public:
        virtual void sort(std::vector<int>& data) = 0;
    };
    ```

1. 具体的な戦略の作成:
次に、具体的な戦略を作成します.これらの戦略は、Strategyインターフェースを実装し、特定のアルゴリズムを提供します.
    ```
    class BubbleSortStrategy : public SortStrategy {
    public:
        void sort(std::vector<int>& data) override {
            // Implement bubble sort
        }
    };
    ```

1. Contextクラスの作成:
最後に、Contextクラスを作成します.このクラスは、Strategyインターフェースを使用してアルゴリズムを実行します.具体的な戦略は、コンストラクタまたは専用のセッターメソッドを通じてContextに注入されます.
    ```
    class Sorter {
    public:
        Sorter(std::shared_ptr<SortStrategy> strategy) : m_strategy(strategy) {}

        void sort(std::vector<int>& data) {
            m_strategy->sort(data);
        }

    private:
        std::shared_ptr<SortStrategy> m_strategy;
    };
    ```
</details>

<details>
<summary>回答例</summary>

```
class SortStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;
};

class BubbleSortStrategy : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        // Implement bubble sort
    }
};

class QuickSortStrategy : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        // Implement quick sort
    }
};

class Sorter {
public:
    Sorter(std::shared_ptr<SortStrategy> strategy) : m_strategy(strategy) {}

    void sort(std::vector<int>& data) {
        m_strategy->sort(data);
    }

private:
    std::shared_ptr<SortStrategy> m_strategy;
};

class Client {
public:
    void doSomething() {
        std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6};
        Sorter sorter(std::make_shared<QuickSortStrategy>());
        sorter.sort(data);
        // Do something with the sorted data
    }
};
```

</details>


### 7-5. Decorator
オブジェクトに動的に新たな責任を追加します.サブクラス化による拡張に対する柔軟な代替手段を提供します.

#### 利点
柔軟性
: Decoratorパターンは、オブジェクトに動的に新しい機能を追加するため、静的な継承よりも柔軟性があります.

オープン/クローズド原則
: 新しい機能を追加するために既存のコードを変更する必要がないため、オープン/クローズド原則に従います.

単一責任原則
: 各Decoratorは一つの機能を追加するため、単一責任原則に従います.

#### 欠点
複雑性
: 多くの小さなオブジェクトが関与するため、コードは読みにくくなり、デバッグが難しくなる可能性があります.

インスタンスの識別
: Decoratorがオブジェクトのインターフェースを変更しないため、Decoratorの存在を隠蔽することができます.しかし、これはオブジェクトの型をテストする必要がある場合に問題となる可能性があります.

設計
: 適切なDecoratorの設計と実装は、一部の場合には難しく、時間を要する可能性があります.

#### 演習
以下は各コーヒーのバリエーションは独自のクラスとして定義されています.
これは、新しいバリエーションを追加するたびに新しいクラスを作成する必要があることを意味します.

```c
class Coffee {
public:
    double cost() {
        return 1.00;
    }
};

class CoffeeWithMilk {
public:
    double cost() {
        return 1.00 + 0.50;
    }
};

class CoffeeWithMilkAndSugar {
public:
    double cost() {
        return 1.00 + 0.50 + 0.25;
    }
};
```

上記の例に対してDecoratorパターンを適用してください.
* Beverageインタフェースを作成する.
* Beverageインターフェースを実装した下記のクラスを作成する.
    * MilkDecorator
    * SugarDecorator


Beverageインターフェースを実装しており、それぞれが飲み物に追加のコストを追加します.これにより、新しいバリエーションを追加するたびに新しいクラスを作成する必要がなくなります.

<details>
<summary>実装ヒント</summary>
1. Componentインターフェースの作成:
まず、共通のインターフェースを定義します.このインターフェースは、すべての具体的なコンポーネントとデコレータが実装する必要があります.
    ```
    class Beverage {
    public:
        virtual double cost() = 0;
    };
    ```
1. 具体的なコンポーネントの作成:
次に、具体的なコンポーネントを作成します.これらのコンポーネントは、Componentインターフェースを実装し、基本的な機能を提供します.
    ```
    class Coffee : public Beverage {
    public:
        double cost() override {
            return 1.00;
        }
    };
    class MilkDecorator : public Beverage {
    private:
        std::shared_ptr<Beverage> m_beverage;
    public:
        MilkDecorator(std::shared_ptr<Beverage> beverage) : m_beverage(beverage) {}
        double cost() override {
            return 0.20 + m_beverage->cost();
        }
    };
    ```
1. Decoratorクラスの作成:
最後に、Decoratorクラスを作成します.このクラスは、Componentインターフェースを実装し、具体的なコンポーネントを内部に保持します.Decoratorは、基本的な機能に追加の機能を提供します.
    ```
    std::shared_ptr<Beverage> coffee = std::make_shared<Coffee>();
    std::shared_ptr<Beverage> coffeeWithMilk = std::make_shared<MilkDecorator>(coffee);
    ```
</details>

<details>
<summary>回答例</summary>

```
class Beverage {
public:
    virtual double cost() = 0;
};

class Coffee : public Beverage {
public:
    double cost() override {
        return 1.00;
    }
};

class MilkDecorator : public Beverage {
public:
    MilkDecorator(std::shared_ptr<Beverage> beverage) : m_beverage(beverage) {}

    double cost() override {
        return 0.50 + m_beverage->cost();
    }

private:
    std::shared_ptr<Beverage> m_beverage;
};

class SugarDecorator : public Beverage {
public:
    SugarDecorator(std::shared_ptr<Beverage> beverage) : m_beverage(beverage) {}

    double cost() override {
        return 0.25 + m_beverage->cost();
    }

private:
    std::shared_ptr<Beverage> m_beverage;
};

int main() {
    std::shared_ptr<Beverage> coffee = std::make_shared<Coffee>();
    std::shared_ptr<Beverage> coffeeWithMilk = std::make_shared<MilkDecorator>(coffee);
    std::cout << "Cost: " << coffeeWithMilk->cost() << std::endl;
    return 0;
}
```

</details>


### 7-6. Adapter
互換性のないインターフェースを持つクラスを結びつけます.

#### 利点
再利用
: 既存のクラスやコンポーネントを、新しいシステムやインターフェースで再利用することができます.

クリーンなコード
: Adapterパターンを使用すると、主要なビジネスロジックから互換性のコードを分離できます.これにより、コードがクリーンで読みやすくなります.

拡張性
: 新しいクラスやインターフェースが追加された場合でも、新しいAdapterを作成することで容易に対応できます.

#### 欠点
複雑性の増加
: 多くのアダプターがシステム内に存在する場合、コードの複雑性が増加する可能性があります.

デバッグの困難さ
: Adapterが透明に動作するため、問題が発生した場合にデバッグが困難になる可能性があります.

パフォーマンス
: Adapterを通じて間接的に操作を行うため、パフォーマンスに影響を及ぼす可能性があります.

#### 演習

既存システムを表すクラス(OldSystem)があるとします.
このシステムに新しい機能を追加するために新しいクラスを作成しますが、新しいクラスは以下のような新しいインターフェースを使用します.
しかし、OldSystemクラスはNewInterfaceと互換性がないため、新しいクラスから直接使用することはできません.

```c
class OldSystem {
public:
    void oldMethod() {
        // Some logic
    }
};

class NewInterface {
public:
    virtual void newMethod() = 0;
};
```

OldSystemクラスをNewInterfaceと互換性を持つためのAdapterクラスを作成して、Adapterパターンを適用してください.

<details>
<summary>実装ヒント</summary>
1. Targetインターフェースの作成:
まず、共通のインターフェースを定義します.このインターフェースは、クライアントが使用するメソッドを定義します.
    ```
    class Target {
    public:
        virtual void request() = 0;
    };
    ```

1. Adapteeクラスの作成:
次に、Adapteeクラスを作成します.このクラスは、既存のクラスやコンポーネントで、Targetインターフェースと互換性がないものです.
    ```
    class Adaptee {
    public:
        void specificRequest() {
            // Some specific logic
        }
    };
    ```

1. Adapterクラスの作成:
最後に、Adapterクラスを作成します.このクラスは、Targetインターフェースを実装し、Adapteeクラスを内部に保持します.Adapterは、TargetインターフェースのメソッドをAdapteeのメソッドに「変換」します.
    ```
    class Adapter : public Target {
    private:
        Adaptee adaptee;
    public:
        void request() override {
            adaptee.specificRequest();
        }
    };
    ```
</details>

<details>
<summary>回答例</summary>

```
class OldSystem {
public:
    void oldMethod() {
        // Some logic
    }
};

class NewInterface {
public:
    virtual void newMethod() = 0;
};

class OldSystemAdapter : public NewInterface {
private:
    OldSystem oldSystem;
public:
    void newMethod() override {
        oldSystem.oldMethod();
    }
};
```

</details>


### 7-7. Command
リクエストをオブジェクトとしてカプセル化し、クライアントをパラメータ化します.

#### 利点
分離とカプセル化
: Commandパターンは、操作とその実行を分離します.これにより、呼び出し元は実行詳細を知る必要がなく、コードのカプセル化が向上します.

操作のキューイングとログ記録
: Commandパターンを使用すると、操作をキューに入れたり、ログに記録したりすることが容易になります.

Undo/Redo機能
: Commandパターンは、操作の履歴を保持することが可能で、これによりUndo/Redoのような機能を実装することが容易になります.

#### 欠点
クラス数の増加
: 各操作に対して個別のCommandクラスを作成する必要があるため、クラスの数が増え、コードが複雑になる可能性があります.

オーバーヘッド
: Commandパターンを使用すると、小さな操作でもCommandオブジェクトを作成する必要があり、これによりオーバーヘッドが生じる可能性があります.

#### 演習

あるシステムで、次のような既存のクラスがあり、
このシステムでは、操作を直接呼び出す必要があります.
```c
class System {
public:
    void operationA() {
        // Some logic for operation A
    }

    void operationB() {
        // Some logic for operation B
    }
};

int main()
{
    System system;
    system.operationA();
    system.operationB();
}
```

しかし、このアプローチでは、操作の実行を制御する柔軟性が限られています.

この問題を解決するため、Commandパターンを適用してください.
* 各操作をカプセル化するCommandクラスを作成する.
* Invokerクラスを通じて操作を実行する.


<details>
<summary>実装ヒント</summary>
1. Commandインターフェースの作成:
まず、共通のインターフェースを定義します.このインターフェースは、すべての具体的なCommandクラスが実装するexecuteメソッドを定義します.
    ```
    class Command {
    public:
        virtual void execute() = 0;
    };
    ```

1. 具体的なCommandクラスの作成:
次に、具体的なCommandクラスを作成します.これらのクラスは、Commandインターフェースを実装し、特定の操作をカプセル化します.
    ```
    class ConcreteCommand : public Command {
    public:
        void execute() override {
            // Implement the specific operation
        }
    };
    ```

1. Invokerクラスの作成:
最後に、Invokerクラスを作成します.このクラスは、Commandオブジェクトを保持し、それを実行します.
    ```
    class Invoker {
    private:
        Command* command;
    public:
        void setCommand(Command* cmd) {
            command = cmd;
        }
        void invoke() {
            if (command) {
                command->execute();
            }
        }
    };
    ```
</details>

<details>
<summary>回答例</summary>

```
class Command {
public:
    virtual void execute() = 0;
};

class OperationACommand : public Command {
private:
    System& system;
public:
    OperationACommand(System& sys) : system(sys) {}
    void execute() override {
        system.operationA();
    }
};

class OperationBCommand : public Command {
private:
    System& system;
public:
    OperationBCommand(System& sys) : system(sys) {}
    void execute() override {
        system.operationB();
    }
};

class Invoker {
private:
    Command* command;
public:
    void setCommand(Command* cmd) {
        command = cmd;
    }
    void invoke() {
        if (command) {
            command->execute();
        }
    }
};
```

</details>
