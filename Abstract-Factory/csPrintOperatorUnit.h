#ifndef CSPRINTOPERATORUNIT_H
#define CSPRINTOPERATORUNIT_H
#include "PrintOperatorUnit.h"


class csPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit csPrintOperatorUnit(const std::string& text) : PrintOperatorUnit(text) { }

    std::string compile(unsigned int level = 0) const {
        return generateShift(level) + "Console.WriteLine( \"" + m_text + "\" );\n";
    }
};
#endif // CSPRINTOPERATORUNIT_H
