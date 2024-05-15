# Chapter 2: Variables and Basic Types

- int v.s. short v.s. long v.s. long long
  - in practice, short太小, long和int一样长, long long更长, 如何value的范围int不够用, 用long long
- 类型转换:
  - 无符号数和有符号数相加, 有符号数会转换为无符号数。 注意小于0的结果, 见下方例子 (假设int 32位)

    ```c++
    unsigned u = 10;
    int i = -42;
    // result: 4294967264 = 10 + (-42) + 2^32
    std::cout << u + i << std::endl; 
    ```

- 初始值 v.s. 赋值
  - 初始化变量值后立刻可以使用

    ```c++
    int a = 2, b = a; // is valid
    ```

  - 一些初始化方式:

    ```c++
    int a = 0; // copy initialization
    int a(0); // direct initialization
    int a{0}; // list initialization
    int a = {0}; // copy list initialization
    ```

    - 对于列表初始化（以及复制列表初始化）而言, 如果存在丢失信息的风险, 编译器会报错

    ```c++
    int a = {3.14}, b{3.14};
    //error: type 'double' cannot be narrowed to 'int' in initializer list
    ```

  - 默认初始化：函数体外的变量被初始化为0, 函数体内的变量不被初始化
    - 同时，类内部的成员变量会被默认初始化（由类决定，如string会被初始化为空字符串）
- 定义和声明
  - 声明 (declaration)：告知程序变量名字，使其可以被使用
    - composed of ```base type``` and ```declarator```(声明符，即变量名)
  - 定义 (definition)：创建实体（对象），申请内存空间
    - 声明非定义：```extern```关键字，```extern int i;``` 声明i, 但不定义
    - 显式初始化：```extern int i = 0;``` 定义i, 并初始化为0，在这个情况下，extern没有作用。
  - 如何在多个文件中使用同一个变量：```extern```关键字
    - 在一个文件中定义变量，其他文件中声明变量
    - or 可以在头文件中定义变量，然后在多个文件中包含这个头文件
- C++ is statically typed
  - 类型检查发生在编译时
  - 一旦变量被定义，它的类型就不能改变
- 作用域:

  - ```c++
    int val = 100;
    for (int val = 1; val <= 10; ++val)
        sum += val; // the definition of inner val vatiable will replace the outer val variable in the inner scope
    std::cout << val << std::endl; // result: 100
    std::cout << sum << std::endl; // result: 55
    ```

- 复合类型: 引用和指针
  - 引用 (lvalue reference): 理解为别名, 因此必须初始化。bind with init value, not copying. Strict Type matching. Cannot reference to a literal value.
    - ```int &r = i;```
    - ```int &r = 42;``` // invalid
  - 指针:
    - pointer v.s. reference: pointer is an object; pointer can be initialized without binding an init value (此时是无效指针, **point to an unknown address, can't be recognized**.).
    - ```int *p = &i;``` p is a pointer to i, store the address of i.
    - Status:
      - Point to an object: ```int *p = &i;```
      - Point to the next address location of an object / Not initialized
        - find the object of the pointer is not checked, so it's dangerous.
      - nullptr: ```int *p = nullptr;```
        - find the object: segmentation fault.
        - init: ```int *p = nullptr;```, ```int *p = 0;```.
    - Void pointer: ```void *p = &i;```
      - Can't be dereferenced, need to cast to a specific type. Can be used in function I/O, compare. 不能直接操作所指的对象
- Const: ```const int bufSize = 512;```
  - have to be inited, cannot be changed. 但是可以拷贝给其他非const变量. Hence, ```int &a = 10;``` is invalid(you may write ```a = 5;``` which is not allowed). However, ```const int &a = 10;``` is valid, since ```a = 5``` is invalid now.
  - Const variable can be accessed in other files by ```extern const int bufSize;``` otherwise it will be a file-local variable.
  - const 引用：const can references const/non-const, but obviously non-const references can't bind to const objects.
  - *SOME EXPECTION*: when const references non-const, the types don't have to match exactly (as long as cast is possible). reason: compiler will create a temporary variable to store the value of the non-const object, then bind the const reference to the temporary variable.

    ```c++
    double i = 42;
    const int &r = i; // valid
    ```

    to

    ```c++
    double i = 42;
    const int temp = i;
    const int &r = temp;
    ```

  why normal case is invalid: say we remove const, then r changes, but i doesn't change (temp=i is like a copy operation), which is not allowed.
  - Another Note: the value referenced by const may be changed.

    ```c++
    int a = 5;
    const int &b  = a;
    std::cout << "b: " << b << std::endl; // 5
    int &c = a;
    c = 10;
    std::cout << "a: " << a << std::endl; // 10
    std::cout << "b: " << b << std::endl; // 10 !!!!!
    std::cout << "c: " << c << std::endl; // 10
    ```

- Const 指针和常量引用区别不大，注意点: Const pointer cannot change pointer, but can change the object pointer refers to. 下面的例子做了一些区分:

    ```c++
    int a = 5;
    const int *ptr = &a;
    std::cout << *ptr << std::endl;//5
    std::cout << ptr << std::endl;//0x16b00efb8
    *ptr = 10; // error
    ptr = nullptr; // valid
    a = 10;
    std::cout << *ptr << std::endl;//10
    std::cout << ptr << std::endl;//0x16b00efb8
    int *const ptr2 = &a;
    *ptr2 = 20; // valid
    ptr2 = nullptr; // error
    ```
