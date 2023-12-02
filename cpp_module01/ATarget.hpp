#pragma once

# include <iostream>
# include <string>

# include "ASpell.hpp"

class ASpell ;

class ATarget
{
    public :
        ATarget(const std::string &type);
        virtual ~ATarget();

        const std::string &getType() const;

        virtual ATarget *clone() const = 0;

        void getHitBySpell(const ASpell &spell) const;
        
    private :
        std::string _type;

} ;