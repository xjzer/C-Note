/*
 * @FilePath     : /root/hirain/note/cpp/first.cpp
 * @Description  : 标注输入输出
 * @Author       : Xjzer
 * @Date         : 2021-04-20 15:29:34
 * @Email        : xjzer2020@163.com
 * @Others       : empty
 * @LastEditTime : 2021-04-23 13:24:26
 */
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char const *argv[])
{
    /* 1.输入输出 */
    sleep(1);
    cout << "hello world" << endl;
    cout << "hello world";
    sleep(1);
    cout << "\n";
    sleep(1);
    cout << "\n";
    /**
     * cout 和 cin 都是 C++ 的内置对象，而不是关键字
     * 输入: cin 标准输入对象 从键盘输入
     * 输出：cout 标准输出对象 显示到屏幕
     * 
     * endl: 结束控制符,输出"\n"并刷新缓冲区,注意单独输出"\n"也会刷新缓冲区
     * <<  ：是一个插入运算符，可看做数据的流向
     */

    /* 2.级联输入输出 */
    int num;
    char str[20] = {0};
    cin >> str >> num;
    cout << "级联输入输出 " << "num = " << num << " str = " << str << endl;
    
    return 0;
}
