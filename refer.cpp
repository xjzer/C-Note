/*
 * @FilePath     : /root/hirain/note/cpp/refer.cpp
 * @Description  : 引用reference
 * @Author       : Xjzer
 * @Date         : 2021-04-23 16:34:24
 * @Email        : xjzer2020@163.com
 * @Others       : empty
 * @LastEditTime : 2021-05-02 14:21:05
 */
#include <iostream>

using namespace std;

/* 引用 */
void Refer(void){
    int a = 99;
    int b = 101;
    int &r = a; //必须在声明引用变量时进行初始化，且不可被修改
    r = b;      //不是修改引用的目标，而是赋值


    cout << a << "  " << r << endl; // 101 101
    a++;
    cout << a << "  " << r << endl; // 102 102
    r++;
    cout << a << "  " << r << endl; // 103 103
    
    cout << &a << "  " << &r << endl; //地址相同

    //由结果可知，a和b的值和地址都相同，++操作可以理解为：将一个有两个名称的变量加1
    //注意：虽然地址相同，但实质上引用和被引用的变量占用的不是同一块内存。引用本质上还是一个指针，之所以不能获取引用的地址，是因为编译器进行了内部转换。
}

/* 常引用 */
void ConstRefer(void){
    int a = 1000;
    int const &r1 = a;
    const int &r2 = a;
    //r1 = 2;   //不可以通过const修饰的引用类型的变量修改引用的目标
    a = 2;      //可以通过引用目标的自身修改值
    cout << "常引用 = " << a << endl;
    /*
     * 回顾C语言指针:
	 *		int *const p;
	 *		int const *p;
	 *		const int *p;
     */
}

/* 返回引用 */
int bb = 10;
int & ReturnRefer(void){
    /**
     * 1.适用：返回复杂结构的引用，这样效率更高
     *  比如 结构体a = 函数b( );   
     *  当函数b返回的是一个结构时，则需要将返回值复制到一个临时变量中，再将这个临时变量复制到结构体a。
     *  当函数b返回的是一个结构的引用时，则相当于给返回值起了一个别名，再将这个返回值  复制到结构体a。
     *  少了一次复制的过程，所以效率更高
     * 2.注意
     *  1>避免返回局部变量的引用
     *  2>返回引用的函数实际上是被引用的变量的别名，所以引用类型的返回是一个左值，
     *    要避免像main函数中的操作1时，可以返回一个常引用。
     *  3>常规函数的返回值都是右值
    */
    cout << "bb = " << bb << endl;
    
    return bb;
}

/* 引用作为函数参数 */
int Arg(int a){
    a *= a;
    return a;
}
int RefArg(int &a){
    a *= a;
    return a;
}
int RefConstArg(int const &a){
    //a *= a;
    return a;
}

void ReferArg(void){
    int a = 3;
    Arg(a);
    Arg(2);

    RefArg(a); //正确
    /* RefArg(2);   //错误
     * 报错：cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
     *       不能将' int& '类型的非const左值引用绑定到' int '类型的右值
     *       通俗理解就是，2虽然是一个int类型，但2是一个右值，此处的参数类型是左值引用
     */

    RefConstArg(2); //不报错，但此时实参已经不可修改
    /**
     * 当实参与引用参数不匹配，并且参数为const引用时，C++将生成临时变量，适用于：
     *     实参的类型正确，但不是左值；
     *     实参的类型不正确，但可以转换为正确的类型。
     * 临时变量只在函数调用期间有效
     */
    RefConstArg(a);

    /**
     * 引用参数适用场合
     * 1. 当数据对象是基本类型或小型结构时，直接按值传递或使用指针
     * 2. 当数据对象是数组时，只能使用指针
     * 3. 当数据对象是较大的结构时，使用指针或引用。
     * 4. 当数据对象是类对象时，只能使用引用。
     * 5. 再根据是否需要修改数据来添加const
     */
}


/* 右值引用 rvalue reference */
void RvalueRefer(void){
    // 右值引用是C++11中新增的，这种引用可以指向右值，使用&&声明
    int a = 1;
    int && b = 1;

    // 待补充：右值引用实现移动语义
}

int main(int argc, char *argv[]){
    Refer();
    ConstRefer();

    /* 引用返回值 */
    ReturnRefer() = 114; //操作1
    cout << "bb = " << bb << endl;

    /* 引用参数 */
    ReferArg();

    /* 右值引用 */
    RvalueRefer();


    return 0;
}
