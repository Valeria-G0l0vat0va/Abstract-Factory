#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H
#include "PrintOperatorUnit.h"


class javaPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit javaPrintOperatorUnit( const std::string& text ) : PrintOperatorUnit(text) { }

    std::string compile( unsigned int level = 0 ) const {
        return generateShift(level) + "System.out.println( \"" + m_text + "\" );";
    }
};
#endif // JAVAPRINTOPERATORUNIT_H
