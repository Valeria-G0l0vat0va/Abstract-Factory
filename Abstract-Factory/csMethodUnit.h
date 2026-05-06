#ifndef CSMETHODUNIT_H
#define CSMETHODUNIT_H
#include "MethodUnit.h"

class csMethodUnit : public MethodUnit
{
public:
    csMethodUnit( const std::string& name, const std::string& returnType, Flags flags )
        :MethodUnit(name, returnType, flags) {}

    std::string compile( unsigned int level = 0 ) const {
        std::string result = generateShift(level);
        if( m_flags & STATIC ) {
            result += "static ";
        } else if( m_flags & VIRTUAL ) {
            result += "virtual ";
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
#endif // CSMETHODUNIT_H
