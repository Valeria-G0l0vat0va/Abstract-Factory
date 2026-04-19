#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H
#include "PrintOperatorUnit.h"


class javaPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit javaPrintOperatorUnit( const std::string& text ) : PrintOperatorUnit(text) { }

    std::string compile( unsigned int level = 0 ) const {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }
};
#endif // JAVAPRINTOPERATORUNIT_H
