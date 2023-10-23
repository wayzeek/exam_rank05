#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"

class ASpell;

class ATarget
{
     public:
        ATarget(std::string const &type);
        virtual ~ATarget();

        std::string const &getType() const;

        void getHitBySpell(ASpell const &aspell_ref) const;

        virtual ATarget *clone() const = 0;
    private:
        std::string type;
};

