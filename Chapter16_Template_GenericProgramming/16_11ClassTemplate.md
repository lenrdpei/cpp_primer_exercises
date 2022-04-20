insert函数中ListItem没有实例化。  
应修改为：
```cpp
void insert(ListItem<elemType> *ptr, elemType value);
```