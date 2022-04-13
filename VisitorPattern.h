#pragma once
#include <iostream>
namespace visitors {

    class Visitor {
    public:
        virtual std::string handlePerson(const std::string& name, int age) = 0;
        
    };

    class Person {
    private:
        std::string name;
        int age;
    public:
        Person(const std::string& name, int age) : name(name), age(age) {};
        std::string accept(Visitor* v) {
            return v->handlePerson(name, age);
        }
    };

};