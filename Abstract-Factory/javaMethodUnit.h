#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H
#include "MethodUnit.h"

class javaMethodUnit : public MethodUnit
{
public:
    javaMethodUnit( const std::string& name, const std::string& returnType, Flags flags )
        :MethodUnit(name, returnType, flags) {}

    std::string compile( unsigned int level = 0 ) const {
        std::string result = "";
        if( m_flags & STATIC ) {
            result += "static ";
        } else if( m_flags & FINAL ) {
            result += "final ";
        }
        result += m_returnType + " ";
        result += m_name + "() {\n";
        for( const auto& b : m_body ) {
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
        return result;
    }

};

#endif // JAVAMETHODUNIT_H
