#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook
{
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *aspell_ptr);
        void forgetSpell(std::string const &name);
        ASpell* createSpell(std::string const &name);
    
    private:
        std::map<std::string, ASpell *> arr_spell;
};