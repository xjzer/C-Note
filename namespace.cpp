/*
 * @FilePath     : /root/hirain/note/cpp/namespace.cpp
 * @Description  : 名字空间namespace
 * @Author       : Xjzer
 * @Date         : 2021-04-22 14:02:17
 * @Email        : xjzer2020@163.com
 * @Others       : empty
 * @LastEditTime : 2021-04-22 15:48:17
 */
#include <iostream>
#include <stdio.h>

using namespace std;

/* 名字空间的定义 */
namespace name
{
    //可以包含变量、函数、类、typedef、#define 等
    int age;
    void test(void)
    {
        cout << age << endl;
    }
}

/* 名字空间的嵌套 */
namespace name1
{
    int num = 1;
    namespace name2
    {
        int num = 2;
    }
}

/* 名字空间的使用 */
void func1(void){
    /* 1.直接使用 */
    name::age = 1000;
    name::test();

    /* 2.使用using声明后使用 */
    using name::age;
    age = 999;
    //test(); //没有声明，不可以访问，编译报错：‘test’ was not declared in this scope
    name::test(); //正确
}

/* 无名名字空间 */
int num = 10;
void func2(void){
    int num = 11;
    //无名名字空间，常用来区分作用域
    cout << num << endl;    //结果11
    cout << ::num << endl;  //结果10
}

int main(int argc, char *argv[])
{
    func1();
    func2();
    return 0;
}