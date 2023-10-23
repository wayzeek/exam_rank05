#pragma once

#include <iostream>
#include <string>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
    public:
        ASpell(std::string const &name, std::string const &effects);
        virtual ~ASpell();

        std::string const &getName() const;
        std::string const &getEffects() const;

        void launch(ATarget const &atarget_ref) const;

        virtual ASpell *clone() const = 0;

    private:
        std::string name;
        std::string effects;

   
};