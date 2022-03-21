### Direct
```cpp
string (&foo(parameter_list))[10];
```

### Type Alias
```cpp
using sarry = string [10];
sarry &foo(parameterlist);
```

### Trailing Return
```cpp
auto foo(parameter_list) -> string (&) [10];
```

### Decltype
```cpp
decltype(s_arry) foo(parameter_list);
