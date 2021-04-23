/*
 * @FilePath     : /root/hirain/note/cpp/datetype.cpp
 * @Description  : 与C不同的一些数据类型
 * @Author       : Xjzer
 * @Date         : 2021-04-22 15:57:31
 * @Email        : xjzer2020@163.com
 * @Others       : empty
 * @LastEditTime : 2021-04-23 15:21:00
 */
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct Tea{
    char name[20];
    int age;
    void test(void){
        age = 10;
        cout << "age = " << age << endl;
    }
};

enum led_t
{
    RED = 0,
    GREEN,
    BLUE,
};

void led_on(led_t leds)     //如果是C语言，则这个参数需要加上enum
{
    switch (leds)
    {

    case RED:
        cout << "RED" << endl;
        break;
    case GREEN:
        cout << "GREEN" << endl;
        break;
    case BLUE:
        cout << "BLUE" << endl;
        break;
    }
}
void StructFunc(void){
    /* 结构体 */
    cout << "===struct===" << endl;
    Tea tea; //定义结构体类型的变量类型时可以省略struct关键字
    tea.test();
    cout << "sizeof(tea) = " << sizeof(tea) << endl; //struct中的函数不占用任何结构体的空间，结果24
}
void EnumFunc(void){
    /* 枚举 */
    cout << "===enum===" << endl;

    //如果编写者只提供说明文档，这样写比较简洁易懂
    led_on(RED);

    led_t leds;

    //  g++比gcc编译器检查数据类型更加的严格
    //leds = 2;   //	使用C++的编译器会报错，类型不匹配; 使用gcc的编译器，不报错

    leds = (led_t)1; //不建议这样使用
    cout << sizeof(leds) << endl;
}
void BoolFunc(void){
    /* 布尔类型 */
    cout << "===bool===" << endl;

    bool onOff = 1000;
    cout << onOff << endl; //输出1
    cout << false << endl; //输出0

    cout << boolalpha << endl; //直接输出true或false
    cout << false << endl;
    cout << onOff << endl;

    cout << noboolalpha << endl; //关闭输出true或false
    cout << true << endl;
}
void StringFunc(void){
    cout << "===string===" << endl;
    string s1; //定义但没有初始化,默认值为"",即空字符串
    string s2 = "hello"; //定义并初始化，结尾没有结束标志'\0'
    string s3 = s2;      //直接通过赋值操作符进行赋值，不论长短
    string s4 = s2 + s3;
    string s5(5, 's'); //由 5 个's'字符组成的字符串，也就是"sssss"

    cout << boolalpha << (s2 == s3) << endl;
    cout << boolalpha << (s2 >  s3) << endl;
    
    printf("C语言格式 %s\n", s4.c_str());
    cout << s4.length() << endl;
    
    int cc[10]   {1,2,3,4,5,6};
    
}
int main(int argc, char const *argv[])
{
    StructFunc();
    EnumFunc();
    BoolFunc();
    StringFunc();
    return 0;
}