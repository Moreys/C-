
#include <iostream>
using std::cout;
using std::endl;

/*
 * 重温微积分
 * 随机过程
 * 矩阵论
 * 机器学习
 * 计算理论
 * */
class Complex
{
public:
    Complex(double real, double image) : _real(real) , _image(image)
    {

    }
    //对两个类型进行打印
    void print() const
    {
        cout << _real << "  " << _image << "i" << endl;
    }
    double getReal() const {    return  _real;  }
    double getImage() const {   return _image;  }

    // 3、运算符重载3——成员函数重载
    // 类的内部函数，可以直接使用
    Complex operator*(const Complex & rhs)
    {
        cout << "Complex Complex::operator*+(const Complex & rhs)" <<endl;
        return Complex(_real * rhs._real, _image * rhs._image);  
    }
    friend Complex operator-(const Complex & lhs, const Complex & rhs);
private:
    double _real;
    double _image; //-1 = i ^ 2
};

//普通运算符重载之普通函数
//1、运算符重载是一个函数 写出函数名
//2、根据操作数写出函数参数
//3、根据业务需求完善函数返回值(看函数是返回引用 还是指针  或者是元素) 以及实现函数业务
//1、运算符重载1——普通函数
Complex operator+(const Complex & lhs, const Complex & rhs)
{
    cout << "Complex operator+()" << endl;
    //实现业务需求
    return Complex(lhs.getReal() + rhs.getReal(),
                   lhs.getImage() + rhs.getImage());
}

//2、运算符重载2——友元函数重载
//不需要在通过get函数获取成员变量
Complex operator-(const Complex & lhs, const Complex & rhs)
{
    cout << "Complex operator-()" << endl;
    //实现业务需求
    return Complex(lhs._real - rhs._real,
                   lhs._image - rhs._image);
}


int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);

    Complex c3 = c1 + c2; //普通的+ 号无法进行两个类型的相加
    cout << "普通函数:operator+:";
    c3.print();
    
    Complex c4 = c1 - c2; //普通的+ 号无法进行两个类型的相加
    cout << "友元函数:operator-:";
    c4.print();

    Complex c5 = c1 * c2;
    cout << "内置函数:operator*";
    c5.print();
    std::cout << "Hello world" << std::endl;
    return 0;
}

