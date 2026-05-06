#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H
#include "ClassUnit.h"

class javaClassUnit : public ClassUnit
{
public:
    static const std::vector< std::string > ACCESS_MODIFIERS;
public:
    explicit javaClassUnit( const std::string& name ) :ClassUnit(name){
         m_fields.resize(ACCESS_MODIFIERS.size());
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags ) {
        int accessModifier = PRIVATE;
        if( flags < ACCESS_MODIFIERS.size() ) {
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }
    std::string compile( unsigned int level = 0 ) const
    {
        std::string result = generateShift(level) + "public class " + m_name + "\n";
        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
            if (m_fields[i].empty()) {
                continue;
            }

            for (const auto& f : m_fields[i]) {
                result += f->compile(level + 1);
            }
            result += "\n";
        }

        result += generateShift(level) + "};\n";
        return result;
    }
};
const std::vector< std::string > javaClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private"};
#endif // JAVACLASSUNIT_H
