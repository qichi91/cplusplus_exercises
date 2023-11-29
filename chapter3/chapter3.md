## Chapter. 3

下記、設問で提示されるメンバ変数とメソッドが実装されたクラスを作成してください。

また、作成したクラスを使用した例も実装して下さい。


### 3-1. 銀行口座と顧客
- `BankAccount`クラス:
    - メンバ変数: 口座残高 (`balance`), 取引履歴 (`transactionHistory`)
    - メソッド: 取引履歴の表示 (`displayTransactionHistory()`), 入金 (`deposit()`), 出金 (`withdraw()`)

- `Customer`クラス:
    - メンバ変数: 顧客名 (`customerName`), 銀行口座リスト (`bankAccounts`)
    - メソッド: 口座追加 (`addBankAccount()`), 口座情報表示 (`displayBankAccounts()`)

### 3-2. 図形と描画
- `Shape`クラス:
    - メソッド: 面積計算 (`calculateArea()`), 描画情報表示 (`displayShapeInfo()`)

- `Drawing`クラス:
    - メンバ変数: 図形リスト (`shapes`)
    - メソッド: 図形追加 (`addShape()`), 図形描画 (`drawShapes()`)

### 3-3. 学生と成績
- `Student`クラス:
    - メンバ変数: 学生名 (`studentName`), 成績 (`grades`)
    - メソッド: 成績追加 (`addGrade()`), 成績表示 (`displayGrades()`)

- `GradeBook`クラス:
    - メンバ変数: 学生リスト (`students`)
    - メソッド: 学生追加 (`addStudent()`), 成績計算 (`calculateAverage()`)

### 3-4. 車両とエンジン
- `Vehicle`クラス:
    - メンバ変数: 車両ID (`vehicleID`), エンジン (`engine`)

- `Engine`クラス:
    - メンバ変数: エンジンID (`engineID`), 燃料種別 (`fuelType`)

### 3-5. 従業員とプロジェクト
- `Employee`クラス:
    - メンバ変数: 従業員名 (`employeeName`), プロジェクトリスト (`projects`)
    - メソッド: プロジェクト追加 (`addProject()`), プロジェクト一覧表示 (`displayProjects()`)

- `Project`クラス:
    - メンバ変数: プロジェクトID (`projectID`), プロジェクト名 (`projectName`)

### 3-6. 動物と動物園
- `Animal`クラス:
    - メンバ変数: 動物名 (`animalName`), 鳴き声 (`sound`)

- `Zoo`クラス:
    - メンバ変数: 動物リスト (`animals`)
    - メソッド: 動物追加 (`addAnimal()`), 動物一覧表示 (`displayAnimals()`)

### 3-7. 商品とショッピングカート
- `Product`クラス:
    - メンバ変数: 商品名 (`productName`), 価格 (`price`), 在庫数 (`stockQuantity`)

- `ShoppingCart`クラス:
    - メンバ変数: カートアイテムリスト (`cartItems`)
    - メソッド: カートアイテム追加 (`addItemToCart()`), カート合計表示 (`displayTotal()`)

### 3-8. 本と図書館
- `Book`クラス:
    - メンバ変数: 本のタイトル (`title`), 著者 (`author`), ISBN (`isbn`)

- `Library`クラス:
    - メンバ変数: 本リスト (`books`)
    - メソッド: 本追加 (`addBook()`), 本検索 (`searchBook()`)

### 3-9. 飛行機と航空会社
- `Airplane`クラス:
    - メンバ変数: 飛行機ID (`airplaneID`), 航空会社 (`airline`)

- `Airline`クラス:
    - メンバ変数: 航空会社名 (`airlineName`), 運航中の飛行機リスト (`airplanes`)
    - メソッド: 飛行機追加 (`addAirplane()`), 飛行機一覧表示 (`displayAirplanes()`)

### 3-10. 料理とレストラン
- `Dish`クラス:
    - メンバ変数: 料理名 (`dishName`), 材料リスト (`ingredients`), 価格 (`price`)

- `Restaurant`クラス:
    - メンバ変数: 料理リスト (`menu`)
    - メソッド: 料理追加 (`addDish()`), メニュー表示 (`displayMenu()`)
