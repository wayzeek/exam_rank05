#pragma once

#include <map>
#include <algorithm>

#include "ASpell.hpp"

class ASpell;

class SpellBook
{
    public :
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *spell);
        void forgetSpell(const std::string &spellName);
        ASpell *createSpell(const std::string &spellName);
        
    private :
        std::map<std::string, ASpell *> _spellBook;
} ;