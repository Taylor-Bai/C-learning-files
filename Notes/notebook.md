# hello world
## hello

*斜体*，**加粗**，**加粗**
***
代码段落：

    int main(){
    std::cout <<"hello,world"<<std::endl;
    return 0;
    }
***
#### 区别 Declaration  Definition

命令行cpp指令：保存编译中的临时文件
`g++ a.cpp b.cpp --save-temps `

编译过程：
首先每个cpp进行编译预处理，将每一个头文件内容插进来。然后每个cpp单独作编译、最后一起链接起来

1.编译预处理（#）输出文件后缀 ——.ii
2.编译器输出后缀 ——.s
3.汇编器输出后缀 ——.o
4.链接器：把所有的cpp.o文件连接到一起——.out
\
\
<font color=orange>头文件里放定义容易出现重定义问题！</font>
头文件函数的声明：函数名，输出类型、输入类型（缺省值）
变量的声明：变量名、变量类型
\
\
本地变量  成员变量  this指针
类中包含变量的**声明**和函数的**定义**
{}开始时分配空间
default constructor无参数的构造函数

new、new[]、delete、delete[]分配空间、调用构造，输入输出、区别
***
初始化列表早于构造函数执行,在输入为对象时有区别，会调用默认的输入对象的构造函数
    
    构造函数：Point(float xa=0.0,float ya=0.0)
                  :y(ya),x(xa){}

面向对象三大特性：封装、继承和多态性
C++提供复杂的内存模型：fully inclusion、by reference，雇员的例子
java只能By reference

构造子类的对象时有时必须调用父类的**非默认**构造函数，需要在初始化列表中初始化

函数的重载

继承中的名字隐藏问题，无法重载函数（全局、局部变量有作用域、函数也有**作用域**）
如何调用父类中被隐藏的函数？

函数的缺省值写在哪里？

调用函数开销很大，大在哪里？ inline函数的实施过程
![Alt text](image.png)

const指针、const变量、const函数如何表示、什么意思？
在头文件中函数后有const什么意思？
const和非const可以构成重载（输入指针不一样）
**const类型必须在初始化时赋值！！**

    #include <iostream>
    using namespace std;
    class A {
        const int i;
    public:
        A():i(0){}
        void f() { cout <<"f()"<< endl;}
        void f()const { cout <<"f() const" << endl;}
    };
    int main(){
        const A a;
        a.f();          //输出f() const
        return 0;
    }
