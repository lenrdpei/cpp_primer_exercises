### Exercise 2.21
a. 非法。试图将int变量的地址赋值给double指针。  
b. 非法。试图将int变量直接复制给double指针，即使int变量的值刚好是0也是不合法的。  
### Exercise 2.23
不能。我们可以使用`if(p)`检查p是不是空指针，但没有办法在不影响程序正常运行的情况下检查p是否指向一个合法的对象。  
### Exercise 2.24
任何变量类型的地址都可以存入`void*`，而`long*`则严格要求指针类型和所指对象严格匹配。
