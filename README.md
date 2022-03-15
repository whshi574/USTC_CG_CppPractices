# C++项目实战练习



***光学不code，等于白学编程***



---

### 怎么去进行实战练习

- 其中个练习是科大刘利刚老师图形学本科课程的课前练习，仅仅为学习和自己练习用，并非为个人传播使用或者商用！！！！！

  刘利刚老师的相关链接：

  [如何自学《计算机图形学》 (ustc.edu.cn)](http://staff.ustc.edu.cn/~lgliu/Resources/CG/How_to_Learn_CG&Coding.htm)

  [刘利刚《计算机图形学》2020 本科课程(ustc.edu.cn)](http://staff.ustc.edu.cn/~lgliu/Courses/ComputerGraphics_2020_spring-summer/default.htm)

  [C++热身练习 USTC_CG/Homeworks/0_CppPratices at master · Ubpa/USTC_CG (github.com)](https://github.com/Ubpa/USTC_CG/tree/master/Homeworks/0_CppPratices)

- 其他待定，先完成上面的

---

### 练习记录

#### 基础的动态数组

刘老师的要求和目标：

 <img src="https://gitee.com/whshi574/images/raw/master/images/20220315143354.png" style="zoom:60%;" />

我自己完成的项目地址：[yuyefeng3574/USTC_CG_CppPractices: record of this practices (github.com)](https://github.com/yuyefeng3574/USTC_CG_CppPractices)



C++中的new和delete http://c.biancheng.net/view/2199.html

C++delete后不代表指针就为null，资源虽然是空的，但是建议还是delete后设置为nullptr [(19条消息) delete之后还需要置NULL吗？_yikunbai5708的博客-CSDN博客_delete和null](https://blog.csdn.net/yikunbai5708/article/details/102000944)

关于null和nullptr的区别：在C++中尽量使用nullptr，区别跟二义性有关系，具体不太懂，语法方面先不用深究

[(19条消息) C++中NULL和nullptr的区别_天涯明月刀的博客-CSDN博客_nullptr和null区别](https://blog.csdn.net/qq_18108083/article/details/84346655)

理解并实现简单的C++动态分配内存：[USTC_CG/Array.cpp at master · yuyefeng3574/USTC_CG (github.com)](https://github.com/yuyefeng3574/USTC_CG/blob/master/Homeworks/0_CppPratices/documents/1_BasicDArray/C2Cpp/src/Array4/Array.cpp)

学习使用函数中的引用，并实现数组的动态分配：

C++中关于引用 http://c.biancheng.net/view/2251.html

函数定义的形式参数用引用的形式表示，然后用原变量名或者你新定义的引用名都可以填入到参数部分

>  //按引用传参
>
> void swap3(int &r1, int &r2) 
>
> {    int temp = r1;    
>
> ​	r1 = r2;    
>
> ​	r2 = temp；
>
> }
>
> int A,B;
>
> swap(A,B);

声明动态数组要声明这个数组的指针，如果不用指针，那么意味着你定义的数组是一个固定大小的数组，我们只需要一个头，后面的尾部我们自己定义。

关于复制构造函数：[C++拷贝构造函数（复制构造函数）详解 (biancheng.net)](http://c.biancheng.net/view/151.html)

复制构造函数时遇到的问题：复制时会访问同类不同对象的私有成员，这是可取的吗？

[(19条消息) C++类中对同类对象private成员访问_eeeeelin的专栏-CSDN博客_类的对象能访问private吗](https://blog.csdn.net/eeeeelin/article/details/52882738)

可以的，C++访问修饰符是以类为单位，而不是以对象为单位，同类的对象之间是可以访问私有成员数据的，但并不是直接访问，比如在main函数或者其他类中进行访问，而是同一类中的成员。

注意：构造函数和析构函数不能返回值

关于iostream库里的cout的用法：[(19条消息) C++中cout的使用_九霄星河的博客-CSDN博客_c++ cout](https://blog.csdn.net/qq_35481167/article/details/82792103)

关于数组能否在原有基础上在进行扩充或者动态分配内存

​	解决：用复制的方式去完成

​	注意：复制是指把这个地址的内容复制到另一个地址，而不是简单的将地址的指赋值给另一个指针变量，这样虽然有两个指针变量且内容相同，但是他们每次都操作了一块地址。

出现问题：

<img src="C:/Users/YuYeFeng/AppData/Roaming/Typora/typora-user-images/image-20220314173152523.png" alt="image-20220314173152523" style="zoom:80%;" />

什么叫读取数据无效？



C++构造函数后面各一个冒号，是构造函数的初始化列表：[C++构造函数初始化列表 (biancheng.net)](http://c.biancheng.net/view/2223.html)

问题：数组指针之间的赋值？把一个数组的指针A赋值给另一个数组B，这个数组B能不能完全赋值后面的值。

答：经过DEBUG后，初步确认是可以的，好像不一定要for循环每个都赋值。



运算符重载：=和[]

C++文档中已记录

 拷贝构造函数与“=”赋值复制运算符重载：http://c.biancheng.net/view/2337.html



关于this指针：它是一个指向当前对象的指针，通过它可以访问当前对象的成员（用-> 来访问）

http://c.biancheng.net/view/2226.html

- this 是 const 指针，它的值是不能被修改的，一切企图修改该指针的操作，如赋值、递增、递减等都是不允许的。
- this 只能在成员函数内部使用，用在其他地方没有意义，也是非法的。
- 只有当对象被创建后 this 才有意义，因此不能在 static 成员函数中使用（后续会讲到 static 成员）。



assert函数是什么？ 断言：如果条件不成立，那么退出程序。

https://www.runoob.com/w3cnote/c-assert.html

性能开销较大





//到get an element那里了



////Obsidian关联内容[[C++学习]]

