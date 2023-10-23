#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock
{
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();

        std::string const &getName() const;
        std::string const &getTitle() const;

        void setTitle(std::string const &title);

        void introduce() const;

        void learnSpell(ASpell *aspell_ptr);
        void forgetSpell(std::string name);
        void launchSpell(std::string name, ATarget const &atarget_ref);
    
    private:
        std::string name;
        std::string title;

        std::map<std::string, ASpell *> spells;
  
};