#include <QCoreApplication>
#include <iostream>
#include <memory>
#include "Factory.h"
#include "ClassUnit.h"
#include "MethodUnit.h"

std::string generateProgram(std::shared_ptr<ILanguageFactory> factory) {
    auto myClass = factory->createClass("MyClass");

    myClass->add(factory->createMethod("testFunc1", "void", 0), ClassUnit::PUBLIC);
    myClass->add(factory->createMethod("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);
    myClass->add(factory->createMethod("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);

    auto method = factory->createMethod("testFunc4", "void", MethodUnit::STATIC);
    method->add(factory->createPrintOperator("Hello, world!\\n"));
    myClass->add(method, ClassUnit::PROTECTED);

    return myClass->compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "=== C++ ===" << std::endl;
    std::cout << generateProgram(std::make_shared<CppFactory>()) << std::endl;

    std::cout << "\n=== C# ===" << std::endl;
    std::cout << generateProgram(std::make_shared<CsFactory>()) << std::endl;

    std::cout << "\n=== Java ===" << std::endl;
    std::cout << generateProgram(std::make_shared<JavaFactory>()) << std::endl;

    return a.exec();
}
