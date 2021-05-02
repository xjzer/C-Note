/*
 * @FilePath     : /root/hirain/note/cpp/function.cpp
 * @Description  : 介绍C++的函数中新增的一些特性
 * @Author       : Xjzer
 * @Date         : 2021-04-25 14:37:28
 * @Email        : xjzer2020@163.com
 * @Others       : empty
 * @LastEditTime : 2021-05-02 16:55:33
 */
#include <iostream>

using namespace std;

/**
 * 函数重载
 * 解释：函数名字相同，但参数个数不同或类型不同或顺序不同
 * 适用：函数基本上执行相同的任务，但使用不同形式的参数 
 * 本质：名称修饰，编译器对函数名称进行了修饰，相当于重命名。通过g++ -S可以验证
 *      不同的编译器有不同的重命名方式，从这个角度讲，函数重载仅仅是语法层面的，
 *      本质上它们还是不同的函数，占用不同的内存，入口地址也不一样。
 * 注意：函数返回值也不能作为重载的依据。
 */
void Reload(int a, char b){
    cout << "Reload(int a, char b)" << endl;
}

void Reload(int a, char b, int c)
{
    cout << "数量不同" << endl;
}
void Reload(int a, int b)
{
    cout << "类型不同" << endl;
}
void Reload(char b, int a)
{
    cout << "顺序不同" << endl;
}

void ReloadTest(void){
    Reload(1,'a');
    Reload(1,2);
    Reload('a',1);
}

/**
 * 默认参数 
 * 注意：
 *  默认参数在函数的声明和定义中都可以指定 
 *  默认参数只能放在形参列表的最后
 *  在同一作用域中，不可以重复指定同一个默认参数
 *      同一个源文件中，定义和声明同时指定默认参数会报错
 *      同一函数的定义和声明放在不同文件中时，可以同时指定，编译器使用的是当前作用域中的默认参数。
 */
int DefaultArg(int a    , int b = 200);
int DefaultArg(int a = 2, int b      );   //在同一作用域中，不可以重复指定同一个默认参数

int DefaultArg(int a, int b){
    return a+b;
}

/**
 * 哑元参数:在函数的列表中只有函数的类型，没有形参名
 */
int DummyArg(int a, int b, char){
    return a+b;
}

/**
 * 内联函数
 * 目的：提高程序的运行速度
 *      常规的函数调用会引起程序指令地址的跳转，需要保存和清理现场，为了消除函数调用的时空开销，C++提供了内联函数
 * 使用方法：在函数的定义前面加上关键字inline，在声明前加无效(待验证)
 * 场景：函数代码执行时间很短，小于调用的时间，所以一般只将那些短小的、频繁调用的函数声明为内联函数
 * 缺点：需要更多的内存，有几次调用就有几个相同的函数拷贝
 * 注意：
 *      节省的时间绝对值并不大，除非该函数被经常调用
 *      由于内联函数比较短小，我们通常的做法是省略函数原型，将整个函数定义（包括函数头和函数体）放在本应该提供函数原型的地方。
 *      对函数作 inline 声明只是程序员对编译器提出的一个建议，而不是强制性的，并非一经指定为 inline 编译器就必须这样做。编译器有自己的判断能力，它会根据具体情况决定是否这样做。
 *      多文件编程时，内联函数的定义一般直接放在头文件中，因为如果放在某个源文件时，虽然能够正常编译，但在链接时会出错，内联函数，编译期间会用它来替换函数调用处，编译完成后函数就不存在了，链接器在将多个目标文件（.o文件）合并成一个可执行文件时找不到内联函数的定义，所以会产生链接错误。
 * 参考资料：http://c.biancheng.net/view/2201.html 
 */

/**
 * 待补充：内联函数与宏定义
 */


int main(int argc, char const *argv[])
{
    /* code */
    ReloadTest();
    cout << DefaultArg(1) << endl;  //结果201
    cout << DefaultArg(1,3) << endl;  //结果4
    cout << DefaultArg( ) << endl;  //结果202
    cout << DummyArg(1, 1, 'a') << endl; //结果2


    return 0;

}
