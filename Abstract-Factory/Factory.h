#ifndef FACTORY_H
#define FACTORY_H
#include"cppClassUnit.h"
#include"cppMethodUnit.h"
#include"cppPrintOperatorUnit.h"
#include"csClassUnit.h"
#include"csMethodUnit.h"
#include"csPrintOperatorUnit.h"
#include"javaClassUnit.h"
#include"javaMethodUnit.h"
#include"javaPrintOperatorUnit.h"

class ILanguageFactory
{
public:
    virtual std::shared_ptr<ClassUnit> createClass(const std::string& name) = 0;
    virtual std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) = 0;
    virtual~ILanguageFactory(){}
};

class cppFactory : public ILanguageFactory
{
    std::shared_ptr<ClassUnit> createClass(const std::string& name)
    {
        return std::make_shared<CppClassUnit>(name);
    }
    std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &return_type, Unit::Flags flags) const
    {
        return std::make_shared<CppMethodUnit>(name, return_type, flags);
    }
    std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const
    {
        return std::make_shared<CppPrintOperatorUnit>(name);
    }
};

class CsFactory : public ILanguageFactory
{
public:
    std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const
    {
        return std::make_shared<CsClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &return_type, Unit::Flags flags) const
    {
        return std::make_shared<CsMethodUnit>(name, return_type, flags);
    }

    std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const
    {
        return std::make_shared<CsPrintOperatorUnit>(name);
    }
};

class JavaFactory : public ILanguageFactory
{
public:
    std::shared_ptr<ClassUnit> CreateClass(const std::string &name) const
    {
        return std::make_shared<JavaClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> CreateMethod(const std::string &name, const std::string &return_type, Unit::Flags flags) const
    {
        return std::make_shared<JavaMethodUnit>(name, return_type, flags);
    }

    std::shared_ptr<PrintOperatorUnit> CreatePrintOperator(const std::string &name) const
    {
        return std::make_shared<JavaPrintOperatorUnit>(name);
    }
};

#endif // FACTORY_H
