/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 11, 2018, 3:22 PM
 */

#include <iostream>
#include <string>

//using namespace std;

/*
 * 
 */

class A {
public:

    A() {
    }

    const std::string& otherFunction() const { /* if A object is created as constant
                                                * this function will be invoked
                                                */
        std::cout << "constant function" << '\n';
        return m_name;
    }

    const std::string& otherFunction() { /* if A object is created as non-constant
                                          * this function will be invoked
                                          */
        std::cout << "non-constant function" << '\n';
        return m_name;
    }

    void setName(const std::string& name) { //Constant function includes constant functions!!
        //const function does not change any member variables.
        //if we do not want the parameter to be changed we use const type& !!!!
        //
        std::cout << " const ref name :" << name << '\n';
        m_name = name;

    }

    void setName(std::string& name) {
        std::cout << " non-const ref name :" << name << '\n';
        m_name = name;
    }

    std::string m_name = "varname";
    int m_age;



};

int main(int argc, char** argv) {

    A a;
    std::string name("noname");
    a.setName(name);



    const std::string& str = a.otherFunction(); // if we use const string& then we cannot change str variable
    // bu if we use strng& or string only we can change the variable
    //if the returning value is const then you cannot cast it to a non-constant variable.

    //str = "deded";


    const A b; /* if we want to create an object as const, there should be a constructor for the class.
                *  Otherwise you cannot create it as constant
                */


    b.otherFunction(); /* constant function is called here. But above non-const function is called */

    std::cout << str << '\n';

    a.setName("deneme");

    std::string strnew("strnew");

    a.setName(strnew);

    return 0;
}

