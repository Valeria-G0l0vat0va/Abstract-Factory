#ifndef CPPPRINTOPERATORUNIT_H
#define CPPPRINTOPERATORUNIT_H
#include "PrintOperatorUnit.h"


class cppPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit cppPrintOperatorUnit( const std::string& text ) : PrintOperatorUnit(text) { }

    std::string compile( unsigned int level = 0 ) const {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }
};
#endif // CPPPRINTOPERATORUNIT_H
