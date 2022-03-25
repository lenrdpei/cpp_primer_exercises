构造函数按照类中变量定义的顺序执行初始化，即先初始化rem，在初始化base。  
故原代码段应修改为：
```cpp
struct X
{
    X (int i, int j): rem(i % j), base(i) {};
    int rem, base;
};
```