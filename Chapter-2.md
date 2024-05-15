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
  - 引用 (lvalue reference): 理解为别名, 因此必须初始化。bind with init value, not copying. Strict Type matching.
  - 指针: 
    - pointer v.s. reference: pointer is an object; pointer can be initialized without binding an init value (此时是无效指针, **point to an unknown address, can't be recognized**.).
    - ```int *p = &i;``` p is a pointer to i, store the address of i.
    - 
