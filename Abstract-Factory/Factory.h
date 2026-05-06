#ifndef FACTORY_H
#define FACTORY_H

#include "cppClassUnit.h"
#include "cppMethodUnit.h"
#include "cppPrintOperatorUnit.h"
#include "csClassUnit.h"
#include "csMethodUnit.h"
#include "csPrintOperatorUnit.h"
#include "javaClassUnit.h"
#include "javaMethodUnit.h"
#include "javaPrintOperatorUnit.h"

class ILanguageFactory
{
public:
    virtual std::shared_ptr<ClassUnit> createClass(const std::string& name) = 0;
    virtual std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) = 0;
    virtual ~ILanguageFactory() {}
};

class CppFactory : public ILanguageFactory
{
public:
    std::shared_ptr<ClassUnit> createClass(const std::string& name)
    {
        return std::make_shared<cppClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags)
    {
        return std::make_shared<cppMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text)
    {
        return std::make_shared<cppPrintOperatorUnit>(text);
    }
};

class CsFactory : public ILanguageFactory
{
public:
    std::shared_ptr<ClassUnit> createClass(const std::string& name)
    {
        return std::make_shared<csClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags)
    {
        return std::make_shared<csMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text)
    {
        return std::make_shared<csPrintOperatorUnit>(text);
    }
};

class JavaFactory : public ILanguageFactory
{
public:
    std::shared_ptr<ClassUnit> createClass(const std::string& name)
    {
        return std::make_shared<javaClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags)
    {
        return std::make_shared<javaMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text)
    {
        return std::make_shared<javaPrintOperatorUnit>(text);
    }
};

#endif // FACTORY_H
